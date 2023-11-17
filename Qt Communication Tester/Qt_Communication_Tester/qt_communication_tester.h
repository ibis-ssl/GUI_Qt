#ifndef QT_COMMUNICATION_TESTER_H
#define QT_COMMUNICATION_TESTER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Qt_Communication_Tester; }
QT_END_NAMESPACE

class Qt_Communication_Tester : public QMainWindow
{
    Q_OBJECT

public:
    Qt_Communication_Tester(QWidget *parent = nullptr);
    ~Qt_Communication_Tester();

private slots:
    void on_startbotton_clicked();

    void on_localEN_stateChanged(int arg1);

    void on_keeperEN_stateChanged(int arg1);

    void on_chipEN_stateChanged(int arg1);

    void on_setIP_textChanged(const QString &arg1);

private:
    Ui::Qt_Communication_Tester *ui;
};
#endif // QT_COMMUNICATION_TESTER_H
