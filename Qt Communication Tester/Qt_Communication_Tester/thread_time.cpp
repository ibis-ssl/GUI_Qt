#include "thread_time.h"
#include <stdio.h>

Thread_time::Thread_time(QObject *parent):
    QThread(parent)
{
}

void Thread_time::run(){
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection );
    timer.setInterval(20);
    timer.start();
    //printf("debug : Thread Starts\n");    fflush(stdout);
    exec();
    //printf("debug : Thread Stops\n");    fflush(stdout);
    timer.stop();
}

void Thread_time::timerHit(){
    //printf("timer hit\n");   fflush(stdout);
    static int time_counter;
    if(time_counter>200){time_counter=0;}
    emit data_update(time_counter++);
}

