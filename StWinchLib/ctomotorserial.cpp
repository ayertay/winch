#include "ctomotorserial.h"
#include <QJsonObject>
#include <QJsonDocument>

CTomotorSerial::CTomotorSerial(QObject *parent) : QObject(parent)
{
    bWinchPortRet = false;
}

CTomotorSerial::~CTomotorSerial()
{

}

bool CTomotorSerial::Winch_Init(QString s_SerialPortName)
{
    //Open Winch Port
    bool b = connect(&m_WinchPort, SIGNAL(readyRead()), this, SLOT(readWinchData()));
    _processingWinch = true;
    //m_PortName_Winch = "/dev/ttyUSB0";
    m_PortName_Winch = s_SerialPortName;

    _processingWinch=true;
    bWinchPortRet = OpenComPort(&m_WinchPort, m_PortName_Winch,QSerialPort::Baud115200,QSerialPort::Data8,QSerialPort::OneStop,QSerialPort::NoParity);
    if(!bWinchPortRet)
    {
        qDebug()<<"Winch Port Open error!";
    }

    return true;
}

//初始化串口
bool CTomotorSerial::OpenComPort(QSerialPort *_Port, QString _portName, qint32 _baud,QSerialPort::DataBits _databits,QSerialPort::StopBits _stopbits,QSerialPort::Parity _parity)
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

bool CTomotorSerial::Pwm_Set(int freq, int pwm)
{
    char buf[14]={0};
    char checksum=0;
    buf[0]=0x5A;
    buf[1]=0xA3;
    buf[2]=0X0A;
    buf[3]=((freq>>24)&0xFF);
    buf[4]=((freq>>16)&0xFF);
    buf[5]=((freq>>8)&0xFF);
    buf[6]=(freq&0xFF);
    buf[7]=((pwm>>24)&0xFF);
    buf[8]=((pwm>>16)&0xFF);
    buf[9]=((pwm>>8)&0xFF);
    buf[10]=(pwm&0xFF);
    buf[11]=0x00;
    checksum = CalcCheckSum((T_u8*)buf, 0, 12);
    buf[12]=checksum;

    m_WinchPort.clear();
    m_WinchPort.flush();
    m_WinchPort.write((const char*)buf, 13);

    return true;
}

bool CTomotorSerial::Winch_SetPos(int alt,int v,int v_acc, int torque, int isbrake)
{
    char buf[16]={0};
    char checksum=0;
    buf[0]=0x5A;
    buf[1]=0xA3;
    buf[2]=0X0A;
    buf[3]=0X08;
    buf[4]=0X00;
    buf[5]=((v>>8)&0xFF);
    buf[6]=(v&0xFF);

    buf[7]=(v_acc&0xFF);

    buf[8] =((alt>>16)&0xFF);
    buf[9] =((alt>>8)&0xFF);
    buf[10]=(alt&0xFF);

    buf[11]=((torque>>8)&0xFF);
    buf[12]=(torque&0xFF);

    buf[13]=0x00;
    checksum = CalcCheckSum((T_u8*)buf, 0, 14);
    buf[14]=checksum;

    m_WinchPort.clear();
    m_WinchPort.flush();
    m_WinchPort.write((const char*)buf, 15);

    //sleep(10);
    return true;
}

bool CTomotorSerial::Winch_Reset()
{
    char buf[16]={0};
    char checksum=0;
    buf[0]=0x5A;
    buf[1]=0xA3;
    buf[2]=0X0A;
    buf[3]=0X01;
    buf[4]=0X00;
    buf[5]=0X00;
    buf[6]=0X00;
    buf[7]=0X00;
    buf[8]=0X00;
    buf[9]=0X00;
    buf[10]=0X00;
    buf[11]=0X00;
    buf[12]=0X00;
    buf[13]=0X00;
    buf[14]=0X00;
    checksum = CalcCheckSum((T_u8*)buf, 0, 14);
    buf[14]=checksum;
    m_WinchPort.write((const char*)buf, 15);

    //sleep(10);
    return true;
}

bool CTomotorSerial::Winch_Stop()
{
    char buf[16]={0};
    char checksum=0;
    buf[0]=0x5A;
    buf[1]=0xA3;
    buf[2]=0X0A;
    buf[3]=0X02;
    buf[4]=0X00;
    buf[5]=0X00;
    buf[6]=0X00;
    buf[7]=0X00;
    buf[8]=0X00;
    buf[9]=0X00;
    buf[10]=0X00;
    buf[11]=0X00;
    buf[12]=0X00;
    buf[13]=0X00;
    buf[14]=0X00;
    checksum = CalcCheckSum((T_u8*)buf, 0, 14);
    buf[14]=checksum;
    m_WinchPort.write((const char*)buf, 15);

    return true;
}

void CTomotorSerial::Winch_ReadStatus()
{
    char buf[14]={0};
    char checksum=0;
    buf[0]=0x5A;
    buf[1]=0xA1;
    buf[2]=0X08;
    buf[3]=0X00;
    buf[4]=0X00;
    buf[5]=0X00;
    buf[6]=0X00;
    buf[7]=0X00;
    buf[8]=0X00;
    buf[9]=0X00;
    buf[10]=0X00;
    buf[12]=0X00;
    checksum = CalcCheckSum((T_u8*)buf, 0, 12);
    buf[12]=checksum;
    m_WinchPort.write((const char*)buf, 13);

    //sleep(10);
}

void CTomotorSerial::Winch_ReadPos()
{
    char buf[14]={0};
    char checksum=0;
    buf[0]=0x5A;
    buf[1]=0xA4;
    buf[2]=0X08;
    buf[3]=0X00;
    buf[4]=0X00;
    buf[5]=0X00;
    buf[6]=0X00;
    buf[7]=0X00;
    buf[8]=0X00;
    buf[9]=0X00;
    buf[10]=0X00;
    buf[11]=0X00;
    checksum = CalcCheckSum((T_u8*)buf, 0, 12);
    buf[12]=checksum;
    m_WinchPort.write((const char*)buf, 13);

    //sleep(10);
}

#define CMD_STATUS_LEN 12
void CTomotorSerial::readWinchData()
{
    if(_processingWinch)
    {
        //sleep(10);
        QByteArray data = m_WinchPort.readAll();
        int length = data.length();
        int offset = 0;

        int i_setPos = 0;
        int i_ReadPos = 0;

        if(length >= CMD_STATUS_LEN)
        {
            qDebug() << "winch data： LEN（"<< length << "）=" << data ;

            if( ((data[0]&0xFF)==0x5A)&&((data[1]&0xFF)==0xB4) )
            {
                i_setPos = data[3];
                i_setPos = (i_setPos<<8)+data[4];
                i_setPos = (i_setPos<<8)+data[5];
                i_setPos = (i_setPos<<8)+data[6];

                i_ReadPos = data[7];
                i_ReadPos = (i_ReadPos<<8)+data[8];
                i_ReadPos = (i_ReadPos<<8)+data[9];
                i_ReadPos = (i_ReadPos<<8)+data[10];

                //g_Current_WinchPos = i_ReadPos;
                //emit signal_ShowCurrentWinchPos();
                if(i_setPos == i_ReadPos)
                {
                    //g_Current_WinchPos = -2800;
                }
            }

        }
    }
}
