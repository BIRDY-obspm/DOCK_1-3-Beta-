/****************************************************************************
** Meta object code from reading C++ file 'dock_main.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DOCK_GUI_v1-5-1/dock_main.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dock_main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DOCK_main_t {
    QByteArrayData data[68];
    char stringdata0[1439];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DOCK_main_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DOCK_main_t qt_meta_stringdata_DOCK_main = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DOCK_main"
QT_MOC_LITERAL(1, 10, 14), // "Default_values"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "Clear_all_button"
QT_MOC_LITERAL(4, 43, 13), // "Load_sce_para"
QT_MOC_LITERAL(5, 57, 8), // "QString&"
QT_MOC_LITERAL(6, 66, 7), // "content"
QT_MOC_LITERAL(7, 74, 11), // "Sce_dirpath"
QT_MOC_LITERAL(8, 86, 13), // "Load_con_para"
QT_MOC_LITERAL(9, 100, 8), // "Con_file"
QT_MOC_LITERAL(10, 109, 11), // "Con_dirpath"
QT_MOC_LITERAL(11, 121, 8), // "Save_Sce"
QT_MOC_LITERAL(12, 130, 12), // "Sce_filename"
QT_MOC_LITERAL(13, 143, 8), // "Save_Con"
QT_MOC_LITERAL(14, 152, 12), // "Con_filename"
QT_MOC_LITERAL(15, 165, 29), // "Setting_dialog_import_default"
QT_MOC_LITERAL(16, 195, 25), // "Reset_all_setting_structs"
QT_MOC_LITERAL(17, 221, 22), // "on_PB_Clearall_clicked"
QT_MOC_LITERAL(18, 244, 21), // "on_PB_LoadSce_clicked"
QT_MOC_LITERAL(19, 266, 20), // "on_PB_Reload_clicked"
QT_MOC_LITERAL(20, 287, 21), // "on_PB_refresh_clicked"
QT_MOC_LITERAL(21, 309, 24), // "on_PB_LoadConfig_clicked"
QT_MOC_LITERAL(22, 334, 20), // "on_PB_NewSce_clicked"
QT_MOC_LITERAL(23, 355, 21), // "on_PB_LoadVTS_clicked"
QT_MOC_LITERAL(24, 377, 21), // "on_PB_LoadIDM_clicked"
QT_MOC_LITERAL(25, 399, 23), // "on_PB_NewConfig_clicked"
QT_MOC_LITERAL(26, 423, 18), // "on_PB_Save_clicked"
QT_MOC_LITERAL(27, 442, 21), // "on_PB_Save_as_clicked"
QT_MOC_LITERAL(28, 464, 23), // "on_PB_curr_path_clicked"
QT_MOC_LITERAL(29, 488, 18), // "on_PB_Exit_clicked"
QT_MOC_LITERAL(30, 507, 23), // "on_PB_Check_Exe_clicked"
QT_MOC_LITERAL(31, 531, 20), // "DOCKS_result_showout"
QT_MOC_LITERAL(32, 552, 22), // "on_CB_EasyQuat_clicked"
QT_MOC_LITERAL(33, 575, 22), // "on_CB_RealQuat_clicked"
QT_MOC_LITERAL(34, 598, 22), // "on_CB_EasyTraj_clicked"
QT_MOC_LITERAL(35, 621, 22), // "on_CB_RealTraj_clicked"
QT_MOC_LITERAL(36, 644, 19), // "on_CB_STELA_clicked"
QT_MOC_LITERAL(37, 664, 21), // "on_CB_ProdVTS_clicked"
QT_MOC_LITERAL(38, 686, 20), // "on_CB_ExeVTS_clicked"
QT_MOC_LITERAL(39, 707, 20), // "on_CB_Addons_clicked"
QT_MOC_LITERAL(40, 728, 23), // "on_CB_keep_temp_clicked"
QT_MOC_LITERAL(41, 752, 24), // "on_CB_keep_debug_clicked"
QT_MOC_LITERAL(42, 777, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(43, 802, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(44, 825, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(45, 849, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(46, 873, 26), // "on_actionLicense_triggered"
QT_MOC_LITERAL(47, 900, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(48, 924, 26), // "on_actionSave_as_triggered"
QT_MOC_LITERAL(49, 951, 27), // "on_Sce_line_editingFinished"
QT_MOC_LITERAL(50, 979, 34), // "on_line_configfile_editingFin..."
QT_MOC_LITERAL(51, 1014, 27), // "on_line_VTS_editingFinished"
QT_MOC_LITERAL(52, 1042, 31), // "on_line_IDMfile_editingFinished"
QT_MOC_LITERAL(53, 1074, 34), // "on_line_start_MJDdate_valueCh..."
QT_MOC_LITERAL(54, 1109, 4), // "arg1"
QT_MOC_LITERAL(55, 1114, 33), // "on_line_start_MJDsec_valueCha..."
QT_MOC_LITERAL(56, 1148, 32), // "on_line_end_MJDdate_valueChanged"
QT_MOC_LITERAL(57, 1181, 31), // "on_line_end_MJDsec_valueChanged"
QT_MOC_LITERAL(58, 1213, 29), // "on_line_stepsize_valueChanged"
QT_MOC_LITERAL(59, 1243, 22), // "on_TB_EasyQuat_clicked"
QT_MOC_LITERAL(60, 1266, 22), // "on_TB_RealQuat_clicked"
QT_MOC_LITERAL(61, 1289, 22), // "on_TB_EasyTraj_clicked"
QT_MOC_LITERAL(62, 1312, 22), // "on_TB_RealTraj_clicked"
QT_MOC_LITERAL(63, 1335, 19), // "on_TB_STELA_clicked"
QT_MOC_LITERAL(64, 1355, 21), // "on_TB_ProdVTS_clicked"
QT_MOC_LITERAL(65, 1377, 20), // "on_TB_ExeVTS_clicked"
QT_MOC_LITERAL(66, 1398, 20), // "on_TB_Addons_clicked"
QT_MOC_LITERAL(67, 1419, 19) // "on_PB_CCSDS_clicked"

    },
    "DOCK_main\0Default_values\0\0Clear_all_button\0"
    "Load_sce_para\0QString&\0content\0"
    "Sce_dirpath\0Load_con_para\0Con_file\0"
    "Con_dirpath\0Save_Sce\0Sce_filename\0"
    "Save_Con\0Con_filename\0"
    "Setting_dialog_import_default\0"
    "Reset_all_setting_structs\0"
    "on_PB_Clearall_clicked\0on_PB_LoadSce_clicked\0"
    "on_PB_Reload_clicked\0on_PB_refresh_clicked\0"
    "on_PB_LoadConfig_clicked\0on_PB_NewSce_clicked\0"
    "on_PB_LoadVTS_clicked\0on_PB_LoadIDM_clicked\0"
    "on_PB_NewConfig_clicked\0on_PB_Save_clicked\0"
    "on_PB_Save_as_clicked\0on_PB_curr_path_clicked\0"
    "on_PB_Exit_clicked\0on_PB_Check_Exe_clicked\0"
    "DOCKS_result_showout\0on_CB_EasyQuat_clicked\0"
    "on_CB_RealQuat_clicked\0on_CB_EasyTraj_clicked\0"
    "on_CB_RealTraj_clicked\0on_CB_STELA_clicked\0"
    "on_CB_ProdVTS_clicked\0on_CB_ExeVTS_clicked\0"
    "on_CB_Addons_clicked\0on_CB_keep_temp_clicked\0"
    "on_CB_keep_debug_clicked\0"
    "on_actionAbout_triggered\0"
    "on_actionNew_triggered\0on_actionOpen_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionLicense_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionSave_as_triggered\0"
    "on_Sce_line_editingFinished\0"
    "on_line_configfile_editingFinished\0"
    "on_line_VTS_editingFinished\0"
    "on_line_IDMfile_editingFinished\0"
    "on_line_start_MJDdate_valueChanged\0"
    "arg1\0on_line_start_MJDsec_valueChanged\0"
    "on_line_end_MJDdate_valueChanged\0"
    "on_line_end_MJDsec_valueChanged\0"
    "on_line_stepsize_valueChanged\0"
    "on_TB_EasyQuat_clicked\0on_TB_RealQuat_clicked\0"
    "on_TB_EasyTraj_clicked\0on_TB_RealTraj_clicked\0"
    "on_TB_STELA_clicked\0on_TB_ProdVTS_clicked\0"
    "on_TB_ExeVTS_clicked\0on_TB_Addons_clicked\0"
    "on_PB_CCSDS_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DOCK_main[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      58,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  304,    2, 0x08 /* Private */,
       3,    0,  305,    2, 0x08 /* Private */,
       4,    2,  306,    2, 0x08 /* Private */,
       8,    2,  311,    2, 0x08 /* Private */,
      11,    1,  316,    2, 0x08 /* Private */,
      13,    1,  319,    2, 0x08 /* Private */,
      15,    0,  322,    2, 0x08 /* Private */,
      16,    0,  323,    2, 0x08 /* Private */,
      17,    0,  324,    2, 0x08 /* Private */,
      18,    0,  325,    2, 0x08 /* Private */,
      19,    0,  326,    2, 0x08 /* Private */,
      20,    0,  327,    2, 0x08 /* Private */,
      21,    0,  328,    2, 0x08 /* Private */,
      22,    0,  329,    2, 0x08 /* Private */,
      23,    0,  330,    2, 0x08 /* Private */,
      24,    0,  331,    2, 0x08 /* Private */,
      25,    0,  332,    2, 0x08 /* Private */,
      26,    0,  333,    2, 0x08 /* Private */,
      27,    0,  334,    2, 0x08 /* Private */,
      28,    0,  335,    2, 0x08 /* Private */,
      29,    0,  336,    2, 0x08 /* Private */,
      30,    0,  337,    2, 0x08 /* Private */,
      31,    0,  338,    2, 0x08 /* Private */,
      32,    0,  339,    2, 0x08 /* Private */,
      33,    0,  340,    2, 0x08 /* Private */,
      34,    0,  341,    2, 0x08 /* Private */,
      35,    0,  342,    2, 0x08 /* Private */,
      36,    0,  343,    2, 0x08 /* Private */,
      37,    0,  344,    2, 0x08 /* Private */,
      38,    0,  345,    2, 0x08 /* Private */,
      39,    0,  346,    2, 0x08 /* Private */,
      40,    0,  347,    2, 0x08 /* Private */,
      41,    0,  348,    2, 0x08 /* Private */,
      42,    0,  349,    2, 0x08 /* Private */,
      43,    0,  350,    2, 0x08 /* Private */,
      44,    0,  351,    2, 0x08 /* Private */,
      45,    0,  352,    2, 0x08 /* Private */,
      46,    0,  353,    2, 0x08 /* Private */,
      47,    0,  354,    2, 0x08 /* Private */,
      48,    0,  355,    2, 0x08 /* Private */,
      49,    0,  356,    2, 0x08 /* Private */,
      50,    0,  357,    2, 0x08 /* Private */,
      51,    0,  358,    2, 0x08 /* Private */,
      52,    0,  359,    2, 0x08 /* Private */,
      53,    1,  360,    2, 0x08 /* Private */,
      55,    1,  363,    2, 0x08 /* Private */,
      56,    1,  366,    2, 0x08 /* Private */,
      57,    1,  369,    2, 0x08 /* Private */,
      58,    1,  372,    2, 0x08 /* Private */,
      59,    0,  375,    2, 0x08 /* Private */,
      60,    0,  376,    2, 0x08 /* Private */,
      61,    0,  377,    2, 0x08 /* Private */,
      62,    0,  378,    2, 0x08 /* Private */,
      63,    0,  379,    2, 0x08 /* Private */,
      64,    0,  380,    2, 0x08 /* Private */,
      65,    0,  381,    2, 0x08 /* Private */,
      66,    0,  382,    2, 0x08 /* Private */,
      67,    0,  383,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    9,   10,
    QMetaType::Bool, 0x80000000 | 5,   12,
    QMetaType::Bool, 0x80000000 | 5,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void, QMetaType::Double,   54,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void, QMetaType::Double,   54,
    QMetaType::Void, QMetaType::Double,   54,
    QMetaType::Void,
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

