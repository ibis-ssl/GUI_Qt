#include "qt_communication_tester.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_Communication_Tester w;
    w.show();
    return a.exec();
}
