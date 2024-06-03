#include "coreuav.h"
//#include "cDroneKit.h"
//#include "StStreamKit.h"
//#include "cDroneKit.h"

#include "ctomotorserial.h"
#include "cybergear.h"
#include <QSettings>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <QJsonObject>
#include <QJsonDocument>

QString   G_PLAN_ID = "0001";
char *g_SERVER_IP;

int   g_Current_SCPos = 0;
float g_Current_WinchPos = 0.0;
float g_Current_WinchTorque = 0.0;

//hook lora address
const int HOOK_LORA_ADDR=1;

CoreUAV::CoreUAV(QObject *parent) : QObject(parent)
{

    g_SERVER_PORT=1884;
    gMqttPath = "arcuas";
    g_LedInited = -1;

    //Careate WorkThread
    p_taskWork = new WorkThread;
    p_taskWork->SetDroneId(G_PLAN_ID);

    //Careate  mptt
    p_myMqtt = new myMqtt;

    //config file init
    QString path=QStringLiteral("/home/uav/APP/UAV_run/config.ini");
    config = new QSettings (path,QSettings::IniFormat, nullptr);

    //Winch init
    //p_WinchPort = new QSerialPort();

}

CoreUAV::~CoreUAV()
{
    //delete p_WinchPort;
    delete config;

    p_taskWork->terminate();
}

int CoreUAV::init()
{

    QVariant v;
    //Get config information from config.ini
    // IP,port,plane ID
    config->beginGroup("SERVER");
    v=config->value("IP", "api.arcuas.io");
    g_sSERVER_IP = v.toString();
    qDebug()<< "g_sSERVER_IP=" << (g_sSERVER_IP);
    QByteArray ba2;
    ba2.append(g_sSERVER_IP);
    g_SERVER_IP = ba2.data();

    v=config->value("PORT", "1884");
    g_SERVER_PORT=v.toInt();
    v=config->value("ID_COMPANY", "0");
    gs_ID_Service=v.toString();

    //g_ID_Service =v.toInt();
    v=config->value("ID_PLANE", G_PLAN_ID);
    gs_ID_Device=v.toString();
    //g_ID_Device =v.toInt();

    v=config->value("TIME_STATUS_SEC", "10");
    g_Time_Status=v.toInt();

    config->endGroup();

    MQTT_SUB_FROM    = gMqttPath+"/from/drone/"+gs_ID_Device+"/";
    MQTT_SUB_TO      = gMqttPath+"/to/drone/"+gs_ID_Device+"/";
    MQTT_SUB_WINCH   = MQTT_SUB_TO+"winch";
    MQTT_PUB_WINCH   = MQTT_SUB_FROM+"winch";

    MQTT_SUB_SC      = MQTT_SUB_TO+"sc";
    MQTT_PUB_SC      = MQTT_SUB_FROM+"sc";

    /*
    MQTT_SUB_MODE    = gMqttPath+"/mode";
    MQTT_SUB_PARM    = gMqttPath+"/parm";
    MQTT_SUB_LED     = gMqttPath+"/led";
    MQTT_SUB_WINCH   = gMqttPath+"/winch";
    MQTT_SUB_TRACK   = gMqttPath+"/track";
    MQTT_SUB_STATUSTIME= gMqttPath+"/status_time";
    MQTT_PUB_STATUS  = gMqttPath+"/status";
    */

    //
    //p_taskWork->SetDroneId(gs_ID_Device);
    //p_taskWork->SetStatusTime(g_Time_Status);

    CreateLog();

    connect(p_myMqtt,SIGNAL(signal_SubMsg(QString,QString)),this,SLOT(On_SubMsg(QString,QString)));

    //connect(p_taskWork, SIGNAL(SignalgetStatusReady(char*,int)), this, SLOT(PostUAVStatus(char*,int)));
    //connect(p_taskWork, SIGNAL(SignalPostUAVStatus(QString)), this, SLOT(OnPostUAVStatus(QString)));
    //connect(p_taskWork,SIGNAL(signal_Winch_SetPos(int,int,int)),this,SLOT(On_Winch_SetPos(int,int,int)));
    //connect(p_taskWork,SIGNAL(signal_Winch_ReadPos()),this,SLOT(Winch_ReadPos()));
    //connect(p_taskWork,SIGNAL(signal_SC_SetPos(int,int,int,int)),this,SLOT(On_SC_SetPos(i20nt,int,int)));
    //connect(p_taskWork,SIGNAL(signal_SC_AutoTest()),this,SLOT(On_SC_AutoTest()));


    //Open Hook Port
    //mHook.Init("/dev/ttyUSB1", HOOK_LORA_ADDR);

    //CyberGear can init
    mCyberGear.Motor_Init(0x3);delay(0.1);
    mCyberGear.Motor_SetZero();delay(0.1);
    mCyberGear.Motor_Move(0);delay(0.1);
    mCyberGear.Motor_SetMode(1);delay(0.1);
    mCyberGear.Motor_Enable();delay(0.1);
    //mCyberGear.Motor_limit_cur(0.5);delay(0.1);  
    delay(0.2);
    //mCyberGear.Motor_DataAutoDump(1);
    //WinchDataDump(1);
    //delay(0.5);
    p_taskWork->SetCyberGearObject(&mCyberGear);

    //Led_Init();

    return 0;
}

