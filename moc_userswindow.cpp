/****************************************************************************
** Meta object code from reading C++ file 'userswindow.h'
**
** Created: Fri May 16 15:03:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MiniPass_v1.0_beta1/views/userswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_usersWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   13,   12,   12, 0x08,
      36,   12,   12,   12, 0x08,
      45,   12,   12,   12, 0x08,
      55,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_usersWindow[] = {
    "usersWindow\0\0row\0updateButtons(int)\0"
    "submit()\0addUser()\0deleteUser()\0"
};

void usersWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        usersWindow *_t = static_cast<usersWindow *>(_o);
        switch (_id) {
        case 0: _t->updateButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->submit(); break;
        case 2: _t->addUser(); break;
        case 3: _t->deleteUser(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData usersWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject usersWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_usersWindow,
      qt_meta_data_usersWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &usersWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *usersWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *usersWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_usersWindow))
        return static_cast<void*>(const_cast< usersWindow*>(this));
    if (!strcmp(_clname, "Ui::usersDialog"))
        return static_cast< Ui::usersDialog*>(const_cast< usersWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int usersWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
