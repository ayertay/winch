/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *lab_NetStatus;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *editLog;
    QWidget *widget_Winch;
    QGroupBox *groupBox;
    QPushButton *BtnWinchTest;
    QPushButton *BtnWinch_Reset;
    QLabel *label;
    QPushButton *pushButton_AutoTest;
    QLabel *label_CurrentWinchPos;
    QLabel *label_3;
    QSpinBox *spinBox_WinchSpeed;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *BtnWinch_Delivery;
    QPushButton *BtnWinch_Retract;
    QPushButton *Btn_Motor_dump_off;
    QPushButton *Btn_Motor_data_dump;
    QPushButton *BtnWinch_LOAD;
    QPushButton *BtnWinch_LOAD_UP;
    QLabel *label_8;
    QLabel *label_CurrentWinchTorque;
    QDoubleSpinBox *spinBox_WinchPos;
    QPushButton *BtnWinch_LOAD_UP_LOCK;
    QPushButton *BtnWinch_HOLD;
    QPushButton *BtnWinch_HOLD_LINE;
    QLabel *label_TIE_LEN;
    QLabel *label_9;
    QLabel *led_Delivery;
    QLabel *label_13;
    QLabel *label_Delivery;
    QLabel *B_1;
    QLabel *B_2;
    QLabel *led_UPandLOCK;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_UPandLOCK;
    QLabel *label_11;
    QLabel *SDA;
    QLabel *SCL;
    QSpinBox *spinBox_LED;
    QPushButton *Btn_SetLED;
    QLabel *label_16;
    QGroupBox *groupBox_2;
    QPushButton *Btn_Motor_CCW;
    QPushButton *Btn_Motor_CW;
    QLabel *label_CurrentSCPos;
    QLabel *label_2;
    QPushButton *BtnSC15_SetPos;
    QSpinBox *spinBox_SC15Pos;
    QLabel *label_4;
    QPushButton *SC15_AutoTest;
    QPushButton *BtnWinch_UNLOCK;
    QPushButton *BtnWinch_LOCK;
    QLabel *label_10;
    QLabel *label_CurrentSCPos_3;
    QLabel *label_TIE_LEN_2;
    QLabel *label_15;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(840, 825);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 40));
        widget_2->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(40, 0));
        label_5->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(label_5);

        lab_NetStatus = new QLabel(widget_2);
        lab_NetStatus->setObjectName(QString::fromUtf8("lab_NetStatus"));
        lab_NetStatus->setMinimumSize(QSize(100, 0));
        lab_NetStatus->setMaximumSize(QSize(100, 16777215));
        lab_NetStatus->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout_2->addWidget(lab_NetStatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_2);

        editLog = new QPlainTextEdit(widget);
        editLog->setObjectName(QString::fromUtf8("editLog"));

        verticalLayout->addWidget(editLog);


        horizontalLayout->addWidget(widget);

        widget_Winch = new QWidget(centralWidget);
        widget_Winch->setObjectName(QString::fromUtf8("widget_Winch"));
        widget_Winch->setMinimumSize(QSize(500, 0));
        groupBox = new QGroupBox(widget_Winch);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 461, 431));
        BtnWinchTest = new QPushButton(groupBox);
        BtnWinchTest->setObjectName(QString::fromUtf8("BtnWinchTest"));
        BtnWinchTest->setGeometry(QRect(190, 120, 51, 30));
        BtnWinch_Reset = new QPushButton(groupBox);
        BtnWinch_Reset->setObjectName(QString::fromUtf8("BtnWinch_Reset"));
        BtnWinch_Reset->setGeometry(QRect(330, 119, 71, 30));
        BtnWinch_Reset->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 70, 22));
        pushButton_AutoTest = new QPushButton(groupBox);
        pushButton_AutoTest->setObjectName(QString::fromUtf8("pushButton_AutoTest"));
        pushButton_AutoTest->setGeometry(QRect(320, 200, 111, 31));
        pushButton_AutoTest->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        pushButton_AutoTest->setCheckable(true);
        pushButton_AutoTest->setFlat(false);
        label_CurrentWinchPos = new QLabel(groupBox);
        label_CurrentWinchPos->setObjectName(QString::fromUtf8("label_CurrentWinchPos"));
        label_CurrentWinchPos->setGeometry(QRect(10, 60, 131, 40));
        label_CurrentWinchPos->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 75 18pt \"PibotoLt\";\n"