int CoreUAV::stop()
{
    mCyberGear.Motor_Stop();
    mCyberGear.Motor_Realse();

    //p_taskWork->StopWork();
    //p_taskWork->terminate();

    WinchDataDump(0);
}
int CoreUAV::run()
{
    int ret=0;

    //mqtt init
    p_myMqtt->setObjectName("sin_UAV_SC"+G_PLAN_ID);
    p_myMqtt->setClientHost(g_sSERVER_IP);
    p_myMqtt->setClientPort(g_SERVER_PORT);
    p_myMqtt->setClientUserName("arcuas");
    p_myMqtt->setClientPassword("arcuas");
//    p_myMqtt->setClientUserName("admin");
//    p_myMqtt->setClientPassword("SINTEKadsb123");
    p_myMqtt->connected();
    delay(200);


    {
        {
            QThread::sleep(2);

            qDebug()<<"work线程测试开始:";
            //p_taskWork->SetWinchReady(bWinchPortRet);
            p_taskWork->start();
        }
    }

    ///定时器
    update_time = new QTimer();
    connect(update_time,SIGNAL(timeout()),this,SLOT(time_update()));
    update_time->start(1000);
    beginTime = QDateTime::currentDateTime();

    return ret;
}

//初始化串口
bool CoreUAV::OpenComPort(QSerialPort *_Port, QString _portName, qint32 _baud,QSerialPort::DataBits _databits,QSerialPort::StopBits _stopbits,QSerialPort::Parity _parity)
{
    _Port->setPortName(_portName);
    _Port->close();
    if(_Port->open(QIODevice::ReadWrite))
    {
        _Port->setBaudRate(_baud,QSerialPort::AllDirections);
        _Port->setDataBits(_databits);
        _Port->setFlowControl(QSerialPort::NoFlowControl);
        _Port->setParity(_parity);
        _Port->setStopBits(_stopbits);

        return true;
    }

    return false;
}

static T_u8 CalcCheckSum(T_u8 *buf, int start, int len)
{
    T_u8  r=0;
    int sum=0;
    int i;
    for(i=0;i<len;i++)
    {
        sum+=buf[start+i];
    }
    r = (sum&0xFF);
    return r;
}

void CoreUAV::On_Winch_SetPos(int alt,int v,int v_acc, int torque, int isbrake)
{
    mWinchTomotor.Winch_SetPos(alt, v, v_acc, torque, isbrake);
}

void CoreUAV::StartWincTest()
{
    p_taskWork->EnableWinchTest(true);
}
void CoreUAV::StopWincTest()
{
    p_taskWork->EnableWinchTest(false);
}

void CoreUAV::TRACE(char* sMsg)
{
//    printf(sMsg);
//    fflush(stdout);
}

//数据处理
//===================================================
void CoreUAV::DeleteStrSpace(QString &str, int len)
{
    QString stemp="";

    for (int i=0;i!=len;++i)
    {
        if (str.mid(i,1)!=" ")
        {
            stemp=stemp+str.mid(i,1);
        }
    }
    str = stemp;
}

void CoreUAV::AsciiToHexBuff(const QString str, BYTE buffer[],int* len)
{
    int i=0;
    for (i=0;i!=(str.length()/2);++i)
    {
        sscanf((str.mid(i*2,2)).toStdString().c_str(),"%x",&buffer[i]);
    }
    *len=i;
}


