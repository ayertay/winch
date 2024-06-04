#ifndef CHOOK_HELTEC_H
#define CHOOK_HELTEC_H

#include <QObject>
#include <QFile>
#include <QMutex>
#include <QSerialPort>
#include <QSettings>

#define T_u8  unsigned char
#define T_u16 unsigned int
#define BYTE unsigned char

class CHook_Heltec : public QObject
{
    Q_OBJECT
public:
    explicit CHook_Heltec(QObject *parent = nullptr);
    ~CHook_Heltec();

    QSerialPort m_HookPort;
    //hook
    int lora_addr;
    QSerialPort *p_HookPort;
    bool        bHookPortRet;
    bool        _processingHook;
    QString     m_PortName_Hook;

public slots:
    bool OpenComPort(QSerialPort *_Port, QString _portName, qint32 _baud,QSerialPort::DataBits _databits,QSerialPort::StopBits _stopbits,QSerialPort::Parity _parity);

    bool Init(QString s_SerialPortName, int lora_addr);
    void readHookData(void);
    void Hook_Open();
    void Hook_Close();
    void Hook_PwmSet(int pwm);
signals:

};

#endif // CHOOK_HELTEC_H
