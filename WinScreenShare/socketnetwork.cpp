#include "socketnetwork.h"
#include "esharecommand.h"

#include <QDebug>
#include <QHostAddress>
#include <QJsonArray>


SocketNetwork::SocketNetwork(QObject *parent)
    : QObject(parent),
    tcpSocket(new QTcpSocket(this)),
    plusWindow(new PlusWindow())
{
    plusWindow->show();

    connectToSocket("127.0.0.1",11451);

    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(onSocketReadyRead()));

    qDebug() << "[HHTINFO] Client Started";
}

SocketNetwork::~SocketNetwork()
{
    delete plusWindow;
    qDebug() << "[HHTINFO] Stop the client";
}


void SocketNetwork::connectToSocket(QString ip, qint16 port)
{
    tcpSocket->connectToHost(QHostAddress(ip), port);
}

void SocketNetwork::connected()
{
     qDebug() << "[HHTINFO] connected";

     plusWindow->UpdateStatus("LocalHost Conneced Successed");

     send(SetDevPattern);

}

void SocketNetwork::disconnect()
{
    qDebug() << "[HHTINFO] Disconnected";
}

void SocketNetwork::send(QString string)
{
    tcpSocket->write(string.toUtf8().data());

    /*
    QJsonDocument doc;
    QJsonArray array;

    array.append(QJsonValue(string));
    doc.setArray(array);
    send(doc);
    */
}

void SocketNetwork::send(QJsonDocument doc)
{
    tcpSocket->write(doc.toJson());
}

void SocketNetwork::onSocketReadyRead()
{
     qDebug() << "[HHTINFO] ReadyRead";
     QByteArray array = tcpSocket->readAll();
     if(!array.isEmpty())
        plusWindow->UpdateStatus("PIN:"+array.trimmed().mid(31,3)+array.trimmed().mid(35,3));
}

void SocketNetwork::disconnected()
{
    tcpSocket->disconnectFromHost();
}