"background-color: rgb(0, 0, 0);"));
        label_CurrentWinchPos->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 123, 61, 22));
        spinBox_WinchSpeed = new QSpinBox(groupBox);
        spinBox_WinchSpeed->setObjectName(QString::fromUtf8("spinBox_WinchSpeed"));
        spinBox_WinchSpeed->setGeometry(QRect(94, 150, 91, 32));
        spinBox_WinchSpeed->setMinimum(-100000);
        spinBox_WinchSpeed->setMaximum(100000);
        spinBox_WinchSpeed->setValue(10);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(-140, 90, 61, 22));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 154, 61, 22));
        BtnWinch_Delivery = new QPushButton(groupBox);
        BtnWinch_Delivery->setObjectName(QString::fromUtf8("BtnWinch_Delivery"));
        BtnWinch_Delivery->setGeometry(QRect(10, 200, 101, 30));
        BtnWinch_Delivery->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        BtnWinch_Retract = new QPushButton(groupBox);
        BtnWinch_Retract->setObjectName(QString::fromUtf8("BtnWinch_Retract"));
        BtnWinch_Retract->setGeometry(QRect(160, 200, 101, 30));
        BtnWinch_Retract->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        Btn_Motor_dump_off = new QPushButton(groupBox);
        Btn_Motor_dump_off->setObjectName(QString::fromUtf8("Btn_Motor_dump_off"));
        Btn_Motor_dump_off->setGeometry(QRect(190, -10, 61, 30));
        Btn_Motor_data_dump = new QPushButton(groupBox);
        Btn_Motor_data_dump->setObjectName(QString::fromUtf8("Btn_Motor_data_dump"));
        Btn_Motor_data_dump->setGeometry(QRect(110, -10, 71, 30));
        BtnWinch_LOAD = new QPushButton(groupBox);
        BtnWinch_LOAD->setObjectName(QString::fromUtf8("BtnWinch_LOAD"));
        BtnWinch_LOAD->setGeometry(QRect(10, 240, 101, 30));
        BtnWinch_LOAD->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        BtnWinch_LOAD_UP = new QPushButton(groupBox);
        BtnWinch_LOAD_UP->setObjectName(QString::fromUtf8("BtnWinch_LOAD_UP"));
        BtnWinch_LOAD_UP->setGeometry(QRect(330, 150, 70, 30));
        BtnWinch_LOAD_UP->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(150, 30, 70, 22));
        label_CurrentWinchTorque = new QLabel(groupBox);
        label_CurrentWinchTorque->setObjectName(QString::fromUtf8("label_CurrentWinchTorque"));
        label_CurrentWinchTorque->setGeometry(QRect(150, 60, 130, 40));
        label_CurrentWinchTorque->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 75 18pt \"PibotoLt\";\n"
"background-color: rgb(0, 0, 0);"));
        label_CurrentWinchTorque->setAlignment(Qt::AlignCenter);
        spinBox_WinchPos = new QDoubleSpinBox(groupBox);
        spinBox_WinchPos->setObjectName(QString::fromUtf8("spinBox_WinchPos"));
        spinBox_WinchPos->setGeometry(QRect(95, 120, 91, 26));
        spinBox_WinchPos->setMinimum(-100000.000000000000000);
        spinBox_WinchPos->setMaximum(999999.989999999990687);
        BtnWinch_LOAD_UP_LOCK = new QPushButton(groupBox);
        BtnWinch_LOAD_UP_LOCK->setObjectName(QString::fromUtf8("BtnWinch_LOAD_UP_LOCK"));
        BtnWinch_LOAD_UP_LOCK->setGeometry(QRect(160, 240, 101, 30));
        BtnWinch_LOAD_UP_LOCK->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        BtnWinch_HOLD = new QPushButton(groupBox);
        BtnWinch_HOLD->setObjectName(QString::fromUtf8("BtnWinch_HOLD"));
        BtnWinch_HOLD->setGeometry(QRect(160, 280, 101, 30));
        BtnWinch_HOLD->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        BtnWinch_HOLD_LINE = new QPushButton(groupBox);
        BtnWinch_HOLD_LINE->setObjectName(QString::fromUtf8("BtnWinch_HOLD_LINE"));
        BtnWinch_HOLD_LINE->setGeometry(QRect(10, 280, 101, 30));
        BtnWinch_HOLD_LINE->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        label_TIE_LEN = new QLabel(groupBox);
        label_TIE_LEN->setObjectName(QString::fromUtf8("label_TIE_LEN"));
        label_TIE_LEN->setGeometry(QRect(290, 60, 131, 41));
        label_TIE_LEN->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 75 18pt \"PibotoLt\";\n"
"background-color: rgb(0, 0, 0);"));
        label_TIE_LEN->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(290, 30, 41, 22));
        led_Delivery = new QLabel(groupBox);
        led_Delivery->setObjectName(QString::fromUtf8("led_Delivery"));
        led_Delivery->setGeometry(QRect(280, 350, 20, 20));
        led_Delivery->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border:3px groove gray;\n"