//log处理
//===================================================
int  CoreUAV::CreateLog()
{
    int iRet=0;
    QString sFileName;
    QDateTime datetime;
    QString timestr=datetime.currentDateTime().toString("_yyyy_MM_dd");
    sFileName = "/home/pi/APP/log/log" + timestr + ".txt";
    qDebug() << sFileName;
    try
    {

        log_file.setFileName(sFileName);
        if(log_file.open(QIODevice::WriteOnly | QIODevice::Append ))
        {
            iRet=1;
            WriteToLog("\n ====================  TASK START ===========================");
        }
        else
        {
            iRet=0;
        };


    } catch (...)
    {
        printf("write log Error!");
        TRACE("write log Error!");
    }

    return iRet;
}

int  CoreUAV::CloseLog()
{
    log_file.close();
}

void CoreUAV::WriteToLog(const QString msg)
{
    static QMutex mutex_log;
    mutex_log.lock();

    //QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2").arg(current_date).arg(msg);

    if(log_file.isOpen())
    {
        //QFile file("log.txt");
        //file.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream text_stream(&log_file);
        text_stream << message << "\r\n";
        log_file.flush();
        //file.close();
    }

    mutex_log.unlock();
}
//===================================================


int  CoreUAV::TxBuffToHttpServer(char buff[], int len)
{
    int iRet=0;
    //emit SendSignalPostRequest(g_SERVER_IP, "/send/data", buff, len);

    return iRet;
}


void CoreUAV::postErrMsg(QString sLog)
{
    //TRACE is fail
    //sLog.sprintf("DroneID=%d, MsgID=%d, tType=CMD_TRACE, result=FAIL", droneId, msgId);
    QByteArray sFeedBack = sLog.toLocal8Bit();
    TxBuffToHttpServer((char*)sFeedBack.data(), sLog.length());
    WriteToLog( sLog );  //===log===
    return;
}
//解码从服务器接收到的数据
//===================================================
void CoreUAV::DecodeServerCmd(unsigned char* rxbuff_stream, int rxLen_stream)
{

}


int CoreUAV::PostUAVStatus(char* sStatus, int len)
{
    /*
    int   TxLen=0;
    STS_Stream_GetOutBufLen(len, &TxLen);
    memset(TxBuf, 0, TxLen);
    STS_GenStream(G_PLAN_ID, 0, 0, (unsigned char*)sStatus, len, TxBuf);
    */

    //HTTP发送
/*
    TxBuffToHttpServer((char*)TxBuf, TxLen);

    //2022-01-16日修改为mqtt发送
    QString str;
    str=QString(QLatin1String(sStatus));

    //写入日志
    sStatus[len] = 0;
    WriteToLog(sStatus);
*/
    return 0;
}

int CoreUAV::TxToHttpServer(QString pub, QString msg)
{
    if(p_myMqtt->IsConneted())
    {
        p_myMqtt->setPublish(pub, msg, 2);
    }

    return 0;
}
int CoreUAV::OnPostUAVStatus(QString sStatus)
{
    //2022-01-16日修改为mqtt发送
    TxToHttpServer(MQTT_PUB_STATUS, sStatus);

    //写入日志
    WriteToLog(sStatus);

    return 0;
}


//GROUP1
int led1_1,led1_2,led2_1,led2_2;
int CoreUAV::Led_Init()
{
    int iRet=0;
    iRet = wiringPiSetup();
    qDebug() << "wiringPiSetup = " << iRet;
    if(iRet==0)
    {
        /*
        pinMode(26,OUTPUT);
        pinMode(27,OUTPUT);
        pinMode(28,OUTPUT);
        pinMode(29,OUTPUT);

        delay(200);

        digitalWrite(26,HIGH);
        digitalWrite(27,HIGH);
        digitalWrite(28,HIGH);
        digitalWrite(29,HIGH);

        WriteToLog("Led Inited OK!");
        */
        pinMode(1,OUTPUT);
        delay(200);
        digitalWrite(1,HIGH);
    }
    return iRet;
}

