#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    setWindowTitle("client");

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
