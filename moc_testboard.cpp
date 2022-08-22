/****************************************************************************
** Meta object code from reading C++ file 'testboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "testboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestBoard_t {
    QByteArrayData data[12];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestBoard_t qt_meta_stringdata_TestBoard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TestBoard"
QT_MOC_LITERAL(1, 10, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "on_show_board_clicked"
QT_MOC_LITERAL(4, 57, 19), // "on_cb_rd53a_clicked"
QT_MOC_LITERAL(5, 77, 21), // "on_cb_rd53b_a_clicked"
QT_MOC_LITERAL(6, 99, 21), // "on_cb_rd53b_b_clicked"
QT_MOC_LITERAL(7, 121, 21), // "on_cb_rd53b_c_clicked"
QT_MOC_LITERAL(8, 143, 25), // "on_cb_linereg_vol_clicked"
QT_MOC_LITERAL(9, 169, 26), // "on_cb_linereg_curr_clicked"
QT_MOC_LITERAL(10, 196, 21), // "on_cb_loadreg_clicked"
QT_MOC_LITERAL(11, 218, 24) // "on_cb_start_ramp_clicked"

    },
    "TestBoard\0on_actionExit_triggered\0\0"
    "on_show_board_clicked\0on_cb_rd53a_clicked\0"
    "on_cb_rd53b_a_clicked\0on_cb_rd53b_b_clicked\0"
    "on_cb_rd53b_c_clicked\0on_cb_linereg_vol_clicked\0"
    "on_cb_linereg_curr_clicked\0"
    "on_cb_loadreg_clicked\0on_cb_start_ramp_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestBoard[] = {

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
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestBoard *_t = static_cast<TestBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionExit_triggered(); break;
        case 1: _t->on_show_board_clicked(); break;
        case 2: _t->on_cb_rd53a_clicked(); break;
        case 3: _t->on_cb_rd53b_a_clicked(); break;
        case 4: _t->on_cb_rd53b_b_clicked(); break;
        case 5: _t->on_cb_rd53b_c_clicked(); break;
        case 6: _t->on_cb_linereg_vol_clicked(); break;
        case 7: _t->on_cb_linereg_curr_clicked(); break;
        case 8: _t->on_cb_loadreg_clicked(); break;
        case 9: _t->on_cb_start_ramp_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TestBoard::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestBoard.data,
      qt_meta_data_TestBoard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TestBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TestBoard.stringdata0))
        return static_cast<void*>(const_cast< TestBoard*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TestBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
