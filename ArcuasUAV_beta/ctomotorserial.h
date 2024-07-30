#ifndef CTOMOTORSERIAL_H
#define CTOMOTORSERIAL_H

#include <QObject>
#include <QFile>
#include <QMutex>
#include <QSerialPort>
#include <QSettings>

#define T_u8  unsigned char
#define T_u16 unsigned int
#define BYTE unsigned char

class CTomotorSerial : public QObject
{
    Q_OBJECT
public:
    CTomotorSerial(QObject *parent = 0);
    ~CTomotorSerial();
public:
    QSerialPort m_WinchPort;
    //Winch
    QSerialPort *p_WinchPort;
    bool        bWinchPortRet;
    bool        _processingWinch;
    QString     m_PortName_Winch;

    bool OpenComPort(QSerialPort *_Port, QString _portName, qint32 _baud,QSerialPort::DataBits _databits,QSerialPort::StopBits _stopbits,QSerialPort::Parity _parity);

    bool Winch_Init(QString s_SerialPortName);
    bool Pwm_Set(int freq, int pwm);
    void readWinchData(void);
    bool Winch_SetPos(int alt,int v,int v_acc, int torque, int isbrake);
    bool Winch_Reset();
    bool Winch_Stop();
    void Winch_ReadStatus();
    void Winch_ReadPos();
};

#endif // CTOMOTORSERIAL_H
