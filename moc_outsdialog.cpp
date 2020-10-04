/****************************************************************************
** Meta object code from reading C++ file 'outsdialog.h'
**
** Created: Mon Dec 2 22:17:55 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "outsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'outsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_outsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x0a,
      35,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_outsDialog[] = {
    "outsDialog\0\0row\0updateButtons(int)\0"
    "submit()\0"
};

void outsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        outsDialog *_t = static_cast<outsDialog *>(_o);
        switch (_id) {
        case 0: _t->updateButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->submit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData outsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject outsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_outsDialog,
      qt_meta_data_outsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &outsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *outsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *outsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_outsDialog))
        return static_cast<void*>(const_cast< outsDialog*>(this));
    if (!strcmp(_clname, "Ui::doorsDialog"))
        return static_cast< Ui::doorsDialog*>(const_cast< outsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int outsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
