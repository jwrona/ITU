/****************************************************************************
** Meta object code from reading C++ file 'event_create.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "event_create.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'event_create.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_event_create_t {
    QByteArrayData data[9];
    char stringdata[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_event_create_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_event_create_t qt_meta_stringdata_event_create = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 7),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 4),
QT_MOC_LITERAL(4, 27, 28),
QT_MOC_LITERAL(5, 56, 31),
QT_MOC_LITERAL(6, 88, 4),
QT_MOC_LITERAL(7, 93, 29),
QT_MOC_LITERAL(8, 123, 27)
    },
    "event_create\0refresh\0\0send\0"
    "on_create_pushButton_clicked\0"
    "on_summary_lineEdit_textChanged\0arg1\0"
    "on_start_dateEdit_dateChanged\0"
    "on_end_dateEdit_dateChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_event_create[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x0a,
       4,    0,   46,    2, 0x08,
       5,    1,   47,    2, 0x08,
       7,    0,   50,    2, 0x08,
       8,    0,   51,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void event_create::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        event_create *_t = static_cast<event_create *>(_o);
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->send(); break;
        case 2: _t->on_create_pushButton_clicked(); break;
        case 3: _t->on_summary_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_start_dateEdit_dateChanged(); break;
        case 5: _t->on_end_dateEdit_dateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (event_create::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&event_create::refresh)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject event_create::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_event_create.data,
      qt_meta_data_event_create,  qt_static_metacall, 0, 0}
};


const QMetaObject *event_create::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *event_create::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_event_create.stringdata))
        return static_cast<void*>(const_cast< event_create*>(this));
    return QDialog::qt_metacast(_clname);
}

int event_create::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void event_create::refresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
