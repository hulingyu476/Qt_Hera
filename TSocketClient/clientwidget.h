#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>

#include <QTcpServer>
#include <QTcpSocket>

#include <QTranslator>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();
    void changeEvent(QEvent *event);

private slots:
    void on_btnConnect_clicked();

    void on_btnSend_clicked();

    void on_btnClose_clicked();


    void on_pushButton_cn_clicked();

    void on_pushButton_en_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *tcpSocket;



};

#endif // CLIENTWIDGET_H
