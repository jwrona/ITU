/****************************************************************************
** Meta object code from reading C++ file 'calendar_create.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calendar_create.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar_create.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_calendar_create_t {
    QByteArrayData data[7];
    char stringdata[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_calendar_create_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_calendar_create_t qt_meta_stringdata_calendar_create = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 7),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 4),
QT_MOC_LITERAL(4, 30, 31),
QT_MOC_LITERAL(5, 62, 4),
QT_MOC_LITERAL(6, 67, 28)
    },
    "calendar_create\0refresh\0\0send\0"
    "on_summary_lineEdit_textChanged\0arg1\0"
    "on_create_pushButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calendar_create[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a,
       4,    1,   36,    2, 0x08,
       6,    0,   39,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void calendar_create::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calendar_create *_t = static_cast<calendar_create *>(_o);
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->send(); break;
        case 2: _t->on_summary_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_create_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (calendar_create::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calendar_create::refresh)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject calendar_create::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_calendar_create.data,
      qt_meta_data_calendar_create,  qt_static_metacall, 0, 0}
};


const QMetaObject *calendar_create::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calendar_create::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_calendar_create.stringdata))
        return static_cast<void*>(const_cast< calendar_create*>(this));
    return QDialog::qt_metacast(_clname);
}

int calendar_create::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void calendar_create::refresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
