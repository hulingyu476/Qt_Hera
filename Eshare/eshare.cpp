#include "eshare.h"

#include <QHostAddress>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>

#include <QThread>

eshare::eshare(QObject *parent)
     : QObject(parent),
     tcpSocket(new QTcpSocket(this))
{
    tcpSocket->connectToHost(QHostAddress::LocalHost, 11451);
    if (tcpSocket->waitForConnected())
        qDebug() << " Connectted to server" ;

    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(slot_ReadyRead()));

}

eshare::~eshare()
{
    qDebug() << "[~eshare]";
    disconnected();
}

void eshare::disconnected()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->waitForDisconnected();
}

void eshare::connected()
{
    qDebug() << " Connectted sig" ;
}
void eshare::cmd(QString string)
{
    write(string);
}
void eshare::write(QString string)
{
    qDebug() << "Write Cmd string:" << string;

    if(tcpSocket->state() != QTcpSocket::ConnectedState)
    {
        qInfo() << "UnConnectted, Failed Write cmd: " << string ;
    }
    tcpSocket->write(string.toUtf8().data());

    tcpSocket->waitForBytesWritten();
}

void eshare::write(QJsonDocument doc)
{
    //SDK only support Compact;not support Indented
    write(QString(doc.toJson(QJsonDocument::Compact)));
}


void eshare::slot_ReadyRead()
{
    QByteArray array = tcpSocket->readAll();
    qInfo() << "ReadyRead=" << array;

    if(!array.isEmpty()){
        DataHandle(array);
    }
}



void eshare::RegistGetQRCodeCallBack(CallBack cbfun)
{
    GetQRCode();
    m_callback_GetQRCode = cbfun;
    //QThread::msleep(2000);
}

