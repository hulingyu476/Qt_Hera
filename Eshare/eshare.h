#ifndef ESHARE_H
#define ESHARE_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QJsonDocument>

typedef void (*CallBack)(QString); //声明函数指针类型

class eshare : QObject
{
    Q_OBJECT
public:
    explicit eshare(QObject *parent = 0 );
    virtual ~eshare(void);

private:
    QTcpSocket *tcpSocket;

public :
    QString GetDeviceList(qint16 cmdval=0);
    QString MirrorConfig(qint16 cmdval=0);
    QString PreviewConfig(qint16 cmdval=0);
    QString ChangeDeviceName(QString cmdval);
    QString GetMirrorHandler(QString cmdval);
    QString SetMirrorPwd(qint16 cmdval=0, qint16 isPwd=1, QString pwd="123456"); //TBD
    QString SetMulitScreen(qint16 cmdval=0);
    QString SetDevPattern(qint16 cmdval=1);
    QString CheckLicense(qint16 cmdval=0);
    QString SetLicense(QString cmdval);
    QString GetQRCode(qint16 cmdval=0);
    QString GetClientList(qint16 cmdval=0);

    QString GetMainControlHandle(qint16 cmdval);
    QString GetSettingHandle(qint16 cmdval);
    QString GetFloatingBallHandle(qint16 cmdval);
    QString SetMainControlVisibility(qint16 cmdval);
    QString SetSettingVisibility(qint16 cmdval);
    QString SetFloatingBallVisibility(qint16 cmdval);

public :
    void write(QString string);
    void write(QJsonDocument doc);
    void cmd(QString string);
    void DataHandle(QByteArray array);

private slots:
    void connected(void);
    void disconnected(void);
    void slot_ReadyRead();

signals:
    void sig_GetQRCode(QString string);

public:
    virtual void RegistGetQRCodeCallBack(CallBack cbfun); //注册回调函数
    static void test(QString string);
private:
    CallBack m_callback_GetQRCode; //函数指针变量
};

#endif // ESHARE_H
