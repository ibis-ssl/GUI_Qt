#include "qt_communication_tester.h"
#include "ui_qt_communication_tester.h"
#include "robot_packet.h"
#include <string.h>
#include <math.h>
#include <QNetworkInterface>

#define SEND_PORT         12345
#define RECV_PORT_BASE    50000     // 受信ポート = RECV_PORT_BASE + orionIP
#define SEND_PACKET_SIZE  (1 + (int)sizeof(RobotCommandSerializedV2))  // ロボットID + コマンド
#define RECV_PACKET_MIN   60        // readMsg() が読む最大インデックス + 1
#define DATA_LOST_LIMIT   10        // 送受信カウンタの差がこれを超えたら "data lost"

// 速度・加速度の固定値
#define LINEAR_VELOCITY_LIMIT   5.0f
#define ANGULAR_VELOCITY_LIMIT  10.0f
#define LATENCY_TIME_MS         100
#define ELAPSED_TIME_MS         20

// 受信データ (リトルエンディアン) の読み出し
static float read_f32(const uint8_t *p) { float v;    memcpy(&v, p, sizeof(v)); return v; }
static uint16_t read_u16(const uint8_t *p) { uint16_t v; memcpy(&v, p, sizeof(v)); return v; }

// float を [high, low] の2バイトで書き込む
static void put_float(uint8_t *p, float val, float range)
{
    TwoByte b = convertFloatToTwoByte(val, range);
    p[0] = b.high;
    p[1] = b.low;
}

static void put_u16(uint8_t *p, uint16_t val)
{
    TwoByte b = convertUInt16ToTwoByte(val);
    p[0] = b.high;
    p[1] = b.low;
}

static void show_int(QTextBrowser *w, int val)     { w->setText(QString::number(val)); }
static void show_f2(QTextBrowser *w, double val)   { w->setText(QString::asprintf("%4.2f", val)); }


Qt_Communication_Tester::Qt_Communication_Tester(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_Communication_Tester)
{
    ui->setupUi(this);
    QObject::connect(&thread_time, SIGNAL(data_update(int)), this, SLOT(timer_callback(int)));

    sendUdpSocket = new QUdpSocket(this);
    recUdpSocket  = new QUdpSocket(this);
    connect(recUdpSocket, &QUdpSocket::readyRead, this, &Qt_Communication_Tester::readPendingDatagrams);

    installEventFilter(this);

    orionIP           = 100;
    is_running        = false;
    last_sent_counter = 0;
    target_theta      = 0;
    kick_power        = 0;
    dribble_power     = 0;
    target_speed[0]   = 0;
    target_speed[1]   = 0;

    ui->show_dribble_power->setText("0");
    ui->show_kick_power->setText("0");
    ui->show_target_theta->setText("0");
    ui->show_vx->setText("0.500");
    ui->show_vy->setText("0.500");
    ui->show_ar->setText("5.000");
}

Qt_Communication_Tester::~Qt_Communication_Tester()
{
    thread_time.quit();
    thread_time.wait();
    delete ui;
}


/* ---------------- 送信 (15ms 周期) ---------------- */