void CoreUAV::Led_Set(int idx_group, int clr)
{
/*
    switch(idx_group)
    {
    case 1:
        switch(clr)
        {
        case 1:         //WHITE
            led1_1 = LOW;
            led1_2 = LOW;
            digitalWrite(26,led1_1);
            digitalWrite(27,led1_2);

            p_taskWork->SetLed(1, led1_1);
            p_taskWork->SetLed(2, led1_2);
            break;
        case 2:         //RED
            led1_1 = HIGH;
            led1_2 = LOW;
            digitalWrite(26,led1_1);
            digitalWrite(27,led1_2);

            p_taskWork->SetLed(1, led1_1);
            p_taskWork->SetLed(2, led1_2);
            break;
        case 3:         //GREEN
            led1_1 = LOW;
            led1_2 = HIGH;
            digitalWrite(26,led1_1);
            digitalWrite(27,led1_2);

            p_taskWork->SetLed(1, led1_1);
            p_taskWork->SetLed(2, led1_2);
            break;
        }
        break;
    case 2:
        switch(clr)
        {
        case 1:
            led2_1 = LOW;
            led2_2 = LOW;
            digitalWrite(28,led2_1);
            digitalWrite(29,led2_2);

            p_taskWork->SetLed(3, led2_1);
            p_taskWork->SetLed(4, led2_2);
            break;
        case 2:
            led2_1 = LOW;
            led2_2 = HIGH;
            digitalWrite(28,led2_1);
            digitalWrite(29,led2_2);

            p_taskWork->SetLed(3, led2_1);
            p_taskWork->SetLed(4, led2_2);
            break;
        case 3:
            led2_1 = HIGH;
            led2_2 = LOW;
            digitalWrite(28,led2_1);
            digitalWrite(29,led2_2);

            p_taskWork->SetLed(3, led2_1);
            p_taskWork->SetLed(4, led2_2);
            break;
        }
        break;
    }
*/
}

void CoreUAV::Led_ON(bool isFlash)
{
/*
    if(isFlash)
    {
        p_taskWork->EnableLedFlash(true);
    }
*/
}

void CoreUAV::Led_OFF()
{
/*
    p_taskWork->EnableLedFlash(false);

    led1_1 = HIGH;
    led1_2 = HIGH;
    digitalWrite(26,led1_1);
    digitalWrite(27,led1_2);

    p_taskWork->SetLed(1, led1_1);
    p_taskWork->SetLed(2, led1_2);

    led2_1 = HIGH;
    led2_2 = HIGH;
    digitalWrite(28,led2_1);
    digitalWrite(29,led2_2);

    p_taskWork->SetLed(3, led2_1);
    p_taskWork->SetLed(4, led2_2);
*/
}

void CoreUAV::Led_SetFlash(int intervel)
{
//    p_taskWork->SetLedFlashTime(intervel);
}

void CoreUAV::TxCmdToWinch()
{
    ;
}

