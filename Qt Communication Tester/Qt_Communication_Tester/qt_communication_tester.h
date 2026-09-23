#ifndef QT_COMMUNICATION_TESTER_H
#define QT_COMMUNICATION_TESTER_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QKeyEvent>
#include "thread_time.h"

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
    void timer_callback(int time_counter);

private slots:
    void on_startbotton_clicked();
    void on_setIP_textChanged(const QString &arg1);
    void on_kick_power_valueChanged(int value);
    void on_dribble_power_valueChanged(int value);
    void on_target_theta_valueChanged(int value);
    void on_vx_valueChanged(int value);
    void on_vy_valueChanged(int value);
    void on_reset_theta_clicked();
    void on_AR_valueChanged(int value);

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    bool eventKeyPress(QKeyEvent *event);
    bool eventKeyRelease(QKeyEvent *event);
    void start_communication();
    void stop_communication();
    void readPendingDatagrams();
    void readMsg(const QNetworkDatagram &datagram);

    Ui::Qt_Communication_Tester *ui;
    Thread_time thread_time;
    QUdpSocket *sendUdpSocket;  // 送信
    QUdpSocket *recUdpSocket;   // 受信

    int  orionIP;               // ロボットのIP下位 (192.168.20.xxx)
    bool is_running;
    int  last_sent_counter;     // 最後に送信したチェックカウンタ

    // ロボットへの指令値
    float target_theta;         // [rad]
    float kick_power;
    float dribble_power;
    float target_speed[2];      // [0]=前後, [1]=左右 [m/s]
};

#endif // QT_COMMUNICATION_TESTER_H
