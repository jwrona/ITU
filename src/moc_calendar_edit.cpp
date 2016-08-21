/****************************************************************************
** Meta object code from reading C++ file 'calendar_edit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calendar_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_calendar_edit_t {
    QByteArrayData data[12];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_calendar_edit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_calendar_edit_t qt_meta_stringdata_calendar_edit = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 6),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 9),
QT_MOC_LITERAL(4, 32, 5),
QT_MOC_LITERAL(5, 38, 2),
QT_MOC_LITERAL(6, 41, 15),
QT_MOC_LITERAL(7, 57, 9),
QT_MOC_LITERAL(8, 67, 9),
QT_MOC_LITERAL(9, 77, 31),
QT_MOC_LITERAL(10, 109, 4),
QT_MOC_LITERAL(11, 114, 28)
    },
    "calendar_edit\0set_ID\0\0gcal_api*\0g_api\0"
    "id\0local_calendar*\0local_cal\0show_json\0"
    "on_summary_lineEdit_textChanged\0arg1\0"
    "on_update_pushButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calendar_edit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a,
       1,    2,   44,    2, 0x0a,
       8,    0,   49,    2, 0x0a,
       9,    1,   50,    2, 0x08,
      11,    0,   53,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void calendar_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calendar_edit *_t = static_cast<calendar_edit *>(_o);
        switch (_id) {
        case 0: _t->set_ID((*reinterpret_cast< gcal_api*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->set_ID((*reinterpret_cast< local_calendar*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->show_json(); break;
        case 3: _t->on_summary_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_update_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gcal_api* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< local_calendar* >(); break;
            }
            break;
        }
    }
}

const QMetaObject calendar_edit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_calendar_edit.data,
      qt_meta_data_calendar_edit,  qt_static_metacall, 0, 0}
};


const QMetaObject *calendar_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calendar_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_calendar_edit.stringdata))
        return static_cast<void*>(const_cast< calendar_edit*>(this));
    return QDialog::qt_metacast(_clname);
}

int calendar_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
