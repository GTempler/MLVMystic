#include "mystic.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mystic w;
    w.show();

    return a.exec();
}
