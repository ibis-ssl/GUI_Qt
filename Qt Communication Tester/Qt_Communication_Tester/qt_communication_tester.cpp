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


    char str[5];
    sprintf(str,"%d",0);
    ui->show_dribble_power->setText(str);\
    ui->show_kick_power->setText(str);
}

Qt_Communication_Tester::~Qt_Communication_Tester()
{

    thread_time.quit();
    thread_time.wait();
    delete ui;
}


void Qt_Communication_Tester::timer_callback(int time_counter){
    orionIP = ui->setIP->value();
    char str[100];
    sprintf(str,"ID=%d check=%3d Vx=%.3f Vy=%.3f theta=%.3f kick=%.2f chip=%d Dri=%.2f local_flags =%d",
            orionIP-100, time_counter,ai_cmd.local_target_speed[0],ai_cmd.local_target_speed[1],ai_cmd.target_theta,
            ai_cmd.kick_power,ai_cmd.chip_en,ai_cmd.drible_power,(int)ai_cmd.allow_local_flags);
    ui->sendingdata->setText(str);

    QByteArray send_packet;
    send_packet.resize(64);

    send_packet[0] = static_cast<uint8_t>(time_counter);
    //send_packet[1] = static_cast<uint8_t>(vel_surge_high);
    //send_packet[2] = static_cast<uint8_t>(vel_surge_low);
    //send_packet[3] = static_cast<uint8_t>(vel_sway_high);
    //send_packet[4] = static_cast<uint8_t>(vel_sway_low);
    //send_packet[5] = static_cast<uint8_t>(vision_theta_high);
    //send_packet[6] = static_cast<uint8_t>(vision_theta_low);
    //send_packet[7] = static_cast<uint8_t>(target_theta_high);
    //send_packet[8] = static_cast<uint8_t>(target_theta_low);
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


    QString address = "192.168.20." +  QString::number(orionIP);

    sendUdpSocket = new QUdpSocket(this);
    sendUdpSocket->bind(QHostAddress(address), 12345);
    sendUdpSocket->writeDatagram(send_packet,32,QHostAddress(address), 12345);
    sendUdpSocket->close();

}


void Qt_Communication_Tester::readPendingDatagrams(){}

void Qt_Communication_Tester::readMsg(QNetworkDatagram datagram){}

void Qt_Communication_Tester::on_startbotton_clicked()
{
    if(is_start==0){
        ui->log->append("start");
        ui->startbotton->setText(QString::fromLocal8Bit("stop"));
        is_start=1;
        thread_time.start();
        recUdpSocket = new QUdpSocket(this);
        recUdpSocket->bind(QHostAddress::Any ,50000+orionIP);
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


void Qt_Communication_Tester::on_localEN_stateChanged(int arg1)
{
    if(arg1>0){
        ai_cmd.allow_local_flags |=  (0b00000010);
    }
    else{
        ai_cmd.allow_local_flags ^= (0b00000010);
    }
}


void Qt_Communication_Tester::on_keeperEN_stateChanged(int arg1)
{
    if(arg1>0){
        ai_cmd.allow_local_flags |= (0b00001000);
    }
    else{
        ai_cmd.allow_local_flags ^= (0b00001000);
    }
}


void Qt_Communication_Tester::on_chipEN_stateChanged(int arg1)
{
    if(arg1>0){
        ai_cmd.chip_en= 1;
    }
    else{
        ai_cmd.chip_en= 0;
    }
}


void Qt_Communication_Tester::on_setIP_textChanged(const QString &arg1)
{
    orionIP = ui->setIP->value();
    char str[100];
    sprintf(str,"set to IP address to 192.168.20.%d",orionIP);
    ui->log->append(str);
    if(is_start==1){
        on_startbotton_clicked();
    }
}

void Qt_Communication_Tester::on_kick_EN_stateChanged(int arg1)
{
    if(arg1>0){
        kick_EN=true;
    }
    else{
        kick_EN=false;
    }
}


void Qt_Communication_Tester::on_dribble_EN_stateChanged(int arg1)
{
    if(arg1>0){
        dribble_EN=true;
    }
    else{
        dribble_EN=false;
    }
}



void Qt_Communication_Tester::on_kick_power_valueChanged(int value)
{
    char str[5];
    sprintf(str,"%d",value*5);
    ui->show_kick_power->setText(str);

    if(kick_EN==1){
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
}

void Qt_Communication_Tester::on_dribble_power_valueChanged(int value)
{
    char str[5];
    sprintf(str,"%d",value*5);
    ui->show_dribble_power->setText(str);

    if(dribble_EN==1){
        ai_cmd.drible_power=ui->dribble_power->value();
    }
    else{
        ai_cmd.drible_power= 0;
    }
}



