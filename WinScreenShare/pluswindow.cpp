#include "pluswindow.h"
#include "ui_pluswindow.h"

#include <QtSvg/QSvgRenderer>
#include <QHostAddress>
#include <QPixmap>



PlusWindow::PlusWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlusWindow)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::FramelessWindowHint);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(125,125,125));
    this->setPalette(palette);

    InitUI();
    //showFullScreen();

}

PlusWindow::~PlusWindow()
{
    delete ui;
}



void PlusWindow::InitUI()
{
    //ui->lableucspace->setStyleSheet("QLabel{border-image: url(:/new/prefix1/res/ucspace.png);}");

    //ui->labelWiFiListPic->setStyleSheet("QLabel{background:url(:/new/prefix1/res/connect-androidap.svg);}");
    ui->labelWiFiListPic->setText(QString());

    ui->labelSwipPic->setText(QString());
//    QPixmap pixmap = QPixmap(":/new/prefix1/res/screen-mirror.svg");
//    QPixmap fitpixmap = pixmap.scaled(ui->labelSwipPic->width()*3,ui->labelSwipPic->height()*3,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
//    ui->labelSwipPic->setPixmap(fitpixmap);


// hide status
    ui->textEditStatus->hide();

    GetWifiInfo();
}

void PlusWindow::UpdateStatus(QString str)
{
    ui->textEditStatus->setText(str);

}

void PlusWindow::UpdateWifiInfo(QString ssid,QString passwd)
{
    QString str;
    str +=QString::fromUtf8("1:将您的设备连接到");
    str +="\n";
    str +=QString::fromUtf8("接入热点: ")+ssid;
    str +="\n";
    str +=QString::fromUtf8("密码: ")+passwd;
    ui->labelWiFi->setText(str);

}

void PlusWindow::GetWifiInfo()
{
    //UpdateWifiInfo(OSInfo::GetWifiName(), OSInfo::GetWifiPasswd());
    OSInfo *info = new OSInfo();
    UpdateWifiInfo(info->GetWifiName(), info->GetWifiPasswd());
    Q_UNUSED(info);
}

void PlusWindow::on_pushButtonPhone_clicked()
{
    //ui->pushButtonPhone->setText("Test");
}

void PlusWindow::Show_Receivedata(QByteArray array)
{
    qInfo().noquote() << array;
    UpdateStatus(array);

}
