#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QDataStream>
#include <QNetworkDatagram>
#include <QNetworkInterface>
#include "timer_thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void timer_callback( int timer_count);

    void on_startbuttom_clicked();

    void on_IP0_stateChanged(int arg1);

    void on_IP9_stateChanged(int arg1);

    void on_IP1_stateChanged(int arg1);

    void on_IP2_stateChanged(int arg1);

    void on_IP3_stateChanged(int arg1);

    void on_IP4_stateChanged(int arg1);

    void on_IP5_stateChanged(int arg1);

    void on_IP6_stateChanged(int arg1);

    void on_IP7_stateChanged(int arg1);

    void on_IP8_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Timer_thread timer_thread;
    QUdpSocket *recUdpSocket0;
    QUdpSocket *recUdpSocket1;
    QUdpSocket *recUdpSocket2;
    QUdpSocket *recUdpSocket3;
    QUdpSocket *recUdpSocket4;
    QUdpSocket *recUdpSocket5;
    QUdpSocket *recUdpSocket6;
    QUdpSocket *recUdpSocket7;
    QUdpSocket *recUdpSocket8;
    QUdpSocket *recUdpSocket9;
    void readPendingDatagrams_IP0();
    void readMsg_IP0(QNetworkDatagram datagram);
    void readPendingDatagrams_IP1();
    void readMsg_IP1(QNetworkDatagram datagram);
    void readPendingDatagrams_IP2();
    void readMsg_IP2(QNetworkDatagram datagram);
    void readPendingDatagrams_IP3();
    void readMsg_IP3(QNetworkDatagram datagram);
    void readPendingDatagrams_IP4();
    void readMsg_IP4(QNetworkDatagram datagram);
    void readPendingDatagrams_IP5();
    void readMsg_IP5(QNetworkDatagram datagram);
    void readPendingDatagrams_IP6();
    void readMsg_IP6(QNetworkDatagram datagram);
    void readPendingDatagrams_IP7();
    void readMsg_IP7(QNetworkDatagram datagram);
    void readPendingDatagrams_IP8();
    void readMsg_IP8(QNetworkDatagram datagram);
    void readPendingDatagrams_IP9();
    void readMsg_IP9(QNetworkDatagram datagram);
    uint8_t IP0_EN,IP1_EN,IP2_EN,IP3_EN,IP4_EN,IP5_EN,IP6_EN,IP7_EN,IP8_EN,IP9_EN;
    uint8_t IP0_temp,IP1_temp,IP2_temp,IP3_temp,IP4_temp,IP5_temp,IP6_temp,IP7_temp,IP8_temp,IP9_temp;
    uint8_t IP0_temp1,IP1_temp1,IP2_temp1,IP3_temp1,IP4_temp1,IP5_temp1,IP6_temp1,IP7_temp1,IP8_temp1,IP9_temp1;
};
#endif // MAINWINDOW_H