int m_Current_Pos = 0;
int g_v = 100;
int m_Step = 10;
int iMsgCnt=0;
bool lastNet=false;
void CoreUAV::time_update()
{
    QString sLog;
    bool b=false;
    QString s_current_time,s_run_time;

    QString msg_status;
    static int process_idx=0;

    if(mCyberGear.m_DataAutoDump==FALSE)
    {
        mCyberGear.Motor_DataAutoDump(1);
    }

    /*
    g_Current_WinchPos = mCyberGear.Motor_GetPos();
    g_Current_WinchTorque = mCyberGear.Motor_GetPos();
    emit signal_ShowCurrentWinchPos();
    */

    //mCyberGear.Motor_Read_mechPos();
    //delay(100);
    //mCyberGear.motor_can_rx();
/*
    //SC Auto Test
    emit signal_ShowCurrentSCPos();
    if(bEnableSCTest)
    {
        emit signal_SC_AutoTest();
    }

    if(g_LedInited!=0)
    {
        g_LedInited = Led_Init();
        if(g_LedInited==0)
        {
            delay(200);
            Led_Set(1, 3);
            delay(200);
            Led_Set(2, 3);
            Led_SetFlash(5);
            Led_ON(true);
        }
    }
*/
    if(!p_myMqtt->IsConneted() )
    {
        //断线重连
        p_myMqtt->connected();
        g_sub=false;
    }
    if(!g_sub)
    {
        if(p_myMqtt->IsConneted())
        {
            sLog = "Server connent success!!!";

            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("************  Net Conneted!!!  ************\n"), 2);

            b=p_myMqtt->setSubscribe(MQTT_SUB_WINCH);
            g_sub = b;
            if( b )
            {
                sLog += "1-WINCH OK!";;
            }
            else
            {
                sLog += "1-WINCH fail!";
            }

            b=p_myMqtt->setSubscribe(MQTT_SUB_SC);
            g_sub = b;
            if( b )
            {
                sLog += "2-SC OK!";;
            }
            else
            {
                sLog += "2-SC fail!";
            }


/*
            b=p_myMqtt->setSubscribe(MQTT_SUB_CTRL);
            g_sub = b;
            if( b )
            {
                sLog += "1-CTRL OK!";
            }
            else
            {
                sLog += "1-CTRL fail!";
            }

            b=p_myMqtt->setSubscribe(MQTT_SUB_MODE);
            g_sub = g_sub&b;
            if( b )
            {
                sLog += "2-MODE OK!";
            }
            else
            {
                sLog += "2-MODE fail!";
            }

            b=p_myMqtt->setSubscribe(MQTT_SUB_PARM);
            g_sub = g_sub&b;
            if( b )
            {
                sLog += "3-PARM OK!";
            }
            else
            {
                sLog += "3-PARM fail!";
            }

            b=p_myMqtt->setSubscribe(MQTT_SUB_LED);
            g_sub = g_sub&b;
            if( b )
            {
                sLog += "4-LED OK!";
            }
            else
            {
                sLog += "4-LED fail!";
            }

            b=p_myMqtt->setSubscribe(MQTT_SUB_WINCH);
            g_sub = g_sub&b;
            if( b )
            {
                sLog += "5-WINCH OK!";;
            }
            else
            {
                sLog += "5-WINCH fail!";
            }

            b=p_myMqtt->setSubscribe(MQTT_SUB_TRACK);
            g_sub = g_sub&b;
            if( b )
            {
                sLog += "6-TRACK OK!";;
            }
            else
            {
                sLog += "6-TRACK fail!";
            }

            b=p_myMqtt->setSubscribe(MQTT_SUB_STATUSTIME);
            g_sub = g_sub&b;
            if( b )
            {
                sLog += "7-STATUSTIME OK!";;
            }
            else
            {
                sLog += "7-STATUSTIMEs fail!";
            }
*/
            WriteToLog( sLog );  //===log===s

        }
        else
        {

        }
    }

    if(lastNet != g_sub)
    {
        if(g_sub)
        {
            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("NetConnect success!"), 2);
            emit signal_NetStatus(1);
        }
        else
        {
            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("NetConnect fail!"), 2);
            emit signal_NetStatus(0);
        }
        lastNet = g_sub;
    }

    //运行时间
    QDateTime current_date_time =QDateTime::currentDateTime();
    s_current_time =current_date_time.toString("hh:mm:ss");
    QTime m_time;
    m_time.setHMS(0, 0, 0, 0);                                       //初始化数据，时 分 秒 毫秒
    s_run_time =m_time.addSecs(beginTime.secsTo(current_date_time)).toString("hh:mm:ss");//计算时间差(秒)，将时间差加入m_time，格式化输出
    //ui->run_time->setText(s_run_time);

    iMsgCnt++;
    if(iMsgCnt==5)
    {
        if(p_myMqtt->IsConneted())
        {
        //    QString str;
        //    str=QString(QLatin1String(sStatus));
            //str="123456";
            //p_myMqtt->setPublish(MQTT_PUB_STATUS, str, 2);


            /*
            QString sLon,sLat,sVolt,sCurr,sTemp,sHumidty;


            sLon = QString::number(g_lon,10,7);
            sLat = QString::number(g_lat,10,7);

            sVolt = QString::number(g_Volt,10,3);
            sCurr = QString::number(g_Curr,10,3);

            sTemp = QString::number(g_Temp,10,3);
            sHumidty = QString::number(g_Humidty,10,3);
            //msg_status = "{'lon':'"+sLon+"','lat:':'"+sLat+"','volt:':'"+sVolt+"','curr:':'"+sCurr+"','temp:':'"+sTemp+"','humidty:':'"+sHumidty+"'}";
            //发布消息
            QJsonObject m_json;
            m_json.insert("lon",sLon);
            m_json.insert("lat",sLat);
            m_json.insert("volt",sVolt);
            m_json.insert("curr",sCurr);
            m_json.insert("temp",sTemp);
            m_json.insert("humidty",sHumidty);

            QJsonDocument m_jsondoc;
            m_jsondoc.setObject(m_json);
            //QByteArray d=m_jsondoc.toJson();
            p_myMqtt->setPublish(MQTT_PUB_STATUS, m_jsondoc.toJson(), 0);
            */
        }
        iMsgCnt=0;
    }

}

