#include "qt_robot_info.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_Robot_info w;
    w.show();
    return a.exec();
}
