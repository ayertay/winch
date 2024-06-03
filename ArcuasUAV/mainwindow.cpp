#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

extern float g_Current_WinchPos;
extern float g_Current_WinchTorque;
extern int g_Current_SCPos;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
    m_ID = 1;
    int bSCPortRet=0;
    bSCPortRet = SC_Init();
    if(!bSCPortRet)
    {
        qDebug()<<"SC Port Open error!";
    }
*/


    mCore.init();
    mCore.run();

    connect(mCore.p_taskWork,SIGNAL(signal_ShowCurrentWinchPos()),this,SLOT(ShowCurrentWinchPos()));
    connect(&mCore,SIGNAL(signal_ShowCurrentWinchPos()),this,SLOT(ShowCurrentWinchPos()));
    connect(&mCore,SIGNAL(signal_AddLogInEdit(QString)),this,SLOT(AddLogInEdit(QString)));
    connect(&mCore,SIGNAL(signal_ShowCurrentSCPos()),this,SLOT(ShowCurrentSCPos()));


    connect(&mCore,SIGNAL(signal_SC_AutoTest()),this,SLOT(On_SC_AutoTest()));
    connect(&mCore,SIGNAL(signal_SC_WritePos(int,int,int,int,int,int)),this,SLOT(SC_WritePos(int,int,int,int,int,int)));

    connect(&mCore,SIGNAL(signal_NetStatus(int)),this,SLOT(On_NetStatus(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnWinchTest_clicked()
{
    int iHight=0;
    int iSpeed=0;
    iHight = ui->spinBox_WinchPos->text().toInt();
    //mCore.Winch_SetPos(iHight, 3, 2, 5, 1);
    iSpeed = ui->spinBox_WinchSpeed->text().toInt();

    mCore.mCyberGear.Motor_Enable();
    mCore.mCyberGear.Motor_Speed(iSpeed);
    mCore.mCyberGear.Motor_Move(iHight);
}

void MainWindow::on_pushButton_AutoTest_clicked(bool checked)
{
    if(checked)
    {
        mCore.StartWincTest();
    }
    else
    {
        mCore.StopWincTest();
    }
}

void MainWindow::ShowCurrentWinchPos()
{
    ui->label_CurrentWinchPos->setText(QString::number(g_Current_WinchPos,'f',4));
    ui->label_CurrentWinchTorque->setText(QString::number(g_Current_WinchTorque,'f',4));
}

void MainWindow::AddLogInEdit(QString sLog)
{
    const QString content = QDateTime::currentDateTime().toString()
                //+ QLatin1String(" Received Topic: ")
                //+ topic.name()
                + QLatin1String(" Message: ")
                + sLog
                + QLatin1Char('\n');

    ui->editLog->insertPlainText(sLog);
}


extern int m_Current_Pos;
extern int g_v;
extern int m_Step;
void MainWindow::on_Btn_Motor_CW_clicked()
{
    m_Current_Pos = m_Current_Pos + 100;
    if(m_Current_Pos>1000)
    {
        m_Current_Pos = 0;
    }
    //sm_st.WritePosEx(1, m_Current_Pos, g_v, 0);
    //mCore.SC_WritePos(m_ID, m_Current_Pos, 0, g_v);
    m_sc.WritePos(m_ID, m_Current_Pos, 0, g_v);

//    int pos = mCore.SC_ReadPos(m_ID);
//    ui->label_CurrentSCPos->setText(QString::number(pos));
}

void MainWindow::on_Btn_Motor_CCW_clicked()
{
    m_Current_Pos = m_Current_Pos - 100;
    if(m_Current_Pos<0)
    {
        m_Current_Pos = 0;
    }
    //sm_st.WritePosEx(1, m_Current_Pos, g_v, 0);
    //mCore.SC_WritePos(m_ID, m_Current_Pos, 0, g_v);
    m_sc.WritePos(m_ID, m_Current_Pos, 0, g_v);

//    int pos = mCore.SC_ReadPos(m_ID);
//    ui->label_CurrentSCPos->setText(QString::number(pos));
}

void MainWindow::on_BtnSC15_SetPos_clicked()
{
    m_Current_Pos = ui->spinBox_SC15Pos->text().toInt();
    m_sc.WritePos(m_ID, m_Current_Pos, 0, g_v);
}

void MainWindow::on_SC15_AutoTest_clicked(bool checked)
{
    if(checked)
    {
        mCore.SC_StartAutoTest();
    }
    else
    {
        mCore.SC_StopAutoTest();
    }
}

void MainWindow::ShowCurrentSCPos()
{
    g_Current_SCPos = SC_ReadPos(m_ID);
    ui->label_CurrentSCPos->setText(QString::number(g_Current_SCPos));
}

int  MainWindow::SC_Init()
{
    if(!m_sc.begin(1000000, "/dev/ttyAMA2"))
    {
       return 0;
    }

    return 1;
}
int  MainWindow::SC_ReadPos(int ID)
{
    T_u8 sc_id = ID&0xFF;
    return m_sc.ReadPos(sc_id);
}

int  MainWindow::SC_WritePos(int ID, int Position, int Time, int Speed)
{
    int iRet=0;
    iRet=m_sc.WritePos(ID, Position, Time, Speed);
    return iRet;
}

void MainWindow::On_SC_AutoTest()
{
    m_Current_Pos = m_Current_Pos + m_Step;
    if(m_Current_Pos>1000)
    {
        m_Current_Pos = 1000;
        m_Step = -1*m_Step;
    }
    m_sc.WritePos(m_ID, m_Current_Pos, 0, g_v);
}

void MainWindow::On_NetStatus(int status)
{
    if(status==1)
    {
        ui->lab_NetStatus->setText("CONNECT");
        ui->lab_NetStatus->setStyleSheet("color: rgb(0, 255, 0);");
    }
    else
    {
       ui->lab_NetStatus->setText("DISCONNECT");
       ui->lab_NetStatus->setStyleSheet("color: rgb(255, 0, 0);");
    };
}

void MainWindow::on_MainWindow_destroyed()
{
    mCore.stop();
}

void MainWindow::on_Btn_Motor_data_dump_clicked()
{
    mCore.WinchDataDump(1);
}


void MainWindow::on_Btn_Motor_dump_off_clicked()
{
    mCore.WinchDataDump(0);
}


void MainWindow::on_BtnWinch_Reset_clicked()
{
    //reset
    mCore.WinchReset();
}


void MainWindow::on_BtnWinch_Delivery_clicked()
{
    //Delivery
    mCore.WinchDelivery();
}


void MainWindow::on_BtnWinch_Retract_clicked()
{
    //Retract
    mCore.WinchRetract();
}


void MainWindow::on_BtnWinch_LOAD_clicked()
{
    //Load
    mCore.mCyberGear.Motor_Stop();
}


void MainWindow::on_BtnWinch_LOAD_UP_clicked()
{
    //Load up
    mCore.WinchLoadUP();
    //mCore.mCyberGear.Motor_Move(0);
}

