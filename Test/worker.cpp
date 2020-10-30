#include "worker.h"

Worker::Worker(QObject *parent):QObject(parent)
{
    qDebug() << "Worker";
}

Worker::~Worker()
{
    qDebug() << "~Worker()";
}

void Worker::slot_dowork()
{
    int count = 10;
    while(count--){
        QThread::msleep(1000);
        qDebug() << "do work: "<< count << " thread id =" << QThread::currentThreadId();
    }
    emit sig_finish();
}