"border-style:outset;"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(98, 380, 31, 20));
        label_Delivery = new QLabel(groupBox);
        label_Delivery->setObjectName(QString::fromUtf8("label_Delivery"));
        label_Delivery->setGeometry(QRect(280, 380, 31, 20));
        B_1 = new QLabel(groupBox);
        B_1->setObjectName(QString::fromUtf8("B_1"));
        B_1->setGeometry(QRect(20, 350, 20, 20));
        B_1->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border:3px groove gray;\n"
"border-style:outset;"));
        B_2 = new QLabel(groupBox);
        B_2->setObjectName(QString::fromUtf8("B_2"));
        B_2->setGeometry(QRect(60, 350, 20, 20));
        B_2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border:3px groove gray;\n"
"border-style:outset;"));
        led_UPandLOCK = new QLabel(groupBox);
        led_UPandLOCK->setObjectName(QString::fromUtf8("led_UPandLOCK"));
        led_UPandLOCK->setGeometry(QRect(238, 350, 20, 20));
        led_UPandLOCK->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border:3px groove gray;\n"
"border-style:outset;"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(60, 380, 31, 20));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(140, 380, 31, 20));
        label_UPandLOCK = new QLabel(groupBox);
        label_UPandLOCK->setObjectName(QString::fromUtf8("label_UPandLOCK"));
        label_UPandLOCK->setGeometry(QRect(238, 380, 31, 20));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 380, 31, 20));
        SDA = new QLabel(groupBox);
        SDA->setObjectName(QString::fromUtf8("SDA"));
        SDA->setGeometry(QRect(142, 350, 20, 20));
        SDA->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border:3px groove gray;\n"
"border-style:outset;"));
        SCL = new QLabel(groupBox);
        SCL->setObjectName(QString::fromUtf8("SCL"));
        SCL->setGeometry(QRect(100, 350, 20, 20));
        SCL->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border:3px groove gray;\n"
"border-style:outset;"));
        spinBox_LED = new QSpinBox(groupBox);
        spinBox_LED->setObjectName(QString::fromUtf8("spinBox_LED"));
        spinBox_LED->setGeometry(QRect(320, 304, 61, 32));
        spinBox_LED->setMinimum(0);
        spinBox_LED->setMaximum(9);
        spinBox_LED->setSingleStep(1);
        spinBox_LED->setValue(0);
        Btn_SetLED = new QPushButton(groupBox);
        Btn_SetLED->setObjectName(QString::fromUtf8("Btn_SetLED"));
        Btn_SetLED->setGeometry(QRect(383, 305, 51, 30));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(324, 280, 61, 22));
        groupBox_2 = new QGroupBox(widget_Winch);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 540, 271, 201));
        Btn_Motor_CCW = new QPushButton(groupBox_2);
        Btn_Motor_CCW->setObjectName(QString::fromUtf8("Btn_Motor_CCW"));
        Btn_Motor_CCW->setGeometry(QRect(142, 110, 99, 30));
        Btn_Motor_CW = new QPushButton(groupBox_2);
        Btn_Motor_CW->setObjectName(QString::fromUtf8("Btn_Motor_CW"));
        Btn_Motor_CW->setGeometry(QRect(30, 110, 99, 30));
        label_CurrentSCPos = new QLabel(groupBox_2);
        label_CurrentSCPos->setObjectName(QString::fromUtf8("label_CurrentSCPos"));
        label_CurrentSCPos->setGeometry(QRect(110, 30, 131, 40));
        label_CurrentSCPos->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 75 18pt \"PibotoLt\";\n"
"background-color: rgb(0, 0, 0);"));
        label_CurrentSCPos->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 40, 91, 21));
        BtnSC15_SetPos = new QPushButton(groupBox_2);
        BtnSC15_SetPos->setObjectName(QString::fromUtf8("BtnSC15_SetPos"));
        BtnSC15_SetPos->setGeometry(QRect(190, 74, 51, 30));
        spinBox_SC15Pos = new QSpinBox(groupBox_2);
        spinBox_SC15Pos->setObjectName(QString::fromUtf8("spinBox_SC15Pos"));
        spinBox_SC15Pos->setGeometry(QRect(94, 71, 91, 32));
        spinBox_SC15Pos->setMinimum(0);
        spinBox_SC15Pos->setMaximum(1000);
        spinBox_SC15Pos->setSingleStep(10);
        spinBox_SC15Pos->setValue(20);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 77, 61, 22));
        SC15_AutoTest = new QPushButton(groupBox_2);
        SC15_AutoTest->setObjectName(QString::fromUtf8("SC15_AutoTest"));
        SC15_AutoTest->setGeometry(QRect(30, 150, 211, 31));
        SC15_AutoTest->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        SC15_AutoTest->setCheckable(true);
        SC15_AutoTest->setFlat(false);
        BtnWinch_UNLOCK = new QPushButton(widget_Winch);
        BtnWinch_UNLOCK->setObjectName(QString::fromUtf8("BtnWinch_UNLOCK"));
        BtnWinch_UNLOCK->setGeometry(QRect(350, 460, 70, 30));
        BtnWinch_UNLOCK->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        BtnWinch_LOCK = new QPushButton(widget_Winch);
        BtnWinch_LOCK->setObjectName(QString::fromUtf8("BtnWinch_LOCK"));
        BtnWinch_LOCK->setGeometry(QRect(350, 500, 70, 30));
        BtnWinch_LOCK->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";"));
        label_10 = new QLabel(widget_Winch);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 500, 41, 22));
        label_CurrentSCPos_3 = new QLabel(widget_Winch);
        label_CurrentSCPos_3->setObjectName(QString::fromUtf8("label_CurrentSCPos_3"));
        label_CurrentSCPos_3->setGeometry(QRect(70, 500, 111, 30));
        label_CurrentSCPos_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 75 18pt \"PibotoLt\";\n"
