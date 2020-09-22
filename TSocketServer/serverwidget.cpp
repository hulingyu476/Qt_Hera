#include "serverwidget.h"
#include "ui_serverwidget.h"

#include <QDebug>

#define ESHAREPORT 8888
ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    tcpServer = NULL;
    tcpSocket = NULL;

    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);

    setWindowTitle("server:8888");

    connect(tcpServer, &QTcpServer::newConnection,
            [=]()
            {
                
                tcpSocket = tcpServer->nextPendingConnection();

               
                QString ip = tcpSocket->peerAddress().toString();
                qint16 port = tcpSocket->peerPort();
                QString temp = QString("[%1:%2]:Connect Sucusesed").arg(ip).arg(port);
                ui->textEditRead->setText(temp);

               
                connect(tcpSocket, &QTcpSocket::readyRead,
                        [=]()
                        {
                            
                            QByteArray array = tcpSocket->readAll();
                            ui->textEditRead->append(array);
                        }
                );
            }
    );
}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_btnSend_clicked()
{
    if(NULL == tcpSocket)
    {
        qDebug("btnSend tcpSocket is NUll");
        return;
    }

    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());

}

void ServerWidget::on_btnClose_clicked()
{
    if(NULL == tcpSocket)
    {
        qDebug("btnClose tcpSocket is NUll");
        return;
    }

    //active close connect
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;
}
