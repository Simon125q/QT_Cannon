/****************************************************************************
** Meta object code from reading C++ file 'CannonField.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "CannonField.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CannonField.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CannonField_t {
    QByteArrayData data[20];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CannonField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CannonField_t qt_meta_stringdata_CannonField = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CannonField"
QT_MOC_LITERAL(1, 12, 12), // "angleChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "newAngle"
QT_MOC_LITERAL(4, 35, 12), // "forceChanged"
QT_MOC_LITERAL(5, 48, 8), // "newForce"
QT_MOC_LITERAL(6, 57, 9), // "targetHit"
QT_MOC_LITERAL(7, 67, 12), // "targetMissed"
QT_MOC_LITERAL(8, 80, 8), // "canShoot"
QT_MOC_LITERAL(9, 89, 3), // "can"
QT_MOC_LITERAL(10, 93, 8), // "setAngle"
QT_MOC_LITERAL(11, 102, 5), // "angle"
QT_MOC_LITERAL(12, 108, 8), // "setForce"
QT_MOC_LITERAL(13, 117, 5), // "force"
QT_MOC_LITERAL(14, 123, 5), // "shoot"
QT_MOC_LITERAL(15, 129, 9), // "newTarget"
QT_MOC_LITERAL(16, 139, 19), // "showBulletTrajctory"
QT_MOC_LITERAL(17, 159, 11), // "setGameOver"
QT_MOC_LITERAL(18, 171, 11), // "restartGame"
QT_MOC_LITERAL(19, 183, 8) // "moveShot"

    },
    "CannonField\0angleChanged\0\0newAngle\0"
    "forceChanged\0newForce\0targetHit\0"
    "targetMissed\0canShoot\0can\0setAngle\0"
    "angle\0setForce\0force\0shoot\0newTarget\0"
    "showBulletTrajctory\0setGameOver\0"
    "restartGame\0moveShot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CannonField[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    0,   85,    2, 0x06 /* Public */,
       7,    0,   86,    2, 0x06 /* Public */,
       8,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   90,    2, 0x0a /* Public */,
      12,    1,   93,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,
      16,    0,   98,    2, 0x0a /* Public */,
      17,    0,   99,    2, 0x0a /* Public */,
      18,    0,  100,    2, 0x0a /* Public */,
      19,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CannonField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CannonField *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->angleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->forceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->targetHit(); break;
        case 3: _t->targetMissed(); break;
        case 4: _t->canShoot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setForce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->shoot(); break;
        case 8: _t->newTarget(); break;
        case 9: _t->showBulletTrajctory(); break;
        case 10: _t->setGameOver(); break;
        case 11: _t->restartGame(); break;
        case 12: _t->moveShot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CannonField::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::angleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CannonField::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::forceChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CannonField::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::targetHit)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CannonField::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::targetMissed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CannonField::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::canShoot)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CannonField::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CannonField.data,
    qt_meta_data_CannonField,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CannonField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CannonField::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CannonField.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CannonField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CannonField::angleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CannonField::forceChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CannonField::targetHit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CannonField::targetMissed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CannonField::canShoot(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
