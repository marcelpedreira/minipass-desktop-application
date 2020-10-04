/****************************************************************************
** Meta object code from reading C++ file 'accesslevelwindow.h'
**
** Created: Thu Jan 2 23:16:19 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "accesslevelwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accesslevelwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_accessLevelWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   19,   18,   18, 0x08,
      42,   18,   18,   18, 0x08,
      63,   18,   18,   18, 0x08,
      87,   18,   18,   18, 0x08,
      96,   18,   18,   18, 0x08,
     107,   18,   18,   18, 0x08,
     116,   18,   18,   18, 0x08,
     133,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_accessLevelWindow[] = {
    "accessLevelWindow\0\0row\0updateButtons(int)\0"
    "addAccessLevelDoor()\0removeAccessLevelDoor()\0"
    "submit()\0submitDB()\0revert()\0"
    "addAccessLevel()\0deleteAccessLevel()\0"
};

void accessLevelWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        accessLevelWindow *_t = static_cast<accessLevelWindow *>(_o);
        switch (_id) {
        case 0: _t->updateButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addAccessLevelDoor(); break;
        case 2: _t->removeAccessLevelDoor(); break;
        case 3: _t->submit(); break;
        case 4: _t->submitDB(); break;
        case 5: _t->revert(); break;
        case 6: _t->addAccessLevel(); break;
        case 7: _t->deleteAccessLevel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData accessLevelWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject accessLevelWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_accessLevelWindow,
      qt_meta_data_accessLevelWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &accessLevelWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *accessLevelWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *accessLevelWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_accessLevelWindow))
        return static_cast<void*>(const_cast< accessLevelWindow*>(this));
    if (!strcmp(_clname, "Ui::accessLevelWindow"))
        return static_cast< Ui::accessLevelWindow*>(const_cast< accessLevelWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int accessLevelWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
