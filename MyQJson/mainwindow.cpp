#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitJson();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitJson()
{

    QJsonArray versionArray;
    versionArray.append(4.8);
    versionArray.append(3.7);
    versionArray.append(8.9);

    QJsonObject pageObject;
    pageObject.insert("Home", "https://www.qt.io/");
    pageObject.insert("DownLoad", "http://www.qt.io/download/");

    QJsonObject json;
    json.insert("Name", "Qt");
    json.insert("From", 1991);
    json.insert("Cross Platform", true);

    json.insert("Version", QJsonValue(versionArray));
    json.insert("Page", QJsonValue(pageObject));

    QJsonDocument docment;
    docment.setObject(json);
    QByteArray byteArray = docment.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    qDebug() << strJson;

    QJsonParseError jsonError;
    // QByteArray byteArray;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError))
    {
        qDebug() << "Parse No error";
        if (document.isObject())
        {
            QJsonObject object = document.object();

            if (object.contains("Name"))
            {
                QJsonValue value = object.value("Name");
                if (value.isString())
                {
                    QString strName = value.toString();
                    qDebug() << "Name : " << strName;
                }
            }

            if (object.contains("From"))
            {
                QJsonValue value = object.value("Frome");
                if (value.isDouble())
                {
                    int nFrom = value.toVariant().toInt();
                    qDebug() << "From : " << nFrom;
                }
            }

            if (object.contains("Cross Platform"))
            {
                QJsonValue value = object.value("Cross Platform");
                if (value.isBool())
                {
                    bool bCrossPlatform = value.toBool();
                    qDebug() << "Cross Platform :" << bCrossPlatform;
                }
            }

            if (object.contains("Version"))
            {
                QJsonValue value = object.value("Version");
                if (value.isArray())
                {
                    QJsonArray array = value.toArray();
                    int nSize = array.size();
                    for (int i = 0; i < nSize; ++i)
                    {
                        QJsonValue value = array.at(i);
                        if (value.isDouble())
                        {
                            double dVersion = value.toDouble();
                            qDebug() << "Version " << dVersion;
                        }
                    }
                }
            }

            if (object.contains("Page"))
            {
                QJsonValue value = object.value("Page");
                if (value.isObject())
                {
                    QJsonObject object = value.toObject();
                    if (object.contains("Home"))
                    {
                        QJsonValue value = object.value("Home");
                        if (value.isString())
                        {
                            QString strHome = value.toString();
                            qDebug() << "Home : " << strHome;
                        }
                    }
                    if (object.contains("DownLoad"))
                    {
                        QJsonValue value = object.value("DownLoad");
                        if (value.isString())
                        {
                            QString strDownload = value.toString();
                            qDebug() << "DownLoad : " << strDownload;
                        }
                    }
                }
            }
        }
    }
}
