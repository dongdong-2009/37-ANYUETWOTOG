/****************************************************************************
** Meta object code from reading C++ file 'p18_choose_charge_type.h'
**
** Created: Fri Apr 18 16:43:44 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "p18_choose_charge_type.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'p18_choose_charge_type.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_p18_choose_charge_type[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,
      53,   23,   23,   23, 0x05,
      82,   23,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   23,   23,   23, 0x08,
     119,   23,   23,   23, 0x08,
     135,   23,   23,   23, 0x08,
     149,   23,   23,   23, 0x08,
     164,   23,   23,   23, 0x08,
     180,   23,   23,   23, 0x08,
     195,   23,   23,   23, 0x08,
     210,   23,   23,   23, 0x08,
     236,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_p18_choose_charge_type[] = {
    "p18_choose_charge_type\0\0"
    "signal_enable_p02dlg_timer()\0"
    "signal_enable_p19dlg_timer()\0"
    "signal_exit_p18dlg()\0init_page_dlg()\0"
    "init_page_val()\0start_timer()\0"
    "timer_handle()\0exit_page_dlg()\0"
    "call_p02_dlg()\0call_p19_dlg()\0"
    "on_pbtn_type_dc_clicked()\0"
    "on_pbtn_type_ac_clicked()\0"
};

void p18_choose_charge_type::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        p18_choose_charge_type *_t = static_cast<p18_choose_charge_type *>(_o);
        switch (_id) {
        case 0: _t->signal_enable_p02dlg_timer(); break;
        case 1: _t->signal_enable_p19dlg_timer(); break;
        case 2: _t->signal_exit_p18dlg(); break;
        case 3: _t->init_page_dlg(); break;
        case 4: _t->init_page_val(); break;
        case 5: _t->start_timer(); break;
        case 6: _t->timer_handle(); break;
        case 7: _t->exit_page_dlg(); break;
        case 8: _t->call_p02_dlg(); break;
        case 9: _t->call_p19_dlg(); break;
        case 10: _t->on_pbtn_type_dc_clicked(); break;
        case 11: _t->on_pbtn_type_ac_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData p18_choose_charge_type::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject p18_choose_charge_type::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_p18_choose_charge_type,
      qt_meta_data_p18_choose_charge_type, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &p18_choose_charge_type::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *p18_choose_charge_type::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *p18_choose_charge_type::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_p18_choose_charge_type))
        return static_cast<void*>(const_cast< p18_choose_charge_type*>(this));
    return QDialog::qt_metacast(_clname);
}

int p18_choose_charge_type::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void p18_choose_charge_type::signal_enable_p02dlg_timer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void p18_choose_charge_type::signal_enable_p19dlg_timer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void p18_choose_charge_type::signal_exit_p18dlg()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
