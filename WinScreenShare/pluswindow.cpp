#include "pluswindow.h"
#include "ui_pluswindow.h"

#include <QHostAddress>

qint16 port = 11451;

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

    ConnectSDK();

}

PlusWindow::~PlusWindow()
{
    delete ui;
}

void PlusWindow::ConnectSDK()
{
    tcpSocket = new QTcpSocket(this);

    tcpSocket->connectToHost(QHostAddress("127.0.0.1"), port);

    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
            {
               QString str = "{\"SetDevPattern\":1}";
               ui->textEdit->clear();

               ui->textEdit->setText("Socket Connected");

               tcpSocket->write(str.toUtf8().data());
             }
            );

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
            {
                QByteArray array = tcpSocket->readAll();

                //ui->textEdit->clear();
                ui->textEdit->append(array);
            }
            );
    connect(tcpSocket,static_cast<void(QAbstractSocket::*)(QAbstractSocket::SocketError)> (&QAbstractSocket::error),
            [=]()
            {
                ;
            }
            );

}

