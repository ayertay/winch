#include "cybergear.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <QDebug>
#include <QSettings>
#include <QTime>

#define MAIN_CAN_ID  254
#define SYS_CAN_ID   253
//#define motor_ID 0x03

#define DEBUG_MODE 1

const int MOTOR_CONTROL = 1;
const int MOTOR_FEEDBACK = 2;
const int MOTOR_ENABLE = 3;
const int MOTOR_STOP = 4;
const int SET_MECHANICAL_ZERO = 6;
const int SINGLE_PARAM_READ = 17;
const int SINGLE_PARAM_WRITE = 18;

int gLast_WinchZeroDetected = -1;
int g_WinchZeroDetected = 1;
int g_WinchLoadUPandLock=0;
int g_WINCH_DELIVER=0;

CyberGear::CyberGear(QObject *parent)
    : QObject{parent}
{
    motor_ID =1;
    m_torque_fdb = 0.0;
    m_DataAutoDump = 0;
    m_MotorStop = 1;
    m_line_length = 0.0;

    m_echo = 1;
}

CyberGear::~CyberGear()
{
    ;
}

void CyberGear::Init()
{
    ;
}

void CyberGear::motor_can_tx(int mode, int data2)
{
    frame.can_id = CAN_EFF_FLAG | (mode<<24) | (data2<<8) | motor_ID;
    frame.can_dlc = 8;

    /*
    printf("can_id  = 0x%X\r\n", frame.can_id);
    printf("can_dlc = %d\r\n", frame.can_dlc);
    int i = 0;
    for(i = 0; i < 8; i++)
        printf("data[%d] = %02X\r\n", i, frame.data[i]);
    */
    //6.Send message
    //printf("6.Send message\r\n");
    nbytes = write(s, &frame, sizeof(frame));
    if(nbytes != sizeof(frame)) {
        //printf("Send Error frame[0]!\r\n");
        system("sudo ifconfig can0 down");
    }

}

#pragma pack(1)
union c_2_f
{
    float f;
    char  buf[4];
};
union c_2_double
{
    double f;
    long int l;
    char  buf[8];
};

float fabs(float v)
{
    if(v<0.0)
        return -1*v;
    else
        return v;
}

double g_f[50]={0.0};
double d_Sum=0.0;
int    i_Cnt;
double GetAverage(double f)
{
    double dRet=0.0;
    d_Sum = 0.0;
    i_Cnt=0;
    for(int i=29;i>0;--i)
    {
        g_f[i] = g_f[i-1];
        d_Sum = d_Sum+g_f[i];
        i_Cnt++;
    }
    g_f[0] = f;
    d_Sum = d_Sum+f;
    i_Cnt++;
    dRet = d_Sum/i_Cnt;
    return  dRet;

}

