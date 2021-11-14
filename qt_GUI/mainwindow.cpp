#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&timer_thread, SIGNAL(data_update(int)), this, SLOT(timer_callback(int)) );
    timer_thread.start();
    IP0_EN=0;
    IP1_EN=0;
    IP2_EN=0;
    IP3_EN=0;
    IP4_EN=0;
    IP5_EN=0;
    IP6_EN=0;
    IP7_EN=0;
    IP8_EN=0;
}

MainWindow::~MainWindow()
{
    timer_thread.quit();
    timer_thread.wait();
    delete ui;
}


void MainWindow::timer_callback(int timer_count){
    if(IP0_EN==1){
        if(IP0_temp==IP0_temp1){
            ui->connect0->setStyleSheet("color:rgb(255,0,0);");
            ui->connect0->setText("disconnect");}
        IP0_temp1=IP0_temp;
    }
    if(IP1_EN==1){
        if(IP1_temp==IP1_temp1){
            ui->connect1->setStyleSheet("color:rgb(255,0,0);");
            ui->connect1->setText("disconnect");}
        IP1_temp1=IP1_temp;
    }
    if(IP2_EN==1){
        if(IP2_temp==IP2_temp1){
            ui->connect2->setStyleSheet("color:rgb(255,0,0);");
            ui->connect2->setText("disconnect");}
        IP2_temp1=IP2_temp;
    }
}

void MainWindow::readPendingDatagrams_IP0()
{
    while (recUdpSocket0->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket0->receiveDatagram();
        readMsg_IP0(datagram);
    }
}
void MainWindow::readMsg_IP0(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP0_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP0_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP0_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP0_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP0_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP0_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP0_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP0_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP0_7->setText(QString::fromLocal8Bit(str8));

    ui->connect0->setStyleSheet("color:rgb(0,0,255);");
    ui->connect0->setText("connect");
}


void MainWindow::readPendingDatagrams_IP1()
{
    while (recUdpSocket1->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket1->receiveDatagram();
        readMsg_IP1(datagram);
    }
}
void MainWindow::readMsg_IP1(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP1_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP1_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP1_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP1_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP1_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP1_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP1_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP1_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP1_7->setText(QString::fromLocal8Bit(str8));
    ui->connect1->setStyleSheet("color:rgb(0,0,255);");
    ui->connect1->setText("connect");
}


void MainWindow::readPendingDatagrams_IP2()
{
    while (recUdpSocket2->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket2->receiveDatagram();
        readMsg_IP2(datagram);
    }
}
void MainWindow::readMsg_IP2(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP2_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP2_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP2_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP2_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP2_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP2_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP2_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP2_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP2_7->setText(QString::fromLocal8Bit(str8));
    ui->connect2->setStyleSheet("color:rgb(0,0,255);");
    ui->connect2->setText("connect");
}



void MainWindow::readPendingDatagrams_IP3()
{
    while (recUdpSocket3->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket3->receiveDatagram();
        readMsg_IP3(datagram);
    }
}
void MainWindow::readMsg_IP3(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP3_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP3_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP3_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP3_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP3_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP3_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP3_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP3_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP3_7->setText(QString::fromLocal8Bit(str8));
    ui->connect3->setStyleSheet("color:rgb(0,0,255);");
    ui->connect3->setText("connect");
}



void MainWindow::readPendingDatagrams_IP4()
{
    while (recUdpSocket4->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket4->receiveDatagram();
        readMsg_IP4(datagram);
    }
}
void MainWindow::readMsg_IP4(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP4_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP4_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP4_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP4_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP4_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP4_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP4_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP4_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP4_7->setText(QString::fromLocal8Bit(str8));
    ui->connect4->setStyleSheet("color:rgb(0,0,255);");
    ui->connect4->setText("connect");
}


void MainWindow::readPendingDatagrams_IP5()
{
    while (recUdpSocket5->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket5->receiveDatagram();
        readMsg_IP5(datagram);
    }
}
void MainWindow::readMsg_IP5(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP5_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP5_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP5_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP5_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP5_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP5_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP5_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP5_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP5_7->setText(QString::fromLocal8Bit(str8));
    ui->connect5->setStyleSheet("color:rgb(0,0,255);");
    ui->connect5->setText("connect");
}

void MainWindow::readPendingDatagrams_IP6()
{
    while (recUdpSocket6->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket6->receiveDatagram();
        readMsg_IP6(datagram);
    }
}
void MainWindow::readMsg_IP6(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP6_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP6_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP6_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP6_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP6_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP6_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP6_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP6_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP6_7->setText(QString::fromLocal8Bit(str8));
    ui->connect6->setStyleSheet("color:rgb(0,0,255);");
    ui->connect6->setText("connect");
}



