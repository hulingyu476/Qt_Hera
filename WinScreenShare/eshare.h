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

struct DeviceList
{
   qint16 devicelistcount;
   QStringList deviceiplist;
};

struct ClientIPList
{
   qint8 caststate;
   QString clientip;
};
struct ClientList
{
   qint16 clientlistcount;
   QList<ClientIPList> clientiplist;
};

struct PasswdConfigs
{
    qint8   ispwd;
    qint8   pwd;
};

struct DevPattern
{
    qint8   devpattern;
    QString   pincode;
};

struct SdkLicense
{
    qint8   license_status;
    QString  license_id;
};
struct SetLicense
{
    QString license_word;
    qint8   license_result;
};

enum ClientActionType
{
    ActionConnect = 0,
    ActionStartMirror,
    ActionStopMirror,
    ActionDisconnect,
    ActionInterrupt,
};

struct ConnectAction
{
    QString  clientName;
    qint8    clientAction;
};

enum FloatBallViewMode
{
    AlwaysShow = 0,
    AlwaysHide,
    AlwaysVisibility,
};

struct EshareInfo
{
    DeviceList          devicelist;
    qint8               mirrorconfig;
    qint8               priviewconfig;
    QString             localdevicename;
    qint8               changedevicenamestatus;
    qint64              mirrorhandler;
    PasswdConfigs       passwdconfigs;
    qint8               multiscreen;
    DevPattern          devpattern;
    qint8               checklicense;
    SdkLicense          sdklicense;
    SetLicense          setlicense;
    QString             qrCode;
    qint64              maincontrolhandler;
    qint8               maincontrolvisibility;
    ConnectAction       connectaction;
    ClientList          clientlist;
    qint64              floatingballhandler;
    qint8               floatingballvisibility;
    qint64              settinghandler;
    qint8               settingvisibility;
    FloatBallViewMode   floatingballmode;
};


class Eshare
{
public:
    EshareInfo eshareinfo;
    Eshare();
//  Json *json;
    void DataHandle(QByteArray array);

    QString GetDeviceList(qint16 cmdval=0);

    QString MirrorConfig(qint16 cmdval=0);
    QString PreviewConfig(qint16 cmdval=0);
    QString ChangeDeviceName(QString cmdval);
    QString GetMirrorHandler(QString cmdval);
    QString SetMirrorPwd(qint16 cmdval=0, qint16 isPwd=1, QString pwd="123456"); //TBD
    QString SetMulitScreen(qint16 cmdval=0);
    QString SetDevPattern(qint16 cmdval=0);
    QString CheckLicense(qint16 cmdval=0);
    QString SetLicense(QString cmdval);
    QString GetQRCode(qint16 cmdval);
    QString GetClientList(qint16 cmdval=0);

    QString GetMainControlHandle(qint16 cmdval);
    QString GetSettingHandle(qint16 cmdval);
    QString GetFloatingBallHandle(qint16 cmdval);
    QString SetMainControlVisibility(qint16 cmdval);
    QString SetSettingVisibility(qint16 cmdval);
    QString SetFloatingBallVisibility(qint16 cmdval);



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
