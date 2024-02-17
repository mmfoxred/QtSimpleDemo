/****************************************************************************
** Meta object code from reading C++ file 'battery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../battery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'battery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Battery_t {
    QByteArrayData data[22];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Battery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Battery_t qt_meta_stringdata_Battery = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Battery"
QT_MOC_LITERAL(1, 8, 12), // "valueChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "value"
QT_MOC_LITERAL(4, 28, 11), // "updateValue"
QT_MOC_LITERAL(5, 40, 8), // "setValue"
QT_MOC_LITERAL(6, 49, 13), // "setAlarmValue"
QT_MOC_LITERAL(7, 63, 10), // "alarmValue"
QT_MOC_LITERAL(8, 74, 8), // "minValue"
QT_MOC_LITERAL(9, 83, 8), // "maxValue"
QT_MOC_LITERAL(10, 92, 9), // "animation"
QT_MOC_LITERAL(11, 102, 13), // "animationStep"
QT_MOC_LITERAL(12, 116, 11), // "borderWidth"
QT_MOC_LITERAL(13, 128, 12), // "borderRadius"
QT_MOC_LITERAL(14, 141, 8), // "bgRadius"
QT_MOC_LITERAL(15, 150, 10), // "headRadius"
QT_MOC_LITERAL(16, 161, 16), // "borderColorStart"
QT_MOC_LITERAL(17, 178, 14), // "borderColorEnd"
QT_MOC_LITERAL(18, 193, 15), // "alarmColorStart"
QT_MOC_LITERAL(19, 209, 13), // "alarmColorEnd"
QT_MOC_LITERAL(20, 223, 16), // "normalColorStart"
QT_MOC_LITERAL(21, 240, 14) // "normalColorEnd"

    },
    "Battery\0valueChanged\0\0value\0updateValue\0"
    "setValue\0setAlarmValue\0alarmValue\0"
    "minValue\0maxValue\0animation\0animationStep\0"
    "borderWidth\0borderRadius\0bgRadius\0"
    "headRadius\0borderColorStart\0borderColorEnd\0"
    "alarmColorStart\0alarmColorEnd\0"
    "normalColorStart\0normalColorEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Battery[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
      16,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x08 /* Private */,
       5,    1,   38,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    7,

 // properties: name, type, flags
       8, QMetaType::Double, 0x00095103,
       9, QMetaType::Double, 0x00095103,
       3, QMetaType::Double, 0x00095103,
       7, QMetaType::Double, 0x00095103,
      10, QMetaType::Bool, 0x00095103,
      11, QMetaType::Double, 0x00095103,
      12, QMetaType::Int, 0x00095103,
      13, QMetaType::Int, 0x00095103,
      14, QMetaType::Int, 0x00095103,
      15, QMetaType::Int, 0x00095103,
      16, QMetaType::QColor, 0x00095103,
      17, QMetaType::QColor, 0x00095103,
      18, QMetaType::QColor, 0x00095103,
      19, QMetaType::QColor, 0x00095103,
      20, QMetaType::QColor, 0x00095103,
      21, QMetaType::QColor, 0x00095103,

       0        // eod
};

void Battery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Battery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->updateValue(); break;
        case 2: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setAlarmValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Battery::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Battery::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Battery *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->getMinValue(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->getMaxValue(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->getValue(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getAlarmValue(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getAnimation(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->getAnimationStep(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getBorderWidth(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getBorderRadius(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getBgRadius(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getHeadRadius(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = _t->getBorderColorStart(); break;
        case 11: *reinterpret_cast< QColor*>(_v) = _t->getBorderColorEnd(); break;
        case 12: *reinterpret_cast< QColor*>(_v) = _t->getAlarmColorStart(); break;
        case 13: *reinterpret_cast< QColor*>(_v) = _t->getAlarmColorEnd(); break;
        case 14: *reinterpret_cast< QColor*>(_v) = _t->getNormalColorStart(); break;
        case 15: *reinterpret_cast< QColor*>(_v) = _t->getNormalColorEnd(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Battery *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMinValue(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setMaxValue(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setValue(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setAlarmValue(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setAnimation(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setAnimationStep(*reinterpret_cast< double*>(_v)); break;
        case 6: _t->setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setBorderRadius(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setBgRadius(*reinterpret_cast< int*>(_v)); break;
        case 9: _t->setHeadRadius(*reinterpret_cast< int*>(_v)); break;
        case 10: _t->setBorderColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 11: _t->setBorderColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        case 12: _t->setAlarmColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 13: _t->setAlarmColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        case 14: _t->setNormalColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 15: _t->setNormalColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Battery::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Battery.data,
    qt_meta_data_Battery,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Battery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Battery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Battery.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Battery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 16;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Battery::valueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
