#include "stwinchlib.h"
#include "coreuav.h"

extern float g_Current_WinchPos;
extern float g_Current_WinchTorque;
extern int g_Current_SCPos;

int gLast_io_18=0;
int gLast_io_22=0;
int g_io_18=0;
int g_io_22=0;
int g_io_SCL=0;
int g_io_SDA=0;
int gLast_io_SCL=0;
int gLast_io_SDA=0;

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
    //mCore.init(motor_id);
    mCore.init();
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
    mCore.WINCH_RELAXED();
}

void WINCH_RELATIVE_LENGTH_CONTROL(float distance, float speed)
{
    mCore.WINCH_RELATIVE_LENGTH_CONTROL(distance, speed);
}

void WINCH_RATE_CONTROL(float speed)
{
    mCore.WINCH_RATE_CONTROL(speed);
}

void WINCH_LOCK()
{
    mCore.WINCH_LOCK();
}

void WINCH_DELIVER(float distance, float speed)
{
    //Delivery
    mCore.WINCH_DELIVER(distance, speed);
}

void WINCH_HOLD()
{
    mCore.WINCH_HOLD();
}

void WINCH_RETRACT(float speed)
{
    mCore.WINCH_RETRACT(speed);
}

void WINCH_LOAD_LINE()
{
    mCore.WINCH_LOAD_LINE();
}

void WINCH_ABANDON_LINE()
{
    mCore.WINCH_ABANDON_LINE();
}

void WINCH_LATCH_LOCK()
{
    mCore.WINCH_LATCH_LOCK();
}

void WINCH_LATCH_UNLOCK()
{
    mCore.WINCH_LATCH_UNLOCK();
}
