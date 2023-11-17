#include "qt_communication_tester.h"
#include "ui_qt_communication_tester.h"

Qt_Communication_Tester::Qt_Communication_Tester(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_Communication_Tester)
{
    ui->setupUi(this);
}

Qt_Communication_Tester::~Qt_Communication_Tester()
{
    delete ui;
}


void Qt_Communication_Tester::on_startbotton_clicked()
{

}


void Qt_Communication_Tester::on_localEN_stateChanged(int arg1)
{

}


void Qt_Communication_Tester::on_keeperEN_stateChanged(int arg1)
{

}


void Qt_Communication_Tester::on_chipEN_stateChanged(int arg1)
{

}


void Qt_Communication_Tester::on_setIP_textChanged(const QString &arg1)
{

}

