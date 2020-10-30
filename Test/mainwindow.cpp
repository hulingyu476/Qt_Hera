#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pworker = new Worker();
    m_pthread = new QThread();

    m_pworker->moveToThread(m_pthread);
    qDebug() << "start,main thread id =" << QThread::currentThreadId();

    connect(m_pthread,&QThread::finished,m_pworker,&QObject::deleteLater);
    connect(this,SIGNAL(sig_dowork()),m_pworker,SLOT(slot_dowork()));
    connect(m_pworker,SIGNAL(sig_finish()),this,SLOT(slot_finish()));
}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow";
    delete ui;

    m_pthread->quit();
    m_pthread->wait();
}

void MainWindow::dowork()
{
    qDebug() << "MainWindow:dowork";
    m_pthread->start();
    emit sig_dowork();
}

void MainWindow::slot_finish()
{
    qDebug() << "finish, thread id=" << QThread::currentThreadId();
}

