#include "workthread.h"
#include <QDebug>
//#include <Python.h>
//#include "cDroneKit.h"
//#include <wiringPi.h>
#include <sys/time.h>
#include "gpiod.h"

extern float g_Current_WinchPos;
extern float g_Current_WinchTorque;

WorkThread::WorkThread()
{
    status_intever_time=5;
    ledtimeCount=0;
    workCount = 0;
    is_Work   = false;

    b_Winch_Ready = false;
    bEnableWinchTest = false;

    bEnableSCTest = false;

    led1_1=1;
    led1_2=1;
    led2_1=1;
    led2_2=1;
    //connect(this, SIGNAL(SignalgetStatusReady(char*,int)), this, SLOT(showUAVStatus(char*,int)));
}

void WorkThread::SetCyberGearObject(CyberGear* p)
{
    pCyberGear = p;
}

/*
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
__suseconds_t start_time=0;
__suseconds_t end_time=0;
__suseconds_t latest_start_time=0;
double pwm_duty=0;
double pwm_period=0;
void WorkThread::CheckPWM()
{
    //check IO button
    g_io_18=gpiod_line_get_value(gpioline_BTN1);
    g_io_22=gpiod_line_get_value(gpioline_BTN2);

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
*/

void WorkThread::run()
{
    //LedProcessing();
    while(true)
    {      

        ///*
        //can data read from winch.
        pCyberGear->motor_can_rx();
        QThread::msleep(20);

        workCount++;
        if(workCount>=10)
        {
            workCount=0;
            g_Current_WinchPos = pCyberGear->Motor_GetPos();
            g_Current_WinchTorque = pCyberGear->Motor_GetTorque();
            emit signal_ShowCurrentWinchPos();
        }
        //*/

        //CheckPWM();


        if( is_Work)
        {
            break;
        }

    }

    qDebug()<<"\n =============== WorkThread end!!!==============="<<workCount<<endl;
}

void WorkThread::SetWinchReady(bool bState)
{
    b_Winch_Ready=bState;
}
void WorkThread::EnableWinchTest(bool bState)
{
    bEnableWinchTest = bState;
}

void WorkThread::EnableSCTest(bool bState)
{
    bEnableSCTest = bState;
}

void WorkThread::WinchTest()
{
    /*
    int pos=0;
    if(!b_Winch_Ready)
        return;
    //Winch Down
    qDebug()<<"Winch Down....\n"<<workCount<<endl;
    pos = -2650;
    emit signal_Winch_SetPos(pos, 4000 ,500 );
    while( g_Current_WinchPos!=pos )
    {
        delay(1000);
        emit signal_Winch_ReadPos();
    }
    pos = -2750;
    emit signal_Winch_SetPos(pos, 0 ,0 );
    while( g_Current_WinchPos!=pos )
    {
        delay(1000);
        emit signal_Winch_ReadPos();
    }
    delay(5000);

    //Winch Up
    qDebug()<<"Winch Up....\n"<<workCount<<endl;
    pos = -500;
    emit signal_Winch_SetPos(pos, 4000 ,500 );
    while( g_Current_WinchPos<=pos )
    {
        delay(1000);
        emit signal_Winch_ReadPos();
    }
    pos = 0;
    emit signal_Winch_SetPos(pos, 0 ,0 );
    while( g_Current_WinchPos!=pos )
    {
        delay(1000);
        emit signal_Winch_ReadPos();
    }
    delay(5000);
    */
}
//===================================================
void WorkThread::LedProcessing()
{
    //========================================
    if(is_Work)
    {
        if(ledtimeCount==flash_intever_time)
        {
            ledtimeCount = 0;
        }

    }
    //========================================
}

void WorkThread::ThreadProcessing()
{
    if(iWrite>0)
    {
        return;
    }
/*
    if(DroneKit_pModule!=0)
    {

        int  len=0;
        memset(sStatus, 0, 1000);

        if( 0==DroneKit_GetStatus(DroneKit_pModule, sStatus, &len) )
        {
            QString s(sStatus);
            SignalPostUAVStatus(s);

        }
    }
*/
    //========================================

}

int WorkThread::showUAVStatus(char*,int)
{
    return 0;
}

void WorkThread::SetiWrite(int i)
{
    iWrite = i;
}

void WorkThread::SetDroneId(QString id)
{
    m_droneId = id;
    //sID.sprintf("DroneID=%d,", m_droneId);
}

void WorkThread::SetLed(int idx,int v)
{
    switch (idx)
    {
    case 1:
        led1_1 = v;
        break;
    case 2:
        led1_2 = v;
        break;
    case 3:
        led2_1 = v;
        break;
    case 4:
        led2_2 = v;
        break;
    };
}
void WorkThread::SetLedFlashTime(int t)
{
    ledtimeCount=0;
    flash_intever_time = t;
}

void WorkThread::EnableLedFlash(bool b)
{
    workCount=0;
    is_Work = b;
}

void WorkThread::SetStatusTime(int t)
{
    if(t<1)
    {
        t=1;
    }
    status_intever_time = t;
}

void WorkThread::StopWork()
{
    is_Work = false;
}
