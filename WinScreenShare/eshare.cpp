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
    jsonObject.insert("GetClientlist", cmdval);

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

QString Eshare::CheckLicense(qint16 cmdval)
{
   QJsonObject jsonObject;
   jsonObject.insert("CheckLicense", cmdval);

   return QString(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact));
}
