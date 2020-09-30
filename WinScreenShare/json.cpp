#include "json.h"

#include <QDebug>

Json::Json()
{
}

QJsonObject Json::getJsonObjectFromString(const QString jsonString)
{
    QJsonParseError jsonError;
    QJsonObject jsonObject;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data(),&jsonError);
    if (!jsonDocument.isNull() && (jsonError.error == QJsonParseError::NoError))
    {
        qDebug() << "getJsonObjectFromString ok:" + jsonString;

        jsonObject = jsonDocument.object();
    }
    else{
        qWarning() << "getJsonObjectFromString error:" + jsonString;
        jsonObject.empty();
    }
    return jsonObject;
}

QJsonDocument Json::getJsonDocumentFromString(const QString jsonString)
{
    QJsonParseError jsonError;
    QJsonObject jsonObject;

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8(),&jsonError);

    if(jsonDocument.isNull()||(jsonError.error != QJsonParseError::NoError))
    {
        qWarning() << "getJsonDocumentFromString "<< jsonString  << " <error code>:" << jsonError.errorString() ;
    }

    qDebug() << "[getJsonDocumentFromString] jsonDocument:" << jsonDocument.toJson().data();

    return jsonDocument;
}

QString Json::getStringFromJsonObject(const QJsonObject& jsonObject)
{
    return QString(QJsonDocument(jsonObject).toJson());
}

QString Json::getStringFromJsonDocument(const QJsonDocument& jsonDocument)
{
    return QString(jsonDocument.toJson());
}


QString Json::ConvertCmdWithInt(const QString jsonString,const QString cmdname,qint16 cmdval)
{
    QJsonDocument jsonDocument = getJsonDocumentFromString(jsonString);

     if (!jsonDocument.isNull())
     {
        if(jsonDocument.isObject())
        {
            QJsonObject object = jsonDocument.object();

            if (object.contains(cmdname))
            {
                QJsonValue value = object.value(cmdname);
                if(value.isDouble()){
                    qint16 currentval = value.toVariant().toInt();
                    qDebug() << "Name : " << currentval;
                    object.insert(cmdname,cmdval);
                }
             }
            return getStringFromJsonObject(object);
        }
     }
     return QString();
}

QString Json::ConvertCmdWithString(const QString jsonString,const QString cmdname,const QString cmdval)
{
    QJsonDocument jsonDocument = getJsonDocumentFromString(jsonString);

     if (!jsonDocument.isNull())
     {
        if(jsonDocument.isObject())
        {
            QJsonObject object = jsonDocument.object();

            if (object.contains(cmdname))
            {
                QJsonValue value = object.value(cmdname);
                if(value.isString()){
                    QString currentstr = value.toString();
                    qDebug() << "Name : " << currentstr;
                    object.insert(cmdname,cmdval);
                }
             }
            return getStringFromJsonObject(object);
        }
     }
     return QString();
}





