#include "eshare.h"

#include <QDebug>

Eshare::Eshare()
{
}

QString Eshare::GetDeviceList(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetDeviceList", cmdval);

    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::GetClientList(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetClientList", cmdval);

    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::GetMainControlHandle(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetMainControlHandle", cmdval);

    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::GetSettingHandle(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetSettingHandle", cmdval);

    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::GetFloatingBallHandle(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetFloatingBallHandle", cmdval);

    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::MirrorConfig(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("MirrorConfig", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::PreviewConfig(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("PreviewConfig", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::SetMulitScreen(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("SetMulitScreen", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::ChangeDeviceName(QString cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("ChangeDeviceName", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::SetDevPattern(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("SetDevPattern", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::GetMirrorHandler(QString cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("GetMirrorHandler", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::SetMirrorPwd(qint16 cmdval, qint16 isPwd, QString pwd)
{
    Q_UNUSED(isPwd)
    Q_UNUSED(pwd)
    QJsonObject jsonObject;
    jsonObject.insert("SetMirrorPwd", cmdval);

    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::CheckLicense(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("CheckLicense", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::GetQRCode(qint16 cmdval)
{
    QJsonObject jsonObject;
    jsonObject.insert("GetQRCode", cmdval);

    return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

QString Eshare::SetMainControlVisibility(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("SetMainControlVisibility", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}
QString Eshare::SetSettingVisibility(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("SetSettingVisibility", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}
QString Eshare::SetFloatingBallVisibility(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("SetFloatingBallVisibility", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}

void Eshare::DataHandle(QByteArray array)
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
                                    //qDebug() << "DeviceList :" << value.toArray();
                                    QJsonArray array = value.toArray();
                                    int nSize = array.size();
                                    eshareinfo.devicelist.devicelistcount = nSize;
                                    for (int i = 0; i < nSize; ++i)
                                    {
                                        QJsonValue value = array.at(i);
                                        if(value.isString())
                                        {
                                            eshareinfo.devicelist.deviceiplist << value.toString();
                                            qDebug() << QString("DeviceList[%1]:%").arg(i).arg(value.toString());
                                        }
                                    }
                                    qDebug() << "final ip";
                                    qDebug() << eshareinfo.devicelist.deviceiplist;
                                }
                            }
                            break;
                        case 1010:  //  ChangeDeviceName
                            if(jsonObject.contains("result"))
                            {
                                QJsonValue value = jsonObject.value("result");
                                if(value.isDouble())
                                {
                                   eshareinfo.changedevicenamestatus = value.toVariant().toInt();
                                   qDebug() << "changedevicenamestatus :" << eshareinfo.changedevicenamestatus;
                                }
                            }
                            break;
                        case 1011:  //  GetMirrorHandle
                            if(jsonObject.contains("handle"))
                            {
                                QJsonValue value = jsonObject.value("handle");
                                if(value.isDouble())
                                {
                                   eshareinfo.maincontrolhandler = value.toVariant().toInt();
                                   qDebug() << "maincontrolhandler :" << eshareinfo.maincontrolhandler;
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
                                       eshareinfo.devpattern.pincode = value.toString();
                                       qDebug() << "pinCode :" << eshareinfo.devpattern.pincode;
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
                                       eshareinfo.sdklicense.license_status = value.toBool();
                                       qDebug() << "license_status :" << eshareinfo.sdklicense.license_status;
                                    }
                                }
                                if(jsonObject.contains("ID"))
                                {
                                    QJsonValue value = jsonObject.value("ID");
                                    if(value.isString())
                                    {
                                       eshareinfo.sdklicense.license_id = value.toString();
                                       qDebug() << "license_id :" << eshareinfo.sdklicense.license_id;
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
                                       eshareinfo.setlicense.license_result = value.toVariant().toInt();
                                       qDebug() << "license_result :" << eshareinfo.setlicense.license_result;
                                    }
                                }
                            }
                            break;
                        case 1015:  //  GetQRCode
                            {
                                if(jsonObject.contains("GetQRCode"))
                                {
                                    QJsonValue value = jsonObject.value("GetQRCode");
                                    if(value.isString())
                                    {
                                       eshareinfo.qrCode = value.toString();
                                       qDebug() << "qrCode :" << eshareinfo.qrCode;
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
                                       eshareinfo.maincontrolhandler = value.toVariant().toInt();
                                       qDebug() << "maincontrolhandler :" << eshareinfo.maincontrolhandler;
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
                                       eshareinfo.connectaction.clientName = value.toString();
                                       qDebug() << "clientName :" << eshareinfo.connectaction.clientName;
                                    }
                                }
                                if(jsonObject.contains("clientAction"))
                                {
                                    QJsonValue value = jsonObject.value("clientAction");
                                    if(value.isDouble())
                                    {
                                       eshareinfo.connectaction.clientAction = value.toVariant().toInt();
                                       qDebug() << "clientAction :" << eshareinfo.connectaction.clientAction;
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
                                    //qDebug() << "DeviceList :" << value.toArray();
                                    QJsonArray array = value.toArray();
                                    int nSize = array.size();
                                    eshareinfo.clientlist.clientlistcount = nSize;

                                    for (int i = 0; i < nSize; ++i)
                                    {
                                        QJsonValue value = array.at(i);
                                        if(value.isObject())
                                        {
                                            qint8 tmp_caststate = 0;
                                            QString tmp_clientip;

                                            QJsonObject jsonObject = value.toObject();
                                            if (jsonObject.contains("castState"))
                                            {
                                                QJsonValue value = jsonObject.value("castValue");
                                                tmp_caststate = value.toVariant().toInt();
                                            }
                                            if (jsonObject.contains("clientIp"))
                                            {
                                                QJsonValue value = jsonObject.value("clientIp");
                                                tmp_clientip  = value.toVariant().toString();
                                            }
                                            eshareinfo.clientlist.deviceiplist[i].caststate = tmp_caststate;
                                            eshareinfo.clientlist.deviceiplist[i].clientip  = tmp_clientip;

                                            qDebug() << QString("caststate=%1,IP=%2").arg(tmp_caststate).arg(tmp_clientip);
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
                                       eshareinfo.floatingballhandler = value.toVariant().toInt();
                                       qDebug() << "floatingballhandler :" << eshareinfo.floatingballhandler;
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
                                       eshareinfo.settinghandler = value.toVariant().toInt();
                                       qDebug() << "settinghandler :" << eshareinfo.settinghandler;
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
