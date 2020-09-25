#include "pluswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlusWindow w;
    w.show();
    return a.exec();
}
