#include "workthread.h"
#include <QDebug>
//#include <Python.h>
//#include "cDroneKit.h"
#include <wiringPi.h>
//#define printf qDebug

//extern void timerProcessing();
//extern void ThreadProcessing();

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

void WorkThread::run()
{
    //LedProcessing();
    while(true)
    {      

        //QThread::sleep(1);

        //pCyberGear->Motor_Read_mechPos();
        //QThread::msleep(20);
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

        /*
        workCount++;
        if(workCount>=1000) workCount=0;
            qDebug()<<"\nWorkThread===================="<<workCount<<endl;

        try
        {

            if(workCount%status_intever_time==0)
                ThreadProcessing();

        }
        catch(...)
        {
            qDebug()<<"\n error!  WorkThread exception!!!==============="<<workCount<<endl;
        }

        //
        if(bEnableWinchTest)
        {
            WinchTest();
        }
        if(bEnableSCTest)
        {
            //emit signal_SC_AutoTest();
        }
        QThread::sleep(5);
        */

        /*
        if(flash_intever_time>0)
        {
            LedProcessing();
        }
        QThread::sleep(1);
        //delay(500);
        ledtimeCount++;
        */


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
}
//===================================================
void WorkThread::LedProcessing()
{
    //========================================
    if(is_Work)
    {
        if(ledtimeCount==flash_intever_time)
        {
            //emit ChangeLed();
/*
            digitalWrite(26,led1_1);
            digitalWrite(27,led1_2);
            digitalWrite(28,led2_1);
            digitalWrite(29,led2_2);
            delay(500);
            digitalWrite(26,HIGH);
            digitalWrite(27,HIGH);
            digitalWrite(28,HIGH);
            digitalWrite(29,HIGH);
*/

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
