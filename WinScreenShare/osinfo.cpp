#include "osinfo.h"

#include <QDebug>
#include <QThread>
#include <QProcess>
#include <QStringList>

OSInfo::OSInfo()
{

}

QString  OSInfo::GetWifiName()
{
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<"netsh wlan show interfaces");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    //qint16 nstrSize = strTemp.size();

    QStringList strlist = strTemp.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    qint16 nSize = strlist.size();
    for (int i =0; i < nSize; i++)
    {
        QString strtmp = strlist[i].simplified();
        if(strtmp.startsWith("SSID"))
        {
            QString ssid = strtmp.section(':',1,1).simplified();
            qDebug() << "ssid:" << ssid;
            return ssid;
        }
    }
    return QString("SSID:Not Found");
}

QString  OSInfo::GetWifiPasswd()
{
    QProcess p(0);
    QStringList cmdlist;
    QString cmdstr;
    QString ssid = GetWifiName();
    cmdstr += "netsh wlan show profile name =\"";
    cmdstr += ssid;
    cmdstr += "\" key = clear";
    cmdlist <<"/c"<< cmdstr;

    qDebug().noquote()<< cmdlist;

    p.start("cmd", cmdlist);
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    //qint16 nstrSize = strTemp.size();
    QString passwdline;
    QString passwd;
    QStringList strlist = strTemp.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    qint16 nSize = strlist.size();
    for (int i =0; i < nSize; i++)
    {
        QString strtmp = strlist[i].simplified();
        //qDebug() << strtmp;
         QLocale ql;
        switch (ql.language())
        {
           case QLocale::Chinese:
            if(strtmp.startsWith("关键内容"))
            {
                passwdline = strtmp;
            }
            break;
        default:
            if(strtmp.startsWith("Key Content"))
            {
                passwdline = strtmp;
            }
            break;
        }
    }
    passwd = passwdline.section(':',1,1).simplified();
    qDebug() << "passwd:" << passwd;

    return passwd;
}
