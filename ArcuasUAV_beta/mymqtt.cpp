#include "mymqtt.h"
#include <QElapsedTimer>
#include <QCoreApplication>

myMqtt::myMqtt(QObject *parent) : QObject(parent)
{
    m_client = new QMqttClient(this);

    sHost="api.arcuas.io";
    port=1884;
    m_client->setHostname(sHost);
    m_client->setPort(port);
    m_client->setUsername("arcuas");
    m_client->setPassword("arcuas");

    connect(m_client, &QMqttClient::stateChanged, this, &myMqtt::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &myMqtt::brokerDisconnected);

    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" Received Topic: ")
                    + topic.name()
                    + QLatin1String(" Message: ")
                    + message
                    + QLatin1Char('\n');
        //ui->editLog->insertPlainText(content);

        emit signal_SubMsg(topic.name(),message);

    });

    connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
        //ui->editLog->insertPlainText(content);
    });

    //updateLogStateChange();
}

void myMqtt::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    //ui->editLog->insertPlainText(content);
}

void myMqtt::getState(QString &s_content)
{
/*
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    //ui->editLog->insertPlainText(content);
*/
    s_content  = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
}

void myMqtt::connected()
{
    m_client->connectToHost();

}

void myMqtt::brokerDisconnected()
{
    m_client->disconnectFromHost();
    /*
    ui->lineEditHost->setEnabled(true);
    ui->spinBoxPort->setEnabled(true);
    ui->buttonConnect->setText(tr("Connect"));
    */
}

bool myMqtt::IsConneted()
{
    if (m_client->state() == QMqttClient::Disconnected)
    {
        return false;
    }
    return true;
}

void myMqtt::sleep(unsigned int msec)
{
    QElapsedTimer  t;
    t.start();
    while(t.elapsed() < msec)
    {
        QCoreApplication::processEvents();
    }

}

bool myMqtt::WaitforConneted(int timeout_ms)
{
    int t,maxcnt;
    maxcnt=timeout_ms/100;
    t=0;
    while((t<maxcnt)&&(m_client->state()==QMqttClient::Disconnected))
    {
        sleep(100);
        t++;
    }
    return IsConneted();
}

void myMqtt::setClientHost(QString  s_Host)
{
    m_client->setHostname(s_Host);
}

void myMqtt::setClientPort(int p)
{
    m_client->setPort(p);
}

void myMqtt::setClientUserName(QString sName)
{
    m_client->setUsername(sName);
}

void myMqtt::setClientPassword(QString sPwd)
{
    m_client->setPassword(sPwd);
}

bool myMqtt::setPublish(QString sTopic, QString sMsg, quint8 qos)
{
    if (m_client->publish(sTopic, sMsg.toUtf8(), qos) == -1)
    {
        //QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
        return false;
    }
    return true;
}

bool myMqtt::setPublish(QString sTopic, QByteArray sMsg, quint8 qos)
{
    if (m_client->publish(sTopic, sMsg, qos) == -1)
    {
        //QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
        return false;
    }
    return true;
}

bool myMqtt::setSubscribe(QString sTopic)
{
    auto subscription = m_client->subscribe(sTopic);
    if (!subscription)
    {
        //QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return false;
    }
    return true;
}
