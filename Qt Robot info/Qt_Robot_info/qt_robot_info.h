#ifndef QT_ROBOT_INFO_H
#define QT_ROBOT_INFO_H

#include <QMainWindow>
#include <QThread>
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
namespace Ui { class Qt_Robot_info; }
QT_END_NAMESPACE

class Qt_Robot_info : public QMainWindow
{
    Q_OBJECT

public:
    Qt_Robot_info(QWidget *parent = nullptr);
    ~Qt_Robot_info();

private slots:
    void on_startbotton_clicked();

    void on_setIP_textChanged(const QString &arg1);

private:
    Ui::Qt_Robot_info *ui;
    int orionIP,is_start;
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

#endif // QT_ROBOT_INFO_H
