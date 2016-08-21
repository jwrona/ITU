/****************************************************************************
** Meta object code from reading C++ file 'calendar_ui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calendar_ui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar_ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CalendarUi_t {
    QByteArrayData data[11];
    char stringdata[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CalendarUi_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CalendarUi_t qt_meta_stringdata_CalendarUi = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 15),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 12),
QT_MOC_LITERAL(4, 41, 16),
QT_MOC_LITERAL(5, 58, 7),
QT_MOC_LITERAL(6, 66, 15),
QT_MOC_LITERAL(7, 82, 10),
QT_MOC_LITERAL(8, 93, 13),
QT_MOC_LITERAL(9, 107, 14),
QT_MOC_LITERAL(10, 122, 9)
    },
    "CalendarUi\0change_interval\0\0send_to_back\0"
    "showMaximizedWin\0restore\0resize_relocate\0"
    "changeable\0setWeekLayout\0setMonthLayout\0"
    "setLayout\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalendarUi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a,
       3,    0,   55,    2, 0x0a,
       4,    0,   56,    2, 0x0a,
       5,    0,   57,    2, 0x0a,
       6,    1,   58,    2, 0x0a,
       8,    0,   61,    2, 0x0a,
       9,    0,   62,    2, 0x0a,
      10,    0,   63,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CalendarUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CalendarUi *_t = static_cast<CalendarUi *>(_o);
        switch (_id) {
        case 0: _t->change_interval(); break;
        case 1: _t->send_to_back(); break;
        case 2: _t->showMaximizedWin(); break;
        case 3: _t->restore(); break;
        case 4: _t->resize_relocate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setWeekLayout(); break;
        case 6: _t->setMonthLayout(); break;
        case 7: _t->setLayout(); break;
        default: ;
        }
    }
}

const QMetaObject CalendarUi::staticMetaObject = {
    { &QDeclarativeView::staticMetaObject, qt_meta_stringdata_CalendarUi.data,
      qt_meta_data_CalendarUi,  qt_static_metacall, 0, 0}
};


const QMetaObject *CalendarUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalendarUi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalendarUi.stringdata))
        return static_cast<void*>(const_cast< CalendarUi*>(this));
    return QDeclarativeView::qt_metacast(_clname);
}

int CalendarUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
