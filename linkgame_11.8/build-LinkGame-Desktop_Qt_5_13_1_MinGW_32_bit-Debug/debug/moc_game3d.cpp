/****************************************************************************
** Meta object code from reading C++ file 'game3d.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LinkGame/game3d.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game3d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Game3d_t {
    QByteArrayData data[8];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game3d_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game3d_t qt_meta_stringdata_Game3d = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Game3d"
QT_MOC_LITERAL(1, 7, 6), // "vanish"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 12), // "timeDecrease"
QT_MOC_LITERAL(4, 28, 12), // "timeIncrease"
QT_MOC_LITERAL(5, 41, 26), // "on_pushButtonPause_clicked"
QT_MOC_LITERAL(6, 68, 31), // "on_pushButtonBackToMenu_clicked"
QT_MOC_LITERAL(7, 100, 26) // "on_pushButtonCheat_clicked"

    },
    "Game3d\0vanish\0\0timeDecrease\0timeIncrease\0"
    "on_pushButtonPause_clicked\0"
    "on_pushButtonBackToMenu_clicked\0"
    "on_pushButtonCheat_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game3d[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Game3d::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game3d *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->vanish(); break;
        case 1: _t->timeDecrease(); break;
        case 2: _t->timeIncrease(); break;
        case 3: _t->on_pushButtonPause_clicked(); break;
        case 4: _t->on_pushButtonBackToMenu_clicked(); break;
        case 5: _t->on_pushButtonCheat_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Game3d::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game3d::vanish)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Game3d::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Game3d.data,
    qt_meta_data_Game3d,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Game3d::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game3d::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Game3d.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Game3d::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Game3d::vanish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
