/****************************************************************************
** Meta object code from reading C++ file 'gpib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gpib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gpib_t {
    QByteArrayData data[17];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gpib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gpib_t qt_meta_stringdata_gpib = {
    {
QT_MOC_LITERAL(0, 0, 4), // "gpib"
QT_MOC_LITERAL(1, 5, 19), // "on_cb_k2400_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 19), // "on_cb_k2460_clicked"
QT_MOC_LITERAL(4, 46, 26), // "on_cb_ramp_current_clicked"
QT_MOC_LITERAL(5, 73, 26), // "on_cb_ramp_voltage_clicked"
QT_MOC_LITERAL(6, 100, 25), // "on_cb_linereg_vol_clicked"
QT_MOC_LITERAL(7, 126, 26), // "on_cb_linereg_curr_clicked"
QT_MOC_LITERAL(8, 153, 24), // "on_cb_start_ramp_clicked"
QT_MOC_LITERAL(9, 178, 23), // "on_cb_test_mult_clicked"
QT_MOC_LITERAL(10, 202, 21), // "on_cb_loadreg_clicked"
QT_MOC_LITERAL(11, 224, 23), // "on_start_button_clicked"
QT_MOC_LITERAL(12, 248, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(13, 273, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(14, 297, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(15, 321, 28), // "on_actionTestchips_triggered"
QT_MOC_LITERAL(16, 350, 23) // "on_cb_stop_ramp_clicked"

    },
    "gpib\0on_cb_k2400_clicked\0\0on_cb_k2460_clicked\0"
    "on_cb_ramp_current_clicked\0"
    "on_cb_ramp_voltage_clicked\0"
    "on_cb_linereg_vol_clicked\0"
    "on_cb_linereg_curr_clicked\0"
    "on_cb_start_ramp_clicked\0"
    "on_cb_test_mult_clicked\0on_cb_loadreg_clicked\0"
    "on_start_button_clicked\0"
    "on_actionAbout_triggered\0"
    "on_actionExit_triggered\0on_actionOpen_triggered\0"
    "on_actionTestchips_triggered\0"
    "on_cb_stop_ramp_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gpib[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gpib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gpib *_t = static_cast<gpib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cb_k2400_clicked(); break;
        case 1: _t->on_cb_k2460_clicked(); break;
        case 2: _t->on_cb_ramp_current_clicked(); break;
        case 3: _t->on_cb_ramp_voltage_clicked(); break;
        case 4: _t->on_cb_linereg_vol_clicked(); break;
        case 5: _t->on_cb_linereg_curr_clicked(); break;
        case 6: _t->on_cb_start_ramp_clicked(); break;
        case 7: _t->on_cb_test_mult_clicked(); break;
        case 8: _t->on_cb_loadreg_clicked(); break;
        case 9: _t->on_start_button_clicked(); break;
        case 10: _t->on_actionAbout_triggered(); break;
        case 11: _t->on_actionExit_triggered(); break;
        case 12: _t->on_actionOpen_triggered(); break;
        case 13: _t->on_actionTestchips_triggered(); break;
        case 14: _t->on_cb_stop_ramp_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject gpib::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_gpib.data,
      qt_meta_data_gpib,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gpib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gpib::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gpib.stringdata0))
        return static_cast<void*>(const_cast< gpib*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int gpib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
