#include "ieee754example.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ieee754Example w;
    w.show();

    return a.exec();
}
