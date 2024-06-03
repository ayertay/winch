#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "coreuav.h"
#include "workthread.h"
#include "ScsServLib//SCServo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BtnWinchTest_clicked();

    void on_pushButton_AutoTest_clicked(bool checked);

    void ShowCurrentWinchPos();
    void AddLogInEdit(QString sLog);
    void on_Btn_Motor_CW_clicked();

    void on_Btn_Motor_CCW_clicked();

    void ShowCurrentSCPos();
    void on_BtnSC15_SetPos_clicked();

    void on_SC15_AutoTest_clicked(bool checked);

    //SC15
    int  SC_Init();
    int  SC_ReadPos(int ID);
    int  SC_WritePos(int ID, int Position, int Time, int Speed);
    void On_SC_AutoTest();

    void On_NetStatus(int status);

    void on_Btn_Motor_data_dump_clicked();

    void on_Btn_Motor_dump_off_clicked();

    void on_BtnWinch_Reset_clicked();

    void on_BtnWinch_Delivery_clicked();

    void on_MainWindow_destroyed();

    void on_BtnWinch_Retract_clicked();

    void on_BtnWinch_LOAD_clicked();

    void on_BtnWinch_LOAD_UP_clicked();

private:
    Ui::MainWindow *ui;
    CoreUAV mCore;
    //WorkThread *pWkThread;
    //SMS_STS sm_st;

    int   m_ID;
    SCSCL m_sc;
};

#endif // MAINWINDOW_H
