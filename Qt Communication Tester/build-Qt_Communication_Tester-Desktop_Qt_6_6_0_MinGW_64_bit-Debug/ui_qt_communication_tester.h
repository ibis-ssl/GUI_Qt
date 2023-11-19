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
#include <QtWidgets/QDial>
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
    QLabel *label_4;
    QTextBrowser *setdata;
    QDial *target_theta;
    QLabel *label_11;
    QTextBrowser *show_target_theta;
    QLabel *label_12;
    QSlider *vx;
    QTextBrowser *show_vy;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QTextBrowser *show_vx;
    QSlider *vy;
    QTextBrowser *show_robot_theta;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QTextBrowser *show_robot_voltage;
    QLabel *label_21;
    QTextBrowser *show_connection;
    QLabel *label_22;
    QTextBrowser *show_kickstate;
    QPushButton *reset_theta;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Qt_Communication_Tester)
    {
        if (Qt_Communication_Tester->objectName().isEmpty())
            Qt_Communication_Tester->setObjectName("Qt_Communication_Tester");
        Qt_Communication_Tester->resize(758, 587);
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
        chipEN->setGeometry(QRect(360, 120, 75, 20));
        keeperEN = new QCheckBox(centralwidget);
        keeperEN->setObjectName("keeperEN");
        keeperEN->setGeometry(QRect(120, 50, 75, 20));
        localEN = new QCheckBox(centralwidget);
        localEN->setObjectName("localEN");
        localEN->setEnabled(true);
        localEN->setGeometry(QRect(210, 50, 75, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 111, 21));
        sendingdata = new QTextBrowser(centralwidget);
        sendingdata->setObjectName("sendingdata");
        sendingdata->setGeometry(QRect(20, 280, 721, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 250, 111, 21));
        data_from_robot = new QTextBrowser(centralwidget);
        data_from_robot->setObjectName("data_from_robot");
        data_from_robot->setGeometry(QRect(20, 370, 721, 51));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 340, 111, 21));
        log = new QTextBrowser(centralwidget);
        log->setObjectName("log");
        log->setGeometry(QRect(20, 450, 311, 61));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 420, 41, 21));
        setIP = new QSpinBox(centralwidget);
        setIP->setObjectName("setIP");
        setIP->setGeometry(QRect(220, 10, 42, 31));
        setIP->setMinimum(100);
        setIP->setMaximum(120);
        kick_power = new QSlider(centralwidget);
        kick_power->setObjectName("kick_power");
        kick_power->setGeometry(QRect(100, 120, 111, 22));
        kick_power->setMaximum(20);
        kick_power->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 90, 81, 21));
        dribble_power = new QSlider(centralwidget);
        dribble_power->setObjectName("dribble_power");
        dribble_power->setGeometry(QRect(100, 90, 111, 21));
        dribble_power->setMaximum(20);
        dribble_power->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 120, 71, 21));
        kick_EN = new QCheckBox(centralwidget);
        kick_EN->setObjectName("kick_EN");
        kick_EN->setGeometry(QRect(290, 120, 61, 20));
        dribble_EN = new QCheckBox(centralwidget);
        dribble_EN->setObjectName("dribble_EN");
        dribble_EN->setGeometry(QRect(290, 90, 75, 20));
        show_dribble_power = new QTextBrowser(centralwidget);
        show_dribble_power->setObjectName("show_dribble_power");
        show_dribble_power->setGeometry(QRect(220, 80, 41, 31));
        show_kick_power = new QTextBrowser(centralwidget);
        show_kick_power->setObjectName("show_kick_power");
        show_kick_power->setGeometry(QRect(220, 120, 41, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(270, 90, 21, 21));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(270, 120, 21, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 160, 111, 21));
        setdata = new QTextBrowser(centralwidget);
        setdata->setObjectName("setdata");
        setdata->setGeometry(QRect(20, 190, 721, 51));
        target_theta = new QDial(centralwidget);
        target_theta->setObjectName("target_theta");
        target_theta->setGeometry(QRect(420, 30, 151, 151));
        target_theta->setMaximum(360);
        target_theta->setValue(180);
        target_theta->setSliderPosition(180);
        target_theta->setWrapping(true);
        target_theta->setNotchesVisible(false);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(430, 10, 51, 31));
        show_target_theta = new QTextBrowser(centralwidget);
        show_target_theta->setObjectName("show_target_theta");
        show_target_theta->setGeometry(QRect(480, 10, 41, 31));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(530, 10, 41, 31));
        vx = new QSlider(centralwidget);
        vx->setObjectName("vx");
        vx->setGeometry(QRect(580, 90, 151, 22));
        vx->setMaximum(200);
        vx->setValue(50);
        vx->setOrientation(Qt::Horizontal);
        show_vy = new QTextBrowser(centralwidget);
        show_vy->setObjectName("show_vy");
        show_vy->setGeometry(QRect(631, 120, 71, 31));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(711, 120, 31, 31));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(581, 120, 51, 31));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(711, 50, 31, 31));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(581, 50, 51, 31));
        show_vx = new QTextBrowser(centralwidget);
        show_vx->setObjectName("show_vx");
        show_vx->setGeometry(QRect(631, 50, 71, 31));
        vy = new QSlider(centralwidget);
        vy->setObjectName("vy");
        vy->setGeometry(QRect(580, 160, 151, 22));
        vy->setMaximum(200);
        vy->setValue(50);
        vy->setOrientation(Qt::Horizontal);
        show_robot_theta = new QTextBrowser(centralwidget);
        show_robot_theta->setObjectName("show_robot_theta");
        show_robot_theta->setGeometry(QRect(570, 480, 51, 31));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(630, 480, 41, 31));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(490, 480, 51, 31));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(490, 440, 81, 31));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(630, 440, 41, 31));
        show_robot_voltage = new QTextBrowser(centralwidget);
        show_robot_voltage->setObjectName("show_robot_voltage");
        show_robot_voltage->setGeometry(QRect(570, 440, 51, 31));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(360, 440, 61, 31));
        show_connection = new QTextBrowser(centralwidget);
        show_connection->setObjectName("show_connection");
        show_connection->setGeometry(QRect(430, 440, 51, 31));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(360, 480, 61, 31));
        show_kickstate = new QTextBrowser(centralwidget);
        show_kickstate->setObjectName("show_kickstate");
        show_kickstate->setGeometry(QRect(430, 480, 51, 31));
        reset_theta = new QPushButton(centralwidget);
        reset_theta->setObjectName("reset_theta");
        reset_theta->setGeometry(QRect(570, 10, 91, 31));
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
        label_4->setText(QCoreApplication::translate("Qt_Communication_Tester", "Set Data", nullptr));
        label_11->setText(QCoreApplication::translate("Qt_Communication_Tester", "Target \316\270", nullptr));
        label_12->setText(QCoreApplication::translate("Qt_Communication_Tester", "deg", nullptr));
        label_13->setText(QCoreApplication::translate("Qt_Communication_Tester", "m/s", nullptr));
        label_14->setText(QCoreApplication::translate("Qt_Communication_Tester", "Target Vy", nullptr));
        label_15->setText(QCoreApplication::translate("Qt_Communication_Tester", "m/s", nullptr));
        label_16->setText(QCoreApplication::translate("Qt_Communication_Tester", "Target Vx", nullptr));
        label_17->setText(QCoreApplication::translate("Qt_Communication_Tester", "deg", nullptr));
        label_18->setText(QCoreApplication::translate("Qt_Communication_Tester", "Robot \316\270", nullptr));
        label_19->setText(QCoreApplication::translate("Qt_Communication_Tester", "Robot Voltage", nullptr));
        label_20->setText(QCoreApplication::translate("Qt_Communication_Tester", "V", nullptr));
        label_21->setText(QCoreApplication::translate("Qt_Communication_Tester", "Connection", nullptr));
        label_22->setText(QCoreApplication::translate("Qt_Communication_Tester", "Kick state", nullptr));
        reset_theta->setText(QCoreApplication::translate("Qt_Communication_Tester", "Reset target \316\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_Communication_Tester: public Ui_Qt_Communication_Tester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_COMMUNICATION_TESTER_H
