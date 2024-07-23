#ifndef COREUAV_H
#define COREUAV_H

#include "cybergear.h"
#include "ctomotorserial.h"
#include "chook_heltec.h"
#include "workthread.h"
#include "PWMthread.h"
#include "mymqtt.h"
//#include <Python.h>
#include <QObject>
#include <QFile>
#include <QMutex>
#include <QTimerEvent>
#include <QTimer>
#include <QDateTime>
#include <QSettings>
#include <QSerialPort>
#include "ScsServLib//SCServo.h"

#define T_u8  unsigned char
#define T_u16 unsigned int
#define BYTE unsigned char

class CoreUAV : public QObject
{
    Q_OBJECT
public:
    explicit CoreUAV(QObject *parent = 0);
    ~CoreUAV();
public:
    WorkThread *p_taskWork;
    PWMThread  *p_pwmThread;
    myMqtt     *p_myMqtt;

    //winch
    CTomotorSerial mWinchTomotor;
    CyberGear      mCyberGear;
    int            m_WinchLocked;

    //Hook
    CHook_Heltec   mHook;

    //SC
    SCSCL       *p_sc;
    int         mID_SC;
    bool        bSCPortRet;
    bool        bEnableSCTest;

    //
    QSettings *config;

    //ip,port
    QString g_sSERVER_IP;
    int     g_SERVER_PORT;
    bool    g_sub=false;
    //mqtt
    //=================
    QString gMqttPath;
    QString MQTT_SUB_FROM;
    QString MQTT_SUB_TO;
    QString MQTT_PUB_WINCH;
    QString MQTT_PUB_SC;

    QString MQTT_SUB_CTRL;
    QString MQTT_SUB_MODE;
    QString MQTT_SUB_TRACK;
    QString MQTT_SUB_PARM;
    QString MQTT_SUB_LED;
    QString MQTT_SUB_WINCH;
    QString MQTT_SUB_STATUSTIME;
    QString MQTT_PUB_STATUS;

    QString MQTT_SUB_SC;
    //=================
    //int     g_ID_Device;
    //int     g_ID_Service;
    QString gs_ID_Service;
    QString gs_ID_Device;
    int     g_Time_Status;      //time for plane status message update to server
    int     g_LedInited;

    //=================
    QTimer *update_time;
    QDateTime beginTime;

    //数据处理
    //===================================================
    void DeleteStrSpace(QString &str, int len);
    void AsciiToHexBuff(const QString str, BYTE buffer[],int* len);

    //log处理
    //===================================================
    QFile log_file;
    int  CreateLog();
    void WriteToLog(const QString msg);
    int  CloseLog();

    //Err
    void postErrMsg(QString s);

    //===================================================
    void TRACE(char* sMsg);

    //解码从服务器接收到的数据
    //===================================================
    int  TxToHttpServer(QString pub, QString msg);
    int  TxBuffToHttpServer(char buff[], int len);
    void DecodeServerCmd(unsigned char* rxbuff_stream, int rxLen_stream);

    //
    void TxCmdToWinch();

    //===================================================
    unsigned char TxBuf[2000];

    //===================================================
    int init();
    int run();
    int stop();
public:
    //flight led set functions:
    int  Led_Init();
    void Led_Set(int idx_group, int clr);
    void Led_ON(bool isFlash);
    void Led_OFF();
    void Led_SetFlash(int intervel);

    int  GPIO_Init();
    void GPIO_Releae();

    bool OpenComPort(QSerialPort *_Port, QString _portName, qint32 _baud,QSerialPort::DataBits _databits,QSerialPort::StopBits _stopbits,QSerialPort::Parity _parity);
signals:
    int  SendSignalPostRequest(char* host, char* path, char* buff, int len);
    void signal_ShowCurrentWinchPos();
    void signal_AddLogInEdit(QString s);
    void signal_ShowCurrentSCPos();
    void signal_SC_AutoTest();
    void signal_SC_WritePos(int id, int pos, int time, int spd);
    void signal_NetStatus(int);
    void signal_ShowCurrentIO(int io_idx,int v);
    void signal_ShowPWM();
public slots:
    int  PostUAVStatus(char* sStatus, int len);
    int  OnPostUAVStatus(QString sStatus);  

    //Winch
    void On_Winch_SetPos(int alt,int v,int v_acc, int torque, int isbrake);    
    void StartWincTest();
    void StopWincTest();

    void WinchDataDump(int i_onoff);
    void WinchReset();
    void WinchDelivery(float speed);
    void WinchDeliveryEx(float distance, float speed);
    void WinchRetract(float speed);
    void WinchLoad();
    void WinchLoadUP();
    void WinchLoadUPandLock();

    void WinchLock();
    void WinchUnlock();

    //the new API is add at 2024-06-19
    void WINCH_RELAXED();
    void WINCH_RELATIVE_LENGTH_CONTROL(float distance, float speed);
    void WINCH_RATE_CONTROL(float speed);
    void WINCH_LOCK();
    void WINCH_DELIVER(float distance, float speed);
    void WINCH_HOLD();
    void WINCH_RETRACT(float speed);
    void WINCH_LOAD_LINE();
    void WINCH_ABANDON_LINE();

    //Hook
    /*
    void readHookData(void);
    void Hook_Open();
    void Hook_Close();
    void Hook_PwmSet(int lora_addr, int pwm);
    */

    //SC15
    void SC_StartAutoTest();
    void SC_StopAutoTest();
    void On_SC_SetPos(int ID, int Position, int Time, int Speed);

    //TIMER
    //===================================================
    void time_update();
    void On_SubMsg(QString sTopic, QString message);
};

#endif // COREUAV_H
