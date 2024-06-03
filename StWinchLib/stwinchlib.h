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

}

#endif // STWINCHLIB_H
