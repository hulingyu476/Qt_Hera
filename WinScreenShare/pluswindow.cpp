#include "pluswindow.h"
#include "ui_pluswindow.h"

#include <QHostAddress>

PlusWindow::PlusWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlusWindow)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::FramelessWindowHint);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(125,125,125));
    this->setPalette(palette);

    //showFullScreen();

}

PlusWindow::~PlusWindow()
{
    delete ui;
}

void PlusWindow::UpdateStatus(QString str)
{
    ui->textEdit->setText(str);

}

void PlusWindow::UpdateSSIDandPasswd(QString ssid,QString passwd)
{
    QString str;
    str +=QString::fromUtf8("将您的设备连接到");
    str +="\n";
    str +=QString::fromUtf8("接入: ")+ssid;
    str +="\n";
    str +=QString::fromUtf8("密码: ")+passwd;
    ui->textEditWiFi->setText(str);

}

void PlusWindow::on_pushButtonPhone_clicked()
{
    ui->pushButtonPhone->setText("");
}

void PlusWindow::Show_Receivedata(QByteArray array)
{
    qInfo().noquote() << array;
    UpdateStatus(array);

}
