#ifndef MYMQTT_H
#define MYMQTT_H

#include <QObject>
#include <QMqttClient>

class myMqtt : public QObject
{
    Q_OBJECT
public:
    explicit myMqtt(QObject *parent = nullptr);

signals:

public slots:

private:
    QMqttClient *m_client;
    QString     sHost;
    quint16     port;
signals:
    void signal_SubMsg(QString sTopic, QString s);
public slots:
    void setClientHost(QString  s_Host);
    void setClientPort(int p);
    void setClientUserName(QString sName);
    void setClientPassword(QString sPwd);

    bool setPublish(QString sTopic, QString sMsg, quint8 qos);
    bool setPublish(QString sTopic, QByteArray sMsg, quint8 qos);
    bool setSubscribe(QString sTopic);
    void getState(QString &s_content);
    void connected();
    void brokerDisconnected();
    bool WaitforConneted(int timeout_ms);
    bool IsConneted();

private slots:
    void sleep(unsigned int msec);
    void updateLogStateChange();
};

#endif // MYMQTT_H
