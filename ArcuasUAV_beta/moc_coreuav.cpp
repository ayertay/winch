/****************************************************************************
** Meta object code from reading C++ file 'coreuav.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "coreuav.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coreuav.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CoreUAV_t {
    QByteArrayData data[54];
    char stringdata0[570];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CoreUAV_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CoreUAV_t qt_meta_stringdata_CoreUAV = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CoreUAV"
QT_MOC_LITERAL(1, 8, 21), // "SendSignalPostRequest"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "char*"
QT_MOC_LITERAL(4, 37, 4), // "host"
QT_MOC_LITERAL(5, 42, 4), // "path"
QT_MOC_LITERAL(6, 47, 4), // "buff"
QT_MOC_LITERAL(7, 52, 3), // "len"
QT_MOC_LITERAL(8, 56, 26), // "signal_ShowCurrentWinchPos"
QT_MOC_LITERAL(9, 83, 19), // "signal_AddLogInEdit"
QT_MOC_LITERAL(10, 103, 1), // "s"
QT_MOC_LITERAL(11, 105, 23), // "signal_ShowCurrentSCPos"
QT_MOC_LITERAL(12, 129, 18), // "signal_SC_AutoTest"
QT_MOC_LITERAL(13, 148, 18), // "signal_SC_WritePos"
QT_MOC_LITERAL(14, 167, 2), // "id"
QT_MOC_LITERAL(15, 170, 3), // "pos"
QT_MOC_LITERAL(16, 174, 4), // "time"
QT_MOC_LITERAL(17, 179, 3), // "spd"
QT_MOC_LITERAL(18, 183, 16), // "signal_NetStatus"
QT_MOC_LITERAL(19, 200, 20), // "signal_ShowCurrentIO"
QT_MOC_LITERAL(20, 221, 6), // "io_idx"
QT_MOC_LITERAL(21, 228, 1), // "v"
QT_MOC_LITERAL(22, 230, 14), // "signal_ShowPWM"
QT_MOC_LITERAL(23, 245, 13), // "PostUAVStatus"
QT_MOC_LITERAL(24, 259, 7), // "sStatus"
QT_MOC_LITERAL(25, 267, 15), // "OnPostUAVStatus"
QT_MOC_LITERAL(26, 283, 15), // "On_Winch_SetPos"
QT_MOC_LITERAL(27, 299, 3), // "alt"
QT_MOC_LITERAL(28, 303, 5), // "v_acc"
QT_MOC_LITERAL(29, 309, 6), // "torque"
QT_MOC_LITERAL(30, 316, 7), // "isbrake"
QT_MOC_LITERAL(31, 324, 13), // "StartWincTest"
QT_MOC_LITERAL(32, 338, 12), // "StopWincTest"
QT_MOC_LITERAL(33, 351, 13), // "WinchDataDump"
QT_MOC_LITERAL(34, 365, 7), // "i_onoff"
QT_MOC_LITERAL(35, 373, 10), // "WinchReset"
QT_MOC_LITERAL(36, 384, 13), // "WinchDelivery"
QT_MOC_LITERAL(37, 398, 5), // "speed"
QT_MOC_LITERAL(38, 404, 15), // "WinchDeliveryEx"
QT_MOC_LITERAL(39, 420, 8), // "distance"
QT_MOC_LITERAL(40, 429, 12), // "WinchRetract"
QT_MOC_LITERAL(41, 442, 9), // "WinchLoad"
QT_MOC_LITERAL(42, 452, 11), // "WinchLoadUP"
QT_MOC_LITERAL(43, 464, 16), // "SC_StartAutoTest"
QT_MOC_LITERAL(44, 481, 15), // "SC_StopAutoTest"
QT_MOC_LITERAL(45, 497, 12), // "On_SC_SetPos"
QT_MOC_LITERAL(46, 510, 2), // "ID"
QT_MOC_LITERAL(47, 513, 8), // "Position"
QT_MOC_LITERAL(48, 522, 4), // "Time"
QT_MOC_LITERAL(49, 527, 5), // "Speed"
QT_MOC_LITERAL(50, 533, 11), // "time_update"
QT_MOC_LITERAL(51, 545, 9), // "On_SubMsg"
QT_MOC_LITERAL(52, 555, 6), // "sTopic"
QT_MOC_LITERAL(53, 562, 7) // "message"

    },
    "CoreUAV\0SendSignalPostRequest\0\0char*\0"
    "host\0path\0buff\0len\0signal_ShowCurrentWinchPos\0"
    "signal_AddLogInEdit\0s\0signal_ShowCurrentSCPos\0"
    "signal_SC_AutoTest\0signal_SC_WritePos\0"
    "id\0pos\0time\0spd\0signal_NetStatus\0"
    "signal_ShowCurrentIO\0io_idx\0v\0"
    "signal_ShowPWM\0PostUAVStatus\0sStatus\0"
    "OnPostUAVStatus\0On_Winch_SetPos\0alt\0"
    "v_acc\0torque\0isbrake\0StartWincTest\0"
    "StopWincTest\0WinchDataDump\0i_onoff\0"
    "WinchReset\0WinchDelivery\0speed\0"
    "WinchDeliveryEx\0distance\0WinchRetract\0"
    "WinchLoad\0WinchLoadUP\0SC_StartAutoTest\0"
    "SC_StopAutoTest\0On_SC_SetPos\0ID\0"
    "Position\0Time\0Speed\0time_update\0"
    "On_SubMsg\0sTopic\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoreUAV[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  144,    2, 0x06 /* Public */,
       8,    0,  153,    2, 0x06 /* Public */,
       9,    1,  154,    2, 0x06 /* Public */,
      11,    0,  157,    2, 0x06 /* Public */,
      12,    0,  158,    2, 0x06 /* Public */,
      13,    4,  159,    2, 0x06 /* Public */,
      18,    1,  168,    2, 0x06 /* Public */,
      19,    2,  171,    2, 0x06 /* Public */,
      22,    0,  176,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    2,  177,    2, 0x0a /* Public */,
      25,    1,  182,    2, 0x0a /* Public */,
      26,    5,  185,    2, 0x0a /* Public */,
      31,    0,  196,    2, 0x0a /* Public */,
      32,    0,  197,    2, 0x0a /* Public */,
      33,    1,  198,    2, 0x0a /* Public */,
      35,    0,  201,    2, 0x0a /* Public */,
      36,    1,  202,    2, 0x0a /* Public */,
      38,    2,  205,    2, 0x0a /* Public */,
      40,    1,  210,    2, 0x0a /* Public */,
      41,    0,  213,    2, 0x0a /* Public */,
      42,    0,  214,    2, 0x0a /* Public */,
      43,    0,  215,    2, 0x0a /* Public */,
      44,    0,  216,    2, 0x0a /* Public */,
      45,    4,  217,    2, 0x0a /* Public */,
      50,    0,  226,    2, 0x0a /* Public */,
      51,    2,  227,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3, QMetaType::Int,   24,    7,
    QMetaType::Int, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   21,   28,   29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   37,   39,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   52,   53,

       0        // eod
};