void Qt_Communication_Tester::timer_callback(int time_counter)
{
    kick_power    = ui->kick_EN->isChecked()    ? ui->kick_power->value()    : 0;
    dribble_power = ui->dribble_EN->isChecked() ? ui->dribble_power->value() : 0;
    target_theta  = (180 - ui->target_theta->value()) * M_PI / 180.0;   // ダイヤル 0～360 → +π～-π

    uint8_t flags = 0x00;
    flags |= ui->VisionOK->isChecked()                         << IS_VISION_AVAILABLE;
    flags |= ui->chipEN->isChecked()                           << ENABLE_CHIP;
    flags |= ui->LIFT_DRIBBLER->isChecked()                    << LIFT_DRIBBLER;
    flags |= ui->STOP_EMERGENCY->isChecked()                   << STOP_EMERGENCY;
    flags |= ui->PRIORITIZE_MOVE->isChecked()                  << PRIORITIZE_MOVE;
    flags |= ui->PRIORITIZE_ACCURATE_ACCELERATION->isChecked() << PRIORITIZE_ACCURATE_ACCELERATION;

    // 速度指令は極座標 (r, θ)
    float speed_r     = sqrt(target_speed[0] * target_speed[0] + target_speed[1] * target_speed[1]);
    float speed_theta = atan2(target_speed[1], target_speed[0]);
    float accel_limit = ui->AR->value() / 100.0;

    orionIP = ui->setIP->value();
    int robot_id = orionIP - 100;

    ui->setdata->setText(QString::asprintf(
        "ID=%d check=%3d r=%.3f Θ=%.3f theta=%.3f kick=%.2f chip=%d Dri=%.2f local_flags =%d",
        robot_id, time_counter, speed_r, speed_theta, target_theta,
        kick_power, ui->chipEN->isChecked(), dribble_power, flags));

    // パケット: [0]=ロボットID, [1～]=コマンド (robot_packet.h の Address 順)
    QByteArray send_packet(SEND_PACKET_SIZE, 0);
    uint8_t *packet = (uint8_t *)send_packet.data();
    uint8_t *cmd    = packet + 1;

    packet[0]              = robot_id;
    cmd[HEADER]            = 0x00;
    cmd[CHECK_COUNTER]     = time_counter;
    // vision 位置欄には (r, θ) を入れている (従来どおり)
    put_float(&cmd[VISION_GLOBAL_X_HIGH],       speed_r,      32.767);
    put_float(&cmd[VISION_GLOBAL_Y_HIGH],       speed_theta,  32.767);
    put_float(&cmd[VISION_GLOBAL_THETA_HIGH],   target_theta, M_PI);
    put_float(&cmd[TARGET_GLOBAL_THETA_HIGH],   target_theta, M_PI);
    cmd[KICK_POWER]        = (uint8_t)kick_power;
    cmd[DRIBBLE_POWER]     = (uint8_t)dribble_power;
    put_float(&cmd[ACCELERATION_LIMIT_HIGH],    accel_limit,            32.767);
    put_float(&cmd[LINEAR_VELOCITY_LIMIT_HIGH], LINEAR_VELOCITY_LIMIT,  32.767);
    put_float(&cmd[ANGULAR_VELOCITY_LIMIT_HIGH],ANGULAR_VELOCITY_LIMIT, 32.767);
    put_u16(&cmd[LATENCY_TIME_MS_HIGH],                   LATENCY_TIME_MS);
    put_u16(&cmd[ELAPSED_TIME_MS_SINCE_LAST_VISION_HIGH], ELAPSED_TIME_MS);
    cmd[FLAGS]             = flags;
    cmd[CONTROL_MODE]      = POLAR_VELOCITY_TARGET_MODE;
    put_float(&cmd[CONTROL_MODE_ARGS + 0],      speed_r,      32.767);
    put_float(&cmd[CONTROL_MODE_ARGS + 2],      speed_theta,  32.767);

    QString sending = QString::asprintf("ID=%3d", robot_id);
    for (int i = 0; i <= 25; i++) {
        sending += QString::asprintf(" [%d]=%3d", i, packet[i]);
    }
    ui->sendingdata->setText(sending);

    QHostAddress address("192.168.20." + QString::number(orionIP));
    sendUdpSocket->writeDatagram(send_packet, address, SEND_PORT);

    last_sent_counter = time_counter;
}


/* ---------------- 受信 ---------------- */

void Qt_Communication_Tester::readPendingDatagrams()
{
    while (recUdpSocket->hasPendingDatagrams()) {
        readMsg(recUdpSocket->receiveDatagram());
    }
}

void Qt_Communication_Tester::readMsg(const QNetworkDatagram &datagram)
{
    QByteArray data = datagram.data();
    int len = data.size();
    if (len < RECV_PACKET_MIN) {
        ui->log->append(QString::asprintf("short packet (%d bytes) dropped", len));
        return;
    }
    const uint8_t *rec = (const uint8_t *)data.constData();

    // ロボットがエコーしたチェックカウンタとの差 (周回を考慮)
    int ring_counter = rec[3];
    int diff = (last_sent_counter - ring_counter + TIME_COUNTER_PERIOD) % TIME_COUNTER_PERIOD;
    if (diff > DATA_LOST_LIMIT) {
        ui->log->append("data lost");
    }

    QTextBrowser *show_ball[4]    = { ui->show_ball0, ui->show_ball1, ui->show_ball2, ui->show_ball3 };
    QTextBrowser *show_current[4] = { ui->show_current0, ui->show_current1, ui->show_current2, ui->show_current3 };
    QTextBrowser *show_temp[7]    = { ui->show_temp0, ui->show_temp1, ui->show_temp2, ui->show_temp3,
                                      ui->show_temp4, ui->show_temp5, ui->show_temp6 };

    show_int(ui->show_connection, ring_counter);
    show_f2(ui->show_robot_theta,       read_f32(&rec[4]));     // yaw_angle
    show_f2(ui->show_robot_voltage,     read_f32(&rec[8]));     // voltage[0]
    for (int i = 0; i < 3; i++) {
        show_int(show_ball[i], rec[12 + i]);
    }
    show_int(ui->show_kickstate,        (uint8_t)(rec[15] * 10));
    show_int(ui->show_error0,           read_u16(&rec[16]));    // error_info[0]
    show_int(ui->show_error1,           read_u16(&rec[18]));    // error_info[1]
    show_f2(ui->show_error2,            read_f32(&rec[20]));    // error_info_data
    for (int i = 0; i < 4; i++) {
        show_int(show_current[i], (int8_t)(rec[24 + i] * 10));
    }
    show_int(show_ball[3], rec[28]);
    for (int i = 0; i < 7; i++) {
        show_int(show_temp[i], rec[29 + i]);
    }
    show_f2(ui->show_robot_theta_diff,  read_f32(&rec[36]));    // diff_angle
    show_f2(ui->show_cap_voltage,       read_f32(&rec[40]));    // voltage[1]
    show_f2(ui->show_odomx,             read_f32(&rec[44]) * 1000);
    show_f2(ui->show_odomy,             read_f32(&rec[48]) * 1000);
    show_f2(ui->show_speedx,            read_f32(&rec[52]));
    show_f2(ui->show_speedy,            read_f32(&rec[56]));

    ui->data_from_robot->setText(QString::asprintf(
        "data_len=%d [0]=%3d [1]=%3d [2]=%3d [3]=%3d \n"
        " [4]=%x  [5]=%x  [6]=%x [7]=%x \n"
        " [8]=%x [9]=%x [10]=%x [11]=%x \n"
        " [12]=%x [13]=%x [14]=%x [15]=%x",
        len, rec[0], rec[1], rec[2], rec[3], rec[4], rec[5], rec[6], rec[7],
        rec[8], rec[9], rec[10], rec[11], rec[12], rec[13], rec[14], rec[15]));

    show_int(ui->show_diff, diff);
}


