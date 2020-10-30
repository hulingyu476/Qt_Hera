#ifndef NETWORK_H
#define NETWORK_H

#include "pluswindow.h"
#include "json.h"
#include "eshare.h"

#include <QObject>
#include <QTcpSocket>
//#include <QJsonDocument>
#include <QTextStream>



class Network : QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0 );
    virtual ~Network(void);

    void InitCommandList();

    void ReceivedDataHandle(QByteArray array);
    QString GetHostIpAddress();
    //QString GetWifiSSIDname();
    //QString GetWifiSSIDpasswd();
public :
    void connectToSocket(QString ip, qint16 port);
    void disconnectFromSocket();
    void send(QString string);
    void send(QJsonDocument doc);


signals:
    void received_socketdata(QByteArray array);

private slots:
    void connected(void);
    void disconnected(void);
    void onSocketReadyRead();


private:
    QTcpSocket *tcpSocket;
    PlusWindow *plusWindow;
    Eshare *eshare;
//  Json *json;
};

#endif // NETWORK_H
