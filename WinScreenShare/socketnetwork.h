#ifndef SOCKETNETWORK_H
#define SOCKETNETWORK_H

#include "pluswindow.h"

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QTextStream>



class SocketNetwork : QObject
{
    Q_OBJECT
public:
    explicit SocketNetwork(QObject *parent = 0 );
    virtual ~SocketNetwork(void);

public slots:
    void connectToSocket(QString ip, qint16 port);
    void disconnect();
    void send(QString string);
    void send(QJsonDocument doc);
    void onSocketReadyRead();


private slots:
    void connected(void);
    void disconnected(void);

private:
    QTcpSocket *tcpSocket;
    PlusWindow *plusWindow;
};

#endif // SOCKETNETWORK_H
