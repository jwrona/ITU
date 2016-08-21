/****************************************************************************
** Meta object code from reading C++ file 'event_edit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "event_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'event_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_event_edit_t {
    QByteArrayData data[7];
    char stringdata[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_event_edit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_event_edit_t qt_meta_stringdata_event_edit = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 28),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 31),
QT_MOC_LITERAL(4, 73, 4),
QT_MOC_LITERAL(5, 78, 29),
QT_MOC_LITERAL(6, 108, 27)
    },
    "event_edit\0on_update_pushButton_clicked\0"
    "\0on_summary_lineEdit_textChanged\0arg1\0"
    "on_start_dateEdit_dateChanged\0"
    "on_end_dateEdit_dateChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_event_edit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    1,   35,    2, 0x08,
       5,    0,   38,    2, 0x08,
       6,    0,   39,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void event_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        event_edit *_t = static_cast<event_edit *>(_o);
        switch (_id) {
        case 0: _t->on_update_pushButton_clicked(); break;
        case 1: _t->on_summary_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_start_dateEdit_dateChanged(); break;
        case 3: _t->on_end_dateEdit_dateChanged(); break;
        default: ;
        }
    }
}

const QMetaObject event_edit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_event_edit.data,
      qt_meta_data_event_edit,  qt_static_metacall, 0, 0}
};


const QMetaObject *event_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *event_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_event_edit.stringdata))
        return static_cast<void*>(const_cast< event_edit*>(this));
    return QDialog::qt_metacast(_clname);
}

int event_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
