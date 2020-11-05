#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QDebug>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);



    tcpSocket = new QTcpSocket(this);
    setWindowTitle(tr("client"));
    ui->btnConnect->setText(tr("Connect"));
    ui->btnClose->setText(tr("Close"));
    ui->btnSend->setText(tr("Send"));

    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
            {
                ui->textEditWrite->setText("Connect Server OK");
             }
            );

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
            {
                QByteArray array = tcpSocket->readAll();
                ui->textEditRead->append(array);
            }
            );

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {

    }
}

void ClientWidget::on_btnConnect_clicked()
{
    qDebug("client start connect");

    //Get Server ip and port
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    qDebug("client connect ip=%s",qPrintable(ip));
    qDebug("client connect port=%d ",port);

    tcpSocket->connectToHost(QHostAddress(ip), port);

    qDebug("client connect socket server");


}

void ClientWidget::on_btnSend_clicked()
{
    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
   //QString str = QString("{\"CheckLicense\":0}");
     //tcpSocket->write(str.toUtf8().data());
    // tcpSocket->flush();
   //QString str2 = QString("{\"GetQRCode\":0}");
    // tcpSocket->write(str2.toUtf8().data());
    tcpSocket->flush();

    qDebug("client send data");
    ui->textEditRead->clear();
}

void ClientWidget::on_btnClose_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}


void ClientWidget::on_pushButton_cn_clicked()
{
    qDebug() << "click cn";
    QTranslator *enTrans = new QTranslator;
    enTrans->load(":/new/prefix1/Chinese.qm");
    qApp->installTranslator(enTrans);

    this->ui->retranslateUi(this);
}

void ClientWidget::on_pushButton_en_clicked()
{
    qDebug() << "click en";
    QTranslator *enTrans = new QTranslator;
    enTrans->load(":/new/prefix1/English.qm");
    qApp->installTranslator(enTrans);

    this->ui->retranslateUi(this);
}
