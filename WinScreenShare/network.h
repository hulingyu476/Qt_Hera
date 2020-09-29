#ifndef NETWORK_H
#define NETWORK_H

#include "pluswindow.h"
#include "json.h"
#include "eshare.h"

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QTextStream>



class Network : QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0 );
    virtual ~Network(void);

    void InitCommand();

public slots:
    void connectToSocket(QString ip, qint16 port);
    void disconnectFromSocket();
    void send(QString string);
    void send(QJsonDocument doc);
    void onSocketReadyRead();

signals:
    void received_socketdata(QByteArray array);

private slots:
    void connected(void);
    void disconnected(void);


private:
    QTcpSocket *tcpSocket;
    PlusWindow *plusWindow;
    Eshare *eshare;
//  Json *json;
};

#endif // NETWORK_H