QString sTemp="";
void CoreUAV::On_SubMsg(QString sTopic, QString message)
{
    QString sLog;
    int iRet_DroneKit=0;

    QJsonObject m_json;
/*
    //飞机控制指令
    if(sTopic==MQTT_SUB_CTRL)
    {
        if(message=="LOCKED")
        {
            iRet_DroneKit=DroneKit_set_locked(DroneKit_pModule);
        }
        else if(message=="UNLOCKED")
        {
            iRet_DroneKit=DroneKit_set_unlocked(DroneKit_pModule);
        }
        else if(message=="TACKOFF")
        {
            iRet_DroneKit=DroneKit_auto_tackoff(DroneKit_pModule);
        }

        if(iRet_DroneKit==0)
        {
            sLog = "tType=CTRL, value="+message+", result=TRUE";
        }
        else
        {
            sLog = "tType=CTRL, value="+message+", result=FAIL";
        }
        TxToHttpServer(MQTT_PUB_STATUS, sLog);
        WriteToLog( sLog );  //===log===
    }
*/
    if(sTopic==MQTT_SUB_SC)
    {
        if(message.left(3)=="POS")
        {
            int pos, t, v;
            int k_pos, k_t, k_v;

            k_pos = 1;
            k_t = 1;
            k_v = 1;

            QString sPama;
            int iPos=0;
            sPama = message;
            iPos = sPama.indexOf(",");
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);
            mID_SC = sTemp.toInt();
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);
            pos = sTemp.toInt();
            pos = pos*k_pos;
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);
            t = sTemp.toInt()*k_t;
            sPama = sPama.right(sPama.length()-iPos-1);

            v = sPama.toInt()*k_v;

            signal_SC_WritePos(mID_SC, pos, t, v);

            p_myMqtt->setPublish(MQTT_PUB_SC, QString("SC Set OK!\n"), 2);
            emit signal_AddLogInEdit(QString("SC Set OK!"));
        }
    }
    else if(sTopic==MQTT_SUB_WINCH)
    {
        if(message=="RESET")
        {
            //reset
            WinchReset();

            //mWinchTomotor.Winch_Reset();
            //mCyberGear.Motor_Move(0);
            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("Winch Reset!"), 2);
            emit signal_AddLogInEdit(QString("Winch Reset!\n"));
        }
        else if(message=="STOP")
        {
            //mWinchTomotor.Winch_Stop();
            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("Winch Stop!"), 2);
            emit signal_AddLogInEdit(QString("Winch Stop!\n"));
        }
        else if(message.left(10)=="DELIVERY")
        {
            //Delivery
            WinchDelivery();
            //Winch_SetPos(0, 0, 0);
            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("Winch Set DELIVERY!"), 2);
            emit signal_AddLogInEdit(QString("Winch Set DELIVERY!\n"));
        }
        else if(message.left(10)=="RETRACT")
        {
            //Retract
            WinchRetract();
        }
        else if(message=="LOAD")
        {
            //Load
            mCyberGear.Motor_Stop();
        }
        else if(message=="LOADUP")
        {
            //Load up
            WinchLoadUP();
        }
        else if(message=="UP")
        {
            //Winch_SetPos(-2800, 0, 0);
            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("Winch Set UP!\n"), 2);
            emit signal_AddLogInEdit(QString("Winch Set UP!"));
        }
        else if(message.left(3)=="POS")
        {
            int h, v, v_acc, torque, isbrake;
            int k_h, k_v, k_vacc;

            k_h = 40;
            k_v = 1;
            k_vacc = 1;

            QString sPama;
            int iPos=0;
            sPama = message;
            iPos = sPama.indexOf(",");
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);
            h = sTemp.toInt();

            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);
            v = sTemp.toInt();
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);
            v_acc = sTemp.toInt();
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);
            torque = sTemp.toInt();
            sPama = sPama.right(sPama.length()-iPos-1);

            isbrake = sPama.toInt();

            //alt = h*k_h;
            //mWinchTomotor.Winch_SetPos(alt, v, v_acc, torque, isbrake);

            mCyberGear.Motor_Speed(v);
            mCyberGear.Motor_Move(h);

            QString str;
            str = QString("Winch Set POS(") + QString::number(h) +","+ QString::number(v) +","+ QString::number(v_acc) +","+ QString::number(torque) +","+ QString::number(isbrake) +QString(") !\n");
            p_myMqtt->setPublish(MQTT_PUB_WINCH, str, 2);

            emit signal_AddLogInEdit(str);
        }
        else if(message.left(4)=="LOCK")
        {
            int freq, pwm;
            QString sPama;
            int iPos=0;
            sPama = message;
            iPos = sPama.indexOf(",");
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);

            freq = sTemp.toInt();
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);
            pwm = sTemp.toInt();

            mWinchTomotor.Pwm_Set(freq, pwm);

            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("Hook set locked!\n"), 2);
            emit signal_AddLogInEdit(QString("Hook set locked!"));
        }
        else if(message.left(9)=="HOOK_OPEN")
        {
            mHook.Hook_Open();

            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("Hook set open!\n"), 2);
            emit signal_AddLogInEdit(QString("Hook set open!"));
        }
        else if(message.left(10)=="HOOK_CLOSE")
        {
            mHook.Hook_Close();

            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString("Hook set close!\n"), 2);
            emit signal_AddLogInEdit(QString("Hook set close!"));
        }
        else if(message.left(8)=="HOOK_PWM")
        {
            int pwm = 0;
            QString sPama;
            int iPos=0;
            sPama = message;
            iPos = sPama.indexOf(",");
            sPama = sPama.right(sPama.length()-iPos-1);

            iPos = sPama.indexOf(",");
            sTemp = sPama.left(iPos);

            pwm = sTemp.toInt();
            mHook.Hook_PwmSet(pwm);

            p_myMqtt->setPublish(MQTT_PUB_WINCH, QString(message+"\n"), 2);
            emit signal_AddLogInEdit(QString(message+"\n"));
        }
    }

}


