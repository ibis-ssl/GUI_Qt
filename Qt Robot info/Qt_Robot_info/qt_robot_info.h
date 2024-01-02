#ifndef QT_ROBOT_INFO_H
#define QT_ROBOT_INFO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Qt_Robot_info; }
QT_END_NAMESPACE

class Qt_Robot_info : public QMainWindow
{
    Q_OBJECT

public:
    Qt_Robot_info(QWidget *parent = nullptr);
    ~Qt_Robot_info();

private:
    Ui::Qt_Robot_info *ui;
};
#endif // QT_ROBOT_INFO_H