void MainWindow::readPendingDatagrams_IP7()
{
    while (recUdpSocket7->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket7->receiveDatagram();
        readMsg_IP7(datagram);
    }
}
void MainWindow::readMsg_IP7(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP7_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP7_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP7_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP7_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP7_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP7_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP7_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP7_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP7_7->setText(QString::fromLocal8Bit(str8));
    ui->connect7->setStyleSheet("color:rgb(0,0,255);");
    ui->connect7->setText("connect");
}


void MainWindow::readPendingDatagrams_IP8()
{
    while (recUdpSocket8->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket8->receiveDatagram();
        readMsg_IP8(datagram);
    }
}
void MainWindow::readMsg_IP8(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP8_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP8_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP8_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP8_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP8_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP8_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP8_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP8_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP8_7->setText(QString::fromLocal8Bit(str8));
    ui->connect8->setStyleSheet("color:rgb(0,0,255);");
    ui->connect8->setText("connect");
}

void MainWindow::readPendingDatagrams_IP9()
{
    while (recUdpSocket9->hasPendingDatagrams()) {
        QNetworkDatagram datagram = recUdpSocket9->receiveDatagram();
        readMsg_IP9(datagram);
    }
}
void MainWindow::readMsg_IP9(QNetworkDatagram datagram)
{
    QByteArray data = datagram.data();
    uint8_t data_temp;
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[10];
    char str6[10];
    char str7[10];
    char str8[10];
    data_temp=data.data()[11];
    IP9_temp=data_temp;
    sprintf(str1,"%d",data_temp);
    ui->IP9_0->setText(QString::fromLocal8Bit(str1));
    data_temp=data.data()[12];
    sprintf(str2,"%d",data_temp);
    ui->IP9_1->setText(QString::fromLocal8Bit(str2));
    data_temp=data.data()[13];
    sprintf(str3,"%d",data_temp);
    ui->IP9_2->setText(QString::fromLocal8Bit(str3));
    data_temp=data.data()[14];
    sprintf(str4,"%d",data_temp);
    ui->IP9_3->setText(QString::fromLocal8Bit(str4));
    data_temp=data.data()[15];
    sprintf(str5,"%d",data_temp);
    ui->IP9_4->setText(QString::fromLocal8Bit(str5));
    data_temp=data.data()[13];
    sprintf(str6,"%d",data_temp);
    ui->IP9_5->setText(QString::fromLocal8Bit(str6));
    data_temp=data.data()[14];
    sprintf(str7,"%d",data_temp);
    ui->IP9_6->setText(QString::fromLocal8Bit(str7));
    data_temp=data.data()[15];
    sprintf(str8,"%d",data_temp);
    ui->IP9_7->setText(QString::fromLocal8Bit(str8));
    ui->connect9->setStyleSheet("color:rgb(0,0,255);");
    ui->connect9->setText("connect");
}





void MainWindow::on_startbuttom_clicked()
{
    static int flag_run=0;

    if(flag_run==0){
        flag_run = 1;
        ui->startbuttom->setText(QString::fromLocal8Bit("Stop"));
    }
    else{
        flag_run = 0;
        ui->startbuttom->setText(QString::fromLocal8Bit("Start"));
    }
}


void MainWindow::on_IP0_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP0_EN=1;
        recUdpSocket0 = new QUdpSocket(this);
        recUdpSocket0->bind(QHostAddress::AnyIPv4 ,50100);
        recUdpSocket0->joinMulticastGroup(QHostAddress("224.5.20.100"));
        connect(recUdpSocket0, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP0);
        ui->connect0->setStyleSheet("color:rgb(255,0,0);");
        ui->connect0->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP0_EN=0;
            recUdpSocket0->close();
            ui->connect0->setStyleSheet("color:rgb(0,0,0);");
            ui->connect0->setText("not connect");
        }
    }

}


void MainWindow::on_IP1_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP1_EN=1;
        recUdpSocket1 = new QUdpSocket(this);
        recUdpSocket1->bind(QHostAddress::AnyIPv4 ,50101);
        recUdpSocket1->joinMulticastGroup(QHostAddress("224.5.20.101"));
        connect(recUdpSocket1, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP1);
        ui->connect1->setStyleSheet("color:rgb(255,0,0);");
        ui->connect1->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP1_EN=0;
            recUdpSocket1->close();
            ui->connect1->setStyleSheet("color:rgb(0,0,0);");
            ui->connect1->setText("not connect");
        }
    }


}

void MainWindow::on_IP2_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP2_EN=1;
        recUdpSocket2 = new QUdpSocket(this);
        recUdpSocket2->bind(QHostAddress::AnyIPv4 ,50102);
        recUdpSocket2->joinMulticastGroup(QHostAddress("224.5.20.102"));
        connect(recUdpSocket2, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP2);
        ui->connect2->setStyleSheet("color:rgb(255,0,0);");
        ui->connect2->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP2_EN=0;
            recUdpSocket2->close();
            ui->connect2->setStyleSheet("color:rgb(0,0,0);");
            ui->connect2->setText("not connect");
        }
    }
}

