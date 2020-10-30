#ifndef WORKER_H
#define WORKER_H

#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QString>
#include <QObject>

class Worker :public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent=0);
    ~Worker();

signals:
    void sig_finish();

public slots:
    void slot_dowork();
};

#endif // WORKER_H
