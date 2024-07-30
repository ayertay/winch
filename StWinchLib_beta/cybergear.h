#ifndef CYBERGEAR_H
#define CYBERGEAR_H

#include <QObject>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

union IntFloat
{
    int   i;
    float f;
};

enum MOTOR_MODE{MODE_NORM,MODE_RESET,MODE_DELIVERY,MODE_RETRACT,MODE_STOP,MODE_HOLD_LINE};

class CyberGear : public QObject
{
    Q_OBJECT
public:
    explicit CyberGear(QObject *parent = nullptr);
    ~CyberGear();

public:
    union IntFloat a;
    struct can_frame frame;
    //struct can_frame frameRx;
    int s, nbytes;

    int   motor_ID;
    float m_aimPos;
    float m_aimSpeed;
    float m_mechPos;
    float m_torque_fdb;
    int   m_MotorMode;  //work mode
    int   g_Ground_check_Cnt;
    int   m_retract_cnt;
    int   m_DataAutoDump;
    int   m_MotorStop;

    int     m_echo;
    float   m_line_length;

    void Init();
    void motor_can_tx(int mode, int data2);
    int  motor_can_rx();
    int Motor_Init(int can_id);
    int Motor_Realse();
    int Motor_SetZero();
    int Motor_SetMode(int mode);
    int Motor_Enable();
    int Motor_Disenable();
    int Motor_Speed(float spd);
    int Motor_limit_spd(float spd);
    int Motor_limit_cur(float cur);
    int Motor_limit_torque(float cur);
    int Motor_Move(float pos);
    int Motor_Stop();
    int Motor_DataAutoDump(int i_onoff);

    int  Motor_Read_mechPos();
    void motor_Decode();
    void Motor_Mode(int mode);
    int  Motor_Read_Mode();

    float Motor_GetPos();
    float Motor_GetTorque();

    void  Led_Set(int idx_group, int clr);

signals:

};

#endif // CYBERGEAR_H
