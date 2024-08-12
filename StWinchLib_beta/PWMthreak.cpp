//PWMthread.cpp
//1. check PWM and IO input.
//

#include "PWMthread.h"
#include <QDebug>
#include <sys/time.h>
#include "gpiod.h"

extern struct gpiod_line *gpioline_BTN1;
extern struct gpiod_line *gpioline_BTN2;
extern struct gpiod_line *gpioline_BTN3;
extern struct gpiod_line *gpioline_BTN4;
#define IO_BTN1 18
#define IO_BTN2 22
#define IO_BTN3 3
#define IO_BTN4 2

extern int gLast_io_18;
extern int gLast_io_22;
extern int gLast_io_SCL;
extern int gLast_io_SDA;
extern int g_io_18;
extern int g_io_22;
extern int g_io_SCL;
extern int g_io_SDA;

extern int g_WinchZeroDetected;

struct timeval tv;
struct tm* st;
static double latest_time=0;

PWMThread::PWMThread()
{
    workCount = 0;
    is_Work   = false;

    gettimeofday(&tv_Begin, NULL);

    t_outPWM_H = tv.tv_usec;    //PWM start time
    t_outPWM_val = 5000;         //PWM set Val
    g_io_22 = 1;
}

__suseconds_t start_time=0;
__suseconds_t end_time=0;
__suseconds_t latest_start_time=0;
double pwm_duty=0;
double pwm_period=0;
void PWMThread::CheckPWM()
{
    /*
    //check IO button
    int val1=0;
    int val2=0;
    val1=gpiod_line_get_value(gpioline_BTN1);
    val2=gpiod_line_get_value(gpioline_BTN2);
    emit signal_ShowCurrentIO(IO_BTN1, val1);
    emit signal_ShowCurrentIO(IO_BTN2, val2);
    */

    //check IO button
    g_io_18=gpiod_line_get_value(gpioline_BTN1);
//    g_io_22=gpiod_line_get_value(gpioline_BTN2);
    g_io_SCL=gpiod_line_get_value(gpioline_BTN3);
    g_io_SDA=gpiod_line_get_value(gpioline_BTN4);

    /*
    if(gLast_io_18!=g_io_18)
    {
        emit signal_ShowCurrentIO(IO_BTN1, g_io_18);
    }
    if(gLast_io_22!=g_io_22)
    {
        emit signal_ShowCurrentIO(IO_BTN2, g_io_22);
    }
    */
    if(gLast_io_SCL!=g_io_SCL)
    {
        emit signal_ShowCurrentIO(IO_BTN3, g_io_SCL);
    }
    if(gLast_io_SDA!=g_io_SDA)
    {
        g_WinchZeroDetected = g_io_SDA;
        emit signal_ShowCurrentIO(IO_BTN4, g_io_SDA);
    }

    //check PWM
    if(gLast_io_18!=g_io_18)
    {
        if(g_io_18==1)
        {
            gettimeofday(&tv, NULL);
            start_time = tv.tv_usec;
            if(latest_start_time!=0)
            {
                pwm_duty = (end_time-latest_start_time);
                pwm_duty = pwm_duty/(start_time-latest_start_time)*100.0;
                pwm_period = 1000000.0/(start_time-latest_start_time);

                //qDebug() <<"start = "<< latest_start_time << "    stop = " << end_time << "   new_start = "<< start_time;
                //qDebug() <<"duty = "<< duty <<"% ";
                //qDebug() <<"period = "<< period <<"Hz \r\n";
            }
        }
        if(g_io_18==0)
        {
            gettimeofday(&tv, NULL);
            end_time = tv.tv_usec;
            latest_start_time = start_time;
            //qDebug()<<"plus time = "<<(end_time-start_time)<<"   ";
        }

    }

    gLast_io_18 = g_io_18;
//    gLast_io_22 = g_io_22;
    gLast_io_SCL = g_io_SCL;
    gLast_io_SDA = g_io_SDA;
}

void PWMThread::SetPWM(int pwmVal)
{
    t_outPWM_val = pwmVal;
}

long long t = 0;
int m_g_io_22 = 1;
double dDuration = 0;
void PWMThread::MakePWM()
{
    //make PWM(50Hz)
    gettimeofday(&tv, NULL);
    dDuration = 1000000.0*(tv.tv_sec-tv_Begin.tv_sec) + (tv.tv_usec-tv_Begin.tv_usec);
    //dDuration = (tv.tv_usec-tv_Begin.tv_usec)/1000.0;
    t = dDuration;
    //qDebug()<<"Duration_time = "<< t << "     tv=" << dDuration;
    if((t>=t_outPWM_val)&&(m_g_io_22==1))   //one period
    {
        m_g_io_22 = 0;
        gpiod_line_set_value(gpioline_BTN2, 0);
    }

    //qDebug()<<"current_time = "<< t << "     tv=" << tv.tv_usec << "     tH=" << t_outPWM_H;
    if((t>=20000)&&(m_g_io_22==0))   //one period
    {
        m_g_io_22 = 1;
        gpiod_line_set_value(gpioline_BTN2, 1);
        //gettimeofday(&tv_Begin, NULL);
        tv_Begin = tv;
    }
}

void PWMThread::run()
{
    qDebug()<<"\n =============== PWMThread start!!!==============="<<endl;
    while(true)
    {      
        CheckPWM();
        MakePWM();

        if( is_Work)
        {
            break;
        }

    }

    qDebug()<<"\n =============== PWMThread end!!!==============="<<endl;
}
