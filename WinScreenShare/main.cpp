#include "socketnetwork.h"

#include <QApplication>

#include <QFile>
#include <stdio.h>
#include <stdlib.h>
#include <QtMsgHandler>
#include <QTextStream>
#include <QDateTime>
#include <QTextBlock>
#include <QMutex>
static QMutex mutex;

#include <QDir>
#include <QDebug>

#define LOGFILENAME "D:\\HHShare.log"


void customerMessageHandle(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //Q_UNUSED(context)
    QDateTime _datatime = QDateTime::currentDateTime();
    QString szDate = _datatime.toString("yyyy-MM-dd hh:mm:ss ddd");
    QString txtMessage(szDate);

    switch (type)
    {
        case QtInfoMsg:
            txtMessage += QString("[Info]");
            break;
        case QtDebugMsg:
            txtMessage += QString("[Debug]");
            break;
        case QtWarningMsg:
            txtMessage += QString("[Warning]");
           break;
        case QtCriticalMsg:
            txtMessage += QString("[Critical]");
            break;
        case QtFatalMsg:
            txtMessage += QString("[Fatal]");
            //abort();
            break;
        default:
            txtMessage += QString("[Trace]");
            //abort();
            break;
    }

    txtMessage.append(QString("%1").arg(context.file));
    txtMessage.append(QString("<%1>").arg(context.line));
    txtMessage.append(msg);


    mutex.lock();
    QFile outFile("D:\\"+_datatime.toString("yyyyMMdd")+".log");
    //QFile outFile(LOGFILENAME);

    outFile.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream textStream(&outFile);
    textStream << txtMessage  << endl;
    outFile.flush();
    outFile.close();
    mutex.unlock();
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qInstallMessageHandler(customerMessageHandle);

    qInfo("WinScreenShare");
    //qDebug("This is a debug message");
    //qWarning("This is a warning message");
    //qCritical("This is a critical message");
    //qFatal("This is a fatal message");

    //PlusWindow w;
    //w.show();
   auto core = new SocketNetwork;

   Q_UNUSED(core)

    return a.exec();
}
