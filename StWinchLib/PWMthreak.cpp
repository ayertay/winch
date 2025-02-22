#include "PWMthread.h"
#include <QDebug>
#include <sys/time.h>
#include "gpiod.h"

extern struct gpiod_line *gpioline_BTN1;
extern struct gpiod_line *gpioline_BTN2;
#define IO_BTN1 18
#define IO_BTN2 22

extern int gLast_io_18;
extern int gLast_io_22;
extern int g_io_18;
extern int g_io_22;

struct timeval tv;
struct tm* st;
static double latest_time=0;

PWMThread::PWMThread()
{
    workCount = 0;
    is_Work   = false;
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
    g_io_22=gpiod_line_get_value(gpioline_BTN2);
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
    gLast_io_22 = g_io_22;
}

void PWMThread::run()
{
    while(true)
    {      
        CheckPWM();


        if( is_Work)
        {
            break;
        }

    }

    qDebug()<<"\n =============== PWMThread end!!!==============="<<workCount<<endl;
}
