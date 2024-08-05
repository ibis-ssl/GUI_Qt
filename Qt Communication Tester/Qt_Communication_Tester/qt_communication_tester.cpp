#include "qt_communication_tester.h"
#include "ui_qt_communication_tester.h"
#include <string.h>
#include <robot_packet.h>

ai_cmd_t ai_cmd;
int kick_EN=0;
int dribble_EN=0;
uint8_t header=0x00;



#define TX_BUF_SIZE_ETHER (128)
typedef union
{
    uint8_t buf[TX_BUF_SIZE_ETHER];

    struct
    {
        uint8_t head[2];
        uint8_t counter, return_counter;

        uint8_t kick_state;

        uint8_t temperature[7];
        uint16_t error_info[2];
        float error_info_data[1];
        int8_t motor_current[4];
        uint8_t ball_detection[4];

        float_t yaw_angle, diff_angle;
        float_t odom[2], odom_speed[2], mouse_raw[2], voltage[2];

        bool is_vision_available;
        bool enable_chip;
        bool lift_dribbler;
        bool stop_emergency;
        bool prioritize_move;
        bool prioritize_accurate_acceleration;
    } data;
} tx_msg_t;

union Data
{
    float f;
    char b[4];
};

union Data16
{
    uint16_t f16;
    char c[2];
};


Qt_Communication_Tester::Qt_Communication_Tester(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_Communication_Tester)
{
    ui->setupUi(this);
    QObject::connect(&thread_time, SIGNAL(data_update(int)),this, SLOT(timer_callback(int)) );
    is_start=0;

    ai_cmd.allow_local_flags=0;

    installEventFilter(this);

    orionIP=100;
    ring_counter=0;
    ring_counter_callback=0;
    char str[5];
    sprintf(str,"%d",0);
    ui->show_dribble_power->setText(str);
    ui->show_kick_power->setText(str);
    ui->show_target_theta->setText("0");
    ui->show_vx->setText("0.500");
    ui->show_vy->setText("0.500");

}

Qt_Communication_Tester::~Qt_Communication_Tester()
{

    thread_time.quit();
    thread_time.wait();
    delete ui;
}


