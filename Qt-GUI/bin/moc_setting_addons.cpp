/****************************************************************************
** Meta object code from reading C++ file 'setting_addons.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DOCK_GUI_v1-5-1/setting_addons.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting_addons.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Setting_AddOns_t {
    QByteArrayData data[11];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Setting_AddOns_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Setting_AddOns_t qt_meta_stringdata_Setting_AddOns = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Setting_AddOns"
QT_MOC_LITERAL(1, 15, 14), // "Import_default"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "st_AddOns&"
QT_MOC_LITERAL(4, 42, 9), // "st_addons"
QT_MOC_LITERAL(5, 52, 5), // "reset"
QT_MOC_LITERAL(6, 58, 13), // "Export_result"
QT_MOC_LITERAL(7, 72, 29), // "on_PB_output_location_clicked"
QT_MOC_LITERAL(8, 102, 16), // "on_PB_OK_clicked"
QT_MOC_LITERAL(9, 119, 20), // "on_PB_Cancel_clicked"
QT_MOC_LITERAL(10, 140, 39) // "on_line_output_location_editi..."

    },
    "Setting_AddOns\0Import_default\0\0"
    "st_AddOns&\0st_addons\0reset\0Export_result\0"
    "on_PB_output_location_clicked\0"
    "on_PB_OK_clicked\0on_PB_Cancel_clicked\0"
    "on_line_output_location_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Setting_AddOns[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       1,    1,   54,    2, 0x2a /* Public | MethodCloned */,
       6,    1,   57,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Setting_AddOns::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Setting_AddOns *_t = static_cast<Setting_AddOns *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Import_default((*reinterpret_cast< st_AddOns(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->Import_default((*reinterpret_cast< st_AddOns(*)>(_a[1]))); break;
        case 2: _t->Export_result((*reinterpret_cast< st_AddOns(*)>(_a[1]))); break;
        case 3: _t->on_PB_output_location_clicked(); break;
        case 4: _t->on_PB_OK_clicked(); break;
        case 5: _t->on_PB_Cancel_clicked(); break;
        case 6: _t->on_line_output_location_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObject Setting_AddOns::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Setting_AddOns.data,
      qt_meta_data_Setting_AddOns,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Setting_AddOns::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Setting_AddOns::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Setting_AddOns.stringdata0))
        return static_cast<void*>(const_cast< Setting_AddOns*>(this));
    return QDialog::qt_metacast(_clname);
}

int Setting_AddOns::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
