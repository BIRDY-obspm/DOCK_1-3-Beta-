/****************************************************************************
** Meta object code from reading C++ file 'setting_realquat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DOCK_GUI_v1-5-1/setting_realquat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting_realquat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Setting_RealQuat_t {
    QByteArrayData data[15];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Setting_RealQuat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Setting_RealQuat_t qt_meta_stringdata_Setting_RealQuat = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Setting_RealQuat"
QT_MOC_LITERAL(1, 17, 14), // "Import_default"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "st_RealQuat&"
QT_MOC_LITERAL(4, 46, 11), // "st_realquat"
QT_MOC_LITERAL(5, 58, 5), // "reset"
QT_MOC_LITERAL(6, 64, 13), // "Export_result"
QT_MOC_LITERAL(7, 78, 16), // "on_PB_OK_clicked"
QT_MOC_LITERAL(8, 95, 20), // "on_PB_Cancel_clicked"
QT_MOC_LITERAL(9, 116, 33), // "on_line_para_file_editingFini..."
QT_MOC_LITERAL(10, 150, 32), // "on_line_seq_file_editingFinished"
QT_MOC_LITERAL(11, 183, 30), // "on_line_output_editingFinished"
QT_MOC_LITERAL(12, 214, 23), // "on_PB_para_file_clicked"
QT_MOC_LITERAL(13, 238, 22), // "on_PB_seq_file_clicked"
QT_MOC_LITERAL(14, 261, 20) // "on_PB_output_clicked"

    },
    "Setting_RealQuat\0Import_default\0\0"
    "st_RealQuat&\0st_realquat\0reset\0"
    "Export_result\0on_PB_OK_clicked\0"
    "on_PB_Cancel_clicked\0"
    "on_line_para_file_editingFinished\0"
    "on_line_seq_file_editingFinished\0"
    "on_line_output_editingFinished\0"
    "on_PB_para_file_clicked\0on_PB_seq_file_clicked\0"
    "on_PB_output_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Setting_RealQuat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x0a /* Public */,
       1,    1,   74,    2, 0x2a /* Public | MethodCloned */,
       6,    1,   77,    2, 0x0a /* Public */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Setting_RealQuat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Setting_RealQuat *_t = static_cast<Setting_RealQuat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Import_default((*reinterpret_cast< st_RealQuat(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->Import_default((*reinterpret_cast< st_RealQuat(*)>(_a[1]))); break;
        case 2: _t->Export_result((*reinterpret_cast< st_RealQuat(*)>(_a[1]))); break;
        case 3: _t->on_PB_OK_clicked(); break;
        case 4: _t->on_PB_Cancel_clicked(); break;
        case 5: _t->on_line_para_file_editingFinished(); break;
        case 6: _t->on_line_seq_file_editingFinished(); break;
        case 7: _t->on_line_output_editingFinished(); break;
        case 8: _t->on_PB_para_file_clicked(); break;
        case 9: _t->on_PB_seq_file_clicked(); break;
        case 10: _t->on_PB_output_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Setting_RealQuat::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Setting_RealQuat.data,
      qt_meta_data_Setting_RealQuat,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Setting_RealQuat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Setting_RealQuat::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Setting_RealQuat.stringdata0))
        return static_cast<void*>(const_cast< Setting_RealQuat*>(this));
    return QDialog::qt_metacast(_clname);
}

int Setting_RealQuat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
