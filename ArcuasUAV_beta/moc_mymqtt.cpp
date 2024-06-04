/****************************************************************************
** Meta object code from reading C++ file 'mymqtt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mymqtt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymqtt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myMqtt_t {
    QByteArrayData data[28];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myMqtt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myMqtt_t qt_meta_stringdata_myMqtt = {
    {
QT_MOC_LITERAL(0, 0, 6), // "myMqtt"
QT_MOC_LITERAL(1, 7, 13), // "signal_SubMsg"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "sTopic"
QT_MOC_LITERAL(4, 29, 1), // "s"
QT_MOC_LITERAL(5, 31, 13), // "setClientHost"
QT_MOC_LITERAL(6, 45, 6), // "s_Host"
QT_MOC_LITERAL(7, 52, 13), // "setClientPort"
QT_MOC_LITERAL(8, 66, 1), // "p"
QT_MOC_LITERAL(9, 68, 17), // "setClientUserName"
QT_MOC_LITERAL(10, 86, 5), // "sName"
QT_MOC_LITERAL(11, 92, 17), // "setClientPassword"
QT_MOC_LITERAL(12, 110, 4), // "sPwd"
QT_MOC_LITERAL(13, 115, 10), // "setPublish"
QT_MOC_LITERAL(14, 126, 4), // "sMsg"
QT_MOC_LITERAL(15, 131, 3), // "qos"
QT_MOC_LITERAL(16, 135, 12), // "setSubscribe"
QT_MOC_LITERAL(17, 148, 8), // "getState"
QT_MOC_LITERAL(18, 157, 8), // "QString&"
QT_MOC_LITERAL(19, 166, 9), // "s_content"
QT_MOC_LITERAL(20, 176, 9), // "connected"
QT_MOC_LITERAL(21, 186, 18), // "brokerDisconnected"
QT_MOC_LITERAL(22, 205, 15), // "WaitforConneted"
QT_MOC_LITERAL(23, 221, 10), // "timeout_ms"
QT_MOC_LITERAL(24, 232, 10), // "IsConneted"
QT_MOC_LITERAL(25, 243, 5), // "sleep"
QT_MOC_LITERAL(26, 249, 4), // "msec"
QT_MOC_LITERAL(27, 254, 20) // "updateLogStateChange"

    },
    "myMqtt\0signal_SubMsg\0\0sTopic\0s\0"
    "setClientHost\0s_Host\0setClientPort\0p\0"
    "setClientUserName\0sName\0setClientPassword\0"
    "sPwd\0setPublish\0sMsg\0qos\0setSubscribe\0"
    "getState\0QString&\0s_content\0connected\0"
    "brokerDisconnected\0WaitforConneted\0"
    "timeout_ms\0IsConneted\0sleep\0msec\0"
    "updateLogStateChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myMqtt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   94,    2, 0x0a /* Public */,
       7,    1,   97,    2, 0x0a /* Public */,
       9,    1,  100,    2, 0x0a /* Public */,
      11,    1,  103,    2, 0x0a /* Public */,
      13,    3,  106,    2, 0x0a /* Public */,
      13,    3,  113,    2, 0x0a /* Public */,
      16,    1,  120,    2, 0x0a /* Public */,
      17,    1,  123,    2, 0x0a /* Public */,
      20,    0,  126,    2, 0x0a /* Public */,
      21,    0,  127,    2, 0x0a /* Public */,
      22,    1,  128,    2, 0x0a /* Public */,
      24,    0,  131,    2, 0x0a /* Public */,
      25,    1,  132,    2, 0x08 /* Private */,
      27,    0,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::UChar,    3,   14,   15,
    QMetaType::Bool, QMetaType::QString, QMetaType::QByteArray, QMetaType::UChar,    3,   14,   15,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int,   23,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::UInt,   26,
    QMetaType::Void,

       0        // eod
};

void myMqtt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<myMqtt *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_SubMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->setClientHost((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setClientPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setClientUserName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setClientPassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { bool _r = _t->setPublish((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->setPublish((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->setSubscribe((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->getState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->connected(); break;
        case 10: _t->brokerDisconnected(); break;
        case 11: { bool _r = _t->WaitforConneted((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->IsConneted();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->sleep((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 14: _t->updateLogStateChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (myMqtt::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myMqtt::signal_SubMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject myMqtt::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_myMqtt.data,
    qt_meta_data_myMqtt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *myMqtt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myMqtt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myMqtt.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int myMqtt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void myMqtt::signal_SubMsg(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
