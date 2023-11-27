#ifndef QT_COMMUNICATION_TESTER_H
#define QT_COMMUNICATION_TESTER_H

#include <QMainWindow>
#include <QThread>
#include "thread_time.h"
#include <stdio.h>
#include <QGraphicsScene>
#include <QUdpSocket>
#include <QDataStream>
#include <QNetworkDatagram>
#include <QHostAddress>
#include <QDebug>
#include "math.h"
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>
#include <QtGlobal>
#include <QNetworkInterface>

QT_BEGIN_NAMESPACE
namespace Ui { class Qt_Communication_Tester; }
QT_END_NAMESPACE

class Qt_Communication_Tester : public QMainWindow
{
    Q_OBJECT

public:
    Qt_Communication_Tester(QWidget *parent = nullptr);
    ~Qt_Communication_Tester();


public slots:
    void timer_callback( int time_counter);

private slots:
    void on_startbotton_clicked();

    void on_setIP_textChanged(const QString &arg1);

    void on_kick_power_valueChanged(int value);

    void on_dribble_power_valueChanged(int value);

    void on_keeperEN_stateChanged(int arg1);

    void on_localEN_stateChanged(int arg1);

    void on_target_theta_valueChanged(int value);

    void on_vx_valueChanged(int value);

    void on_vy_valueChanged(int value);

    void on_reset_theta_clicked();

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    bool eventKeyPress(QKeyEvent *event);
    bool eventKeyRelease(QKeyEvent *event);

private:
    Ui::Qt_Communication_Tester *ui;
    int orionIP,is_start;
    Thread_time thread_time;
    QUdpSocket *sendUdpSocket;  // 送信
    QUdpSocket *recUdpSocket;   // 受信
    QElapsedTimer timer;
    qint64 nanoSec;
    void readPendingDatagrams();
    void readMsg(QNetworkDatagram datagram);
    uint8_t send_packet[32];

    float two_to_float(uint8_t data[2]);
    float two_to_int(uint8_t data[2]);

    uint8_t ring_counter, ring_counter_callback;
};


class ai_cmd_t
{
    public:
        float target_theta, global_vision_theta;
        float drible_power;
        float kick_power;
        uint8_t chip_en;
        float local_target_speed[2];
        int global_robot_position[2];
        int global_global_target_positio_n__[2];
        int global_ball_position[2];
        uint8_t allow_local_flags;
        int ball_local_x, ball_local_y, ball_local_radius, ball_local_FPS;
};

#endif // QT_COMMUNICATION_TESTER_H
