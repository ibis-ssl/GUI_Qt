#ifndef TIMER_THREAD_H
#define TIMER_THREAD_H

#include <QThread>
#include <QTimer>

class Timer_thread : public QThread
{
    Q_OBJECT
public:
    explicit Timer_thread(QObject *parent = 0);
    void run();

    signals:
        void data_update(int timer_count);

    public slots:

    private slots:
        void timerHit();
};

#endif // TIMER_THREAD_H
