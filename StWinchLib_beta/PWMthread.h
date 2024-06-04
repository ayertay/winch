#ifndef PWMTHREAD_H
#define PWMTHREAD_H

#include <QThread>
#include <QObject>

class PWMThread : public QThread
{
Q_OBJECT
public:
    PWMThread();
private:
    int  workCount;     //计数
    virtual void run(); //任务处理线程
public:
    bool  is_Work;
    //====================
    void CheckPWM();
};

#endif // PWMThread_H
