#include "qt_communication_tester.h"
#include "ui_qt_communication_tester.h"

ai_cmd_t ai_cmd;
int kick_EN=0;
int dribble_EN=0;

Qt_Communication_Tester::Qt_Communication_Tester(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_Communication_Tester)
{
    ui->setupUi(this);
    QObject::connect(&thread_time, SIGNAL(data_update(int)),this, SLOT(timer_callback(int)) );
    is_start=0;
    ai_cmd.allow_local_flags=0;

    installEventFilter(this);


    char str[5];
    sprintf(str,"%d",0);
    ui->show_dribble_power->setText(str);
    ui->show_kick_power->setText(str);
    ui->show_target_theta->setText("0");
    ui->show_vx->setText("0.300");
    ui->show_vy->setText("0.300");

}

Qt_Communication_Tester::~Qt_Communication_Tester()
{

    thread_time.quit();
    thread_time.wait();
    delete ui;
}


void Qt_Communication_Tester::timer_callback(int time_counter){


    auto to_two_byte = [](float val, float range) -> std::pair<uint8_t, uint8_t> {
        uint16_t two_byte = static_cast<int>(32767 * static_cast<float>(val / range) + 32767);
        uint8_t byte_low, byte_high;
        byte_low = two_byte & 0x00FF;
        byte_high = (two_byte & 0xFF00) >> 8;
        return std::make_pair(byte_low, byte_high);
    };


    //kick value
    if(ui->chipEN->isChecked()>0){
        ai_cmd.chip_en= 1;
    }
    else{
        ai_cmd.chip_en= 0;
    }

    if(ui->kick_EN->isChecked()>0){
        if(ai_cmd.chip_en==1){
            ai_cmd.kick_power= 100+ui->kick_power->value();
        }
        else{
            ai_cmd.kick_power= ui->kick_power->value();
        }
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


    ai_cmd.target_theta=(float)(ui->target_theta->value()-180.0)*M_PI/180.0;

    // -pi ~ pi -> 0 ~ 32767 ~ 65534
    auto [target_theta_low, target_theta_high] = to_two_byte(ai_cmd.target_theta, M_PI);
    auto [vel_surge_low, vel_surge_high] = to_two_byte(ai_cmd.local_target_speed[0], 7.0);
    auto [vel_sway_low, vel_sway_high] = to_two_byte(ai_cmd.local_target_speed[1], 7.0);

    orionIP = ui->setIP->value();
    char str[100];
    sprintf(str,"ID=%d check=%3d Vx=%.3f Vy=%.3f theta=%.3f kick=%.2f chip=%d Dri=%.2f local_flags =%d",
            orionIP-100, time_counter,ai_cmd.local_target_speed[0],ai_cmd.local_target_speed[1],ai_cmd.target_theta,
            ai_cmd.kick_power,ai_cmd.chip_en,ai_cmd.drible_power,(uint8_t)ai_cmd.allow_local_flags);
    ui->setdata->setText(str);


    QByteArray send_packet;
    send_packet.resize(64);
    send_packet.fill(0,64);

    send_packet[0] = static_cast<uint8_t>(time_counter);
    send_packet[1] = static_cast<uint8_t>(vel_surge_high);
    send_packet[2] = static_cast<uint8_t>(vel_surge_low);
    send_packet[3] = static_cast<uint8_t>(vel_sway_high);
    send_packet[4] = static_cast<uint8_t>(vel_sway_low);
    //send_packet[5] = static_cast<uint8_t>(vision_theta_high);
    //send_packet[6] = static_cast<uint8_t>(vision_theta_low);
    send_packet[7] = static_cast<uint8_t>(target_theta_high);
    send_packet[8] = static_cast<uint8_t>(target_theta_low);
    send_packet[9] = static_cast<uint8_t>(ai_cmd.kick_power);
    send_packet[10] = static_cast<uint8_t>(ai_cmd.drible_power);
    send_packet[11] = static_cast<uint8_t>(ai_cmd.allow_local_flags);
    //send_packet[12] = static_cast<uint8_t>(ball_x_high);
    //send_packet[13] = static_cast<uint8_t>(ball_x_low);
    //send_packet[14] = static_cast<uint8_t>(ball_y_high);
    //send_packet[15] = static_cast<uint8_t>(ball_y_low);
    //send_packet[16] = static_cast<uint8_t>(vision_x_high);
    //send_packet[17] = static_cast<uint8_t>(vision_x_low);
    //send_packet[18] = static_cast<uint8_t>(vision_y_high);
    //send_packet[19] = static_cast<uint8_t>(vision_y_low);
    //send_packet[20] = static_cast<uint8_t>(target_x_high);
    //send_packet[21] = static_cast<uint8_t>(target_x_low);
    //send_packet[22] = static_cast<uint8_t>(target_y_high);
    //send_packet[23] = static_cast<uint8_t>(target_y_low);


    char str2[400];
    sprintf(str2,"ID=%3d [0]=%3d [1]=%3d [2]=%3d [3]=%3d [4]=%3d [5]=%3d [6]=%3d [7]=%3d [8]=%3d [9]=%3d [10]=%3d [11]=%3d [12]=%3d [13]=%3d [14]=%3d [15]=%3d [16]=%3d [17]=%3d [18]=%3d [19]=%3d [20]=%3d [21]=%3d [22]=%3d [23]=%3d",
            orionIP-100,(int)send_packet[0],(int)send_packet[1],(int)send_packet[2],(int)send_packet[3],(int)send_packet[4],(int)send_packet[5],(int)send_packet[6],(int)send_packet[7],(int)send_packet[8],(int)send_packet[9]
            ,(int)send_packet[10],(int)send_packet[11],(int)send_packet[12],(int)send_packet[13],(int)send_packet[14],(int)send_packet[15],(int)send_packet[16],(int)send_packet[17],(int)send_packet[18],(int)send_packet[19]
            ,(int)send_packet[20],(int)send_packet[21],(int)send_packet[22],(int)send_packet[23]);
    ui->sendingdata->setText(str2);
    QString address = "192.168.20." +  QString::number(orionIP);

    sendUdpSocket = new QUdpSocket(this);
    sendUdpSocket->bind(QHostAddress(address), 12345);
    sendUdpSocket->writeDatagram(send_packet,32,QHostAddress(address), 12345);
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
            ai_cmd.local_target_speed[1]=(float)(ui->vy->value())*(-1.0)/100.0;
            break;
        case Qt::Key_D:
            ai_cmd.local_target_speed[1]=(float)(ui->vy->value())/100.0;
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

    char str[400];
    sprintf(str,"data_len=%d [0]=%3d [1]=%3d [2]=%3d [3]=%3d [4]=%3d [5]=%3d [6]=%3d [7]=%3d [8]=%3d [9]=%3d [10]=%3d",
            len,data.data()[0],data.data()[1],data.data()[2],data.data()[3],data.data()[4],data.data()[5],data.data()[6],data.data()[7],data.data()[8],data.data()[9],data.data()[10]);
    ui->data_from_robot->setText(str);

    char str2[10];
    sprintf(str2,"=%d",((data.data()[2] << 8 | data.data()[1]) + 360));
    ui->show_robot_theta->setText(str2);
    char str3[10];
    sprintf(str3,"=%d",data.data()[7]);
    ui->show_robot_voltage->setText(str3);

    char str4[10];
    sprintf(str4,"=%d",data.data()[0]);
    ui->show_connection->setText(str4);

    char str5[10];
    sprintf(str5,"=%d",data.data()[6]);
    ui->show_kickstate->setText(str5);

}

void Qt_Communication_Tester::on_startbotton_clicked()
{
    if(is_start==0){
        ui->log->append("start");
        ui->startbotton->setText(QString::fromLocal8Bit("stop"));
        is_start=1;
        thread_time.start();
        recUdpSocket = new QUdpSocket(this);
        recUdpSocket->bind(QHostAddress::Any ,50000+orionIP);

        QString address = "224.5.20.100." +  QString::number(orionIP);
        recUdpSocket->joinMulticastGroup(QHostAddress(address));
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




void Qt_Communication_Tester::on_keeperEN_stateChanged(int arg1)
{
    if(arg1 > 0){
        ai_cmd.allow_local_flags |=  (0b00000010);
    }
    else{
        ai_cmd.allow_local_flags ^= (0b00000010);
    }

}


void Qt_Communication_Tester::on_localEN_stateChanged(int arg1)
{
    //loacl flags
    if(arg1 > 0){
        ai_cmd.allow_local_flags |= (0b00001000);
    }
    else{
        ai_cmd.allow_local_flags ^= (0b00001000);
    }


}


void Qt_Communication_Tester::on_target_theta_valueChanged(int value)
{

    char str[5];
    sprintf(str,"%d",value-180);
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

    if (event->type() == QEvent::KeyPress) {
        bRtn = eventKeyPress(static_cast<QKeyEvent *>(event));
    }
    else if (event->type() == QEvent::KeyRelease) {
        bRtn = eventKeyRelease(static_cast<QKeyEvent *>(event));
    }
    return bRtn;
}

float two_to_float(uint8_t data[2]) { return (float)((data[0] << 8 | data[1]) - 32767.0) / 32767.0; }

void Qt_Communication_Tester::on_reset_theta_clicked()
{
    ai_cmd.target_theta=0;
    ui->target_theta->setValue(180);

}

