#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include <QObject>
#include "cybergear.h"

class WorkThread : public QThread
{
Q_OBJECT
public:
    WorkThread();
private:
    QString     m_droneId;
    //QString sID;
    virtual void run();//任务处理线程

    int led1_1,led1_2,led2_1,led2_2;
public:
    CyberGear*      pCyberGear;
    void SetCyberGearObject(CyberGear* p);

    int   status_intever_time;
    int   flash_intever_time;
    bool  is_Work;

    char sStatus[1000];
    int  workCount;//计数
    int  ledtimeCount;
    void ThreadProcessing();

    bool bEnableWinchTest;
    bool b_Winch_Ready;
    void WinchTest();
    void SetWinchReady(bool bState);
    void EnableWinchTest(bool bState);

    bool bEnableSCTest;
    void EnableSCTest(bool bState);
    //===================
    void LedProcessing();
    int  iWrite;
    void SetiWrite(int i);
    void SetDroneId(QString id);

    //====================
    void SetLed(int idx,int v);
    void SetLedFlashTime(int t);
    void EnableLedFlash(bool b);

    //====================
    void SetStatusTime(int t);  //status feedback intever time
    void StopWork();

    //====================
    void CheckPWM();
signals:
    int  SignalgetStatusReady(char*,int);
    void SignalPostUAVStatus(QString s);
    void signal_Winch_SetPos(int alt,int v,int v_acc);
    void signal_Winch_ReadPos();
    void signal_ShowCurrentSCPos();
    void signal_ShowCurrentWinchPos();
    void signal_ShowCurrentIO(int io_idx,int v);

    void signal_SC_AutoTest();

public slots:
    int showUAVStatus(char*,int);
};

#endif // WORKTHREAD_H
