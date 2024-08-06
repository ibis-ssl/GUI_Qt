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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_Robot_info
{
public:
    QWidget *centralwidget;
    QTextBrowser *show_speedy;
    QTextBrowser *show_ball3;
    QTextBrowser *show_connection;
    QTextBrowser *show_ball0;
    QTextBrowser *show_temp3;
    QTextBrowser *show_temp4;
    QLabel *label_17;
    QLabel *label_20;
    QTextBrowser *show_current3;
    QLabel *label_28;
    QTextBrowser *show_cap_voltage;
    QLabel *label_23;
    QTextBrowser *show_robot_theta;
    QTextBrowser *show_kickstate;
    QLabel *label_30;
    QTextBrowser *show_speedx;
    QLabel *label_31;
    QLabel *label_21;
    QLabel *label_26;
    QTextBrowser *show_odomx;
    QLabel *label_18;
    QTextBrowser *show_current2;
    QLabel *label_19;
    QTextBrowser *show_temp2;
    QTextBrowser *show_ball1;
    QLabel *label_47;
    QTextBrowser *show_current0;
    QTextBrowser *show_current1;
    QTextBrowser *show_temp0;
    QTextBrowser *show_temp1;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_25;
    QTextBrowser *show_robot_voltage;
    QLabel *label_27;
    QTextBrowser *show_temp5;
    QTextBrowser *show_temp6;
    QLabel *label_34;
    QTextBrowser *show_ball2;
    QLabel *label_29;
    QTextBrowser *show_odomy;
    QTextBrowser *show_robot_theta_diff;
    QLabel *label_38;
    QTextBrowser *show_error1;
    QTextBrowser *show_error2;
    QTextBrowser *data_from_robot;
    QLabel *label_6;
    QTextBrowser *show_error0;
    QLabel *label_5;
    QTextBrowser *log;
    QSpinBox *setIP;
    QPushButton *startbotton;
    QLabel *label;
    QLabel *label_39;
    QLabel *label_40;
    QProgressBar *Robot_Voltage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Qt_Robot_info)
    {
        if (Qt_Robot_info->objectName().isEmpty())
            Qt_Robot_info->setObjectName("Qt_Robot_info");
        Qt_Robot_info->resize(714, 309);
        Qt_Robot_info->setToolButtonStyle(Qt::ToolButtonIconOnly);
        Qt_Robot_info->setAnimated(true);
        Qt_Robot_info->setDocumentMode(false);
        Qt_Robot_info->setDockNestingEnabled(false);
        centralwidget = new QWidget(Qt_Robot_info);
        centralwidget->setObjectName("centralwidget");
        show_speedy = new QTextBrowser(centralwidget);
        show_speedy->setObjectName("show_speedy");
        show_speedy->setGeometry(QRect(610, 170, 71, 31));
        show_ball3 = new QTextBrowser(centralwidget);
        show_ball3->setObjectName("show_ball3");
        show_ball3->setGeometry(QRect(300, 250, 41, 31));
        show_connection = new QTextBrowser(centralwidget);
        show_connection->setObjectName("show_connection");
        show_connection->setGeometry(QRect(650, 10, 51, 31));
        show_ball0 = new QTextBrowser(centralwidget);
        show_ball0->setObjectName("show_ball0");
        show_ball0->setGeometry(QRect(150, 250, 41, 31));
        QFont font;
        font.setBold(false);
        show_ball0->setFont(font);
        show_temp3 = new QTextBrowser(centralwidget);
        show_temp3->setObjectName("show_temp3");
        show_temp3->setGeometry(QRect(520, 210, 41, 31));
        QFont font1;
        font1.setBold(true);
        show_temp3->setFont(font1);
        show_temp4 = new QTextBrowser(centralwidget);
        show_temp4->setObjectName("show_temp4");
        show_temp4->setGeometry(QRect(570, 210, 41, 31));
        show_temp4->setFont(font1);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(690, 90, 41, 31));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(450, 10, 16, 31));
        show_current3 = new QTextBrowser(centralwidget);
        show_current3->setObjectName("show_current3");
        show_current3->setGeometry(QRect(300, 180, 41, 31));
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(690, 50, 41, 31));
        show_cap_voltage = new QTextBrowser(centralwidget);
        show_cap_voltage->setObjectName("show_cap_voltage");
        show_cap_voltage->setGeometry(QRect(610, 50, 71, 31));
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(370, 130, 51, 31));
        show_robot_theta = new QTextBrowser(centralwidget);
        show_robot_theta->setObjectName("show_robot_theta");
        show_robot_theta->setGeometry(QRect(420, 90, 71, 31));
        show_kickstate = new QTextBrowser(centralwidget);
        show_kickstate->setObjectName("show_kickstate");
        show_kickstate->setGeometry(QRect(420, 50, 71, 31));
        label_30 = new QLabel(centralwidget);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(370, 90, 51, 31));
        show_speedx = new QTextBrowser(centralwidget);
        show_speedx->setObjectName("show_speedx");
        show_speedx->setGeometry(QRect(610, 130, 71, 31));
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(500, 90, 41, 31));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(580, 10, 61, 31));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(550, 130, 51, 31));
        show_odomx = new QTextBrowser(centralwidget);
        show_odomx->setObjectName("show_odomx");
        show_odomx->setGeometry(QRect(420, 130, 71, 31));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(550, 90, 51, 31));
        show_current2 = new QTextBrowser(centralwidget);
        show_current2->setObjectName("show_current2");
        show_current2->setGeometry(QRect(250, 180, 41, 31));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(300, 10, 81, 31));
        show_temp2 = new QTextBrowser(centralwidget);
        show_temp2->setObjectName("show_temp2");
        show_temp2->setGeometry(QRect(470, 210, 41, 31));
        show_temp2->setFont(font1);
        show_ball1 = new QTextBrowser(centralwidget);
        show_ball1->setObjectName("show_ball1");
        show_ball1->setGeometry(QRect(200, 250, 41, 31));
        label_47 = new QLabel(centralwidget);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(150, 220, 21, 31));
        show_current0 = new QTextBrowser(centralwidget);
        show_current0->setObjectName("show_current0");
        show_current0->setGeometry(QRect(150, 180, 41, 31));
        show_current1 = new QTextBrowser(centralwidget);
        show_current1->setObjectName("show_current1");
        show_current1->setGeometry(QRect(200, 180, 41, 31));
        show_temp0 = new QTextBrowser(centralwidget);
        show_temp0->setObjectName("show_temp0");
        show_temp0->setGeometry(QRect(370, 210, 41, 31));
        show_temp0->setFont(font1);
        show_temp1 = new QTextBrowser(centralwidget);
        show_temp1->setObjectName("show_temp1");
        show_temp1->setGeometry(QRect(420, 210, 41, 31));
        show_temp1->setFont(font1);
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(370, 170, 51, 31));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(360, 50, 61, 31));
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(550, 170, 51, 31));
        show_robot_voltage = new QTextBrowser(centralwidget);
        show_robot_voltage->setObjectName("show_robot_voltage");
        show_robot_voltage->setGeometry(QRect(380, 10, 61, 31));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(340, 210, 41, 31));
        show_temp5 = new QTextBrowser(centralwidget);
        show_temp5->setObjectName("show_temp5");
        show_temp5->setGeometry(QRect(620, 210, 41, 31));
        show_temp5->setFont(font1);
        show_temp6 = new QTextBrowser(centralwidget);
        show_temp6->setObjectName("show_temp6");
        show_temp6->setGeometry(QRect(670, 210, 41, 31));
        show_temp6->setFont(font1);
        label_34 = new QLabel(centralwidget);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(150, 150, 51, 31));
        show_ball2 = new QTextBrowser(centralwidget);
        show_ball2->setObjectName("show_ball2");
        show_ball2->setGeometry(QRect(250, 250, 41, 31));
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(540, 50, 81, 31));
        show_odomy = new QTextBrowser(centralwidget);
        show_odomy->setObjectName("show_odomy");
        show_odomy->setGeometry(QRect(420, 170, 71, 31));
        show_robot_theta_diff = new QTextBrowser(centralwidget);
        show_robot_theta_diff->setObjectName("show_robot_theta_diff");
        show_robot_theta_diff->setGeometry(QRect(610, 90, 71, 31));
        label_38 = new QLabel(centralwidget);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(440, 250, 61, 31));
        show_error1 = new QTextBrowser(centralwidget);
        show_error1->setObjectName("show_error1");
        show_error1->setGeometry(QRect(500, 250, 61, 31));
        show_error2 = new QTextBrowser(centralwidget);
        show_error2->setObjectName("show_error2");
        show_error2->setGeometry(QRect(630, 250, 81, 31));
        data_from_robot = new QTextBrowser(centralwidget);
        data_from_robot->setObjectName("data_from_robot");
        data_from_robot->setGeometry(QRect(10, 60, 331, 81));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 140, 41, 31));
        show_error0 = new QTextBrowser(centralwidget);
        show_error0->setObjectName("show_error0");
        show_error0->setGeometry(QRect(390, 250, 41, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 40, 111, 21));
        log = new QTextBrowser(centralwidget);
        log->setObjectName("log");
        log->setGeometry(QRect(10, 170, 131, 111));
        setIP = new QSpinBox(centralwidget);
        setIP->setObjectName("setIP");
        setIP->setGeometry(QRect(240, 10, 51, 31));
        setIP->setMinimum(100);
        setIP->setMaximum(120);
        startbotton = new QPushButton(centralwidget);
        startbotton->setObjectName("startbotton");
        startbotton->setGeometry(QRect(10, 10, 111, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 111, 31));
        label_39 = new QLabel(centralwidget);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(560, 250, 71, 31));
        label_40 = new QLabel(centralwidget);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(350, 250, 41, 31));
        Robot_Voltage = new QProgressBar(centralwidget);
        Robot_Voltage->setObjectName("Robot_Voltage");
        Robot_Voltage->setGeometry(QRect(470, 10, 111, 31));
        Robot_Voltage->setValue(75);
        Robot_Voltage->setTextVisible(true);
        Robot_Voltage->setOrientation(Qt::Horizontal);
        Robot_Voltage->setInvertedAppearance(false);
        Robot_Voltage->setTextDirection(QProgressBar::TopToBottom);
        Qt_Robot_info->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Qt_Robot_info);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 714, 22));
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
        label_17->setText(QCoreApplication::translate("Qt_Robot_info", "deg", nullptr));
        label_20->setText(QCoreApplication::translate("Qt_Robot_info", "V", nullptr));
        label_28->setText(QCoreApplication::translate("Qt_Robot_info", "V", nullptr));
        label_23->setText(QCoreApplication::translate("Qt_Robot_info", "odom X", nullptr));
        label_30->setText(QCoreApplication::translate("Qt_Robot_info", "Robot \316\270", nullptr));
        label_31->setText(QCoreApplication::translate("Qt_Robot_info", "deg", nullptr));
        label_21->setText(QCoreApplication::translate("Qt_Robot_info", "Connection", nullptr));
        label_26->setText(QCoreApplication::translate("Qt_Robot_info", "speed X", nullptr));
        label_18->setText(QCoreApplication::translate("Qt_Robot_info", "diff_angle", nullptr));
        label_19->setText(QCoreApplication::translate("Qt_Robot_info", "Robot Voltage", nullptr));
        label_47->setText(QCoreApplication::translate("Qt_Robot_info", "Ball", nullptr));
        label_24->setText(QCoreApplication::translate("Qt_Robot_info", "odom Y", nullptr));
        label_22->setText(QCoreApplication::translate("Qt_Robot_info", "Kick state", nullptr));
        label_25->setText(QCoreApplication::translate("Qt_Robot_info", "speed Y", nullptr));
        label_27->setText(QCoreApplication::translate("Qt_Robot_info", "Temp", nullptr));
        label_34->setText(QCoreApplication::translate("Qt_Robot_info", "Current", nullptr));
        label_29->setText(QCoreApplication::translate("Qt_Robot_info", "Cap Voltage", nullptr));
        label_38->setText(QCoreApplication::translate("Qt_Robot_info", "Error  info", nullptr));
        label_6->setText(QCoreApplication::translate("Qt_Robot_info", "Log", nullptr));
        label_5->setText(QCoreApplication::translate("Qt_Robot_info", "Data from robot", nullptr));
        startbotton->setText(QCoreApplication::translate("Qt_Robot_info", "Start", nullptr));
        label->setText(QCoreApplication::translate("Qt_Robot_info", "Target IP: 192.168.20.", nullptr));
        label_39->setText(QCoreApplication::translate("Qt_Robot_info", " Error value", nullptr));
        label_40->setText(QCoreApplication::translate("Qt_Robot_info", "Error ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_Robot_info: public Ui_Qt_Robot_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_ROBOT_INFO_H
