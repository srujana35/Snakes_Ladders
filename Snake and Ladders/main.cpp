#include "introduction.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    introduction w;
    w.showMaximized();

    return a.exec();
}
