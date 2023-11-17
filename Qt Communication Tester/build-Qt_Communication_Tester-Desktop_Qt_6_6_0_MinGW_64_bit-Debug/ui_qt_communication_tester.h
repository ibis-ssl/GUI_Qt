/********************************************************************************
** Form generated from reading UI file 'qt_communication_tester.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_COMMUNICATION_TESTER_H
#define UI_QT_COMMUNICATION_TESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_Communication_Tester
{
public:
    QWidget *centralwidget;
    QPushButton *startbotton;
    QLabel *label;
    QCheckBox *chipEN;
    QCheckBox *keeperEN;
    QCheckBox *localEN;
    QLabel *label_2;
    QTextBrowser *setdata;
    QTextBrowser *sendingdata;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *data_from_robot;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QLabel *label_6;
    QSpinBox *setIP;
    QPushButton *IPset;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Qt_Communication_Tester)
    {
        if (Qt_Communication_Tester->objectName().isEmpty())
            Qt_Communication_Tester->setObjectName("Qt_Communication_Tester");
        Qt_Communication_Tester->resize(758, 459);
        centralwidget = new QWidget(Qt_Communication_Tester);
        centralwidget->setObjectName("centralwidget");
        startbotton = new QPushButton(centralwidget);
        startbotton->setObjectName("startbotton");
        startbotton->setGeometry(QRect(10, 10, 91, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 10, 111, 31));
        chipEN = new QCheckBox(centralwidget);
        chipEN->setObjectName("chipEN");
        chipEN->setGeometry(QRect(20, 80, 75, 20));
        keeperEN = new QCheckBox(centralwidget);
        keeperEN->setObjectName("keeperEN");
        keeperEN->setGeometry(QRect(100, 80, 75, 20));
        localEN = new QCheckBox(centralwidget);
        localEN->setObjectName("localEN");
        localEN->setGeometry(QRect(190, 80, 75, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 111, 21));
        setdata = new QTextBrowser(centralwidget);
        setdata->setObjectName("setdata");
        setdata->setGeometry(QRect(20, 180, 721, 51));
        sendingdata = new QTextBrowser(centralwidget);
        sendingdata->setObjectName("sendingdata");
        sendingdata->setGeometry(QRect(20, 270, 721, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 240, 111, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 150, 111, 21));
        data_from_robot = new QTextBrowser(centralwidget);
        data_from_robot->setObjectName("data_from_robot");
        data_from_robot->setGeometry(QRect(20, 360, 721, 51));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 330, 111, 21));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(450, 30, 301, 141));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(460, 10, 41, 21));
        setIP = new QSpinBox(centralwidget);
        setIP->setObjectName("setIP");
        setIP->setGeometry(QRect(220, 10, 42, 31));
        setIP->setMinimum(100);
        setIP->setMaximum(120);
        IPset = new QPushButton(centralwidget);
        IPset->setObjectName("IPset");
        IPset->setGeometry(QRect(270, 10, 41, 31));
        Qt_Communication_Tester->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Qt_Communication_Tester);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 758, 22));
        Qt_Communication_Tester->setMenuBar(menubar);
        statusbar = new QStatusBar(Qt_Communication_Tester);
        statusbar->setObjectName("statusbar");
        Qt_Communication_Tester->setStatusBar(statusbar);

        retranslateUi(Qt_Communication_Tester);

        QMetaObject::connectSlotsByName(Qt_Communication_Tester);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_Communication_Tester)
    {
        Qt_Communication_Tester->setWindowTitle(QCoreApplication::translate("Qt_Communication_Tester", "Orion_CommunicationTester", nullptr));
        startbotton->setText(QCoreApplication::translate("Qt_Communication_Tester", "Start", nullptr));
        label->setText(QCoreApplication::translate("Qt_Communication_Tester", "Target IP: 192.168.20.", nullptr));
        chipEN->setText(QCoreApplication::translate("Qt_Communication_Tester", "Chip EN", nullptr));
        keeperEN->setText(QCoreApplication::translate("Qt_Communication_Tester", "Keeper EN", nullptr));
        localEN->setText(QCoreApplication::translate("Qt_Communication_Tester", "Local EN", nullptr));
        label_2->setText(QCoreApplication::translate("Qt_Communication_Tester", "Select Function", nullptr));
        label_3->setText(QCoreApplication::translate("Qt_Communication_Tester", "Sending Data", nullptr));
        label_4->setText(QCoreApplication::translate("Qt_Communication_Tester", "Set Data", nullptr));
        label_5->setText(QCoreApplication::translate("Qt_Communication_Tester", "Data from robot", nullptr));
        label_6->setText(QCoreApplication::translate("Qt_Communication_Tester", "Log", nullptr));
        IPset->setText(QCoreApplication::translate("Qt_Communication_Tester", "Set", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_Communication_Tester: public Ui_Qt_Communication_Tester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_COMMUNICATION_TESTER_H
