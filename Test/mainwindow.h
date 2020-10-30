#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QThread>
#include <QString>
#include <QObject>
#include <QApplication>

#include <QMainWindow>
#include "worker.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void dowork();

private:
    Ui::MainWindow *ui;
    Worker *m_pworker;
    QThread *m_pthread;

signals:
    void sig_dowork();

public slots:
    void slot_finish();
};
#endif // MAINWINDOW_H