/* ---------------- 開始 / 停止 ---------------- */

void Qt_Communication_Tester::start_communication()
{
    ui->log->append("start");
    ui->startbotton->setText("stop");
    is_running = true;
    thread_time.start();

    recUdpSocket->bind(QHostAddress::AnyIPv4, RECV_PORT_BASE + orionIP, QUdpSocket::ShareAddress);
    QHostAddress group("224.5.20." + QString::number(orionIP));
    for (const QNetworkInterface &iface : QNetworkInterface::allInterfaces()) {
        recUdpSocket->joinMulticastGroup(group, iface);
    }
}

void Qt_Communication_Tester::stop_communication()
{
    ui->log->append("stop");
    ui->startbotton->setText("start");
    is_running = false;
    thread_time.quit();
    thread_time.wait();
    recUdpSocket->close();
}

void Qt_Communication_Tester::on_startbotton_clicked()
{
    if (is_running) {
        stop_communication();
    } else {
        start_communication();
    }
}

void Qt_Communication_Tester::on_setIP_textChanged(const QString &arg1)
{
    orionIP = arg1.toInt();
    ui->log->append(QString::asprintf("set to IP address to 192.168.20.%d", orionIP));
    if (is_running) {
        stop_communication();
    }
}


/* ---------------- キー操作 ---------------- */

bool Qt_Communication_Tester::eventFilter(QObject *, QEvent *event)
{
    switch (event->type()) {
    case QEvent::WindowDeactivate:
        target_speed[0] = 0;
        target_speed[1] = 0;
        return false;
    case QEvent::KeyPress:
        return eventKeyPress(static_cast<QKeyEvent *>(event));
    case QEvent::KeyRelease:
        return eventKeyRelease(static_cast<QKeyEvent *>(event));
    default:
        return false;
    }
}

bool Qt_Communication_Tester::eventKeyPress(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return true;
    }
    switch (event->key()) {
    case Qt::Key_W: target_speed[0] =  ui->vx->value() / 100.0; break;
    case Qt::Key_S: target_speed[0] = -ui->vx->value() / 100.0; break;
    case Qt::Key_A: target_speed[1] =  ui->vy->value() / 100.0; break;
    case Qt::Key_D: target_speed[1] = -ui->vy->value() / 100.0; break;
    case Qt::Key_Escape:
        if (is_running) {
            stop_communication();
        }
        break;
    default:
        return false;
    }
    return true;
}

bool Qt_Communication_Tester::eventKeyRelease(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return true;
    }
    switch (event->key()) {
    case Qt::Key_W:
    case Qt::Key_S: target_speed[0] = 0; break;
    case Qt::Key_A:
    case Qt::Key_D: target_speed[1] = 0; break;
    default:
        return false;
    }
    return true;
}


/* ---------------- スライダー等の表示 ---------------- */

void Qt_Communication_Tester::on_kick_power_valueChanged(int value)
{
    show_int(ui->show_kick_power, value * 5);
}

void Qt_Communication_Tester::on_dribble_power_valueChanged(int value)
{
    show_int(ui->show_dribble_power, value * 5);
}

void Qt_Communication_Tester::on_target_theta_valueChanged(int value)
{
    show_int(ui->show_target_theta, 180 - value);
}

void Qt_Communication_Tester::on_vx_valueChanged(int value)
{
    ui->show_vx->setText(QString::asprintf("%.3f", value / 100.0));
}

void Qt_Communication_Tester::on_vy_valueChanged(int value)
{
    ui->show_vy->setText(QString::asprintf("%.3f", value / 100.0));
}

void Qt_Communication_Tester::on_AR_valueChanged(int value)
{
    ui->show_ar->setText(QString::asprintf("%.2f", value / 100.0));
}

void Qt_Communication_Tester::on_reset_theta_clicked()
{
    target_theta = 0;
    ui->target_theta->setValue(180);
}