QString eshare::GetDeviceList(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetDeviceList", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::GetClientList(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetClientList", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::GetMainControlHandle(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetMainControlHandle", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));write(cmd);return cmd;
}

QString eshare::GetSettingHandle(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetSettingHandle", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::GetFloatingBallHandle(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetFloatingBallHandle", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::MirrorConfig(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("MirrorConfig", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::PreviewConfig(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("PreviewConfig", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::SetMulitScreen(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("SetMulitScreen", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::ChangeDeviceName(QString cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("ChangeDeviceName", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::SetDevPattern(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("SetDevPattern", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::GetMirrorHandler(QString cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetMirrorHandler", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::SetMirrorPwd(qint16 cmdval, qint16 isPwd, QString pwd)
{
    Q_UNUSED(isPwd)
    Q_UNUSED(pwd)
    QJsonObject jsonObject;
    jsonObject.insert("SetMirrorPwd", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::CheckLicense(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("CheckLicense", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::SetLicense(QString cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("SetLicense", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

QString eshare::GetQRCode(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetQRCode", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);
    return cmd;
}

QString eshare::SetMainControlVisibility(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("SetMainControlVisibility", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}
QString eshare::SetSettingVisibility(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("SetSettingVisibility", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}
QString eshare::SetFloatingBallVisibility(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("SetFloatingBallVisibility", cmdval);

    QString cmd=QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
    write(cmd);

    return cmd;
}

void eshare::DataHandle(QByteArray array)
{
    QJsonParseError jsonError;
    QJsonObject jsonObject;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(array,&jsonError);
    if (!jsonDocument.isNull() && (jsonError.error == QJsonParseError::NoError))
    {
        if(jsonDocument.isObject())
        {
            jsonObject = jsonDocument.object();

            if(jsonObject.contains("Cmd"))
            {
                QJsonValue value = jsonObject.value("Cmd");
                if(value.isDouble())
                {
                    int cmd = value.toVariant().toInt();
                    switch (cmd)
                    {
                    case 1007:  //  GetDeviceList
                        if(jsonObject.contains("DeviceList"))
                        {
                            QJsonValue value = jsonObject.value("DeviceList");
                            if(value.isArray())
                            {
                               QJsonArray array = value.toArray();
                                int nSize = array.size();

                                for (int i = 0; i < nSize; i++)
                                {
                                    QJsonValue arrayobject = array.at(i);

                                    if(arrayobject.isObject())
                                    {
                                        QJsonObject jsonObject = arrayobject.toObject();
                                        if(jsonObject.contains("deviceIp"))
                                        {
                                            QJsonValue value = jsonObject.value("deviceIp");
                                            if(value.isString())
                                            {
                                                //eshareinfo.devicelist.deviceiplist << value.toString();
                                                qDebug() << QString("DeviceList[%1]:%2").arg(i).arg(value.toString());
                                            }
                                        }
                                    }
                                }
                                qDebug() << "final ip";
                                //qDebug().noquote() << eshareinfo.devicelist.deviceiplist;
                            }
                        }
                        break;
                    case 1010:  //  ChangeDeviceName
                        if(jsonObject.contains("result"))
                        {
                            QJsonValue value = jsonObject.value("result");
                            if(value.isDouble())
                            {
                               // eshareinfo.changedevicenamestatus = value.toVariant().toInt();
                               // qDebug() << "changedevicenamestatus :" << value.toVariant().toInt();
                            }
                        }
                        break;
                    case 1011:  //  GetMirrorHandle
                        if(jsonObject.contains("handle"))
                        {
                            QJsonValue value = jsonObject.value("handle");
                            if(value.isDouble())
                            {
                               // eshareinfo.maincontrolhandler = value.toVariant().toInt();
                               // qDebug() << "maincontrolhandler :" << value.toVariant().toInt();
                            }
                        }
                        break;
                    case 1012:  //  SetDevPattern
                    {
                        if(jsonObject.contains("Pin"))
                        {
                            QJsonValue value = jsonObject.value("Pin");
                            if(value.isString())
                            {
                                //eshareinfo.devpattern.pincode = value.toString();
                                //qDebug() << "pinCode :" << value.toString();
                            }
                        }
                    }
                    break;
                    case 1013:  //  CheckLicense
                    {
                        if(jsonObject.contains("licenseStatus"))
                        {
                            QJsonValue value = jsonObject.value("licenseStatus");
                            if(value.isBool())
                            {
                                //eshareinfo.sdklicense.license_status = value.toBool();
                                //qDebug() << "license_status :" << eshareinfo.sdklicense.license_status;
                            }
                        }
                        if(jsonObject.contains("ID"))
                        {
                            QJsonValue value = jsonObject.value("ID");
                            if(value.isString())
                            {
                                //eshareinfo.sdklicense.license_id = value.toString();
                                //qDebug() << "license_id :" << value.toString();
                            }
                        }
                    }
                    break;
                    case 1014:  //  SetLicense
                    {
                        if(jsonObject.contains("licenseResult"))
                        {
                            QJsonValue value = jsonObject.value("licenseResult");
                            if(value.isDouble())
                            {
                                //eshareinfo.setlicense.license_result = value.toVariant().toInt();
                                qDebug() << "license_result :" << value.toVariant().toInt();
                            }
                        }
                    }
                    break;
                    case 1015:  //  GetQRCode
                    {
                        if(jsonObject.contains("qrCode"))
                        {
                            QJsonValue value = jsonObject.value("qrCode");
                                    if(value.isString())
                            {
                                //eshareinfo.qrCode = value.toString();
                                //qInfo() << "qrCode :" << value.toString();
                                emit sig_GetQRCode(value.toString());
                                if(m_callback_GetQRCode) m_callback_GetQRCode(value.toString()); //CallBack func
                            }
                        }
                    }
                    break;
                    case 1016:  //  GetMainControlHandler
                    {
                        if(jsonObject.contains("mainControl"))
                        {
                            QJsonValue value = jsonObject.value("mainControl");
                            if(value.isDouble())
                            {
                                //eshareinfo.maincontrolhandler = value.toVariant().toInt();
                                qDebug() << "maincontrolhandler :" << value.toVariant().toInt();
                            }
                        }
                    }
                    break;
                    case 1017:  //  Client Connect Message
                    {
                        if(jsonObject.contains("clientName"))
                        {
                            QJsonValue value = jsonObject.value("clientName");
                            if(value.isString())
                            {
                                //eshareinfo.connectaction.clientName = value.toString();
                                qDebug() << "clientName :" << value.toString();
                            }
                        }
                        if(jsonObject.contains("clientAction"))
                        {
                            QJsonValue value = jsonObject.value("clientAction");
                            if(value.isDouble())
                            {
                                //eshareinfo.connectaction.clientAction = value.toVariant().toInt();
                                qDebug() << "clientAction :" << value.toVariant().toInt();
                            }
                        }
                    }
                    break;
                    case 1018:  //  GetClientList
                        if(jsonObject.contains("clientList"))
                        {
                            QJsonValue value = jsonObject.value("clientList");
                            if(value.isArray())
                            {

                                QJsonArray array = value.toArray();
                                int nSize = array.size();
                                //eshareinfo.clientlist.clientlistcount = nSize;

                                for (int i = 0; i < nSize; i++)
                                {
                                    QJsonValue arrayobject = array.at(i);

                                    if(arrayobject.isObject())
                                    {
                                       // qDebug() <<  arrayobject;//onlydebug
                                        QJsonObject jsonObject = arrayobject.toObject();
                                        //ClientIPList iplist;
                                        if(jsonObject.contains("clientIp"))
                                        {
                                            QJsonValue value = jsonObject.value("clientIp");
                                            if(value.isString())
                                            {
                                               // iplist.clientip = value.toString();
                                            }
                                        }
                                        if(jsonObject.contains("castState"))
                                        {
                                            QJsonValue value = jsonObject.value("castState");
                                            if(value.isDouble())
                                            {
                                                //iplist.caststate = value.toVariant().toInt();
                                            }
                                        }
                                        //eshareinfo.clientlist.clientiplist << iplist;
                                    }
                                }
                            }
                        }
                        break;
                    case 1019:  //  GetFloatingBallingHandler
                    {
                        if(jsonObject.contains("floatingBall"))
                        {
                            QJsonValue value = jsonObject.value("floatingBall");
                            if(value.isDouble())
                            {
                                //eshareinfo.floatingballhandler = value.toVariant().toInt();
                                qDebug() << "floatingballhandler :" << value.toVariant().toInt();
                            }
                        }
                    }
                    break;
                    case 1020:  //  GetSettingHandler
                    {
                        if(jsonObject.contains("setting"))
                        {
                            QJsonValue value = jsonObject.value("setting");
                            if(value.isDouble())
                            {
                                //eshareinfo.settinghandler = value.toVariant().toInt();
                                qDebug() << "settinghandler :" << value.toVariant().toInt();
                            }
                        }
                    }
                    break;

                    }
                }
            }
        }
    }


}