void CoreUAV::SC_StartAutoTest()
{
    bEnableSCTest = true;
    p_taskWork->EnableSCTest(bEnableSCTest);
}

void CoreUAV::SC_StopAutoTest()
{
    bEnableSCTest = false;
    p_taskWork->EnableSCTest(bEnableSCTest);
}

void CoreUAV::On_SC_SetPos(int ID, int Position, int Time, int Speed)
{
    //SC_WritePos(ID, Position, Time, Speed);
}

void CoreUAV::WinchDataDump(int i_onoff)
{
    mCyberGear.Motor_DataAutoDump(i_onoff);
}

void CoreUAV::WinchReset()
{
//

 //   mCyberGear.Motor_limit_cur(1.5);
//    sleep(0.05);
 //   mCyberGear.Motor_limit_torque(2.5);
 //   sleep(0.05);

    mCyberGear.Motor_Enable();
    sleep(0.05);
    mCyberGear.Motor_Speed(2);
    sleep(0.05);
    mCyberGear.Motor_Mode(MOTOR_MODE::MODE_RESET);
    sleep(0.05);
    mCyberGear.Motor_Move(-2000);
    sleep(0.05);
    //if(mCyberGear.m_mechPos)
}

void CoreUAV::WinchDelivery()
{
    mCyberGear.m_aimPos = 20;

    mCyberGear.Motor_Enable();
    sleep(0.05);
    mCyberGear.Motor_Speed(10);
    sleep(0.05);
    mCyberGear.m_retract_cnt=0;
    mCyberGear.Motor_Mode(MOTOR_MODE::MODE_DELIVERY);
    sleep(0.05);
    mCyberGear.Motor_Move(mCyberGear.m_aimPos);
    sleep(0.05);
}

void CoreUAV::WinchRetract()
{
    mCyberGear.m_aimPos = 0;
    mCyberGear.Motor_Enable();
    sleep(0.05);
    mCyberGear.Motor_Speed(10);
    sleep(0.05);
    mCyberGear.Motor_Mode(MOTOR_MODE::MODE_RETRACT);
    mCyberGear.Motor_Move(mCyberGear.m_aimPos);
    sleep(0.05);
}

void CoreUAV::WinchLoadUP()
{
    mCyberGear.Motor_Enable();
    sleep(0.05);
    mCyberGear.Motor_Speed(2);
    sleep(0.05);
    mCyberGear.Motor_Mode(MOTOR_MODE::MODE_NORM);
    sleep(0.05);
    mCyberGear.Motor_Move(0);
    sleep(0.05);
}
