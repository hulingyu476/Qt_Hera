#ifndef PLUSWINDOW_H
#define PLUSWINDOW_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class PlusWindow;
}

class PlusWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlusWindow(QWidget *parent = nullptr);
    ~PlusWindow();

    void ConnectSDK();
private:
    Ui::PlusWindow *ui;
    QTcpSocket *tcpSocket;
};

#endif // PLUSWINDOW_H
