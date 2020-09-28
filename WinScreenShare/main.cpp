#include "socketnetwork.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //PlusWindow w;
    //w.show();
   auto core = new SocketNetwork;


    return a.exec();
}
