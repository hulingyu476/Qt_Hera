#include "clientwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QTranslator chineseTrans;
    chineseTrans.load(":/new/prefix1/Chinese.qm");
    a.installTranslator(&chineseTrans);*/

    ClientWidget w;
    w.show();

    return a.exec();
}
