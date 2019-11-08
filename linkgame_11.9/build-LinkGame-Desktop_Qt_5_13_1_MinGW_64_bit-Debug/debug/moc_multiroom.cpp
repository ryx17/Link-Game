/****************************************************************************
** Meta object code from reading C++ file 'multiroom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LinkGame/multiroom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MultiRoom_t {
    QByteArrayData data[15];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MultiRoom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MultiRoom_t qt_meta_stringdata_MultiRoom = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MultiRoom"
QT_MOC_LITERAL(1, 10, 21), // "on_HostButton_toggled"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "checked"
QT_MOC_LITERAL(4, 41, 23), // "on_ClientButton_toggled"
QT_MOC_LITERAL(5, 65, 31), // "on_pushButtonBackToMenu_clicked"
QT_MOC_LITERAL(6, 97, 14), // "ClientReadData"
QT_MOC_LITERAL(7, 112, 15), // "ClientReadError"
QT_MOC_LITERAL(8, 128, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 157, 17), // "NewConnectionSlot"
QT_MOC_LITERAL(10, 175, 16), // "disconnectedSlot"
QT_MOC_LITERAL(11, 192, 14), // "ServerReadData"
QT_MOC_LITERAL(12, 207, 28), // "on_pushButtonConnect_clicked"
QT_MOC_LITERAL(13, 236, 26), // "on_pushButtonBuild_clicked"
QT_MOC_LITERAL(14, 263, 26) // "on_pushButtonStart_clicked"

    },
    "MultiRoom\0on_HostButton_toggled\0\0"
    "checked\0on_ClientButton_toggled\0"
    "on_pushButtonBackToMenu_clicked\0"
    "ClientReadData\0ClientReadError\0"
    "QAbstractSocket::SocketError\0"
    "NewConnectionSlot\0disconnectedSlot\0"
    "ServerReadData\0on_pushButtonConnect_clicked\0"
    "on_pushButtonBuild_clicked\0"
    "on_pushButtonStart_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultiRoom[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       5,    0,   75,    2, 0x08 /* Private */,
       6,    0,   76,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MultiRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MultiRoom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_HostButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_ClientButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonBackToMenu_clicked(); break;
        case 3: _t->ClientReadData(); break;
        case 4: _t->ClientReadError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->NewConnectionSlot(); break;
        case 6: _t->disconnectedSlot(); break;
        case 7: _t->ServerReadData(); break;
        case 8: _t->on_pushButtonConnect_clicked(); break;
        case 9: _t->on_pushButtonBuild_clicked(); break;
        case 10: _t->on_pushButtonStart_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MultiRoom::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MultiRoom.data,
    qt_meta_data_MultiRoom,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MultiRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MultiRoom.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MultiRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