void Qt_Communication_Tester::timer_callback(int time_counter){


    auto to_two_byte = [](float val, float range) -> std::pair<uint8_t, uint8_t> {
        uint16_t two_byte = (uint16_t)(32767.f * (float)(val / range) + 32767.f);
        uint8_t byte_low, byte_high;
        byte_low = two_byte & 0x00FF;
        byte_high = (two_byte & 0xFF00) >> 8;
        return std::make_pair(byte_low, byte_high);
    };



    //kick value
    if(ui->kick_EN->isChecked()>0){
            ai_cmd.kick_power= ui->kick_power->value();
    }
    else{
        ai_cmd.kick_power= 0;
    }

    //dribble value
    if(ui->dribble_EN->isChecked()>0){
        ai_cmd.drible_power=ui->dribble_power->value();
    }
    else{
        ai_cmd.drible_power= 0;
    }


    uint8_t flags = 0x00;
    flags |= (ui->VisionOK->isChecked() << IS_VISION_AVAILABLE);
    flags |= (ui->chipEN->isChecked() << ENABLE_CHIP);
    flags |= (ui->LIFT_DRIBBLER->isChecked() << LIFT_DRIBBLER);
    flags |= (ui->STOP_EMERGENCY->isChecked() << STOP_EMERGENCY);
    flags |= (ui->PRIORITIZE_MOVE->isChecked() << PRIORITIZE_MOVE);
    flags |= (ui->PRIORITIZE_ACCURATE_ACCELERATION->isChecked() << PRIORITIZE_ACCURATE_ACCELERATION);
    uint8_t FLAGS;
    FLAGS = flags;


    ai_cmd.target_theta=(float)(ui->target_theta->value()-180.0)*(-1.0)*M_PI/180.0;

    // -pi ~ pi -> 0 ~ 32767 ~ 65534
    auto [target_theta_low, target_theta_high] = to_two_byte(ai_cmd.target_theta, M_PI);
    //auto [vel_surge_low, vel_surge_high] = to_two_byte(ai_cmd.local_target_speed[0], 7.0);
    //auto [vel_sway_low, vel_sway_high] = to_two_byte(ai_cmd.local_target_speed[1], 7.0);
    auto [vision_x_low, vision_x_high] = to_two_byte(ai_cmd.local_target_speed[0], 32.767);
    auto [vision_y_low, vision_y_high] = to_two_byte(ai_cmd.local_target_speed[1], 32.767);
    auto [vision_theta_low, vision_theta_high] = to_two_byte(ai_cmd.target_theta, M_PI);
    auto [SPEED_LIMIT_LOW, SPEED_LIMIT_HIGH] = to_two_byte(5.0, 32.767);
    auto [OMEGA_LIMIT_LOW, OMEGA_LIMIT_HIGH] = to_two_byte(10.0, 32.767);
    TwoByte latency_time = convertUInt16ToTwoByte(100.0);
    uint8_t LATENCY_TIME_MS_HIGH, LATENCY_TIME_MS_LOW;
    LATENCY_TIME_MS_HIGH=static_cast<uint8_t>(latency_time.high);
    LATENCY_TIME_MS_LOW=static_cast<uint8_t>(latency_time.low);
    TwoByte elapsed_time = convertUInt16ToTwoByte(20.0);
    uint8_t ELAPSED_TIME_MS_SINCE_LAST_VISION_HIGH, ELAPSED_TIME_MS_SINCE_LAST_VISION_LOW;
    ELAPSED_TIME_MS_SINCE_LAST_VISION_HIGH=static_cast<uint8_t>(elapsed_time.high);
    ELAPSED_TIME_MS_SINCE_LAST_VISION_LOW =static_cast<uint8_t>(elapsed_time.low);
    uint8_t CONTROL_MODE;
    CONTROL_MODE=SIMPLE_VELOCITY_TARGET_MODE;
    //CONTROL_MODE_ARGS=mode_args.simple_velocity;

    orionIP = ui->setIP->value();
    char str[100];
    sprintf(str,"ID=%d check=%3d Vx=%.3f Vy=%.3f theta=%.3f kick=%.2f chip=%d Dri=%.2f local_flags =%d",
            orionIP-100, time_counter,ai_cmd.local_target_speed[0],ai_cmd.local_target_speed[1],ai_cmd.target_theta,
            ai_cmd.kick_power,ai_cmd.chip_en,ai_cmd.drible_power,(uint8_t)flags);
    ui->setdata->setText(str);


    QByteArray send_packet;
    send_packet.resize(64);
    send_packet.fill(0,64);

    header=0x00;

    send_packet[0] = static_cast<uint8_t>(header);
    send_packet[1] = static_cast<uint8_t>(time_counter);
    send_packet[2] = static_cast<uint8_t>(vision_x_high);
    send_packet[3] = static_cast<uint8_t>(vision_x_low);
    send_packet[4] = static_cast<uint8_t>(vision_y_high);
    send_packet[5] = static_cast<uint8_t>(vision_y_low);
    send_packet[6] = static_cast<uint8_t>(vision_theta_high);
    send_packet[7] = static_cast<uint8_t>(vision_theta_low);
    send_packet[8] = static_cast<uint8_t>(target_theta_high);
    send_packet[9] = static_cast<uint8_t>(target_theta_low);
    send_packet[10] = static_cast<uint8_t>(ai_cmd.kick_power);
    send_packet[11] = static_cast<uint8_t>(ai_cmd.drible_power);
    send_packet[12] = static_cast<uint8_t>(SPEED_LIMIT_HIGH);
    send_packet[13] = static_cast<uint8_t>(SPEED_LIMIT_LOW);
    send_packet[14] = static_cast<uint8_t>(OMEGA_LIMIT_HIGH);
    send_packet[15] = static_cast<uint8_t>(OMEGA_LIMIT_LOW);
    send_packet[16] = static_cast<uint8_t>(LATENCY_TIME_MS_HIGH);
    send_packet[17] = static_cast<uint8_t>(LATENCY_TIME_MS_LOW);
    send_packet[18] = static_cast<uint8_t>(ELAPSED_TIME_MS_SINCE_LAST_VISION_HIGH);
    send_packet[19] = static_cast<uint8_t>(ELAPSED_TIME_MS_SINCE_LAST_VISION_LOW);
    send_packet[20] = static_cast<uint8_t>(FLAGS);
    send_packet[21] = static_cast<uint8_t>(CONTROL_MODE);
    send_packet[22] = static_cast<uint8_t>(vision_x_high);
    send_packet[23] = static_cast<uint8_t>(vision_x_low);
    send_packet[24] = static_cast<uint8_t>(vision_y_high);
    send_packet[25] = static_cast<uint8_t>(vision_y_low);



    char str2[400];
    sprintf(str2,"ID=%3d [0]=%3d [1]=%3d [2]=%3d [3]=%3d [4]=%3d [5]=%3d [6]=%3d [7]=%3d [8]=%3d [9]=%3d [10]=%3d [11]=%3d [12]=%3d [13]=%3d [14]=%3d [15]=%3d [16]=%3d [17]=%3d [18]=%3d [19]=%3d [20]=%3d [21]=%3d [22]=%3d [23]=%3d [24]=%3d [25]=%3d",
            orionIP-100,(uint8_t)send_packet[0],(uint8_t)send_packet[1],(uint8_t)send_packet[2],(uint8_t)send_packet[3],(uint8_t)send_packet[4],(uint8_t)send_packet[5],(uint8_t)send_packet[6]
            ,(uint8_t)send_packet[7],(uint8_t)send_packet[8],(uint8_t)send_packet[9],(uint8_t)send_packet[10],(uint8_t)send_packet[11],(uint8_t)send_packet[12],(uint8_t)send_packet[13]
            ,(uint8_t)send_packet[14],(uint8_t)send_packet[15],(uint8_t)send_packet[16],(uint8_t)send_packet[17],(uint8_t)send_packet[18],(uint8_t)send_packet[19]
            ,(uint8_t)send_packet[20],(uint8_t)send_packet[21],(uint8_t)send_packet[22],(uint8_t)send_packet[23],(uint8_t)send_packet[24],(uint8_t)send_packet[25]);
    ui->sendingdata->setText(str2);
    QString address = "192.168.20." +  QString::number(orionIP);

    sendUdpSocket = new QUdpSocket(this);
    sendUdpSocket->bind(QHostAddress(address), 12345);
    sendUdpSocket->writeDatagram(send_packet,64,QHostAddress(address), 12345);
    sendUdpSocket->close();

}


