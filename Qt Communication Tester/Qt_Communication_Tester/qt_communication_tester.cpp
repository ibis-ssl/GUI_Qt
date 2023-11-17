#include "qt_communication_tester.h"
#include "ui_qt_communication_tester.h"

ai_cmd_t ai_cmd;

Qt_Communication_Tester::Qt_Communication_Tester(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_Communication_Tester)
{
    ui->setupUi(this);
    QObject::connect(&thread_time, SIGNAL(data_update(int)),this, SLOT(timer_callback(int)) );
    is_start=0;
    ai_cmd.allow_local_flags=0;
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
    ui->setdata->setText(str);

    QByteArray send_packet;
    send_packet.resize(32);

    send_packet[0] = static_cast<uint8_t>(time_counter);


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
    ai_cmd.allow_local_flags=0;
}


void Qt_Communication_Tester::on_localEN_stateChanged(int arg1)
{
    ai_cmd.allow_local_flags |= (arg1 << 2);
}


void Qt_Communication_Tester::on_keeperEN_stateChanged(int arg1)
{
    if(ai_cmd.allow_local_flags)
    ai_cmd.allow_local_flags |=  (arg1 << 4);
}


void Qt_Communication_Tester::on_chipEN_stateChanged(int arg1)
{
    ai_cmd.chip_en= arg1;
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

}


void Qt_Communication_Tester::on_dribble_EN_stateChanged(int arg1)
{

}



void Qt_Communication_Tester::on_drible_power_valueChanged(int value)
{

}


void Qt_Communication_Tester::on_kick_power_valueChanged(int value)
{

}

