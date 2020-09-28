#ifndef ESHARECOMMAND_H
#define ESHARECOMMAND_H

#include <QString>

QString GetDeviceList       = "{\"GetDeviceList\":0}";
QString MirrorConfigStart   = "{\"MirrorConfig\":1,\"DeviceIp\":\"192.168.58.60\"}";
QString MirrorConfigEnd     = "{\"MirrorConfig\":0,\"DeviceIp\":\"192.168.58.60\"}";
QString ChangeDeviceName    = "{\"ChangeDeviceName\":\"newline\"}";

QString SetDevPattern       = "{\"SetDevPattern\":1}";

#endif // ESHARECOMMAND_H