static struct can_frame frameRx;
//struct msghdr frameRx;
int CyberGear::motor_can_rx()
{
    //frame.can_id = CAN_EFF_FLAG | (mode<<24) | (data2<<8) | motor_ID;
    //frame.can_dlc = 8;

    int i = 0;
    //6.Read message
    //printf("6.Read message\r\n");
    nbytes = read(s, &frameRx, sizeof(frameRx));
    if(nbytes<=0 )
    {
        return -1;
    }
    //

    while(nbytes>0)
    {
        nbytes = read(s, &frameRx, sizeof(frameRx));

        //qDebug()<< "can id = " << QString("%1").arg(frameRx.can_id, 8 , 16, QLatin1Char('0'));

        QByteArray buf;
        c_2_f s_f;
        c_2_f s_mechPos;
        c_2_f s_torque_fdb;

        buf.clear();
        buf.resize(sizeof(frameRx.data));
        switch(frameRx.can_id&0x7FFFFCFF)
        {
        case 0x110100FE:    //0x110103FE
        {
            motor_Decode();
            memcpy(buf.data(), frameRx.data, 8);

            s_f.buf[0] = frameRx.data[4];
            s_f.buf[1] = frameRx.data[5];
            s_f.buf[2] = frameRx.data[6];
            s_f.buf[3] = frameRx.data[7];

#ifdef  DEBUG_MODE
            QTime ttt=QTime::currentTime();
            qDebug()<< ttt.toString("hh::mm::ss.zzz") << " "<< buf.toHex(' ') << "  "<<s_f.f;
#endif

            break;
        }
        case 0x0A0200FD:    //0x0A0203FD
        {
            /*
            c_2_f sd;
            sd.l = frameRx.data[7];
            sd.l = sd.l<<8 + frameRx.data[6];
            sd.l = sd.l<<8 + frameRx.data[5];
            sd.l = sd.l<<8 + frameRx.data[4];
            sd.l = sd.l<<8 + frameRx.data[3];
            sd.l = sd.l<<8 + frameRx.data[2];
            sd.l = sd.l<<8 + frameRx.data[1];
            sd.l = sd.l<<8 + frameRx.data[0];

            buf.resize(sizeof(frameRx.data));
            memcpy(buf.data(), frameRx.data, 8);

            QTime t1=QTime::currentTime();
            qDebug()<< t1.toString("hh::mm::ss.zzz") << " "<< buf.toHex(' ') << "  "<<sd.f;
            */

            s_mechPos.buf[0] = frameRx.data[2];
            s_mechPos.buf[1] = frameRx.data[3];
            s_mechPos.buf[2] = frameRx.data[4];
            s_mechPos.buf[3] = frameRx.data[5];
            m_mechPos = s_mechPos.f;

            /*
            if(m_aimSpeed<m_aimPos/10)
            {
                m_aimSpeed=m_aimSpeed+0.1;
                m_aimSpeed(m_aimSpeed);
            }
            */

/*
            if(fabs(m_aimPos-m_mechPos)<2)
            {
                if(m_aimSpeed!=1)
                    Motor_Speed(1);
            }
            else if(fabs(m_aimPos-m_mechPos)<5)
            {
                if(m_aimSpeed!=2)
                    Motor_Speed(2);
            }
            else if(fabs(m_aimPos-m_mechPos)<10)
            {
                if(m_aimSpeed!=3)
                    Motor_Speed(3);
            }
            else if(fabs(m_aimPos-m_mechPos)<20)
            {
                if(m_aimSpeed!=5)
                    Motor_Speed(5);
            }
*/
            break;
        }

        case 0x0A1200FD:    //0x0A1203FD
        {
            memcpy(buf.data(), frameRx.data, 8);
            s_torque_fdb.buf[0] = frameRx.data[0];
            s_torque_fdb.buf[1] = frameRx.data[1];
            s_torque_fdb.buf[2] = frameRx.data[2];
            s_torque_fdb.buf[3] = frameRx.data[3];
            //if(fabs(s_torque_fdb.f)>0.00001)
            {
                m_torque_fdb = s_torque_fdb.f*0.05+m_torque_fdb*0.95;
            }
            //m_torque_fdb = s_torque_fdb.f;
            /*
            if(s_torque_fdb.f>0.0001)
            {
                m_torque_fdb = GetAverage(s_torque_fdb.f);
            }
            */

            if(g_WinchZeroDetected==0)
            {
                if(m_MotorMode==MODE_HOLD_LINE)
                {
                    m_line_length = fabs(m_mechPos);
                    //save to configfile
                    //config file init
                    QSettings *config;
                    QString path=QStringLiteral("/home/uav/APP/UAV_run/config.ini");
                    config = new QSettings (path,QSettings::IniFormat, nullptr);
                    config->beginGroup("WINCH");
                    config->setValue("TIE_LEN", QString::number(m_line_length, 'f', 4));
                    config->sync();
                    config->endGroup();
                    delete config;
                }
                //motor stop
                m_MotorMode = MODE_STOP;
            }

            /*
            if(g_WinchZeroDetected==0)
            {
                m_MotorMode = MODE_NORM;
                //if((m_MotorMode == MODE_NORM)&&(gLast_WinchZeroDetected!=g_WinchZeroDetected))
                //if(m_aimPos<m_mechPos)
                {
                    Motor_Move(m_mechPos);
                    //Motor_Stop();
                    m_torque_fdb = 0.0;
                    Motor_SetZero();
                    Motor_Enable();

                    gLast_WinchZeroDetected = g_WinchZeroDetected;

                }
                return 0;
            }
            else
            {
                gLast_WinchZeroDetected = g_WinchZeroDetected;
            }*/

            switch(m_MotorMode)
            {
                case MOTOR_MODE::MODE_STOP:
                {
                    if(m_MotorStop==0)
                    {
                        Motor_Move(m_mechPos);
                        sleep(0.05);
                        Motor_Stop();sleep(0.05);
                        Motor_SetZero();sleep(0.05);
                        m_torque_fdb = 0.0;
                        Motor_Enable();sleep(0.05);
                        Motor_Speed(20);sleep(0.05);
                        m_MotorStop = 1;
                    }
                    break;
                }
                case MOTOR_MODE::MODE_NORM:
                {
                    m_MotorStop = 0;
                    break;
                }
                case MOTOR_MODE::MODE_RESET:
                {  
                    m_MotorStop = 0;
                    if(fabs(m_torque_fdb)>0.3)
                    {
                        Motor_Move(m_mechPos);
                        Motor_Stop();
                        m_torque_fdb = 0.0;
                        m_MotorMode = MODE_NORM;
                        Motor_SetZero();
                        Motor_Enable();
                    }
                    break;
                }
                /*
                case MOTOR_MODE::MODE_LOADUP:
                {
                    if(g_WinchZeroDetected==0)
                    {
                        Motor_Move(m_mechPos);
                        Motor_Stop();
                        m_torque_fdb = 0.0;
                        m_MotorMode = MODE_NORM;
                        Motor_SetZero();
                        Motor_Enable();

                        gLast_WinchZeroDetected = g_WinchZeroDetected;

                    }
                    break;
                }
                */
                case MOTOR_MODE::MODE_DELIVERY:
                {
                    m_MotorStop = 0;
                    //
                    if((m_aimPos-m_mechPos)<10)
                    {
                        if(fabs(m_torque_fdb)<0.08)
                        {
                            g_Ground_check_Cnt++;       //30ms/cnt
                            printf("checker ", g_Ground_check_Cnt);
                            if(g_Ground_check_Cnt>30)
                            {
                                Motor_Move(m_mechPos+3);
                                m_torque_fdb = 0.0;
                                //m_MotorMode = MODE_NORM;
                                //m_aimPos=0;
                                sleep(3);
                                m_MotorMode = MODE_RETRACT;
                                Motor_Move(0);

                                g_Ground_check_Cnt=0;
                            }
                        }
                        else
                        {
                            Motor_Move(m_mechPos+11);
                            g_Ground_check_Cnt=0;
                        }
                    }


                    break;
                }
                case MOTOR_MODE::MODE_HOLD_LINE:
                case MOTOR_MODE::MODE_RETRACT:
                {
                    m_MotorStop = 0;

                    if((m_mechPos-m_aimPos)<10)
                    {
                        if(m_aimSpeed>5)
                        {
                            Motor_Speed(5);
                        }
                        if(fabs(m_torque_fdb)>0.3)
                        {
                            Motor_Move(m_mechPos);
                            Motor_Stop();
                            m_torque_fdb = 0.0;
                            m_MotorMode = MODE_NORM;
                            Motor_SetZero();
                            Motor_Enable();
                        }
                    }
                    else if((m_mechPos-m_aimPos)<30)
                    {
                        if(m_aimSpeed>10)
                        {
                            Motor_Speed(10);
                        }
                    }
                    else if((m_mechPos-m_aimPos)<50)
                    {
                        if(m_aimSpeed>20)
                        {
                            Motor_Speed(20);
                        }
                    }
                    else
                    {
                        if(fabs(m_torque_fdb)>0.8)
                        {
                            //if(m_retract_cnt>4)
                            {
                                Motor_Move(m_mechPos);
                                sleep(0.5);
                                Motor_Stop();
                                m_torque_fdb = 0.0;
                                m_MotorMode = MODE_NORM;
                                //Motor_SetZero();
                                //Motor_Enable();
                            }
                            /*
                            else
                            {
                                m_MotorMode = MODE_DELIVERY;
                                m_retract_cnt++;
                            }
                            */
                        }
                        /*
                        else
                        {
                            if(fabs(m_torque_fdb)>0.2)
                            {
                                m_MotorMode = MODE_DELIVERY;
                                m_retract_cnt++;
                            }
                        }
                        */
                    }

                    break;
                }
            }

#ifdef  DEBUG_MODE
        if(m_echo)
        {
            QTime ttt=QTime::currentTime();
            //qDebug()<< ttt.toString("hh::mm::ss.zzz") << " "<< buf.toHex(' ') << "  "<<s_f.f;
            qDebug()<< ttt.toString("hh::mm::ss.zzz") << " "<< buf.toHex(' ') <<" "<< "  aimPos="<< QString::number(m_aimPos,'f',4)<< "  mechPos="<< QString::number(s_mechPos.f,'f',4)<< "  m_torque="<< QString::number(m_torque_fdb,'f',4)<< "  s_torque_fdb="<< QString::number(s_torque_fdb.f,'f',4);
        }
#endif
            break;
        }
        }
    }


    /*
    qDebug()<<"id="<<frame.can_id;
    for(i = 0; i < 8; i++)
        //printf("data[%d] = %02X ", i, frameRx.data[i]);
        qDebug()<<" "<< frameRx.data[i];
    */
    /*
    printf("id=%08X", frame.can_id);
    for(i = 0; i < 8; i++)
        printf("data[%d] = %02X ", i, frameRx.data[i]);
    printf("\r\n");
    */

    return 0;
}

