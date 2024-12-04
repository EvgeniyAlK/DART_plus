/****************************************************************************
** Meta object code from reading C++ file 'GDSerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/GDPlatform/GDSerialPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GDSerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GDSerialPort_t {
    QByteArrayData data[16];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GDSerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GDSerialPort_t qt_meta_stringdata_GDSerialPort = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GDSerialPort"
QT_MOC_LITERAL(1, 13, 13), // "responseReady"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "response"
QT_MOC_LITERAL(4, 37, 14), // "sendingCommand"
QT_MOC_LITERAL(5, 52, 7), // "command"
QT_MOC_LITERAL(6, 60, 5), // "State"
QT_MOC_LITERAL(7, 66, 7), // "Unknown"
QT_MOC_LITERAL(8, 74, 4), // "Scan"
QT_MOC_LITERAL(9, 79, 11), // "DeviceFound"
QT_MOC_LITERAL(10, 91, 10), // "Connecting"
QT_MOC_LITERAL(11, 102, 9), // "Connected"
QT_MOC_LITERAL(12, 112, 14), // "SendingCommand"
QT_MOC_LITERAL(13, 127, 11), // "CommandSent"
QT_MOC_LITERAL(14, 139, 11), // "ReadingData"
QT_MOC_LITERAL(15, 151, 8) // "DataRead"

    },
    "GDSerialPort\0responseReady\0\0response\0"
    "sendingCommand\0command\0State\0Unknown\0"
    "Scan\0DeviceFound\0Connecting\0Connected\0"
    "SendingCommand\0CommandSent\0ReadingData\0"
    "DataRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GDSerialPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       1,   30, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    5,

 // enums: name, alias, flags, count, data
       6,    6, 0x0,    9,   35,

 // enum data: key, value
       7, uint(GDSerialPort::Unknown),
       8, uint(GDSerialPort::Scan),
       9, uint(GDSerialPort::DeviceFound),
      10, uint(GDSerialPort::Connecting),
      11, uint(GDSerialPort::Connected),
      12, uint(GDSerialPort::SendingCommand),
      13, uint(GDSerialPort::CommandSent),
      14, uint(GDSerialPort::ReadingData),
      15, uint(GDSerialPort::DataRead),

       0        // eod
};

void GDSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GDSerialPort *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->responseReady((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendingCommand((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GDSerialPort::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GDSerialPort::responseReady)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GDSerialPort::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_GDSerialPort.data,
    qt_meta_data_GDSerialPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GDSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GDSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GDSerialPort.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int GDSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GDSerialPort::responseReady(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