void DOCK_main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DOCK_main *_t = static_cast<DOCK_main *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Default_values(); break;
        case 1: _t->Clear_all_button(); break;
        case 2: _t->Load_sce_para((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->Load_con_para((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: { bool _r = _t->Save_Sce((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->Save_Con((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->Setting_dialog_import_default(); break;
        case 7: _t->Reset_all_setting_structs(); break;
        case 8: _t->on_PB_Clearall_clicked(); break;
        case 9: _t->on_PB_LoadSce_clicked(); break;
        case 10: _t->on_PB_Reload_clicked(); break;
        case 11: _t->on_PB_refresh_clicked(); break;
        case 12: _t->on_PB_LoadConfig_clicked(); break;
        case 13: _t->on_PB_NewSce_clicked(); break;
        case 14: _t->on_PB_LoadVTS_clicked(); break;
        case 15: _t->on_PB_LoadIDM_clicked(); break;
        case 16: _t->on_PB_NewConfig_clicked(); break;
        case 17: _t->on_PB_Save_clicked(); break;
        case 18: _t->on_PB_Save_as_clicked(); break;
        case 19: _t->on_PB_curr_path_clicked(); break;
        case 20: _t->on_PB_Exit_clicked(); break;
        case 21: _t->on_PB_Check_Exe_clicked(); break;
        case 22: _t->DOCKS_result_showout(); break;
        case 23: _t->on_CB_EasyQuat_clicked(); break;
        case 24: _t->on_CB_RealQuat_clicked(); break;
        case 25: _t->on_CB_EasyTraj_clicked(); break;
        case 26: _t->on_CB_RealTraj_clicked(); break;
        case 27: _t->on_CB_STELA_clicked(); break;
        case 28: _t->on_CB_ProdVTS_clicked(); break;
        case 29: _t->on_CB_ExeVTS_clicked(); break;
        case 30: _t->on_CB_Addons_clicked(); break;
        case 31: _t->on_CB_keep_temp_clicked(); break;
        case 32: _t->on_CB_keep_debug_clicked(); break;
        case 33: _t->on_actionAbout_triggered(); break;
        case 34: _t->on_actionNew_triggered(); break;
        case 35: _t->on_actionOpen_triggered(); break;
        case 36: _t->on_actionSave_triggered(); break;
        case 37: _t->on_actionLicense_triggered(); break;
        case 38: _t->on_actionExit_triggered(); break;
        case 39: _t->on_actionSave_as_triggered(); break;
        case 40: _t->on_Sce_line_editingFinished(); break;
        case 41: _t->on_line_configfile_editingFinished(); break;
        case 42: _t->on_line_VTS_editingFinished(); break;
        case 43: _t->on_line_IDMfile_editingFinished(); break;
        case 44: _t->on_line_start_MJDdate_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_line_start_MJDsec_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 46: _t->on_line_end_MJDdate_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->on_line_end_MJDsec_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 48: _t->on_line_stepsize_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 49: _t->on_TB_EasyQuat_clicked(); break;
        case 50: _t->on_TB_RealQuat_clicked(); break;
        case 51: _t->on_TB_EasyTraj_clicked(); break;
        case 52: _t->on_TB_RealTraj_clicked(); break;
        case 53: _t->on_TB_STELA_clicked(); break;
        case 54: _t->on_TB_ProdVTS_clicked(); break;
        case 55: _t->on_TB_ExeVTS_clicked(); break;
        case 56: _t->on_TB_Addons_clicked(); break;
        case 57: _t->on_PB_CCSDS_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject DOCK_main::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DOCK_main.data,
      qt_meta_data_DOCK_main,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DOCK_main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DOCK_main::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DOCK_main.stringdata0))
        return static_cast<void*>(const_cast< DOCK_main*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DOCK_main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 58)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 58;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 58)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 58;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