bool Qt_Communication_Tester::eventKeyPress(QKeyEvent *event)
{

    if (event->isAutoRepeat()) {
        return true;
    }

    switch (event->key()) {
        case Qt::Key_W:
            ai_cmd.local_target_speed[0]=(float)ui->vx->value()/100.0;
            break;
        case Qt::Key_S:
            ai_cmd.local_target_speed[0]=(float)(ui->vx->value())*(-1.0)/100.0;
            break;
        case Qt::Key_A:
            ai_cmd.local_target_speed[1]=(float)(ui->vy->value())/100.0;
            break;
        case Qt::Key_D:
            ai_cmd.local_target_speed[1]=(float)(ui->vy->value())*(-1.0)/100.0;
            break;
        case Qt::Key_Escape:
            if(is_start==1){
            on_startbotton_clicked();
            }
            break;
        default:  return false;
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
            ai_cmd.local_target_speed[0]=0.0;
            break;
    case Qt::Key_A:
            ai_cmd.local_target_speed[1]=0.0;
            break;
    case Qt::Key_S:
            ai_cmd.local_target_speed[0]=0.0;
            break;
    case Qt::Key_D:
            ai_cmd.local_target_speed[1]=0.0;
            break;
    default: return false;
    }
    return true;
}

void Qt_Communication_Tester::readPendingDatagrams(){
    while (recUdpSocket->hasPendingDatagrams()) {
            QNetworkDatagram datagram = recUdpSocket->receiveDatagram();
            readMsg(datagram);
    }
}

