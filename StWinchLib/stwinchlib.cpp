#include "stwinchlib.h"
#include "coreuav.h"

extern float g_Current_WinchPos;
extern float g_Current_WinchTorque;
extern int g_Current_SCPos;

int gLast_io_18=0;
int gLast_io_22=0;
int g_io_18=0;
int g_io_22=0;

extern double pwm_duty;
extern double pwm_period;

CoreUAV mCore;

StWinchLib::StWinchLib()
{
}

int add(int a, int b)
{
    return a+b;
}

int WinchCoreRun(int motor_id)
{
    mCore.init(motor_id);
    mCore.run();
    return 0;
}

void WinchReset()
{
    //reset
    mCore.WinchReset();
}

void WinchDelivery(int spd)
{
    //Delivery
    mCore.WinchDelivery(spd);
}

void WinchSetSpeed(int spd)
{
    mCore.mCyberGear.Motor_Speed(spd);
}

void WinchSetPos(int iSpeed,int iDistance)
{
    mCore.mCyberGear.Motor_Enable();
    mCore.mCyberGear.Motor_Speed(iSpeed);
    mCore.mCyberGear.Motor_Move(iDistance);
}

void WinchLoad()
{
    //Load
    mCore.WinchLoad();
}

void WinchLoadUP()
{
    //Load up
    mCore.WinchLoadUP();
}

float WinchGetPos()
{
    return g_Current_WinchPos;
}

float WinchGetTorque()
{
    return g_Current_WinchTorque;
}

float WinchGetPWMDuty()
{
    float fRet=pwm_duty;
    return fRet;
}

float WinchGetPWMPeriod()
{
    float fRet=pwm_period;
    return fRet;
}


//==========================
//the new API is as fllow

void WINCH_RELAXED()
{
    mCore.WinchLoad();
}

void WINCH_RELATIVE_LENGTH_CONTROL()
{
    ;
}

void WINCH_RATE_CONTROL()
{
    ;
}

void WINCH_LOCK()
{
    ;
}

void WINCH_DELIVER(int spd)
{
    //Delivery
    mCore.WinchDelivery(spd);
}

void WINCH_HOLD()
{
    ;
}

void WINCH_RETRACT()
{
    ;
}

void WINCH_HOLD_LINE()
{
    ;
}