float CyberGear::Motor_GetPos()
{
    return m_mechPos;
}
float CyberGear::Motor_GetTorque()
{
    return m_torque_fdb;
}

void CyberGear::motor_Decode()
{
    //m_Angle = frameRx.data[0]<<;
}

int CyberGear::Motor_Init(int can_id)
{
    int ret;

    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_filter rfilter[2];
    memset(&frame, 0, sizeof(struct can_frame));

    system("sudo ip link set can0 type can bitrate 1000000");
    system("sudo ifconfig can0 up");
    //printf("this is a can send demo\r\n");

    //1.Create socket
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (s < 0) {
        perror("socket PF_CAN failed");
        return 1;
    }
    //printf("1.Create socket OK\r\n");

    //2.Specify can0 device
    strcpy(ifr.ifr_name, "can0");
    ret = ioctl(s, SIOCGIFINDEX, &ifr);
    if (ret < 0) {
        perror("ioctl failed");
        return 1;
    }
    //printf("2.Specify can0 device\r\n");

    //3.Bind the socket to can0
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    ret = bind(s, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("bind failed");
        return 1;
    }
    //printf("3.Bind the socket to can0\r\n");

    //4.Disable filtering rules, do not receive packets, only send
    //setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
    //printf("4.Disable filtering rules, do not receive packets, only send\r\n");
    motor_ID = can_id;
    rfilter[0].can_id = 0x110100FE|(motor_ID<<8);
    rfilter[0].can_mask = CAN_SFF_MASK;
    rfilter[1].can_id = 0x0A0200FD|(motor_ID<<8);
    rfilter[1].can_mask = CAN_SFF_MASK;
    fcntl(s, F_SETFL, FNDELAY);
    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter[0], sizeof(rfilter[0]));
    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter[1], sizeof(rfilter[1]));

    return 0;
}

