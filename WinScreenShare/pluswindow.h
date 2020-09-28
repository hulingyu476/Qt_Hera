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
};

#endif // PLUSWINDOW_H
