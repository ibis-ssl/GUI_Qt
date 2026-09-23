#ifndef THREAD_TIME_H
#define THREAD_TIME_H

#include <QThread>
#include <QObject>
#include <QTimer>

// time_counter は 0 ～ TIME_COUNTER_PERIOD-1 を周回する
#define TIME_COUNTER_PERIOD 201

class Thread_time : public QThread
{
    Q_OBJECT
public:
    explicit Thread_time(QObject *parent = nullptr);
    void run();

signals:
    void data_update(int time_counter);

private slots:
    void timerHit();

private:
    int time_counter = 0;
};

#endif // THREAD_TIME_H
