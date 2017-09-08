/****************************************************************************
** Meta object code from reading C++ file 'p04_alarmquery_dialog.h'
**
** Created: Fri Apr 18 16:43:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "p04_alarmquery_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'p04_alarmquery_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_p04_alarmquery_dialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   22,   22,   22, 0x08,
      60,   22,   22,   22, 0x08,
      76,   22,   22,   22, 0x08,
      90,   22,   22,   22, 0x08,
     105,   22,   22,   22, 0x08,
     121,   22,   22,   22, 0x08,
     145,   22,   22,   22, 0x08,
     168,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_p04_alarmquery_dialog[] = {
    "p04_alarmquery_dialog\0\0signal_exit_p04dlg()\0"
    "init_page_dlg()\0init_page_val()\0"
    "start_timer()\0timer_handle()\0"
    "exit_page_dlg()\0on_pbtn_enter_clicked()\0"
    "on_pbtn_down_clicked()\0on_pbtn_up_clicked()\0"
};

void p04_alarmquery_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        p04_alarmquery_dialog *_t = static_cast<p04_alarmquery_dialog *>(_o);
        switch (_id) {
        case 0: _t->signal_exit_p04dlg(); break;
        case 1: _t->init_page_dlg(); break;
        case 2: _t->init_page_val(); break;
        case 3: _t->start_timer(); break;
        case 4: _t->timer_handle(); break;
        case 5: _t->exit_page_dlg(); break;
        case 6: _t->on_pbtn_enter_clicked(); break;
        case 7: _t->on_pbtn_down_clicked(); break;
        case 8: _t->on_pbtn_up_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData p04_alarmquery_dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject p04_alarmquery_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_p04_alarmquery_dialog,
      qt_meta_data_p04_alarmquery_dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &p04_alarmquery_dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *p04_alarmquery_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *p04_alarmquery_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_p04_alarmquery_dialog))
        return static_cast<void*>(const_cast< p04_alarmquery_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int p04_alarmquery_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void p04_alarmquery_dialog::signal_exit_p04dlg()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
