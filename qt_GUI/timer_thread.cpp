#include "timer_thread.h"
#include <stdio.h>

Timer_thread::Timer_thread(QObject *parent) :
    QThread(parent)
{
}

void Timer_thread::run(){
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection );
    timer.setInterval(100);
    timer.start();
    exec();
    timer.stop();
}

void Timer_thread::timerHit(){
    static int timer_count;
    emit data_update( timer_count++ );     //emit signal       シ グナル data_update( int )を発生させる．
}
