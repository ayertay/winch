#include "chook_heltec.h"
#include <QJsonObject>
#include <QJsonDocument>

CHook_Heltec::CHook_Heltec(QObject *parent)
    : QObject{parent}
{

}

CHook_Heltec::~CHook_Heltec()
{
    ;
}


//初始化串口
bool CHook_Heltec::OpenComPort(QSerialPort *_Port, QString _portName, qint32 _baud,QSerialPort::DataBits _databits,QSerialPort::StopBits _stopbits,QSerialPort::Parity _parity)
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

bool CHook_Heltec::Init(QString s_SerialPortName, int addr)
{
    //Open Hook Port
    bool b=false;
    b = connect(&m_HookPort, SIGNAL(readyRead()), this, SLOT(readHookData()));
    _processingHook = true;
    m_PortName_Hook = s_SerialPortName;
    _processingHook=true;
    bHookPortRet = OpenComPort(&m_HookPort, m_PortName_Hook,QSerialPort::Baud115200,QSerialPort::Data8,QSerialPort::OneStop,QSerialPort::NoParity);
    if(!bHookPortRet)
    {
        qDebug()<<"Hook Port Open error!";
    }

    //Init Addr
    lora_addr = addr;

    return true;
}

void CHook_Heltec::Hook_Open()
{
    Hook_PwmSet(500);
}

void CHook_Heltec::Hook_Close()
{
    Hook_PwmSet(2200);
}

void CHook_Heltec::Hook_PwmSet(int pwm)
{
    char buf[6]={0};
    char checksum=0;
    buf[0]=0xA5;
    buf[1]=lora_addr&0xFF;
    buf[2]=(pwm>>8)&0xFF;
    buf[3]=pwm&0xFF;
    buf[4]=0X00;
    checksum = CalcCheckSum((T_u8*)buf, 0, 4);
    //buf[4]=checksum;

    m_HookPort.clear();
    m_HookPort.flush();
    m_HookPort.write((const char*)buf, 5);
}

#define CMD_STATUS_LEN 12
void CHook_Heltec::readHookData()
{
    if(_processingHook)
    {
        //sleep(10);
        QByteArray data = m_HookPort.readAll();
        int length = data.length();

        if(length >= CMD_STATUS_LEN)
        {
            qDebug() << "Hook data： LEN（"<< length << "）=" << data ;

            if( ((data[0]&0xFF)==0xA5)&&((data[1]&0xFF)==(lora_addr&0xFF)) )
            {
                //emit signal_ShowCurrentWinchPos();

                //HOOK 1 TX OK!

            }

        }
    }
}
