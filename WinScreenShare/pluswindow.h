#ifndef PLUSWINDOW_H
#define PLUSWINDOW_H

#include <QWidget>


namespace Ui {
class PlusWindow;
}

class PlusWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlusWindow(QWidget *parent = nullptr);
    ~PlusWindow();

private:
    Ui::PlusWindow *ui;

public:
    void UpdateStatus(QString str);
    void UpdateSSIDandPasswd(QString ssid, QString passwd);
    void InitUI();
private slots:
    void on_pushButtonPhone_clicked();
    void Show_Receivedata(QByteArray array);
};

#endif // PLUSWINDOW_H
