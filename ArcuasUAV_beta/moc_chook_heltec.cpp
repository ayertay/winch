/****************************************************************************
** Meta object code from reading C++ file 'chook_heltec.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "chook_heltec.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chook_heltec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CHook_Heltec_t {
    QByteArrayData data[21];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHook_Heltec_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHook_Heltec_t qt_meta_stringdata_CHook_Heltec = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CHook_Heltec"
QT_MOC_LITERAL(1, 13, 11), // "OpenComPort"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "QSerialPort*"
QT_MOC_LITERAL(4, 39, 5), // "_Port"
QT_MOC_LITERAL(5, 45, 9), // "_portName"
QT_MOC_LITERAL(6, 55, 5), // "_baud"
QT_MOC_LITERAL(7, 61, 21), // "QSerialPort::DataBits"
QT_MOC_LITERAL(8, 83, 9), // "_databits"
QT_MOC_LITERAL(9, 93, 21), // "QSerialPort::StopBits"
QT_MOC_LITERAL(10, 115, 9), // "_stopbits"
QT_MOC_LITERAL(11, 125, 19), // "QSerialPort::Parity"
QT_MOC_LITERAL(12, 145, 7), // "_parity"
QT_MOC_LITERAL(13, 153, 4), // "Init"
QT_MOC_LITERAL(14, 158, 16), // "s_SerialPortName"
QT_MOC_LITERAL(15, 175, 9), // "lora_addr"
QT_MOC_LITERAL(16, 185, 12), // "readHookData"
QT_MOC_LITERAL(17, 198, 9), // "Hook_Open"
QT_MOC_LITERAL(18, 208, 10), // "Hook_Close"
QT_MOC_LITERAL(19, 219, 11), // "Hook_PwmSet"
QT_MOC_LITERAL(20, 231, 3) // "pwm"

    },
    "CHook_Heltec\0OpenComPort\0\0QSerialPort*\0"
    "_Port\0_portName\0_baud\0QSerialPort::DataBits\0"
    "_databits\0QSerialPort::StopBits\0"
    "_stopbits\0QSerialPort::Parity\0_parity\0"
    "Init\0s_SerialPortName\0lora_addr\0"
    "readHookData\0Hook_Open\0Hook_Close\0"
    "Hook_PwmSet\0pwm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHook_Heltec[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    6,   44,    2, 0x0a /* Public */,
      13,    2,   57,    2, 0x0a /* Public */,
      16,    0,   62,    2, 0x0a /* Public */,
      17,    0,   63,    2, 0x0a /* Public */,
      18,    0,   64,    2, 0x0a /* Public */,
      19,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3, QMetaType::QString, QMetaType::Int, 0x80000000 | 7, 0x80000000 | 9, 0x80000000 | 11,    4,    5,    6,    8,   10,   12,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void CHook_Heltec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CHook_Heltec *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->OpenComPort((*reinterpret_cast< QSerialPort*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3])),(*reinterpret_cast< QSerialPort::DataBits(*)>(_a[4])),(*reinterpret_cast< QSerialPort::StopBits(*)>(_a[5])),(*reinterpret_cast< QSerialPort::Parity(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->Init((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->readHookData(); break;
        case 3: _t->Hook_Open(); break;
        case 4: _t->Hook_Close(); break;
        case 5: _t->Hook_PwmSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CHook_Heltec::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CHook_Heltec.data,
    qt_meta_data_CHook_Heltec,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CHook_Heltec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHook_Heltec::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CHook_Heltec.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CHook_Heltec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
