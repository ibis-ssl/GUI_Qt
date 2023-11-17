#ifndef THREAD_TIME_H
#define THREAD_TIME_H

#include <QThread>
#include <QObject>
#include <QTimer>

class Thread_time : public QThread
{
    Q_OBJECT
public:
    explicit Thread_time(QObject *parent = nullptr);
    void run();

signals:
    void data_update(int time_counter);

public slots:

private slots:
    void timerHit();
};

#endif // THREAD_TIME_H