"background-color: rgb(0, 0, 0);"));
        label_CurrentSCPos_3->setAlignment(Qt::AlignCenter);
        label_TIE_LEN_2 = new QLabel(widget_Winch);
        label_TIE_LEN_2->setObjectName(QString::fromUtf8("label_TIE_LEN_2"));
        label_TIE_LEN_2->setGeometry(QRect(70, 460, 111, 30));
        label_TIE_LEN_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"font: 75 18pt \"PibotoLt\";\n"
"background-color: rgb(0, 0, 0);"));
        label_TIE_LEN_2->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(widget_Winch);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 467, 41, 22));

        horizontalLayout->addWidget(widget_Winch);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 840, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ARCUAS UAV CTRL ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "NET:", nullptr));
        lab_NetStatus->setText(QCoreApplication::translate("MainWindow", "DISCONNECT", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "WinchTest", nullptr));
        BtnWinchTest->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        BtnWinch_Reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CurrentPos:", nullptr));
        pushButton_AutoTest->setText(QCoreApplication::translate("MainWindow", "AutoTest", nullptr));
        label_CurrentWinchPos->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "SetPos:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "SetPos:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "speed:", nullptr));
        BtnWinch_Delivery->setText(QCoreApplication::translate("MainWindow", "Delivery", nullptr));
        BtnWinch_Retract->setText(QCoreApplication::translate("MainWindow", "Retract", nullptr));
        Btn_Motor_dump_off->setText(QCoreApplication::translate("MainWindow", "can stop", nullptr));
        Btn_Motor_data_dump->setText(QCoreApplication::translate("MainWindow", "can dump", nullptr));
        BtnWinch_LOAD->setText(QCoreApplication::translate("MainWindow", "RELAXED", nullptr));
        BtnWinch_LOAD_UP->setText(QCoreApplication::translate("MainWindow", "LOAD_UP", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Torque:", nullptr));
        label_CurrentWinchTorque->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        BtnWinch_LOAD_UP_LOCK->setText(QCoreApplication::translate("MainWindow", "WINCH_LOCK", nullptr));
        BtnWinch_HOLD->setText(QCoreApplication::translate("MainWindow", "WINCH_HOLD", nullptr));
        BtnWinch_HOLD_LINE->setText(QCoreApplication::translate("MainWindow", "HOLD_LINE", nullptr));
        label_TIE_LEN->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "LEN:", nullptr));
        led_Delivery->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "SCL", nullptr));
        label_Delivery->setText(QCoreApplication::translate("MainWindow", "LOCK", nullptr));
        B_1->setText(QString());
        B_2->setText(QString());
        led_UPandLOCK->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "D22", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "SDA", nullptr));
        label_UPandLOCK->setText(QCoreApplication::translate("MainWindow", "ZERO", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "D18", nullptr));
        SDA->setText(QString());
        SCL->setText(QString());
        Btn_SetLED->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "SetLED:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "SC15(20~1000)", nullptr));
        Btn_Motor_CCW->setText(QCoreApplication::translate("MainWindow", "CCW", nullptr));
        Btn_Motor_CW->setText(QCoreApplication::translate("MainWindow", "CW", nullptr));
        label_CurrentSCPos->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "CurrentPos:", nullptr));
        BtnSC15_SetPos->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "SetPos:", nullptr));
        SC15_AutoTest->setText(QCoreApplication::translate("MainWindow", "AutoTest", nullptr));
        BtnWinch_UNLOCK->setText(QCoreApplication::translate("MainWindow", "UNLOCK", nullptr));
        BtnWinch_LOCK->setText(QCoreApplication::translate("MainWindow", "LOCK", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "PWM:", nullptr));
        label_CurrentSCPos_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_TIE_LEN_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "LEN:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