void CoreUAV::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CoreUAV *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->SendSignalPostRequest((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< char*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->signal_ShowCurrentWinchPos(); break;
        case 2: _t->signal_AddLogInEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->signal_ShowCurrentSCPos(); break;
        case 4: _t->signal_SC_AutoTest(); break;
        case 5: _t->signal_SC_WritePos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->signal_NetStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->signal_ShowCurrentIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->signal_ShowPWM(); break;
        case 9: { int _r = _t->PostUAVStatus((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->OnPostUAVStatus((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->On_Winch_SetPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 12: _t->StartWincTest(); break;
        case 13: _t->StopWincTest(); break;
        case 14: _t->WinchDataDump((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->WinchReset(); break;
        case 16: _t->WinchDelivery((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->WinchDeliveryEx((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->WinchRetract((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->WinchLoad(); break;
        case 20: _t->WinchLoadUP(); break;
        case 21: _t->SC_StartAutoTest(); break;
        case 22: _t->SC_StopAutoTest(); break;
        case 23: _t->On_SC_SetPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 24: _t->time_update(); break;
        case 25: _t->On_SubMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (CoreUAV::*)(char * , char * , char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::SendSignalPostRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CoreUAV::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::signal_ShowCurrentWinchPos)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CoreUAV::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::signal_AddLogInEdit)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CoreUAV::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::signal_ShowCurrentSCPos)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CoreUAV::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::signal_SC_AutoTest)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CoreUAV::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::signal_SC_WritePos)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CoreUAV::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::signal_NetStatus)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CoreUAV::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::signal_ShowCurrentIO)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CoreUAV::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreUAV::signal_ShowPWM)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CoreUAV::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CoreUAV.data,
    qt_meta_data_CoreUAV,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CoreUAV::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CoreUAV::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CoreUAV.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CoreUAV::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
int CoreUAV::SendSignalPostRequest(char * _t1, char * _t2, char * _t3, int _t4)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
void CoreUAV::signal_ShowCurrentWinchPos()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CoreUAV::signal_AddLogInEdit(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CoreUAV::signal_ShowCurrentSCPos()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CoreUAV::signal_SC_AutoTest()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CoreUAV::signal_SC_WritePos(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CoreUAV::signal_NetStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CoreUAV::signal_ShowCurrentIO(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CoreUAV::signal_ShowPWM()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
