/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata[582];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 6),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 37),
QT_MOC_LITERAL(4, 57, 35),
QT_MOC_LITERAL(5, 93, 37),
QT_MOC_LITERAL(6, 131, 34),
QT_MOC_LITERAL(7, 166, 32),
QT_MOC_LITERAL(8, 199, 34),
QT_MOC_LITERAL(9, 234, 27),
QT_MOC_LITERAL(10, 262, 31),
QT_MOC_LITERAL(11, 294, 34),
QT_MOC_LITERAL(12, 329, 7),
QT_MOC_LITERAL(13, 337, 29),
QT_MOC_LITERAL(14, 367, 16),
QT_MOC_LITERAL(15, 384, 14),
QT_MOC_LITERAL(16, 399, 21),
QT_MOC_LITERAL(17, 421, 18),
QT_MOC_LITERAL(18, 440, 11),
QT_MOC_LITERAL(19, 452, 39),
QT_MOC_LITERAL(20, 492, 36),
QT_MOC_LITERAL(21, 529, 16),
QT_MOC_LITERAL(22, 546, 4),
QT_MOC_LITERAL(23, 551, 10),
QT_MOC_LITERAL(24, 562, 12),
QT_MOC_LITERAL(25, 575, 5)
    },
    "MainWindow\0closed\0\0"
    "on_calendar_create_pushButton_clicked\0"
    "on_calendar_edit_pushButton_clicked\0"
    "on_calendar_delete_pushButton_clicked\0"
    "on_event_create_pushButton_clicked\0"
    "on_event_edit_pushButton_clicked\0"
    "on_event_delete_pushButton_clicked\0"
    "on_login_pushButton_clicked\0"
    "on_send_code_pushButton_clicked\0"
    "on_local_calendar_checkBox_toggled\0"
    "checked\0on_refresh_pushButton_clicked\0"
    "send_code_finish\0QNetworkReply*\0"
    "refresh_calendar_list\0refresh_event_list\0"
    "calendar_id\0on_calendar_list_listWidget_itemClicked\0"
    "on_event_list_listWidget_itemClicked\0"
    "QListWidgetItem*\0item\0closeEvent\0"
    "QCloseEvent*\0event\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,  100,    2, 0x0a,
       4,    0,  101,    2, 0x0a,
       5,    0,  102,    2, 0x0a,
       6,    0,  103,    2, 0x0a,
       7,    0,  104,    2, 0x0a,
       8,    0,  105,    2, 0x0a,
       9,    0,  106,    2, 0x0a,
      10,    0,  107,    2, 0x0a,
      11,    1,  108,    2, 0x0a,
      13,    0,  111,    2, 0x0a,
      14,    1,  112,    2, 0x0a,
      16,    0,  115,    2, 0x0a,
      17,    1,  116,    2, 0x0a,
      19,    0,  119,    2, 0x0a,
      20,    1,  120,    2, 0x0a,
      23,    1,  123,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 24,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->on_calendar_create_pushButton_clicked(); break;
        case 2: _t->on_calendar_edit_pushButton_clicked(); break;
        case 3: _t->on_calendar_delete_pushButton_clicked(); break;
        case 4: _t->on_event_create_pushButton_clicked(); break;
        case 5: _t->on_event_edit_pushButton_clicked(); break;
        case 6: _t->on_event_delete_pushButton_clicked(); break;
        case 7: _t->on_login_pushButton_clicked(); break;
        case 8: _t->on_send_code_pushButton_clicked(); break;
        case 9: _t->on_local_calendar_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_refresh_pushButton_clicked(); break;
        case 11: _t->send_code_finish((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 12: _t->refresh_calendar_list(); break;
        case 13: _t->refresh_event_list((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->on_calendar_list_listWidget_itemClicked(); break;
        case 15: _t->on_event_list_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 16: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::closed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