void Qt_Communication_Tester::readMsg(QNetworkDatagram datagram){

    QByteArray data = datagram.data();
    int len = data.size();

    uint8_t rec_data[len];
    std::memcpy(rec_data ,data.data(),len);

    tx_msg_t rx_data;
    Data data_convert;
    Data16 data_convert16;

    ring_counter = rec_data[3];
    data_convert.b[0]=rec_data[4];
    data_convert.b[1]=rec_data[5];
    data_convert.b[2]=rec_data[6];
    data_convert.b[3]=rec_data[7];
    rx_data.data.yaw_angle=data_convert.f;
    data_convert.b[0]=rec_data[8];
    data_convert.b[1]=rec_data[9];
    data_convert.b[2]=rec_data[10];
    data_convert.b[3]=rec_data[11];
    rx_data.data.voltage[0]=data_convert.f;
    rx_data.data.ball_detection[0]=rec_data[12];
    rx_data.data.ball_detection[1]=rec_data[13];
    rx_data.data.ball_detection[2]=rec_data[14];
    rx_data.data.kick_state=rec_data[15]*10;

    char str4[6];
    sprintf(str4,"%d",ring_counter);
    ui->show_connection->setText(str4);
    char str2[6];
    sprintf(str2,"%4.2f",(float)rx_data.data.yaw_angle);
    ui->show_robot_theta->setText(str2);
    char str3[6];
    sprintf(str3,"%4.2f",rx_data.data.voltage[0]);
    ui->show_robot_voltage->setText(str3);
    char str_ball0[6];
    sprintf(str_ball0,"%d",rx_data.data.ball_detection[0]);
    ui->show_ball0->setText(str_ball0);
    char str_ball1[6];
    sprintf(str_ball1,"%d",rx_data.data.ball_detection[1]);
    ui->show_ball1->setText(str_ball1);
    char str_ball2[6];
    sprintf(str_ball2,"%d",rx_data.data.ball_detection[2]);
    ui->show_ball2->setText(str_ball2);
    char str5[6];
    sprintf(str5,"%d",rx_data.data.kick_state);
    ui->show_kickstate->setText(str5);




    data_convert16.c[0]=rec_data[16];
    data_convert16.c[1]=rec_data[17];
    rx_data.data.error_info[0]=data_convert16.f16;
    data_convert16.c[0]=rec_data[18];
    data_convert16.c[1]=rec_data[19];
    rx_data.data.error_info[1]=data_convert16.f16;
    data_convert.b[0]=rec_data[20];
    data_convert.b[1]=rec_data[21];
    data_convert.b[2]=rec_data[22];
    data_convert.b[3]=rec_data[23];
    rx_data.data.error_info_data[0]=data_convert.f;

    rx_data.data.motor_current[0]=rec_data[24];
    rx_data.data.motor_current[1]=rec_data[25];
    rx_data.data.motor_current[2]=rec_data[26];
    rx_data.data.motor_current[3]=rec_data[27];

    char str_error0[6];
    sprintf(str_error0,"%d",rx_data.data.error_info[0]);
    ui->show_error0->setText(str_error0);
    char str_error1[6];
    sprintf(str_error1,"%d",rx_data.data.error_info[1]);
    ui->show_error1->setText(str_error1);
    char str_error2[6];
    sprintf(str_error2,"%4.2f",rx_data.data.error_info_data[0]);
    ui->show_error2->setText(str_error2);
    char str_current0[6];
    sprintf(str_current0,"%d",rx_data.data.motor_current[0]);
    ui->show_current0->setText(str_current0);
    char str_current1[6];
    sprintf(str_current1,"%d",rx_data.data.motor_current[1]);
    ui->show_current1->setText(str_current1);
    char str_current2[6];
    sprintf(str_current2,"%d",rx_data.data.motor_current[2]);
    ui->show_current2->setText(str_current2);
    char str_current3[6];
    sprintf(str_current3,"%d",rx_data.data.motor_current[3]);
    ui->show_current3->setText(str_current3);

    rx_data.data.ball_detection[3]=rec_data[28];

    rx_data.data.temperature[0]=rec_data[29];
    rx_data.data.temperature[1]=rec_data[30];
    rx_data.data.temperature[2]=rec_data[31];
    rx_data.data.temperature[3]=rec_data[32];
    rx_data.data.temperature[4]=rec_data[33];
    rx_data.data.temperature[5]=rec_data[34];
    rx_data.data.temperature[6]=rec_data[35];
    data_convert.b[0]=rec_data[36];
    data_convert.b[1]=rec_data[37];
    data_convert.b[2]=rec_data[38];
    data_convert.b[3]=rec_data[39];
    rx_data.data.diff_angle=data_convert.f;


    char str_ball3[6];
    sprintf(str_ball3,"%d",rx_data.data.ball_detection[3]);
    ui->show_ball3->setText(str_ball3);
    char str_temp0[6];
    sprintf(str_temp0,"%d",rx_data.data.temperature[0]);
    ui->show_temp0->setText(str_temp0);
    char str_temp1[6];
    sprintf(str_temp1,"%d",rx_data.data.temperature[1]);
    ui->show_temp1->setText(str_temp1);
    char str_temp2[6];
    sprintf(str_temp2,"%d",rx_data.data.temperature[2]);
    ui->show_temp2->setText(str_temp2);
    char str_temp3[6];
    sprintf(str_temp3,"%d",rx_data.data.temperature[3]);
    ui->show_temp3->setText(str_temp3);
    char str_temp4[6];
    sprintf(str_temp4,"%d",rx_data.data.temperature[4]);
    ui->show_temp4->setText(str_temp4);
    char str_temp5[6];
    sprintf(str_temp5,"%d",rx_data.data.temperature[5]);
    ui->show_temp5->setText(str_temp5);
    char str_temp6[6];
    sprintf(str_temp6,"%d",rx_data.data.temperature[6]);
    ui->show_temp6->setText(str_temp6);
    char str_diff[6];
    sprintf(str_diff,"%4.2f",rx_data.data.diff_angle);
    ui->show_robot_theta_diff->setText(str_diff);

    data_convert.b[0]=rec_data[40];
    data_convert.b[1]=rec_data[41];
    data_convert.b[2]=rec_data[42];
    data_convert.b[3]=rec_data[43];
    rx_data.data.voltage[1]=data_convert.f;
    data_convert.b[0]=rec_data[44];
    data_convert.b[1]=rec_data[45];
    data_convert.b[2]=rec_data[46];
    data_convert.b[3]=rec_data[47];
    rx_data.data.odom[0]=data_convert.f * 1000;
    data_convert.b[0]=rec_data[48];
    data_convert.b[1]=rec_data[49];
    data_convert.b[2]=rec_data[50];
    data_convert.b[3]=rec_data[51];
    rx_data.data.odom[1]=data_convert.f * 1000;

    char str6[6];
    sprintf(str6,"%4.2f",rx_data.data.voltage[1]);
    ui->show_cap_voltage->setText(str6);
    char str7[6];
    sprintf(str7,"%4.2f",rx_data.data.odom[0]);
    ui->show_odomx->setText(str7);
    char str8[6];
    sprintf(str8,"%4.2f",rx_data.data.odom[1]);
    ui->show_odomy->setText(str8);
    ring_counter_callback=rec_data[3];

    data_convert.b[0]=rec_data[52];
    data_convert.b[1]=rec_data[53];
    data_convert.b[2]=rec_data[54];
    data_convert.b[3]=rec_data[55];
    rx_data.data.odom_speed[0]=data_convert.f;
    data_convert.b[0]=rec_data[56];
    data_convert.b[1]=rec_data[57];
    data_convert.b[2]=rec_data[58];
    data_convert.b[3]=rec_data[59];
    rx_data.data.odom_speed[1]=data_convert.f;

    char str9[6];
    sprintf(str9,"%4.2f",rx_data.data.odom_speed[0]);
    ui->show_speedx->setText(str9);
    char str10[6];
    sprintf(str10,"%4.2f",rx_data.data.odom_speed[1]);
    ui->show_speedy->setText(str10);

    char str[400];
    sprintf(str,"data_len=%d [0]=%3d [1]=%3d [2]=%3d [3]=%3d \n [4]=%x  [5]=%x  [6]=%x [7]=%x \n [8]=%x [9]=%x [10]=%x [11]=%x \n [12]=%x [13]=%x [14]=%x [15]=%x",
            len,rec_data[0],rec_data[1],rec_data[2],rec_data[3],rec_data [4],rec_data [5],rec_data [6],rec_data [7],rec_data [8],rec_data [9],rec_data [10]
            ,rec_data [11],rec_data [12],rec_data [13],rec_data [14],rec_data [15]);
    ui->data_from_robot->setText(str);



}

