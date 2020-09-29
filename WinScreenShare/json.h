#ifndef JSON_H
#define JSON_H

#include <QObject>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>

class Json
{
public:
    Json();

    QJsonObject getJsonObjectFromString(const QString jsonString);
    QJsonDocument getJsonDocumentFromString(const QString jsonString);
    QString getStringFromJsonObject(const QJsonObject &jsonObject);
    QString getStringFromJsonDocument(const QJsonDocument &jsonDocument);


    QString ConvertCmdWithInt(const QString jsonString, const QString cmdname, qint16 cmdval);
    QString ConvertCmdWithString(const QString jsonString, const QString cmdname, const QString cmdval);
};

#endif // JSON_H
