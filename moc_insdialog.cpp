/****************************************************************************
** Meta object code from reading C++ file 'insdialog.h'
**
** Created: Thu Jan 2 23:16:10 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "insdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'insdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_insDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x08,
      34,   10,   10,   10, 0x08,
      43,   10,   10,   10, 0x08,
      54,   10,   10,   10, 0x08,
      63,   10,   10,   10, 0x08,
      81,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_insDialog[] = {
    "insDialog\0\0row\0updateButtons(int)\0"
    "submit()\0submitDB()\0revert()\0"
    "addActivatedOut()\0removeActivatedOut()\0"
};

void insDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        insDialog *_t = static_cast<insDialog *>(_o);
        switch (_id) {
        case 0: _t->updateButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->submit(); break;
        case 2: _t->submitDB(); break;
        case 3: _t->revert(); break;
        case 4: _t->addActivatedOut(); break;
        case 5: _t->removeActivatedOut(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData insDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject insDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_insDialog,
      qt_meta_data_insDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &insDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *insDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *insDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_insDialog))
        return static_cast<void*>(const_cast< insDialog*>(this));
    if (!strcmp(_clname, "Ui::insDialog"))
        return static_cast< Ui::insDialog*>(const_cast< insDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int insDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
