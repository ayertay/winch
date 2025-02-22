#-------------------------------------------------
#
# Project created by QtCreator 2022-10-12T15:13:50
#
#-------------------------------------------------

QT += core gui
QT += serialport
QT += network
QT += mqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArcuasUAV
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += exceptions

SOURCES += \
    PWMthreak.cpp \
    chook_heltec.cpp \
    ctomotorserial.cpp \
    cybergear.cpp \
        main.cpp \
        mainwindow.cpp \
    coreuav.cpp \
    mymqtt.cpp \
    workthreak.cpp

HEADERS += \
    PWMthread.h \
    chook_heltec.h \
    ctomotorserial.h \
    cybergear.h \
    global.h \
        mainwindow.h \
    coreuav.h \
    mymqtt.h \
    workthread.h

FORMS += \
        mainwindow.ui

LIBS += -lwiringPi
LIBS += -L. -lgpiod

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/ScsServLib/ -lSCServo

INCLUDEPATH += $$PWD/ScsServLib
DEPENDPATH += $$PWD/ScsServLib

unix:!macx: PRE_TARGETDEPS += $$PWD/ScsServLib/libSCServo.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/ScsServLib/release/ -lSCServo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ScsServLib/debug/ -lSCServo
else:unix: LIBS += -L$$PWD/ScsServLib/ -lSCServo

INCLUDEPATH += $$PWD/ScsServLib
DEPENDPATH += $$PWD/ScsServLib
