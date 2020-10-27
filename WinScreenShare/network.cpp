#include "network.h"

#include "eshare.h"

#include <QNetworkInterface>
#include <QHostAddress>
#include <QJsonArray>
#include <QDebug>

#include <QThread>
#include <QProcess>

Network::Network(QObject *parent)
    : QObject(parent),
    tcpSocket(new QTcpSocket(this)),
    plusWindow(new PlusWindow()),
    eshare(new Eshare())
{
    plusWindow->show(); 

    connectToSocket(QHostAddress(QHostAddress::LocalHost).toString(),11451);
    //connectToSocket(GetHostIpAddress(),11451);
    //connectToSocket(QString("192.168.31.109"),11451);

    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(onSocketReadyRead()));

    connect(this, SIGNAL(received_socketdata(QByteArray)), plusWindow, SLOT(Show_Receivedata(QByteArray)));

    qDebug() << "[HHTINFO] Client Started";

    InitCommandList();
}

Network::~Network()
{
    delete plusWindow;
    qDebug() << "[HHTINFO] Stop the client";
}


void Network::connectToSocket(QString ip, qint16 port)
{
    tcpSocket->connectToHost(QHostAddress(ip), port);
    if (tcpSocket->waitForConnected())
        qDebug() << "[HHTINFO] Connect to server IP:" << ip << "port:"<< port;
}

void Network::connected()
{
     qDebug() << "[HHTINFO] LocalHost connected";
     plusWindow->UpdateStatus("LocalHost Conneced");

     //send("{\"SetDevPattern\":1}"); //only for test
}

void Network::disconnectFromSocket()
{
    qDebug() << "[HHTINFO] disconnectFromSocket";
    tcpSocket->waitForBytesWritten();
}

void Network::send(QString string)
{
    qInfo() << "send string:" << string;

    if(tcpSocket->state() != QTcpSocket::ConnectedState)
    {
        qInfo() << "Not ConnectedState, send failed:" << string;
    }
    tcpSocket->write(string.toUtf8().data());

    tcpSocket->flush();


    /*
    QJsonDocument doc;
    QJsonArray array;

    array.append(QJsonValue(string));
    doc.setArray(array);
    send(doc);
    */
}

void Network::send(QJsonDocument doc)
{
    //tcpSocket->write(doc.toJson(QJsonDocument::Indented));
    //tcpSocket->write(doc.toJson(QJsonDocument::Compact));

    send(QString(doc.toJson(QJsonDocument::Compact)));
}

void Network::onSocketReadyRead()
{
     qDebug() << "[HHTINFO] ReadyRead";
     QByteArray array = tcpSocket->readAll();
     if(!array.isEmpty()){
        //plusWindow->UpdateStatus("PIN:"+array.trimmed().mid(31,3)+array.trimmed().mid(35,3));
        // plusWindow->UpdateStatus(array);
        //qDebug() << "[HHTINFO] emit";
         emit received_socketdata(array);
         ReceivedDataHandle(array);
     }
}

void Network::disconnected()
{
    tcpSocket->disconnectFromHost();
}

void Network::ReceivedDataHandle(QByteArray array)
{
   eshare->DataHandle(array);
}

void Network::InitCommandList()
{
    qDebug() << "[HHTINFO] InitCommandList";
    send(eshare->SetDevPattern(1));
    //QThread::msleep(1);
    send(eshare->GetDeviceList());


    //send(eshare->GetDeviceList());
    //send(eshare->GetClientList());

    //send(eshare->SetLicense(QString("YOUNEEDKEY")));
    send(eshare->CheckLicense());
    //0 is ng,same as other client; 1 2 mode is OK
    //send(eshare->SetDevPattern(1));
    //send(eshare->SetSettingVisibility(1));
    //send(eshare->SetMainControlVisibility(1));
    //send(eshare->SetFloatingBallVisibility(1));
}

QString Network::GetHostIpAddress()
{
    QString strIpAddress;
    QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses();
    int nListSize = ipAddressList.size();
    //get first IPv4 address
    for(int i =0; i < nListSize; ++i)
    {
        if( ipAddressList.at(i) != QHostAddress::LocalHost &&
                ipAddressList.at(i).toIPv4Address())
        {
            strIpAddress = ipAddressList.at(i).toString();
            if(strIpAddress.startsWith("192"))
                break;
        }
    }

    if( strIpAddress.isEmpty())
    {
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }
    qDebug() << "GetHostIpAddress" << strIpAddress;
    return strIpAddress;
}











