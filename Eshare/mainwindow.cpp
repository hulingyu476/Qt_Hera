#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QCoreApplication>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    eshare *es = new eshare();
    es->RegistGetQRCodeCallBack(QRCode);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::QRCode(QString string)
{
    qDebug() <<"MainWindow QRCode:" << string;
}