void Qt_Communication_Tester::on_startbotton_clicked()
{
    if(is_start==0){
        ui->log->append("start");
        ui->startbotton->setText(QString::fromLocal8Bit("stop"));
        is_start=1;
        thread_time.start();
        recUdpSocket = new QUdpSocket(this);
        recUdpSocket->bind(QHostAddress::AnyIPv4 ,50000+orionIP, QUdpSocket::ShareAddress);

        QString address_rec = "224.5.20." +  QString::number(orionIP);

        QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
        foreach (QNetworkInterface iface, list)
        recUdpSocket->joinMulticastGroup(QHostAddress(address_rec), iface);
        connect(recUdpSocket, &QUdpSocket::readyRead, this, &Qt_Communication_Tester::readPendingDatagrams);
    }
    else{
        ui->log->append("stop");
        ui->startbotton->setText(QString::fromLocal8Bit("start"));
        is_start=0;

        thread_time.quit();
        recUdpSocket->close();

    }
}


void Qt_Communication_Tester::on_setIP_textChanged(const QString &arg1)
{
    orionIP = arg1.toInt();
    char str[100];
    sprintf(str,"set to IP address to 192.168.20.%d",orionIP);
    ui->log->append(str);
    if(is_start==1){
        on_startbotton_clicked();
    }
}

