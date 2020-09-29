#ifndef ESHARE_H
#define ESHARE_H

#include <QObject>

//#include "json.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>

#include <QString>
#include <QList>

typedef struct DeviceList
{
   qint16 DeviceListCount;
   QList<QString> deviceip;
}ST_DEVICELIST;

typedef struct PasswdConfigs
{
    qint8   ispwd;
    qint8   pwd;
}PASSWDCONFIGS;

typedef struct DevPattern
{
    qint8   devpattern;
    qint8   pincode;
}DEVPATTERN;

typedef struct SdkLicense
{
    qint8   license_status;
    qint64  license_id;
    QString license_word;
    qint8   license_result;
}SDKLICENSE;

enum ClientActionType
{
    ActionConnect = 0,
    ActionStartMirror,
    ActionStopMirror,
    ActionDisconnect,
    ActionInterrupt,
};

typedef struct ClientAction
{
    QString          clientName;
    ClientActionType clientActionType;
}CLIENTACTION;

enum FloatBallViewMode
{
    AlwaysShow = 0,
    AlwaysHide,
    AlwaysVisibility,
};

typedef struct EsharInfo
{
    ST_DEVICELIST       DeviceList;
    qint8               mirrorconfig;
    qint8               priviewconfig;
    QString             localdevicename;
    qint64              mirrorhandler;
    PASSWDCONFIGS       passwdconfigs;
    qint8               multiscreen;
    qint8               checklicense;
    SDKLICENSE          SdkLicense;
    QString             qrCode;
    qint64              maincontrolhandler;
    qint8               maincontrolvisibility;
    CLIENTACTION        ClientAction;
    qint64              floatingballhandler;
    qint8               floatingballvisibility;
    qint64              settinglhandler;
    qint8               settingvisibility;
    FloatBallViewMode   floatingballmode;
}st_eshareinfo;


class Eshare
{
public:
    Eshare();
//  Json *json;
    QString GetDeviceList(qint16 cmdval=0);
    QString GetClientList(qint16 cmdval=0);
    QString MirrorConfig(qint16 cmdval=0);
    QString PreviewConfig(qint16 cmdval=0);
    QString SetMulitScreen(qint16 cmdval=0);
    QString SetDevPattern(qint16 cmdval=0);
    QString CheckLicense(qint16 cmdval=0);

    QString ChangeDeviceName(QString cmdval);
    QString GetMirrorHandler(QString cmdval);


private:
//    QString strGetDeviceList        = "{\"GetDeviceList\":0}";
//    QString strMirrorConfig         = "{\"MirrorConfig\":0,\"DeviceIp\":\"192.168.1.11\"}";
//    QString strPreviewConfig        = "{\"PreviewConfig\":0,\"DeviceIp\":\"192.168.1.11\"}";
//    QString strChangeDeviceName     = "{\"ChangeDeviceName\":\"newline\"}";
//    QString strGetMirrorHandler     = "{\"GetMirrorHandler\":0}";
//    QString strSetMirrorPwd         = "{\"SetMirrorPwd\":0,\"isPwd\":1,\"Pwd\":\"123456\"}";
//    QString strSetDevPattern        = "{\"SetDevPattern\":1}";
//    QString strSetMulitScreen       = "{\"SetMulitScreen\":0}";
//    QString strCheckLicense         = "{\"CheckLicense\":0}";


};

#endif // ESHARE_H
