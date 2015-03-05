/****************************************************************************
** Meta object code from reading C++ file 'myqwtplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myqwtplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myqwtplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyQwtPlot_t {
    QByteArrayData data[8];
    char stringdata[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQwtPlot_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQwtPlot_t qt_meta_stringdata_MyQwtPlot = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MyQwtPlot"
QT_MOC_LITERAL(1, 10, 12), // "valueChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "selectedFun"
QT_MOC_LITERAL(4, 36, 3), // "pos"
QT_MOC_LITERAL(5, 40, 14), // "DrawShadowline"
QT_MOC_LITERAL(6, 55, 3), // "max"
QT_MOC_LITERAL(7, 59, 3) // "min"

    },
    "MyQwtPlot\0valueChanged\0\0selectedFun\0"
    "pos\0DrawShadowline\0max\0min"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQwtPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   34,    2, 0x0a /* Public */,
       5,    2,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,

       0        // eod
};

void MyQwtPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyQwtPlot *_t = static_cast<MyQwtPlot *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->selectedFun((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 2: _t->DrawShadowline((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyQwtPlot::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyQwtPlot::valueChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MyQwtPlot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyQwtPlot.data,
      qt_meta_data_MyQwtPlot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyQwtPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQwtPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyQwtPlot.stringdata))
        return static_cast<void*>(const_cast< MyQwtPlot*>(this));
    return QObject::qt_metacast(_clname);
}

int MyQwtPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyQwtPlot::valueChanged(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
