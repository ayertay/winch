/****************************************************************************
** Meta object code from reading C++ file 'workthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "workthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorkThread_t {
    QByteArrayData data[15];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkThread_t qt_meta_stringdata_WorkThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WorkThread"
QT_MOC_LITERAL(1, 11, 20), // "SignalgetStatusReady"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "char*"
QT_MOC_LITERAL(4, 39, 19), // "SignalPostUAVStatus"
QT_MOC_LITERAL(5, 59, 1), // "s"
QT_MOC_LITERAL(6, 61, 19), // "signal_Winch_SetPos"
QT_MOC_LITERAL(7, 81, 3), // "alt"
QT_MOC_LITERAL(8, 85, 1), // "v"
QT_MOC_LITERAL(9, 87, 5), // "v_acc"
QT_MOC_LITERAL(10, 93, 20), // "signal_Winch_ReadPos"
QT_MOC_LITERAL(11, 114, 23), // "signal_ShowCurrentSCPos"
QT_MOC_LITERAL(12, 138, 26), // "signal_ShowCurrentWinchPos"
QT_MOC_LITERAL(13, 165, 18), // "signal_SC_AutoTest"
QT_MOC_LITERAL(14, 184, 13) // "showUAVStatus"

    },
    "WorkThread\0SignalgetStatusReady\0\0char*\0"
    "SignalPostUAVStatus\0s\0signal_Winch_SetPos\0"
    "alt\0v\0v_acc\0signal_Winch_ReadPos\0"
    "signal_ShowCurrentSCPos\0"
    "signal_ShowCurrentWinchPos\0"
    "signal_SC_AutoTest\0showUAVStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       4,    1,   59,    2, 0x06 /* Public */,
       6,    3,   62,    2, 0x06 /* Public */,
      10,    0,   69,    2, 0x06 /* Public */,
      11,    0,   70,    2, 0x06 /* Public */,
      12,    0,   71,    2, 0x06 /* Public */,
      13,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3, QMetaType::Int,    2,    2,

       0        // eod
};

void WorkThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorkThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->SignalgetStatusReady((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SignalPostUAVStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signal_Winch_SetPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->signal_Winch_ReadPos(); break;
        case 4: _t->signal_ShowCurrentSCPos(); break;
        case 5: _t->signal_ShowCurrentWinchPos(); break;
        case 6: _t->signal_SC_AutoTest(); break;
        case 7: { int _r = _t->showUAVStatus((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (WorkThread::*)(char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::SignalgetStatusReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WorkThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::SignalPostUAVStatus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WorkThread::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::signal_Winch_SetPos)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WorkThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::signal_Winch_ReadPos)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WorkThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::signal_ShowCurrentSCPos)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WorkThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::signal_ShowCurrentWinchPos)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WorkThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkThread::signal_SC_AutoTest)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WorkThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_WorkThread.data,
    qt_meta_data_WorkThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WorkThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int WorkThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
int WorkThread::SignalgetStatusReady(char * _t1, int _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
void WorkThread::SignalPostUAVStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WorkThread::signal_Winch_SetPos(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WorkThread::signal_Winch_ReadPos()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WorkThread::signal_ShowCurrentSCPos()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WorkThread::signal_ShowCurrentWinchPos()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WorkThread::signal_SC_AutoTest()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
