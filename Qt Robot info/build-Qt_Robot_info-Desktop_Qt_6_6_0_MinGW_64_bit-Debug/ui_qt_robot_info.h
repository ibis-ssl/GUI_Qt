/********************************************************************************
** Form generated from reading UI file 'qt_robot_info.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_ROBOT_INFO_H
#define UI_QT_ROBOT_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_Robot_info
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Qt_Robot_info)
    {
        if (Qt_Robot_info->objectName().isEmpty())
            Qt_Robot_info->setObjectName("Qt_Robot_info");
        Qt_Robot_info->resize(800, 600);
        centralwidget = new QWidget(Qt_Robot_info);
        centralwidget->setObjectName("centralwidget");
        Qt_Robot_info->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Qt_Robot_info);
        menubar->setObjectName("menubar");
        Qt_Robot_info->setMenuBar(menubar);
        statusbar = new QStatusBar(Qt_Robot_info);
        statusbar->setObjectName("statusbar");
        Qt_Robot_info->setStatusBar(statusbar);

        retranslateUi(Qt_Robot_info);

        QMetaObject::connectSlotsByName(Qt_Robot_info);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_Robot_info)
    {
        Qt_Robot_info->setWindowTitle(QCoreApplication::translate("Qt_Robot_info", "Qt_Robot_info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_Robot_info: public Ui_Qt_Robot_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_ROBOT_INFO_H
