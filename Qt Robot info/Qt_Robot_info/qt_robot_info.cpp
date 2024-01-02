#include "qt_robot_info.h"
#include "ui_qt_robot_info.h"

Qt_Robot_info::Qt_Robot_info(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_Robot_info)
{
    ui->setupUi(this);
}

Qt_Robot_info::~Qt_Robot_info()
{
    delete ui;
}


void Qt_Robot_info::readMsg(QNetworkDatagram datagram){

    QByteArray data = datagram.data();
    int len = data.size();

    uint8_t rec_data[len];
    std::memcpy(rec_data ,data.data(),len);

    tx_msg_t rx_data;
    Data data_convert;

    switch (rec_data[2]) {
    case 10:
        ring_counter = rec_data[3];
        data_convert.b[0]=rec_data[4];
        data_convert.b[1]=rec_data[5];
        data_convert.b[2]=rec_data[6];
        data_convert.b[3]=rec_data[7];
        rx_data.data.yaw_angle=data_convert.f;
        data_convert.b[0]=rec_data[8];
        data_convert.b[1]=rec_data[9];
        data_convert.b[2]=rec_data[10];
        data_convert.b[3]=rec_data[11];
        rx_data.data.diff_angle=data_convert.f;
        rx_data.data.ball_detection[0]=rec_data[12];
        rx_data.data.ball_detection[1]=rec_data[13];
        rx_data.data.ball_detection[2]=rec_data[14];
        rx_data.data.ball_detection[3]=rec_data[15];

        char str4[6];
        sprintf(str4,"%d",ring_counter);
        ui->show_connection->setText(str4);
        char str2[6];
        sprintf(str2,"%4.2f",(float)rx_data.data.yaw_angle);
        ui->show_robot_theta->setText(str2);
        char str_2[6];
        sprintf(str_2,"%4.2f",(float)rx_data.data.diff_angle);
        ui->show_robot_theta_diff->setText(str_2);
        char str_ball0[6];
        sprintf(str_ball0,"%d",rx_data.data.ball_detection[0]);
        ui->show_ball0->setText(str_ball0);
        char str_ball1[6];
        sprintf(str_ball1,"%d",rx_data.data.ball_detection[1]);
        ui->show_ball1->setText(str_ball1);
        char str_ball2[6];
        sprintf(str_ball2,"%d",rx_data.data.ball_detection[2]);
        ui->show_ball2->setText(str_ball2);
        char str_ball3[6];
        sprintf(str_ball3,"%d",rx_data.data.ball_detection[3]);
        ui->show_ball3->setText(str_ball3);

        break;
    case 11:
        rx_data.data.error_info[0]=rec_data[4];
        rx_data.data.error_info[1]=rec_data[5];
        rx_data.data.error_info[2]=rec_data[6];
        rx_data.data.error_info[3]=rec_data[7];
        rx_data.data.error_info[4]=rec_data[8];
        rx_data.data.error_info[5]=rec_data[9];
        rx_data.data.error_info[6]=rec_data[10];
        rx_data.data.error_info[7]=rec_data[11];
        rx_data.data.motor_current[0]=rec_data[12];
        rx_data.data.motor_current[1]=rec_data[13];
        rx_data.data.motor_current[2]=rec_data[14];
        rx_data.data.motor_current[3]=rec_data[15];

        char str_error0[6];
        sprintf(str_error0,"%d",rx_data.data.error_info[0]);
        ui->show_error0->setText(str_error0);
        char str_error1[6];
        sprintf(str_error1,"%d",rx_data.data.error_info[1]);
        ui->show_error1->setText(str_error1);
        char str_error2[6];
        sprintf(str_error2,"%d",rx_data.data.error_info[2]);
        ui->show_error2->setText(str_error2);
        char str_error3[6];
        sprintf(str_error3,"%d",rx_data.data.error_info[3]);
        ui->show_error3->setText(str_error3);
        char str_error4[6];
        sprintf(str_error4,"%d",rx_data.data.error_info[4]);
        ui->show_error4->setText(str_error4);
        char str_error5[6];
        sprintf(str_error5,"%d",rx_data.data.error_info[5]);
        ui->show_error5->setText(str_error5);
        char str_error6[6];
        sprintf(str_error6,"%d",rx_data.data.error_info[6]);
        ui->show_error6->setText(str_error6);
        char str_error7[6];
        sprintf(str_error7,"%d",rx_data.data.error_info[7]);
        ui->show_error7->setText(str_error7);
        char str_current0[6];
        sprintf(str_current0,"%d",rx_data.data.motor_current[0]);
        ui->show_current0->setText(str_current0);
        char str_current1[6];
        sprintf(str_current1,"%d",rx_data.data.motor_current[1]);
        ui->show_current1->setText(str_current1);
        char str_current2[6];
        sprintf(str_current2,"%d",rx_data.data.motor_current[2]);
        ui->show_current2->setText(str_current2);
        char str_current3[6];
        sprintf(str_current3,"%d",rx_data.data.motor_current[3]);
        ui->show_current3->setText(str_current3);

        break;
    case 12:
        rx_data.data.kick_state=rec_data[4]*10;
        rx_data.data.temperature[0]=rec_data[5];
        rx_data.data.temperature[1]=rec_data[6];
        rx_data.data.temperature[2]=rec_data[7];
        rx_data.data.temperature[3]=rec_data[8];
        rx_data.data.temperature[4]=rec_data[9];
        rx_data.data.temperature[5]=rec_data[10];
        rx_data.data.temperature[6]=rec_data[11];
        data_convert.b[0]=rec_data[12];
        data_convert.b[1]=rec_data[13];
        data_convert.b[2]=rec_data[14];
        data_convert.b[3]=rec_data[15];
        rx_data.data.voltage[0]=data_convert.f;

        char str5[6];
        sprintf(str5,"%d",rx_data.data.kick_state);
        ui->show_kickstate->setText(str5);
        char str_temp0[6];
        sprintf(str_temp0,"%d",rx_data.data.temperature[0]);
        ui->show_temp0->setText(str_temp0);
        char str_temp1[6];
        sprintf(str_temp1,"%d",rx_data.data.temperature[1]);
        ui->show_temp1->setText(str_temp1);
        char str_temp2[6];
        sprintf(str_temp2,"%d",rx_data.data.temperature[2]);
        ui->show_temp2->setText(str_temp2);
        char str_temp3[6];
        sprintf(str_temp3,"%d",rx_data.data.temperature[3]);
        ui->show_temp3->setText(str_temp3);
        char str_temp4[6];
        sprintf(str_temp4,"%d",rx_data.data.temperature[4]);
        ui->show_temp4->setText(str_temp4);
        char str_temp5[6];
        sprintf(str_temp5,"%d",rx_data.data.temperature[5]);
        ui->show_temp5->setText(str_temp5);
        char str_temp6[6];
        sprintf(str_temp6,"%d",rx_data.data.temperature[6]);
        ui->show_temp6->setText(str_temp6);
        char str3[6];
        sprintf(str3,"%4.2f",rx_data.data.voltage[0]);
        ui->show_robot_voltage->setText(str3);

        break;
    case 13:
        data_convert.b[0]=rec_data[4];
        data_convert.b[1]=rec_data[5];
        data_convert.b[2]=rec_data[6];
        data_convert.b[3]=rec_data[7];
        rx_data.data.voltage[1]=data_convert.f;
        data_convert.b[0]=rec_data[8];
        data_convert.b[1]=rec_data[9];
        data_convert.b[2]=rec_data[10];
        data_convert.b[3]=rec_data[11];
        rx_data.data.odom[0]=data_convert.f * 1000;
        data_convert.b[0]=rec_data[12];
        data_convert.b[1]=rec_data[13];
        data_convert.b[2]=rec_data[14];
        data_convert.b[3]=rec_data[15];
        rx_data.data.odom[1]=data_convert.f * 1000;

        char str6[6];
        sprintf(str6,"%4.2f",rx_data.data.voltage[1]);
        ui->show_cap_voltage->setText(str6);
        char str7[6];
        sprintf(str7,"%4.2f",rx_data.data.odom[0]);
        ui->show_odomx->setText(str7);
        char str8[6];
        sprintf(str8,"%4.2f",rx_data.data.odom[1]);
        ui->show_odomy->setText(str8);
        break;
    case 14:
        ring_counter_callback=rec_data[3];
        data_convert.b[0]=rec_data[4];
        data_convert.b[1]=rec_data[5];
        data_convert.b[2]=rec_data[6];
        data_convert.b[3]=rec_data[7];
        rx_data.data.odom_speed[0]=data_convert.f;
        data_convert.b[0]=rec_data[8];
        data_convert.b[1]=rec_data[9];
        data_convert.b[2]=rec_data[10];
        data_convert.b[3]=rec_data[11];
        rx_data.data.odom_speed[1]=data_convert.f;

        char str9[6];
        sprintf(str9,"%4.2f",rx_data.data.odom_speed[0]);
        ui->show_speedx->setText(str9);
        char str10[6];
        sprintf(str10,"%4.2f",rx_data.data.odom_speed[1]);
        ui->show_speedy->setText(str10);
        break;
    default:
        break;
    }

    char str[400];
    sprintf(str,"data_len=%d [0]=%3d [1]=%3d [2]=%3d [3]=%3d \n [4]=%x  [5]=%x  [6]=%x [7]=%x \n [8]=%x [9]=%x [10]=%x [11]=%x \n [12]=%x [13]=%x [14]=%x [15]=%x",
            len,rec_data[0],rec_data[1],rec_data[2],rec_data[3],rec_data [4],rec_data [5],rec_data [6],rec_data [7],rec_data [8],rec_data [9],rec_data [10]
            ,rec_data [11],rec_data [12],rec_data [13],rec_data [14],rec_data [15]);
    ui->data_from_robot->setText(str);



}
