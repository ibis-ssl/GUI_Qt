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
#include <QtWidgets/QSlider>
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
    QTextBrowser *sendingdata;
    QLabel *label_3;
    QTextBrowser *data_from_robot;
    QLabel *label_5;
    QTextBrowser *log;
    QLabel *label_6;
    QSpinBox *setIP;
    QSlider *kick_power;
    QLabel *label_7;
    QSlider *dribble_power;
    QLabel *label_8;
    QCheckBox *kick_EN;
    QCheckBox *dribble_EN;
    QTextBrowser *show_dribble_power;
    QTextBrowser *show_kick_power;
    QLabel *label_9;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Qt_Communication_Tester)
    {
        if (Qt_Communication_Tester->objectName().isEmpty())
            Qt_Communication_Tester->setObjectName("Qt_Communication_Tester");
        Qt_Communication_Tester->resize(758, 474);
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
        chipEN->setGeometry(QRect(370, 140, 75, 20));
        keeperEN = new QCheckBox(centralwidget);
        keeperEN->setObjectName("keeperEN");
        keeperEN->setGeometry(QRect(20, 80, 75, 20));
        localEN = new QCheckBox(centralwidget);
        localEN->setObjectName("localEN");
        localEN->setEnabled(true);
        localEN->setGeometry(QRect(110, 80, 75, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 111, 21));
        sendingdata = new QTextBrowser(centralwidget);
        sendingdata->setObjectName("sendingdata");
        sendingdata->setGeometry(QRect(20, 290, 721, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 260, 111, 21));
        data_from_robot = new QTextBrowser(centralwidget);
        data_from_robot->setObjectName("data_from_robot");
        data_from_robot->setGeometry(QRect(20, 380, 721, 51));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 350, 111, 21));
        log = new QTextBrowser(centralwidget);
        log->setObjectName("log");
        log->setGeometry(QRect(450, 30, 301, 141));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(460, 10, 41, 21));
        setIP = new QSpinBox(centralwidget);
        setIP->setObjectName("setIP");
        setIP->setGeometry(QRect(220, 10, 42, 31));
        setIP->setMinimum(100);
        setIP->setMaximum(120);
        kick_power = new QSlider(centralwidget);
        kick_power->setObjectName("kick_power");
        kick_power->setGeometry(QRect(100, 140, 111, 22));
        kick_power->setMaximum(20);
        kick_power->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 110, 81, 21));
        dribble_power = new QSlider(centralwidget);
        dribble_power->setObjectName("dribble_power");
        dribble_power->setGeometry(QRect(100, 110, 111, 21));
        dribble_power->setMaximum(20);
        dribble_power->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 140, 71, 21));
        kick_EN = new QCheckBox(centralwidget);
        kick_EN->setObjectName("kick_EN");
        kick_EN->setGeometry(QRect(300, 140, 61, 20));
        dribble_EN = new QCheckBox(centralwidget);
        dribble_EN->setObjectName("dribble_EN");
        dribble_EN->setGeometry(QRect(300, 110, 75, 20));
        show_dribble_power = new QTextBrowser(centralwidget);
        show_dribble_power->setObjectName("show_dribble_power");
        show_dribble_power->setGeometry(QRect(220, 100, 41, 31));
        show_kick_power = new QTextBrowser(centralwidget);
        show_kick_power->setObjectName("show_kick_power");
        show_kick_power->setGeometry(QRect(220, 140, 41, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(270, 110, 21, 21));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(270, 140, 21, 21));
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
        label_5->setText(QCoreApplication::translate("Qt_Communication_Tester", "Data from robot", nullptr));
        label_6->setText(QCoreApplication::translate("Qt_Communication_Tester", "Log", nullptr));
        label_7->setText(QCoreApplication::translate("Qt_Communication_Tester", "Dribble power", nullptr));
        label_8->setText(QCoreApplication::translate("Qt_Communication_Tester", "kick power", nullptr));
        kick_EN->setText(QCoreApplication::translate("Qt_Communication_Tester", "Kick EN", nullptr));
        dribble_EN->setText(QCoreApplication::translate("Qt_Communication_Tester", "Dribble EN", nullptr));
        label_9->setText(QCoreApplication::translate("Qt_Communication_Tester", "%", nullptr));
        label_10->setText(QCoreApplication::translate("Qt_Communication_Tester", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_Communication_Tester: public Ui_Qt_Communication_Tester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_COMMUNICATION_TESTER_H
