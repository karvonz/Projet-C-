/****************************************************************************
** Meta object code from reading C++ file 'playerinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/playerinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlayerInterface_t {
    QByteArrayData data[17];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerInterface_t qt_meta_stringdata_PlayerInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PlayerInterface"
QT_MOC_LITERAL(1, 16, 19), // "changeCurrentFilter"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "VComboBox*"
QT_MOC_LITERAL(4, 48, 11), // "listeFilter"
QT_MOC_LITERAL(5, 60, 8), // "openFile"
QT_MOC_LITERAL(6, 69, 8), // "QString*"
QT_MOC_LITERAL(7, 78, 4), // "name"
QT_MOC_LITERAL(8, 83, 14), // "changePosition"
QT_MOC_LITERAL(9, 98, 11), // "newPosition"
QT_MOC_LITERAL(10, 110, 13), // "drawNextFrame"
QT_MOC_LITERAL(11, 124, 18), // "frameCounterMethod"
QT_MOC_LITERAL(12, 143, 11), // "startButton"
QT_MOC_LITERAL(13, 155, 14), // "switchToWebCam"
QT_MOC_LITERAL(14, 170, 15), // "unlockFrameRate"
QT_MOC_LITERAL(15, 186, 12), // "stepOneFrame"
QT_MOC_LITERAL(16, 199, 12) // "resetFilters"

    },
    "PlayerInterface\0changeCurrentFilter\0"
    "\0VComboBox*\0listeFilter\0openFile\0"
    "QString*\0name\0changePosition\0newPosition\0"
    "drawNextFrame\0frameCounterMethod\0"
    "startButton\0switchToWebCam\0unlockFrameRate\0"
    "stepOneFrame\0resetFilters"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       5,    1,   67,    2, 0x0a /* Public */,
       8,    1,   70,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,
      11,    0,   74,    2, 0x0a /* Public */,
      12,    0,   75,    2, 0x0a /* Public */,
      13,    0,   76,    2, 0x0a /* Public */,
      14,    0,   77,    2, 0x0a /* Public */,
      15,    0,   78,    2, 0x0a /* Public */,
      16,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayerInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayerInterface *_t = static_cast<PlayerInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeCurrentFilter((*reinterpret_cast< VComboBox*(*)>(_a[1]))); break;
        case 1: _t->openFile((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 2: _t->changePosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->drawNextFrame(); break;
        case 4: _t->frameCounterMethod(); break;
        case 5: _t->startButton(); break;
        case 6: _t->switchToWebCam(); break;
        case 7: _t->unlockFrameRate(); break;
        case 8: _t->stepOneFrame(); break;
        case 9: _t->resetFilters(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VComboBox* >(); break;
            }
            break;
        }
    }
}

const QMetaObject PlayerInterface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayerInterface.data,
      qt_meta_data_PlayerInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlayerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerInterface.stringdata0))
        return static_cast<void*>(const_cast< PlayerInterface*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlayerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
