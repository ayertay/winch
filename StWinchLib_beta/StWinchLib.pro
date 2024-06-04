QT -= gui
QT += serialport
QT += network
QT += mqtt

TEMPLATE = lib
DEFINES += STWINCHLIB_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    PWMthreak.cpp \
    chook_heltec.cpp \
    coreuav.cpp \
    ctomotorserial.cpp \
    cybergear.cpp \
    mymqtt.cpp \
    stwinchlib.cpp \
    workthreak.cpp

HEADERS += \
    PWMthread.h \
    StWinchLib_global.h \
    chook_heltec.h \
    coreuav.h \
    ctomotorserial.h \
    cybergear.h \
    mymqtt.h \
    stwinchlib.h \
    workthread.h

LIBS += -lwiringPi
LIBS += -L. -lgpiod

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
