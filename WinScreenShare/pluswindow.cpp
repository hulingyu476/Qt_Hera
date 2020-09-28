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


