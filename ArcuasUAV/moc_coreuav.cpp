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
    QByteArrayData data[47];
    char stringdata0[486];
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
QT_MOC_LITERAL(19, 200, 13), // "PostUAVStatus"
QT_MOC_LITERAL(20, 214, 7), // "sStatus"
QT_MOC_LITERAL(21, 222, 15), // "OnPostUAVStatus"
QT_MOC_LITERAL(22, 238, 15), // "On_Winch_SetPos"
QT_MOC_LITERAL(23, 254, 3), // "alt"
QT_MOC_LITERAL(24, 258, 1), // "v"
QT_MOC_LITERAL(25, 260, 5), // "v_acc"
QT_MOC_LITERAL(26, 266, 6), // "torque"
QT_MOC_LITERAL(27, 273, 7), // "isbrake"
QT_MOC_LITERAL(28, 281, 13), // "StartWincTest"
QT_MOC_LITERAL(29, 295, 12), // "StopWincTest"
QT_MOC_LITERAL(30, 308, 13), // "WinchDataDump"
QT_MOC_LITERAL(31, 322, 7), // "i_onoff"
QT_MOC_LITERAL(32, 330, 10), // "WinchReset"
QT_MOC_LITERAL(33, 341, 13), // "WinchDelivery"
QT_MOC_LITERAL(34, 355, 12), // "WinchRetract"
QT_MOC_LITERAL(35, 368, 11), // "WinchLoadUP"
QT_MOC_LITERAL(36, 380, 16), // "SC_StartAutoTest"
QT_MOC_LITERAL(37, 397, 15), // "SC_StopAutoTest"
QT_MOC_LITERAL(38, 413, 12), // "On_SC_SetPos"
QT_MOC_LITERAL(39, 426, 2), // "ID"
QT_MOC_LITERAL(40, 429, 8), // "Position"
QT_MOC_LITERAL(41, 438, 4), // "Time"
QT_MOC_LITERAL(42, 443, 5), // "Speed"
QT_MOC_LITERAL(43, 449, 11), // "time_update"
QT_MOC_LITERAL(44, 461, 9), // "On_SubMsg"
QT_MOC_LITERAL(45, 471, 6), // "sTopic"
QT_MOC_LITERAL(46, 478, 7) // "message"

    },
    "CoreUAV\0SendSignalPostRequest\0\0char*\0"
    "host\0path\0buff\0len\0signal_ShowCurrentWinchPos\0"
    "signal_AddLogInEdit\0s\0signal_ShowCurrentSCPos\0"
    "signal_SC_AutoTest\0signal_SC_WritePos\0"
    "id\0pos\0time\0spd\0signal_NetStatus\0"
    "PostUAVStatus\0sStatus\0OnPostUAVStatus\0"
    "On_Winch_SetPos\0alt\0v\0v_acc\0torque\0"
    "isbrake\0StartWincTest\0StopWincTest\0"
    "WinchDataDump\0i_onoff\0WinchReset\0"
    "WinchDelivery\0WinchRetract\0WinchLoadUP\0"
    "SC_StartAutoTest\0SC_StopAutoTest\0"
    "On_SC_SetPos\0ID\0Position\0Time\0Speed\0"
    "time_update\0On_SubMsg\0sTopic\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoreUAV[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  124,    2, 0x06 /* Public */,
       8,    0,  133,    2, 0x06 /* Public */,
       9,    1,  134,    2, 0x06 /* Public */,
      11,    0,  137,    2, 0x06 /* Public */,
      12,    0,  138,    2, 0x06 /* Public */,
      13,    4,  139,    2, 0x06 /* Public */,
      18,    1,  148,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    2,  151,    2, 0x0a /* Public */,
      21,    1,  156,    2, 0x0a /* Public */,
      22,    5,  159,    2, 0x0a /* Public */,
      28,    0,  170,    2, 0x0a /* Public */,
      29,    0,  171,    2, 0x0a /* Public */,
      30,    1,  172,    2, 0x0a /* Public */,
      32,    0,  175,    2, 0x0a /* Public */,
      33,    0,  176,    2, 0x0a /* Public */,
      34,    0,  177,    2, 0x0a /* Public */,
      35,    0,  178,    2, 0x0a /* Public */,
      36,    0,  179,    2, 0x0a /* Public */,
      37,    0,  180,    2, 0x0a /* Public */,
      38,    4,  181,    2, 0x0a /* Public */,
      43,    0,  190,    2, 0x0a /* Public */,
      44,    2,  191,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3, QMetaType::Int,   20,    7,
    QMetaType::Int, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   23,   24,   25,   26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   39,   40,   41,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   45,   46,

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
        case 7: { int _r = _t->PostUAVStatus((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->OnPostUAVStatus((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->On_Winch_SetPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 10: _t->StartWincTest(); break;
        case 11: _t->StopWincTest(); break;
        case 12: _t->WinchDataDump((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->WinchReset(); break;
        case 14: _t->WinchDelivery(); break;
        case 15: _t->WinchRetract(); break;
        case 16: _t->WinchLoadUP(); break;
        case 17: _t->SC_StartAutoTest(); break;
        case 18: _t->SC_StopAutoTest(); break;
        case 19: _t->On_SC_SetPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 20: _t->time_update(); break;
        case 21: _t->On_SubMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