void MainWindow::on_IP3_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP3_EN=1;
        recUdpSocket3 = new QUdpSocket(this);
        recUdpSocket3->bind(QHostAddress::AnyIPv4 ,50103);
        recUdpSocket3->joinMulticastGroup(QHostAddress("224.5.20.103"));
        connect(recUdpSocket3, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP3);
        ui->connect3->setStyleSheet("color:rgb(255,0,0);");
        ui->connect3->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP3_EN=0;
            recUdpSocket3->close();
            ui->connect3->setStyleSheet("color:rgb(0,0,0);");
            ui->connect3->setText("not connect");
        }
    }
}

void MainWindow::on_IP4_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP4_EN=1;
        recUdpSocket4 = new QUdpSocket(this);
        recUdpSocket4->bind(QHostAddress::AnyIPv4 ,50104);
        recUdpSocket4->joinMulticastGroup(QHostAddress("224.5.20.104"));
        connect(recUdpSocket4, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP4);
        ui->connect4->setStyleSheet("color:rgb(255,0,0);");
        ui->connect4->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP4_EN=0;
            recUdpSocket4->close();
            ui->connect4->setStyleSheet("color:rgb(0,0,0);");
            ui->connect4->setText("not connect");
        }
    }
}

void MainWindow::on_IP5_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP5_EN=1;
        recUdpSocket5 = new QUdpSocket(this);
        recUdpSocket5->bind(QHostAddress::AnyIPv4 ,50105);
        recUdpSocket5->joinMulticastGroup(QHostAddress("224.5.20.105"));
        connect(recUdpSocket5, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP5);
        ui->connect5->setStyleSheet("color:rgb(255,0,0);");
        ui->connect5->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP5_EN=0;
            recUdpSocket5->close();
            ui->connect5->setStyleSheet("color:rgb(0,0,0);");
            ui->connect5->setText("not connect");
        }
    }
}

void MainWindow::on_IP6_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP6_EN=1;
        recUdpSocket6 = new QUdpSocket(this);
        recUdpSocket6->bind(QHostAddress::AnyIPv4 ,50106);
        recUdpSocket6->joinMulticastGroup(QHostAddress("224.5.20.106"));
        connect(recUdpSocket6, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP6);
        ui->connect6->setStyleSheet("color:rgb(255,0,0);");
        ui->connect6->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP6_EN=0;
            recUdpSocket6->close();
            ui->connect6->setStyleSheet("color:rgb(0,0,0);");
            ui->connect6->setText("not connect");
        }
    }
}

void MainWindow::on_IP7_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP7_EN=1;
        recUdpSocket7 = new QUdpSocket(this);
        recUdpSocket7->bind(QHostAddress::AnyIPv4 ,50107);
        recUdpSocket7->joinMulticastGroup(QHostAddress("224.5.20.107"));
        connect(recUdpSocket7, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP7);
        ui->connect7->setStyleSheet("color:rgb(255,0,0);");
        ui->connect7->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP7_EN=0;
            recUdpSocket7->close();
            ui->connect7->setStyleSheet("color:rgb(0,0,0);");
            ui->connect7->setText("not connect");
        }
    }
}

void MainWindow::on_IP8_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP8_EN=1;
        recUdpSocket8 = new QUdpSocket(this);
        recUdpSocket8->bind(QHostAddress::AnyIPv4 ,50103);
        recUdpSocket8->joinMulticastGroup(QHostAddress("224.5.20.108"));
        connect(recUdpSocket8, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP8);
        ui->connect8->setStyleSheet("color:rgb(255,0,0);");
        ui->connect8->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP8_EN=0;
            recUdpSocket8->close();
            ui->connect8->setStyleSheet("color:rgb(0,0,0);");
            ui->connect8->setText("not connect");
        }
    }
}

void MainWindow::on_IP9_stateChanged(int arg1)
{
    static int flag_on=0;
    if(arg1==2){
        flag_on = 1;
        IP9_EN=1;
        recUdpSocket9 = new QUdpSocket(this);
        recUdpSocket9->bind(QHostAddress::AnyIPv4 ,50109);
        recUdpSocket9->joinMulticastGroup(QHostAddress("224.5.20.109"));
        connect(recUdpSocket9, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams_IP9);
        ui->connect9->setStyleSheet("color:rgb(255,0,0);");
        ui->connect9->setText("disconnect");
    }
    else{
        if(flag_on == 1){
            flag_on = 0;
            IP3_EN=0;
            recUdpSocket9->close();
            ui->connect9->setStyleSheet("color:rgb(0,0,0);");
            ui->connect9->setText("not connect");
        }
    }
}
