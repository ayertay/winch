#ifndef STWINCHLIB_H
#define STWINCHLIB_H

#include "StWinchLib_global.h"

class STWINCHLIB_EXPORT StWinchLib
{
public:
    StWinchLib();
};

extern "C"
{
    STWINCHLIB_EXPORT int  add(int a, int b);

    STWINCHLIB_EXPORT int  WinchCoreRun(int isRun);
    STWINCHLIB_EXPORT void WinchReset();
    STWINCHLIB_EXPORT void WinchDelivery(int spd);

    STWINCHLIB_EXPORT void WinchSetSpeed(int spd);
    STWINCHLIB_EXPORT void WinchSetPos(int iSpeed,int iDistance);
    STWINCHLIB_EXPORT void WinchLoad();
    STWINCHLIB_EXPORT void WinchLoadUP();

    STWINCHLIB_EXPORT float WinchGetPos();
    STWINCHLIB_EXPORT float WinchGetTorque();
    STWINCHLIB_EXPORT float WinchGetPWMDuty();
    STWINCHLIB_EXPORT float WinchGetPWMPeriod();

    //the new API is add at 2024-06-19
    STWINCHLIB_EXPORT void WINCH_RELAXED();
    STWINCHLIB_EXPORT void WINCH_RELATIVE_LENGTH_CONTROL(float distance, float speed);
    STWINCHLIB_EXPORT void WINCH_RATE_CONTROL(float speed);
    STWINCHLIB_EXPORT void WINCH_LOCK();
    STWINCHLIB_EXPORT void WINCH_DELIVER(float distance, float speed);
    STWINCHLIB_EXPORT void WINCH_HOLD();
    STWINCHLIB_EXPORT void WINCH_RETRACT(float speed);
    STWINCHLIB_EXPORT void WINCH_LOAD_LINE();
    STWINCHLIB_EXPORT void WINCH_ABANDON_LINE();

    //the extra API
    STWINCHLIB_EXPORT void WINCH_LATCH_LOCK();
    STWINCHLIB_EXPORT void WINCH_LATCH_UNLOCK();
    STWINCHLIB_EXPORT float WINCH_LINE_LENGTH();
    STWINCHLIB_EXPORT void  WINCH_CAN_ECHO(int isEnable);
}

#endif // STWINCHLIB_H