void Qt_Communication_Tester::on_kick_power_valueChanged(int value)
{
    char str[5];
    sprintf(str,"%d",value*5);
    ui->show_kick_power->setText(str);
}

void Qt_Communication_Tester::on_dribble_power_valueChanged(int value)
{
    char str[5];
    sprintf(str,"%d",value*5);
    ui->show_dribble_power->setText(str);
}




void Qt_Communication_Tester::on_target_theta_valueChanged(int value)
{

    char str[5];
    sprintf(str,"%d",(value-180)*(-1));
    ui->show_target_theta->setText(str);
}


void Qt_Communication_Tester::on_vx_valueChanged(int value)
{
    char str[5];
    sprintf(str,"%.3f",(float)value/100.0);
    ui->show_vx->setText(str);
}


void Qt_Communication_Tester::on_vy_valueChanged(int value)
{
    char str[5];
    sprintf(str,"%.3f",(float)value/100.0);
    ui->show_vy->setText(str);

}


bool Qt_Communication_Tester::eventFilter(QObject *, QEvent *event)
{
    bool bRtn = false;

    if(event->type() ==  QEvent::WindowDeactivate){
        ai_cmd.local_target_speed[0]=0.0;
        ai_cmd.local_target_speed[1]=0.0;
    }
    else{
        if (event->type() == QEvent::KeyPress) {
            bRtn = eventKeyPress(static_cast<QKeyEvent *>(event));
        }
        else if (event->type() == QEvent::KeyRelease) {
            bRtn = eventKeyRelease(static_cast<QKeyEvent *>(event));
        }
    }

    return bRtn;
}

float two_to_float(uint8_t data[2]) { return (float)((data[0] << 8 | data[1]) - 32767.0) / 32767.0; }

void Qt_Communication_Tester::on_reset_theta_clicked()
{
    ai_cmd.target_theta=0;
    ui->target_theta->setValue(180);

}

