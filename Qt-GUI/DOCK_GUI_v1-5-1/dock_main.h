/*
 Developer: LIN, Hao-Chih (Jim, LIN)
 Email: f44006076@gmail.com
 Advisor: Boris, Segret
 Final modified date: 23/10/2015
 ==============================================================
 ===========================LICENSE============================
 ==============================================================
 This file is part of DOCKS.

 DOCKS is free software: you can redistribute it and/or modify
 it under the terms of the  GNU LESSER GENERAL PUBLIC LICENSE
 as published by the Free Software Foundation, either version
 3 of the License, or any later version.

 DOCKS is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU LESSER GENERAL PUBLIC LICENSE for more details.

 You should have received a copy of the
 GNU LESSER GENERAL PUBLIC LICENSE along with DOCKS.
 If not, see <http://www.gnu.org/licenses/lgpl.txt>.
*/

#ifndef DOCK_MAIN_H
#define DOCK_MAIN_H

#include <QMainWindow>
#include <QString>
#include <QList>

#include <QProcess>

#include "setting_easyquat.h"
#include "setting_realquat.h"
#include "setting_easytraj.h"
#include "setting_realtraj.h"
#include "setting_stela.h"
#include "setting_prodvts.h"
#include "setting_exevts.h"
#include "setting_addons.h"
#include "setting_ccsds.h"

namespace Ui {
class DOCK_main;
}

class DOCK_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit DOCK_main(QWidget *parent = 0);
    ~DOCK_main();

private:
    QString Sce_filename;
    QString Sce_dirpath;
    QString Sce_content;
    QString Config_filename;
    QString Config_dirpath;
    QString Config_content;
    QString IDM_filename;
    QString IDM_dirpath;
    QString VTS_filename;
    QString VTS_dirpath;

    bool Keep_temp_file;
    bool Keep_debug_file;
    bool VTS_keep_app_setting;
    bool Save_question_flag;
    int sim_start_date;
    int sim_end_date;
    double sim_start_sec;
    double sim_end_sec;
    double sim_step_size;

    //Dialog class
    Setting_EasyQuat w_EasyQuat;
    Setting_RealQuat w_RealQuat;
    Setting_EasyTraj w_EasyTraj;
    Setting_RealTraj w_RealTraj;
    Setting_STELA w_STELA;
    Setting_ProdVTS w_ProdVTS;
    Setting_ExeVTS w_ExeVTS;
    Setting_AddOns w_AddOns;
    Setting_CCSDS w_CCSDS;

    //Dialog exchange struct (from"setting_dialog_struct.h")
    st_EasyQuat st_easyquat;
    st_RealQuat st_realquat;
    st_EasyTraj st_easytraj;
    st_RealTraj st_realtraj;
    st_AddOns st_addons;
    st_STELA st_stela;
    VTS_CIC_para vts_cic_para;
    VTS_Soft vts_soft;

    QProcess *p;

private slots:

    void Default_values();
    void Clear_all_button();
    void Load_sce_para(QString &content, QString &Sce_dirpath);
    void Load_con_para(QString &Con_file, QString &Con_dirpath);
    bool Save_Sce(QString &Sce_filename);
    bool Save_Con(QString &Con_filename);
    void Setting_dialog_import_default();
    void Reset_all_setting_structs();
    void closeEvent(QCloseEvent *event);

    void on_PB_Clearall_clicked();
    void on_PB_LoadSce_clicked();
    void on_PB_Reload_clicked();
    void on_PB_refresh_clicked();
    void on_PB_LoadConfig_clicked();
    void on_PB_NewSce_clicked();
    void on_PB_LoadVTS_clicked();
    void on_PB_LoadIDM_clicked();
    void on_PB_NewConfig_clicked();
    void on_PB_Save_clicked();
    void on_PB_Save_as_clicked();
    void on_PB_curr_path_clicked();
    void on_PB_Exit_clicked();
    // Execute DOCKS
    void on_PB_Check_Exe_clicked();
    void DOCKS_result_showout();

    void on_CB_EasyQuat_clicked();
    void on_CB_RealQuat_clicked();
    void on_CB_EasyTraj_clicked();
    void on_CB_RealTraj_clicked();
    void on_CB_STELA_clicked();
    void on_CB_ProdVTS_clicked();
    void on_CB_ExeVTS_clicked();
    void on_CB_Addons_clicked();
    void on_CB_keep_temp_clicked();
    void on_CB_keep_debug_clicked();

    void on_actionAbout_triggered();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionLicense_triggered();
    void on_actionExit_triggered();
    void on_actionSave_as_triggered();

    void on_Sce_line_editingFinished();
    void on_line_configfile_editingFinished();
    void on_line_VTS_editingFinished();
    void on_line_IDMfile_editingFinished();

    void on_line_start_MJDdate_valueChanged(int arg1);
    void on_line_start_MJDsec_valueChanged(double arg1);
    void on_line_end_MJDdate_valueChanged(int arg1);
    void on_line_end_MJDsec_valueChanged(double arg1);
    void on_line_stepsize_valueChanged(double arg1);

    void on_TB_EasyQuat_clicked();
    void on_TB_RealQuat_clicked();
    void on_TB_EasyTraj_clicked();
    void on_TB_RealTraj_clicked();
    void on_TB_STELA_clicked();
    void on_TB_ProdVTS_clicked();
    void on_TB_ExeVTS_clicked();
    void on_TB_Addons_clicked();
    void on_PB_CCSDS_clicked();

    void on_PB_stopProcess_clicked();

private:
    Ui::DOCK_main *ui;
};

#endif // DOCK_MAIN_H
