#include "thread_time.h"

Thread_time::Thread_time(QObject *parent):
    QThread(parent)
{
}

void Thread_time::run(){
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    timer.setInterval(15);
    timer.start();
    exec();
    timer.stop();
}

void Thread_time::timerHit(){
    emit data_update(time_counter);
    time_counter = (time_counter + 1) % TIME_COUNTER_PERIOD;
}
