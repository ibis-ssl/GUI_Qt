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

    ui->connect1->setStyleSheet("color:rgb(0,0,255);");
    ui->connect1->setText("connect");
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

}

void MainWindow::on_IP3_stateChanged(int arg1)
{

}

void MainWindow::on_IP4_stateChanged(int arg1)
{

}

void MainWindow::on_IP5_stateChanged(int arg1)
{

}

void MainWindow::on_IP6_stateChanged(int arg1)
{

}

void MainWindow::on_IP7_stateChanged(int arg1)
{

}

void MainWindow::on_IP8_stateChanged(int arg1)
{

}

void MainWindow::on_IP9_stateChanged(int arg1)
{

}