int CyberGear::Motor_Realse()
{
    //7.Close the socket and can0
    if(s>0)
    {
        close(s);
    }
    //printf("7.Close the socket and can0\r\n");
    //system("sudo ifconfig can0 down");

    return 0;
}

int CyberGear::Motor_SetMode(int mode)
{
    frame.data[0] = 0x05;
    frame.data[1] = 0x70;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = mode&0xFF;
    frame.data[5] = 0;
    frame.data[6] = 0;
    frame.data[7] = 0;
    motor_can_tx(SINGLE_PARAM_WRITE, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_Enable()
{
    frame.data[0] = 0;
    frame.data[1] = 0;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = 0;
    frame.data[5] = 0;
    frame.data[6] = 0;
    frame.data[7] = 0;
    motor_can_tx(MOTOR_ENABLE, MAIN_CAN_ID);

    return 0;
}

int CyberGear::Motor_Disenable()
{
    frame.data[0] = 0;
    frame.data[1] = 0;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = 0;
    frame.data[5] = 0;
    frame.data[6] = 0;
    frame.data[7] = 0;
    motor_can_tx(MOTOR_ENABLE, MAIN_CAN_ID);

    return 0;
}

int CyberGear::Motor_Speed(float spd)
{
    a.f = spd;
    m_aimSpeed = spd;
    frame.data[0] = 0x17;
    frame.data[1] = 0x70;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = (a.i&0xFF);
    frame.data[5] = (a.i>>8)&0xFF;
    frame.data[6] = (a.i>>16)&0xFF;
    frame.data[7] = (a.i>>24)&0xFF;
    motor_can_tx(SINGLE_PARAM_WRITE, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_limit_spd(float spd)
{
    a.f = spd;
    frame.data[0] = 0x17;
    frame.data[1] = 0x70;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = (a.i&0xFF);
    frame.data[5] = (a.i>>8)&0xFF;
    frame.data[6] = (a.i>>16)&0xFF;
    frame.data[7] = (a.i>>24)&0xFF;
    motor_can_tx(SINGLE_PARAM_WRITE, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_limit_cur(float cur)
{
    a.f = cur;
    frame.data[0] = 0x18;
    frame.data[1] = 0x70;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = (a.i&0xFF);
    frame.data[5] = (a.i>>8)&0xFF;
    frame.data[6] = (a.i>>16)&0xFF;
    frame.data[7] = (a.i>>24)&0xFF;
    motor_can_tx(SINGLE_PARAM_WRITE, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_limit_torque(float val)
{
    a.f = val;
    frame.data[0] = 0x0B;
    frame.data[1] = 0x70;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = (a.i&0xFF);
    frame.data[5] = (a.i>>8)&0xFF;
    frame.data[6] = (a.i>>16)&0xFF;
    frame.data[7] = (a.i>>24)&0xFF;
    motor_can_tx(SINGLE_PARAM_WRITE, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_SetZero()
{
    frame.data[0] = 1;
    frame.data[1] = 0;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = 0;
    frame.data[5] = 0;
    frame.data[6] = 0;
    frame.data[7] = 0;
    motor_can_tx(SET_MECHANICAL_ZERO, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_Move(float pos)
{
    float loc_ref = pos;
    m_aimPos=pos;
    a.f = loc_ref;
    frame.data[0] = 0x16;
    frame.data[1] = 0x70;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = (a.i&0xFF);
    frame.data[5] = (a.i>>8)&0xFF;
    frame.data[6] = (a.i>>16)&0xFF;
    frame.data[7] = (a.i>>24)&0xFF;
    motor_can_tx(SINGLE_PARAM_WRITE, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_Stop()
{
    frame.data[0] = 0;
    frame.data[1] = 0;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = 0;
    frame.data[5] = 0;
    frame.data[6] = 0;
    frame.data[7] = 0;
    motor_can_tx(MOTOR_STOP, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_Read_mechPos()
{
    frame.data[0] = 0x19;
    frame.data[1] = 0x70;
    frame.data[2] = 0;
    frame.data[3] = 0;
    frame.data[4] = 0;
    frame.data[5] = 0;
    frame.data[6] = 0;
    frame.data[7] = 0;
    motor_can_tx(SINGLE_PARAM_READ, MAIN_CAN_ID);
    return 0;
}

int CyberGear::Motor_DataAutoDump(int i_onoff)
{
    frame.can_dlc = 8;
    if(1==i_onoff)
    {
        frame.data[0] = 0x64;
        frame.data[1] = 0x00;
        frame.data[2] = 0x11;
        frame.data[3] = 0x00;
        frame.data[4] = 0x00;
        frame.data[5] = 0x10;
        frame.data[6] = 0x0E;
        frame.data[7] = 0X00;
        //motor_can_tx(SINGLE_PARAM_WRITE, 0X0000|SYS_CAN_ID);
        frame.can_id = CAN_EFF_FLAG | 0x0A00FD01 | motor_ID;;
        frame.can_dlc = 8;
        nbytes = write(s, &frame, sizeof(frame));

        sleep(0.2);

        frame.data[0] = 0x16;
        frame.data[1] = 0x30;
        frame.data[2] = 0x0A;
        frame.data[3] = 0x20;
        frame.data[4] = 0x0A;
        frame.data[5] = 0x20;
        frame.data[6] = 0x2D;
        frame.data[7] = 0X30;
        //motor_can_tx(SINGLE_PARAM_WRITE, 0X0100|SYS_CAN_ID);
        frame.can_id = CAN_EFF_FLAG | 0x0A31FD01 | motor_ID;;
        frame.can_dlc = 8;
        nbytes = write(s, &frame, sizeof(frame));
        sleep(0.2);

        frame.data[0] = 0x00;
        frame.data[1] = 0x00;
        frame.data[2] = 0x00;
        frame.data[3] = 0x00;
        frame.data[4] = 0x00;
        frame.data[5] = 0x00;
        frame.data[6] = 0x00;
        frame.data[7] = 0X00;
        //motor_can_tx(SINGLE_PARAM_WRITE, 0X0200|SYS_CAN_ID);
        frame.can_id = CAN_EFF_FLAG | 0x0A02FD01 | motor_ID;;
        frame.can_dlc = 8;
        nbytes = write(s, &frame, sizeof(frame));
    }
    else
    {
        frame.data[0] = 0x00;
        frame.data[1] = 0x00;
        frame.data[2] = 0x00;
        frame.data[3] = 0x00;
        frame.data[4] = 0x00;
        frame.data[5] = 0x00;
        frame.data[6] = 0x00;
        frame.data[7] = 0X00;
        //motor_can_tx(SINGLE_PARAM_WRITE, 0X0300|SYS_CAN_ID);
        frame.can_id = CAN_EFF_FLAG | 0x0A03FD01 | motor_ID;;
        frame.can_dlc = 8;
        nbytes = write(s, &frame, sizeof(frame));
    }

    m_DataAutoDump = i_onoff;

    return 0;
}

void CyberGear::Motor_Mode(int mode)
{
    m_MotorMode = mode;
}

int CyberGear::Motor_Read_Mode()
{
    return m_MotorMode;
}
