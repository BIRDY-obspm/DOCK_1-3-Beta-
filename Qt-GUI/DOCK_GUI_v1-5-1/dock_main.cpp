#include "dock_main.h"
#include "ui_dock_main.h"

#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>

#include <QTextStream>
#include <QMessageBox>
#include <QProcess>
#include <QRegularExpression>

#include <QDateTime>
#include <QLabel>
#include <QProgressBar>

// libraries for executing DOCKS
#include <QProcess>
#include <QByteArray>
#include <QPlainTextEdit>
#include <QScrollBar>


DOCK_main::DOCK_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DOCK_main)
{
    ui->setupUi(this);
    this->setWindowTitle("Design & Operation Cross-checKing Services (DOCKS)");
    this->setFixedSize(this->size());
    Clear_all_button();

    // Initialize global variables
    this->Sce_filename = "";
    this->Sce_dirpath = Default_input_dir;
    this->Sce_content = "";
    this->Config_filename = "";
    this->Config_dirpath = Default_input_dir;
    this->Config_content = "";
    this->Save_question_flag = 0; //False

    Default_values();

    // Disable all buttons & lines
    ui->GB_module_selection->setEnabled(false);

    ui->line_configfile->setEnabled(false);
    ui->PB_LoadConfig->setEnabled(false);
    ui->PB_NewConfig->setEnabled(false);
    ui->line_VTS->setEnabled(false);
    ui->PB_LoadVTS->setEnabled(false);
    ui->line_IDMfile->setEnabled(false);
    ui->PB_LoadIDM->setEnabled(false);
    ui->PB_CCSDS->setEnabled(false);
    ui->GB_flags->setEnabled(false);
    ui->GB_sim_time->setEnabled(false);

    // Initialize pop up setting windows
    this->w_EasyQuat.setModal(true);
    this->w_EasyQuat.setWindowTitle("Setting of EasyQuat");
    this->w_EasyQuat.setWindowFlags(Qt::WindowTitleHint);
    this->w_EasyQuat.setFixedSize(this->w_EasyQuat.size());

    this->w_RealQuat.setModal(true);
    this->w_RealQuat.setWindowTitle("Setting of RealQuat");
    this->w_RealQuat.setWindowFlags(Qt::WindowTitleHint);
    this->w_RealQuat.setFixedSize(this->w_RealQuat.size());

    this->w_EasyTraj.setModal(true);
    this->w_EasyTraj.setWindowTitle("Setting of EasyTraj");
    this->w_EasyTraj.setWindowFlags(Qt::WindowTitleHint);
    this->w_EasyTraj.setFixedSize(this->w_EasyTraj.size());

    this->w_RealTraj.setModal(true);
    this->w_RealTraj.setWindowTitle("Setting of RealTraj");
    this->w_RealTraj.setWindowFlags(Qt::WindowTitleHint);
    this->w_RealTraj.setFixedSize(this->w_RealTraj.size());

    this->w_STELA.setModal(true);
    this->w_STELA.setWindowTitle("Setting of STELA");
    this->w_STELA.setWindowFlags(Qt::WindowTitleHint);
    this->w_STELA.setFixedSize(this->w_STELA.size());

    this->w_ProdVTS.setModal(true);
    this->w_ProdVTS.setWindowTitle("Setting of ProdVTS");
    this->w_ProdVTS.setWindowFlags(Qt::WindowTitleHint);
    this->w_ProdVTS.setFixedSize(this->w_ProdVTS.size());

    this->w_ExeVTS.setModal(true);
    this->w_ExeVTS.setWindowTitle("Setting of ExeVTS");
    this->w_ExeVTS.setWindowFlags(Qt::WindowTitleHint);
    this->w_ExeVTS.setFixedSize(this->w_ExeVTS.size());

    this->w_AddOns.setModal(true);
    this->w_AddOns.setWindowTitle("Setting of AddOns");
    this->w_AddOns.setWindowFlags(Qt::WindowTitleHint);
    this->w_AddOns.setFixedSize(this->w_AddOns.size());

    this->w_CCSDS.setModal(true);
    this->w_CCSDS.setWindowTitle("Setting of Satellite CCSDS");
    this->w_CCSDS.setWindowFlags(Qt::WindowTitleHint);
    this->w_CCSDS.setFixedSize(this->w_CCSDS.size());
    // Initialize all para of all pop up setting windows
    Setting_dialog_import_default();

    // Show current GUI path
    QDir curr;
    ui->textBrowser->setText("Current path: " + curr.currentPath());
    ui->progressBar->setVisible(false);
}

DOCK_main::~DOCK_main()
{
    delete ui;
}

void DOCK_main::Default_values()
{

    this->IDM_filename = "";
    this->IDM_dirpath = "";

    this->VTS_filename = "";
    this->VTS_dirpath = "";

    this->Keep_temp_file = 0; //False
    this->Keep_debug_file = 0;
    this->VTS_keep_app_setting = 0;

    this->sim_start_date = Default_start_date;
    this->sim_end_date = Default_end_date;
    this->sim_start_sec = Default_start_sec;
    this->sim_end_sec = Default_end_sec;
    this->sim_step_size = Default_step_size; //sec
}

void DOCK_main::Clear_all_button()
{
    ui->CB_Addons->setChecked(false);
    ui->TB_Addons->setEnabled(false);
    ui->CB_EasyQuat->setChecked(false);
    ui->TB_EasyQuat->setEnabled(false);
    ui->CB_EasyTraj->setChecked(false);
    ui->TB_EasyTraj->setEnabled(false);
    ui->CB_ExeVTS->setChecked(false);
    ui->TB_ExeVTS->setEnabled(false);
    ui->CB_ProdVTS->setChecked(false);
    ui->TB_ProdVTS->setEnabled(false);
    ui->CB_RealQuat->setChecked(false);
    ui->TB_RealQuat->setEnabled(false);
    ui->CB_RealTraj->setChecked(false);
    ui->TB_RealTraj->setEnabled(false);
    ui->CB_STELA->setChecked(false);
    ui->TB_STELA->setEnabled(false);

    ui->RB_EasyQuat->setAutoExclusive(false);
    ui->RB_EasyQuat->setChecked(false);
    ui->RB_EasyQuat->setAutoExclusive(true);
    ui->RB_EasyQuat->setEnabled(false);

    ui->RB_EasyTraj->setAutoExclusive(false);
    ui->RB_EasyTraj->setChecked(false);
    ui->RB_EasyTraj->setAutoExclusive(true);
    ui->RB_EasyTraj->setEnabled(false);

    ui->RB_RealQuat->setAutoExclusive(false);
    ui->RB_RealQuat->setChecked(false);
    ui->RB_RealQuat->setAutoExclusive(true);
    ui->RB_RealQuat->setEnabled(false);

    ui->RB_RealTraj->setAutoExclusive(false);
    ui->RB_RealTraj->setChecked(false);
    ui->RB_RealTraj->setAutoExclusive(true);
    ui->RB_RealTraj->setEnabled(false);

    ui->RB_STELA->setAutoExclusive(false);
    ui->RB_STELA->setChecked(false);
    ui->RB_STELA->setAutoExclusive(true);
    ui->RB_STELA->setEnabled(false);

    ui->line_configfile->clear();
    ui->line_IDMfile->clear();
    ui->line_VTS->clear();
    ui->CB_keep_debug->setChecked(false);
    ui->CB_keep_temp->setChecked(false);
    ui->line_start_MJDdate->clear();
    ui->line_start_MJDsec->clear();
    ui->line_end_MJDdate->clear();
    ui->line_end_MJDsec->clear();
    ui->line_stepsize->clear();

    Default_values();
}

void DOCK_main::Reset_all_setting_structs()
{
    this->st_easyquat  = st_EasyQuat();
    this->st_realquat  = st_RealQuat();
    this->st_easytraj  = st_EasyTraj();
    this->st_realtraj  = st_RealTraj();
    this->st_addons    = st_AddOns();
    this->st_stela     = st_STELA();
    this->vts_soft     = VTS_Soft();
    this->vts_cic_para = VTS_CIC_para();
}


void DOCK_main::Load_sce_para(QString &content, QString &Sce_dirpath)  //called by reference
{
    Clear_all_button();
    //this->Sce_filename = ui->Sce_line->text();

    QRegularExpression re;
    QRegularExpressionMatch match;
    QDir test_dir;
    QString Search_target;
    QString temp;
    QStringList _list;

    //------------------------------
    // ---Load "General settings"---
    //------------------------------
    // For "Configuration" file
    re.setPattern("( *Configuration_file *= *)\" *(?<Config_file>.*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("Config_file");

        if ( QFileInfo(Sce_dirpath + '/' + Search_target).isFile() ) // for relative path definition
        {
            this->Config_filename = QFileInfo(Sce_dirpath + '/' + Search_target).absoluteFilePath();
            this->Config_dirpath = QDir(Sce_dirpath).absolutePath();
            ui->line_configfile->setText(this->Config_filename);
        }
        else if ( QFileInfo(Search_target).isFile()) // for absolute path definition
        {
            this->Config_filename = QFileInfo(Search_target).absoluteFilePath();
            ui->line_configfile->setText(this->Config_filename);
            test_dir.setPath(this->Config_filename);
            test_dir.cdUp();
            this->Config_dirpath = test_dir.absolutePath();
        }
        else
        {
            ui->line_configfile->setText("");
            this->Config_filename = "Error";
        }
    }
    else
    {
        ui->line_configfile->setText("");
        this->Config_filename = "Error";
    }

    // For "IDM-CIC" file
    re.setPattern("( *IDM_CIC_file *= *)\" *(?<IDM_CIC>.*\\.xml) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("IDM_CIC");
        if (QFileInfo(Sce_dirpath + '/' + Search_target).isFile()) // for relative path definition
        {
            this->IDM_filename = QFileInfo(Sce_dirpath + '/' + Search_target).absoluteFilePath();
            this->IDM_dirpath = QDir(Sce_dirpath).absolutePath();
            ui->line_IDMfile->setText(this->IDM_filename);
        }
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
        {
            this->IDM_filename = QFileInfo(Search_target).absoluteFilePath();
            ui->line_IDMfile->setText(this->IDM_filename);
            test_dir.setPath(this->IDM_filename);
            test_dir.cdUp();
            this->IDM_dirpath = test_dir.absolutePath();
        }
        else
        {
            ui->line_IDMfile->setText("");
            this->IDM_filename = "Error";
        }
    }
    else
    {
        ui->line_IDMfile->setText("");
        this->IDM_filename = "Error";
    }

    // For "Keep_temp_file" flag
    re.setPattern("( *Keep_temp_file *= *)\" *(?<flag>\\w+) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("flag");
        if (Search_target == "True")
        {
            ui->CB_keep_temp->setChecked(true);
            this->Keep_temp_file = 1; // True
        }
        else
            this->Keep_temp_file = 0;
    }
    else
    {
        ui->CB_keep_temp->setChecked(false);
        this->Keep_temp_file = 0; // False
    }

    // For "Keep_debug_file" flag
    re.setPattern("( *Keep_debug_file *= *)\" *(?<flag>\\w+) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("flag");
        if (Search_target == "True")
        {
            ui->CB_keep_debug->setChecked(true);
            this->Keep_debug_file = 1; // True
        }
        else
            this->Keep_debug_file = 0;
    }
    else
    {
        ui->CB_keep_debug->setChecked(false);
        this->Keep_debug_file = 0; // False
    }


    // For "Simulation_time_start"
    re.setPattern("( *Simulation_time_start *= *)\" *(?<time>\\d+ \\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("time");
        _list = Search_target.split(" ");
        ui->line_start_MJDdate->setValue(_list.value(0).toInt());
        ui->line_start_MJDsec->setValue(_list.value(1).toDouble());
        this->sim_start_date = ui->line_start_MJDdate->value();
        this->sim_start_sec = ui->line_start_MJDsec->value();
    }
    else
    {
        ui->line_start_MJDdate->setValue(Default_start_date);
        ui->line_start_MJDsec->setValue(Default_start_sec);
        this->sim_start_date = Default_start_date;
        this->sim_start_sec = Default_start_sec;
    }

    // For "Simulation_time_end"
    re.setPattern("( *Simulation_time_end *= *)\" *(?<time>\\d+ \\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("time");
        _list = Search_target.split(" ");
        ui->line_end_MJDdate->setValue(_list.value(0).toInt());
        ui->line_end_MJDsec->setValue(_list.value(1).toDouble());
        this->sim_end_date = _list.value(0).toInt();
        this->sim_end_sec = _list.value(1).toDouble();
    }
    else
    {
        ui->line_end_MJDdate->setValue(Default_end_date);
        ui->line_end_MJDsec->setValue(Default_end_sec);
        this->sim_end_date = Default_end_date;
        this->sim_end_sec = Default_end_sec;
    }

    // For "Step size" part
    re.setPattern("( *Simulation_step_size *= *)\" *(?<step>\\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("step");
        ui->line_stepsize->setValue(Search_target.toDouble());
        this->sim_step_size = Search_target.toDouble();
    }
    else
    {
        ui->line_stepsize->setValue(Default_step_size);
        this->sim_step_size = Default_step_size;
    }

    //-------------------------------
    // ---Load "Modules selection"---
    //-------------------------------
    int RealQuat_pos, EasyQuat_pos, RealTraj_pos, EasyTraj_pos, STELA_pos;
    RealQuat_pos = EasyQuat_pos = RealTraj_pos = EasyTraj_pos = STELA_pos = 0;

    re.setPattern("(?<!#) *PRODQUAT");
    match = re.match(content);
    if(match.hasMatch())
    {
        RealQuat_pos = match.capturedStart();
        ui->CB_RealQuat->setChecked(true);
        ui->RB_RealQuat->setEnabled(true);
        ui->RB_RealQuat->setChecked(true);
        ui->TB_RealQuat->setEnabled(true);
    }

    re.setPattern("(?<!#) *EASYQUAT");
    match = re.match(content);
    if(match.hasMatch())
    {
        EasyQuat_pos = match.capturedStart();
        ui->CB_EasyQuat->setChecked(true);
        ui->RB_EasyQuat->setEnabled(true);
        ui->TB_EasyQuat->setEnabled(true);
        if (EasyQuat_pos > RealQuat_pos)
            ui->RB_EasyQuat->setChecked(true);
    }

    re.setPattern("(?<!#) *PRODTRAJ");
    match = re.match(content);
    if(match.hasMatch())
    {
        RealTraj_pos = match.capturedStart();
        ui->CB_RealTraj->setChecked(true);
        ui->RB_RealTraj->setEnabled(true);
        ui->RB_RealTraj->setChecked(true);
        ui->TB_RealTraj->setEnabled(true);
    }

    re.setPattern("(?<!#) *EXESTELA");
    match = re.match(content);
    if(match.hasMatch())
    {
        STELA_pos = match.capturedStart();
        ui->CB_STELA->setChecked(true);
        ui->RB_STELA->setEnabled(true);
        ui->TB_STELA->setEnabled(true);
        if (STELA_pos > RealTraj_pos)
            ui->RB_STELA->setChecked(true);
    }

    re.setPattern("(?<!#) *EASYTRAJ");
    match = re.match(content);
    if(match.hasMatch())
    {
        EasyTraj_pos = match.capturedStart();
        ui->CB_EasyTraj->setChecked(true);
        ui->RB_EasyTraj->setEnabled(true);
        ui->TB_EasyTraj->setEnabled(true);
        if ( (EasyTraj_pos > RealTraj_pos) && (EasyTraj_pos > STELA_pos) )
            ui->RB_EasyTraj->setChecked(true);
    }

    re.setPattern("(?<!#) *PRODVTS");
    match = re.match(content);
    if(match.hasMatch())
    {
        ui->CB_ProdVTS->setChecked(true);
        ui->TB_ProdVTS->setEnabled(true);
    }

    re.setPattern("(?<!#) *EXEVTS");
    match = re.match(content);
    if(match.hasMatch())
    {
        ui->CB_ExeVTS->setChecked(true);
        ui->TB_ExeVTS->setEnabled(true);
    }

    re.setPattern("(?<!#) *EXTRCEL");
    match = re.match(content);
    if(match.hasMatch())
    {
        ui->CB_Addons->setChecked(true);
        ui->TB_Addons->setEnabled(true);
    }

    //=====Easy quaternion parameters=====
    // For "Easy_sed_inputs" (True or False)
    re.setPattern("( *Easy_sed_inputs *= *)\" *(?<flag>\\w+) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("flag");
        if (Search_target == "True")
            this->st_easyquat.Seq_inputs_flag = 1; // True
        else
            this->st_easyquat.Seq_inputs_flag = 0;
    }
    else
        this->st_easyquat.Seq_inputs_flag = 0; // False

    // For "Seq_inputs_file"
    re.setPattern("( *Seq_inputs_file *= *)\" *(?<parameter>.*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (QFileInfo(Sce_dirpath + '/' + Search_target).isFile()) // for relative path definition
        {
            this->st_easyquat.Seq_inputs_filename = QFileInfo(Sce_dirpath + '/' + Search_target).absoluteFilePath();
            this->st_easyquat.Seq_inputs_dirpath = QDir(Sce_dirpath).absolutePath();
        }
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
        {
            this->st_easyquat.Seq_inputs_filename = QFileInfo(Search_target).absoluteFilePath();
            test_dir.setPath(this->st_easyquat.Seq_inputs_filename);
            test_dir.cdUp();
            this->st_easyquat.Seq_inputs_dirpath = test_dir.absolutePath();
        }
        else
        {
            this->st_easyquat.Seq_inputs_filename = "";
            this->st_easyquat.Seq_inputs_dirpath = "";
        }
    }

    // For "Easy_quat_start" date part
    re.setPattern("( *Easy_quat_start *= *)\" *(?<time>\\d+ \\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("time");
        _list = Search_target.split(" ");
        temp = _list.value(0);
        this->st_easyquat.Sce_Start_MJD_date = temp.toInt();
        temp = _list.value(1);
        this->st_easyquat.Sce_Start_MJD_sec = temp.toDouble();
    }
    else
    {
        this->st_easyquat.Sce_Start_MJD_date = this->sim_start_date;
        this->st_easyquat.Sce_Start_MJD_sec = this->sim_start_sec;
    }
    this->st_easyquat.sim_start_date = this->sim_start_date;
    this->st_easyquat.sim_start_sec = this->sim_start_sec;

    // For "Easy_quat_end" date part
    re.setPattern("( *Easy_quat_end *= *)\" *(?<time>\\d+ \\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("time");
        _list = Search_target.split(" ");
        temp = _list.value(0);
        this->st_easyquat.Sce_End_MJD_date = temp.toInt();
        temp = _list.value(1);
        this->st_easyquat.Sce_End_MJD_sec = temp.toDouble();
    }
    else
    {
        this->st_easyquat.Sce_End_MJD_date = this->sim_end_date;
        this->st_easyquat.Sce_End_MJD_sec = this->sim_end_sec;
    }
    this->st_easyquat.sim_end_date = this->sim_end_date;
    this->st_easyquat.sim_end_sec = this->sim_end_sec;

    // For "Easy_quat_step"
    re.setPattern("( *Easy_quat_step *= *)\" *(?<step>\\d+\\.*\\d*)");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("step");
        this->st_easyquat.Sce_Step_size = Search_target.toDouble();
    }
    else
        this->st_easyquat.Sce_Step_size = this->sim_step_size;

    // For "Easy_init_quat"
    re.setPattern("( *Easy_init_quat *= *)\" *(?<value>-*\\d+\\.*\\d* -*\\d+\\.*\\d* -*\\d+\\.*\\d* -*\\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("value");
        _list = Search_target.split(" ");
        temp = _list.value(0);
        this->st_easyquat.quat_w = temp.toDouble();
        temp = _list.value(1);
        this->st_easyquat.quat_x = temp.toDouble();
        temp = _list.value(2);
        this->st_easyquat.quat_y = temp.toDouble();
        temp = _list.value(3);
        this->st_easyquat.quat_z = temp.toDouble();
    }

    // For "Easy_ang_vel"
    re.setPattern("( *Easy_ang_vel *= *)\" *(?<value>-*\\d+\\.*\\d* -*\\d+\\.*\\d* -*\\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("value");
        _list = Search_target.split(" ");
        temp = _list.value(0);
        this->st_easyquat.ang_x = temp.toDouble();
        temp = _list.value(1);
        this->st_easyquat.ang_y = temp.toDouble();
        temp = _list.value(2);
        this->st_easyquat.ang_z = temp.toDouble();
    }

    //=====Easy quaternion parameters=====
    // For "Easy_traj_start"
    re.setPattern("( *Easy_traj_start *= *)\" *(?<time>\\d+ \\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("time");
        _list = Search_target.split(" ");
        temp = _list.value(0);
        this->st_easytraj.Sce_Start_MJD_date = temp.toInt();
        temp = _list.value(1);
        this->st_easytraj.Sce_Start_MJD_sec = temp.toDouble();
    }
    else
    {
        this->st_easytraj.Sce_Start_MJD_date = this->sim_start_date;
        this->st_easytraj.Sce_Start_MJD_sec = this->sim_start_sec;
    }
    this->st_easytraj.sim_start_date = this->sim_start_date;
    this->st_easytraj.sim_start_sec = this->sim_start_sec;


    // For "Easy_traj_end" date part
    re.setPattern("( *Easy_traj_end *= *)\" *(?<time>\\d+ \\d+\\.*\\d*) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("time");
        _list = Search_target.split(" ");
        temp = _list.value(0);
        this->st_easytraj.Sce_End_MJD_date = temp.toInt();
        temp = _list.value(1);
        this->st_easytraj.Sce_End_MJD_sec = temp.toDouble();
    }
    else
    {
        this->st_easytraj.Sce_End_MJD_date = this->sim_end_date;
        this->st_easytraj.Sce_End_MJD_sec = this->sim_end_sec;
    }
    this->st_easytraj.sim_end_date = this->sim_end_date;
    this->st_easytraj.sim_end_sec = this->sim_end_sec;

    // For "Easy_traj_step"
    re.setPattern("( *Easy_traj_step *= *)\" *(?<step>\\d+\\.*\\d*)");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("step");
        this->st_easytraj.Sce_Step_size = Search_target.toDouble();
    }
    else
        this->st_easytraj.Sce_Step_size = this->sim_step_size;

    // For "Easy_traj_type" (Keplerian or Circular)
    re.setPattern("( *Easy_traj_type *= *)\" *(?<flag>\\w+) *\"");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("flag");
        if (Search_target == "Circular")
            this->st_easytraj.Easy_traj_type = "Circular";
        else
            this->st_easytraj.Easy_traj_type = "Keplerian";
    }
    else
        this->st_easytraj.Easy_traj_type = "Keplerian";

    // For "Easy_traj_sma"
    re.setPattern("( *Easy_traj_sma *= *)\" *(?<value>\\d+\\.*\\d*)");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("value");
        this->st_easytraj.Easy_traj_sma = Search_target.toDouble();
    }

    // For "Easy_traj_ecc"
    re.setPattern("( *Easy_traj_ecc *= *)\" *(?<value>\\d+\\.*\\d*)");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("value");
        this->st_easytraj.Easy_traj_ecc = Search_target.toDouble();
    }

    // For "Easy_traj_inc"
    re.setPattern("( *Easy_traj_inc *= *)\" *(?<value>\\d+\\.*\\d*)");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("value");
        this->st_easytraj.Easy_traj_inc = Search_target.toDouble();
    }

    // For "Easy_traj_pom"
    re.setPattern("( *Easy_traj_pom *= *)\" *(?<value>\\d+\\.*\\d*)");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("value");
        this->st_easytraj.Easy_traj_pom = Search_target.toDouble();
    }

    // For "Easy_traj_gom"
    re.setPattern("( *Easy_traj_gom *= *)\" *(?<value>\\d+\\.*\\d*)");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("value");
        this->st_easytraj.Easy_traj_gom = Search_target.toDouble();
    }

    // For "Easy_traj_anm"
    re.setPattern("( *Easy_traj_anm *= *)\" *(?<value>\\d+\\.*\\d*)");
    match = re.match(content);
    if(match.hasMatch())
    {
        Search_target = match.captured("value");
        this->st_easytraj.Easy_traj_anm = Search_target.toDouble();
    }

}

void DOCK_main::Load_con_para(QString &Con_file, QString &Con_dirpath)
{
    if( (Con_file.isEmpty()) || (this->Config_filename == "Error") )
    {
        QMessageBox::critical(0, "error", "Can not find the Configuration file !!");
        Reset_all_setting_structs();
        this->Config_content = "";
        return;
    }

    QFile _file(Con_file);
    if(!_file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(0, "error", "Can not read the Configuration file");
        Reset_all_setting_structs();
        this->Config_content = "";
        return;
    }
    else
    {
        QTextStream in (&_file);
        this->Config_content = in.readAll();
    }

    ui->GB_module_selection->setEnabled(true);
    ui->line_VTS->setEnabled(true);
    ui->PB_LoadVTS->setEnabled(true);
    ui->line_IDMfile->setEnabled(true);
    ui->PB_LoadIDM->setEnabled(true);
    ui->PB_CCSDS->setEnabled(true);
    ui->GB_flags->setEnabled(true);
    ui->GB_sim_time->setEnabled(true);

    QRegularExpression re;
    QRegularExpressionMatch match;

    //----------------------------
    //### Necessary parameters ###
    //----------------------------
    QDir test_path;
    QString Search_target;

    //===VTS module===
    // For "VTS_project_file" file
    re.setPattern("( *VTS_project_file *= *)\" *(?<VTS_file>.*.vts) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("VTS_file");
        if (QFileInfo(Con_dirpath + '/' + Search_target).isFile()) // for relative path definition
        {
            this->VTS_filename = QFileInfo(Con_dirpath + '/' + Search_target).absoluteFilePath();
            this->VTS_dirpath = QDir(Con_dirpath).absolutePath();
            ui->line_VTS->setText(this->VTS_filename);
        }
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
        {
            this->VTS_filename = QFileInfo(Search_target).absoluteFilePath();
            ui->line_VTS->setText(this->VTS_filename);
            test_path.setPath(this->VTS_filename);
            test_path.cdUp();
            this->VTS_dirpath = test_path.absolutePath();
        }
        else
        {
            ui->line_VTS->setText("");
            this->VTS_filename = "";
        }
    }
    else
    {
        ui->line_VTS->setText("");
        this->VTS_filename = "";
    }

    // For "VTS_software_location"
    re.setPattern("( *VTS_software_location *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (test_path.exists(Con_dirpath + '/' + Search_target + "startVTS")) // for relative path definition
        {
            //ui->line_VTS->setText(Con_dirpath + '/' + Search_target);
            this->vts_soft.default_software_location = QDir(Con_dirpath + '/' + Search_target).absolutePath();
            this->vts_soft.software_location = this->vts_soft.default_software_location;
        }
        else if (test_path.exists(Search_target + "startVTS")) // for absolute path definition
        {
            //ui->line_VTS->setText(Search_target);
            this->vts_soft.default_software_location = QDir(Search_target).absolutePath();
            this->vts_soft.software_location = this->vts_soft.default_software_location;
        }
        else
        {
            this->vts_soft.default_software_location = "";
            this->vts_soft.software_location = this->vts_soft.default_software_location;
        }
    }
    else
    {
        this->vts_soft.default_software_location = "";
        this->vts_soft.software_location = this->vts_soft.default_software_location;
    }
    // For "Keep_Apps_setting" flag
    re.setPattern("( *Keep_Apps_setting *= *)\" *(?<flag>\\w+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("flag");
        if (Search_target == "True")
            this->vts_soft.VTS_keep_app_setting = 1; // True
        else
            this->vts_soft.VTS_keep_app_setting = 0;
    }
    else
        this->vts_soft.VTS_keep_app_setting = 0; // False

    //===For VTS CIC-files parameters===
    // Reset "VTS_CIC_para" struct
    this->vts_cic_para = VTS_CIC_para();

    // For "Satellite_name"
    re.setPattern("( *Satellite_name *= *)\" *(?<parameter>\\w+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
        this->vts_cic_para.Satellite_name = match.captured("parameter");

    // For "Satellite_Axes"
    re.setPattern("( *Satellite_Axes *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
        this->vts_cic_para.Satellite_Axes = match.captured("parameter");

    // For "Satellite_parentpath"
    re.setPattern("( *Satellite_parentpath *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
        this->vts_cic_para.Satellite_parentpath = match.captured("parameter");

    // For "Satellite_ref_frame_A"
    re.setPattern("( *Satellite_ref_frame_A *= *)\" *(?<parameter>\\w+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
        this->vts_cic_para.Satellite_ref_frame_A = match.captured("parameter");

    // For "Satellite_ref_frame_B"
    re.setPattern("( *Satellite_ref_frame_B *= *)\" *(?<parameter>\\w+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
        this->vts_cic_para.Satellite_ref_frame_B = match.captured("parameter");

    // For "Satellite_attitude_dir"
    re.setPattern("( *Satellite_attitude_dir *= *)\" *(?<parameter>\\w+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
        this->vts_cic_para.Satellite_attitude_dir = match.captured("parameter");

    // For "Satellite_att_type"
    re.setPattern("( *Satellite_att_type *= *)\" *(?<parameter>\\w+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
        this->vts_cic_para.Satellite_att_type = match.captured("parameter");

    // For "Satellite_time_system"
    re.setPattern("( *Satellite_time_system *= *)\" *(?<parameter>\\w+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
        this->vts_cic_para.Satellite_time_system = match.captured("parameter");

    // For "Satellite_3ds"
    re.setPattern("( *Satellite_3ds *= *)\" *(?<parameter>.*.3ds) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (QFileInfo(Con_dirpath + '/' + Search_target).isFile()) // for relative path definition
            this->vts_cic_para.Satellite_3ds = QFileInfo(Con_dirpath + '/' + Search_target).absoluteFilePath();
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
            this->vts_cic_para.Satellite_3ds = QFileInfo(Search_target).absoluteFilePath();
    }

    // For "Satellite_quaternion"
    re.setPattern("( *Satellite_quaternion *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (QFileInfo(Con_dirpath + '/' + Search_target).isFile()) // for relative path definition
            this->vts_cic_para.Satellite_quaternion = QFileInfo(Con_dirpath + '/' + Search_target).absoluteFilePath();
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
            this->vts_cic_para.Satellite_quaternion = QFileInfo(Search_target).absoluteFilePath();
    }

    // For "Satellite_position"
    re.setPattern("( *Satellite_position *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (QFileInfo(Con_dirpath + '/' + Search_target).isFile()) // for relative path definition
            this->vts_cic_para.Satellite_position = QFileInfo(Con_dirpath + '/' + Search_target).absoluteFilePath();
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
            this->vts_cic_para.Satellite_position = QFileInfo(Search_target).absoluteFilePath();
    }

    //===VTS generation module===
    // For "VTS_output_location"
    re.setPattern("( *VTS_output_location *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (test_path.exists(Con_dirpath + '/' + Search_target)) // for relative path definition
        {
            this->vts_soft.Default_output_location = QDir(Con_dirpath + '/' + Search_target).absolutePath();
            this->vts_soft.Output_location = this->vts_soft.Default_output_location;
        }
        else if (test_path.exists(Search_target)) // for absolute path definition
        {
            this->vts_soft.Default_output_location = QDir(Search_target).absolutePath();
            this->vts_soft.Output_location = this->vts_soft.Default_output_location;
        }
    }


    //===For STELA module===
    // For "STELA_software_location"
    re.setPattern("( *STELA_software_location *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (test_path.exists(Con_dirpath + '/' + Search_target)) // for relative path definition
        {
            this->st_stela.default_software_location = QDir(Con_dirpath + '/' + Search_target).absolutePath();
            this->st_stela.software_location = this->st_stela.default_software_location;
        }
        else if (test_path.exists(Search_target)) // for absolute path definition
        {
            this->st_stela.default_software_location = QDir(Search_target).absolutePath();
            this->st_stela.software_location = this->st_stela.default_software_location;
        }

    }

    //===Easy Quaternion module===
    // For "Easy_quat_output_location"
    re.setPattern("( *Easy_quat_output_location *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (test_path.exists(Con_dirpath + '/' + Search_target)) // for relative path definition
        {
            this->st_easyquat.Default_output_location = QDir(Con_dirpath + '/' + Search_target).absolutePath();
            this->st_easyquat.Output_location = this->st_easyquat.Default_output_location;
        }
        else if (test_path.exists(Search_target)) // for absolute path definition
        {
            this->st_easyquat.Default_output_location = QDir(Search_target).absolutePath();
            this->st_easyquat.Output_location = this->st_easyquat.Default_output_location;
        }
    }
    else
    //{
    //    this->st_easyquat.Default_output_location = Default_output_dir;
    //    this->st_easyquat.Output_location = this->st_easyquat.Default_output_location;
    //}

    //===Dynamic Quaternion module===
    // Reset "st_RealQuat" struct
    this->st_realquat = st_RealQuat();

    // For "Dyn_quat_para_setting"
    re.setPattern("( *Dyn_quat_para_setting *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (QFileInfo(Con_dirpath + '/' + Search_target).isFile()) // for relative path definition
        {
            this->st_realquat.para_filename = QFileInfo(Con_dirpath + '/' + Search_target).absoluteFilePath();
            this->st_realquat.para_dirpath = QDir(Con_dirpath).absolutePath();
        }
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
        {
            this->st_realquat.para_filename = QFileInfo(Search_target).absoluteFilePath();
            test_path.setPath(this->st_easyquat.Seq_inputs_filename);
            test_path.cdUp();
            this->st_realquat.para_dirpath = test_path.absolutePath();
        }
        else
        {
            this->st_realquat.para_filename = "";
            this->st_realquat.para_dirpath = "";
        }
    }

    // For "Dyn_quat_seq_inputs_file"
    re.setPattern("( *Dyn_quat_seq_inputs_file *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (QFileInfo(Con_dirpath + '/' + Search_target).isFile()) // for relative path definition
        {
            this->st_realquat.Seq_inputs_filename = QFileInfo(Con_dirpath + '/' + Search_target).absoluteFilePath();
            this->st_realquat.Seq_inputs_dirpath = QDir(Con_dirpath).absolutePath();
        }
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
        {
            this->st_realquat.Seq_inputs_filename = QFileInfo(Search_target).absoluteFilePath();
            test_path.setPath(this->st_easyquat.Seq_inputs_filename);
            test_path.cdUp();
            this->st_realquat.Seq_inputs_dirpath = test_path.absolutePath();
        }
        else
        {
            this->st_realquat.Seq_inputs_filename = "";
            this->st_realquat.Seq_inputs_dirpath = "";
        }
    }

    // For "Dyn_quat_output_location"
    re.setPattern("( *Dyn_quat_output_location *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (test_path.exists(Con_dirpath + '/' + Search_target)) // for relative path definition
        {
            this->st_realquat.Default_output_location = QDir(Con_dirpath + '/' + Search_target).absolutePath();
            this->st_realquat.Output_location = this->st_realquat.Default_output_location;
        }
        else if (test_path.exists(Search_target)) // for absolute path definition
        {
            this->st_realquat.Default_output_location = QDir(Search_target).absolutePath();
            this->st_realquat.Output_location = this->st_realquat.Default_output_location;
        }
    }

    //===Easy Trajectory module===
    // For "Easy_traj_output_location"
    re.setPattern("( *Easy_traj_output_location *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (test_path.exists(Con_dirpath + '/' + Search_target)) // for relative path definition
        {
            this->st_easytraj.Default_output_location = QDir(Con_dirpath + '/' + Search_target).absolutePath();
            this->st_easytraj.Output_location = this->st_easytraj.Default_output_location;
        }
        else if (test_path.exists(Search_target)) // for absolute path definition
        {
            this->st_easytraj.Default_output_location = QDir(Search_target).absolutePath();
            this->st_easytraj.Output_location = this->st_easytraj.Default_output_location;
        }
    }
    else
    //{
    //    this->st_easytraj.Default_output_location = Default_output_dir;
    //    this->st_easytraj.Output_location = this->st_easytraj.Default_output_location;
    //}

    //===Dynamic Trajectory module===
    // Reset "st_RealTraj" struct
    this->st_realtraj = st_RealTraj();

    // For "Dyn_traj_config"
    re.setPattern("( *Dyn_traj_config *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (QFileInfo(Con_dirpath + '/' + Search_target).isFile()) // for relative path definition
        {
            this->st_realtraj.traj_config_filename = QFileInfo(Con_dirpath + '/' + Search_target).absoluteFilePath();
            this->st_realtraj.traj_config_dirpath = QDir(Con_dirpath).absolutePath();
        }
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
        {
            this->st_realtraj.traj_config_filename = QFileInfo(Search_target).absoluteFilePath();
            test_path.setPath(this->st_realtraj.traj_config_filename);
            test_path.cdUp();
            this->st_realtraj.traj_config_dirpath = test_path.absolutePath();
        }
        else
        {
            this->st_realtraj.traj_config_filename = "";
            this->st_realtraj.traj_config_dirpath = "";
        }
    }

    // For "Dyn_host_traj_file"
    re.setPattern("( *Dyn_host_traj_file *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (QFileInfo(Con_dirpath + '/' + Search_target).isFile()) // for relative path definition
        {
            this->st_realtraj.host_traj_filename = QFileInfo(Con_dirpath + '/' + Search_target).absoluteFilePath();
            this->st_realtraj.host_traj_dirpath = QDir(Con_dirpath).absolutePath();
        }
        else if (QFileInfo(Search_target).isFile()) // for absolute path definition
        {
            this->st_realtraj.host_traj_filename = QFileInfo(Search_target).absoluteFilePath();
            test_path.setPath(this->st_realtraj.host_traj_filename);
            test_path.cdUp();
            this->st_realtraj.host_traj_dirpath = test_path.absolutePath();
        }
        else
        {
            this->st_realtraj.host_traj_filename = "";
            this->st_realtraj.host_traj_dirpath = "";
        }
    }

    // For "Dyn_traj_output_location"
    re.setPattern("( *Dyn_traj_output_location *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (test_path.exists(Con_dirpath + '/' + Search_target)) // for relative path definition
        {
            this->st_realtraj.Default_output_location = QDir(Con_dirpath + '/' + Search_target).absolutePath();
            this->st_realtraj.Output_location = this->st_realtraj.Default_output_location;
        }
        else if (test_path.exists(Search_target)) // for absolute path definition
        {
            this->st_realtraj.Default_output_location = QDir(Search_target).absolutePath();
            this->st_realtraj.Output_location = this->st_realtraj.Default_output_location;
        }
    }


    //===Celestia_output_location===
    // Reset "st_AddOns" struct
    this->st_addons = st_AddOns();

    // For "Celestia_output_location"
    re.setPattern("( *Celestia_output_location *= *)\" *(?<parameter>.+) *\"");
    match = re.match(this->Config_content);
    if(match.hasMatch())
    {
        Search_target = match.captured("parameter");
        if (test_path.exists(Con_dirpath + '/' + Search_target)) // for relative path definition
        {
            this->st_addons.Default_output_location = QDir(Con_dirpath + '/' + Search_target).absolutePath();
            this->st_addons.Output_location = this->st_addons.Default_output_location;
        }
        else if (test_path.exists(Search_target)) // for absolute path definition
        {
            this->st_addons.Default_output_location = QDir(Search_target).absolutePath();
            this->st_addons.Output_location = this->st_addons.Default_output_location;
        }
    }

    // ===Call the Setting_dialog_import_default() to import all para into all setting dialogs===
    Setting_dialog_import_default();
}

void DOCK_main::Setting_dialog_import_default()
{
    this->w_EasyQuat.Import_default(this->st_easyquat,1);
    this->w_RealQuat.Import_default(this->st_realquat,1);
    this->w_EasyTraj.Import_default(this->st_easytraj,1);
    this->w_RealTraj.Import_default(this->st_realtraj,1);
    this->w_STELA.Import_default(this->st_stela,1);
    this->w_ProdVTS.Import_default(this->vts_soft,1);
    this->w_ExeVTS.Import_default(this->vts_soft,1);
    this->w_AddOns.Import_default(this->st_addons,1);
    this->w_CCSDS.Import_default(this->vts_cic_para,1);
}


bool DOCK_main::Save_Sce(QString &Sce_filename)
{
    if (Sce_filename != NULL)
    {
        QFile savefile(Sce_filename);
        if(!savefile.open(QFile::WriteOnly | QFile::Text))
            return 0; //false
        else
        {
            QTextStream data_out(&savefile);
            data_out   << "=========================================\n"
                       << "=======DOCK v1.5 auto-gen Scenario=======\n"
                       << "=========================================\n"
                       << "Generated date: " << QDateTime::currentDateTime().toString() << "\n"
                       << "\n"
                       << "----------------------------\n"
                       << "### Necessary parameters ###\n"
                       << "----------------------------\n"
                       << "=====General setting=====\n"
                       << "Configuration_file = \"" + this->Config_filename + "\"\n";
            if(this->Keep_temp_file)
                data_out << "Keep_temp_file = \"True\"\n";
            else
                data_out << "Keep_temp_file = \"False\"\n";

            if(this->Keep_debug_file)
                data_out << "Keep_debug_file = \"True\"\n";
            else
                data_out << "Keep_debug_file = \"False\"\n";

            data_out << "\n=====IDM-CIC=====\n"
                       << "IDM_CIC_file = \"" + this->IDM_filename + "\"\n"
                       << "\n"
                       << "=====Simulation parameters=====\n"
                       << "Simulation_time_start = \"" + QString::number(this->sim_start_date) + " " + QString::number(this->sim_start_sec, 'g', 9) + "\"\n"
                       << "Simulation_time_end = \"" + QString::number(this->sim_end_date) + " " + QString::number(this->sim_end_sec, 'g', 9) + "\"\n"
                       << "Simulation_step_size = \"" + QString::number(this->sim_step_size, 'g', 9) + "\"\n"
                       << "\n"
                       << "=====Module Selection=====\n";
            if(  (ui->CB_EasyQuat->isChecked())  &&  (!ui->RB_EasyQuat->isChecked())  )
                data_out << "EASYQUAT\n";
            if(  (ui->CB_RealQuat->isChecked())  &&  (!ui->RB_RealQuat->isChecked())  )
                data_out << "PRODQUAT\n";
            if(  (ui->CB_STELA->isChecked())  &&  (!ui->RB_STELA->isChecked())  )
                data_out << "EXESTELA\n";
            if(  (ui->CB_EasyTraj->isChecked())  &&  (!ui->RB_EasyTraj->isChecked())  )
                data_out << "EASYTRAJ\n";
            if(  (ui->CB_RealTraj->isChecked())  &&  (!ui->RB_RealTraj->isChecked())  )
                data_out << "PRODTRAJ\n";
            if(  (ui->CB_EasyQuat->isChecked())  &&  (ui->RB_EasyQuat->isChecked())  )
                data_out << "EASYQUAT\n";
            if(  (ui->CB_RealQuat->isChecked())  &&  (ui->RB_RealQuat->isChecked())  )
                data_out << "PRODQUAT\n";
            if(  (ui->CB_STELA->isChecked())  &&  (ui->RB_STELA->isChecked())  )
                data_out << "EXESTELA\n";
            if(  (ui->CB_EasyTraj->isChecked())  &&  (ui->RB_EasyTraj->isChecked())  )
                data_out << "EASYTRAJ\n";
            if(  (ui->CB_RealTraj->isChecked())  &&  (ui->RB_RealTraj->isChecked())  )
                data_out << "PRODTRAJ\n";
            if(ui->CB_ProdVTS->isChecked())
                data_out << "PRODVTS\n";
            if(ui->CB_ExeVTS->isChecked())
                data_out << "EXEVTS\n";
            if(ui->CB_Addons->isChecked())
                data_out << "EXTRCEL\n";

            data_out << "\n"
                     << "------------------------------\n"
                     << "### Modularized parameters ###\n"
                     << "------------------------------\n"
                     << "=====Easy quaternion parameters=====\n";

            if(this->st_easyquat.Seq_inputs_flag)
                data_out << "Easy_sed_inputs = \"True\"\n";
            else
                data_out << "Easy_sed_inputs = \"False\"\n";

            data_out << "Seq_inputs_file = \"" + this->st_easyquat.Seq_inputs_filename + "\"\n"
                     << "Easy_quat_start = \"" + QString::number(this->st_easyquat.Sce_Start_MJD_date) + " " + QString::number(this->st_easyquat.Sce_Start_MJD_sec, 'g', 9) + "\"\n"
                     << "Easy_quat_end   = \"" + QString::number(this->st_easyquat.Sce_End_MJD_date) + " " + QString::number(this->st_easyquat.Sce_End_MJD_sec, 'g', 9) + "\"\n"
                     << "Easy_quat_step  = \"" + QString::number(this->st_easyquat.Sce_Step_size, 'g', 9) + "\"\n"
                     << "Easy_init_quat  = \"" + QString::number(this->st_easyquat.quat_w, 'g', 5) + " " + QString::number(this->st_easyquat.quat_x, 'g', 5) + " " + QString::number(this->st_easyquat.quat_y, 'g', 5) + " " + QString::number(this->st_easyquat.quat_z, 'g', 5) + "\"\n"
                     << "Easy_ang_vel    = \"" + QString::number(this->st_easyquat.ang_x, 'g', 6) + " " + QString::number(this->st_easyquat.ang_y, 'g', 6) + " " + QString::number(this->st_easyquat.ang_z, 'g', 6) + "\"\n"
                     << "\n"
                     << "=====Easy trajectory parameters=====\n"
                     << "Easy_traj_start = \"" + QString::number(this->st_easytraj.Sce_Start_MJD_date) + " " + QString::number(this->st_easytraj.Sce_Start_MJD_sec, 'g', 9) + "\"\n"
                     << "Easy_traj_end   = \"" + QString::number(this->st_easytraj.Sce_End_MJD_date) + " " + QString::number(this->st_easytraj.Sce_End_MJD_sec, 'g', 9) + "\"\n"
                     << "Easy_traj_step  = \"" + QString::number(this->st_easytraj.Sce_Step_size, 'g', 9) + "\"\n";

            if(this->st_easytraj.Easy_traj_type == "Circular")
                data_out << "Easy_traj_type  = \"Circular\"\n";
            else
                data_out << "Easy_traj_type  = \"Keplerian\"\n";

            data_out << "---Orbital elements---\n"
                     << "Easy_traj_sma = \"" + QString::number(this->st_easytraj.Easy_traj_sma, 'g', 9) + "\"\n"
                     << "Easy_traj_ecc = \"" + QString::number(this->st_easytraj.Easy_traj_ecc, 'g', 9) + "\"\n"
                     << "Easy_traj_inc = \"" + QString::number(this->st_easytraj.Easy_traj_inc, 'g', 9) + "\"\n"
                     << "Easy_traj_pom = \"" + QString::number(this->st_easytraj.Easy_traj_pom, 'g', 9) + "\"\n"
                     << "Easy_traj_gom = \"" + QString::number(this->st_easytraj.Easy_traj_gom, 'g', 9) + "\"\n"
                     << "Easy_traj_anm = \"" + QString::number(this->st_easytraj.Easy_traj_anm, 'g', 9) + "\"\n";

            data_out.flush();
            savefile.close();
            return 1;
        }
    }
    return 0; //false
}


bool DOCK_main::Save_Con(QString &Con_filename)
{
    if (Con_filename != NULL)
    {
        QFile savefile(Con_filename);
        if(!savefile.open(QFile::WriteOnly | QFile::Text))
            return 0; //false
        else
        {
            QTextStream data_out(&savefile);
            data_out    << "=============================================\n"
                        << "=======DOCK v1.5 auto-gen Cofiguration=======\n"
                        << "=============================================\n"
                        << "Generated date: " << QDateTime::currentDateTime().toString() << "\n"
                        << "\n"
                        << "----------------------------\n"
                        << "### Necessary parameters ###\n"
                        << "----------------------------\n"
                        << "===VTS module===\n"
                        << "VTS_software_location  = \"" + QDir(this->vts_soft.software_location).absolutePath() + "/\"\n"
                        << "VTS_project_file       = \"" + QFileInfo(this->VTS_filename).absoluteFilePath() + "\"\n";
            if(this->vts_soft.VTS_keep_app_setting)
                data_out << "Keep_Apps_setting      = \"True\"\n";
            else
                data_out << "Keep_Apps_setting      = \"False\"\n";

            data_out    << "\n"
                        << "=====For VTS CCSDS parameters=====\n"
                        << "Satellite_name         = \"" + this->vts_cic_para.Satellite_name + "\"\n"
                        << "Satellite_Axes         = \"" + this->vts_cic_para.Satellite_Axes + "\"\n";

            if(this->vts_cic_para.Satellite_3ds.isEmpty())
                data_out << "Satellite_3ds          = \"UNKNOWN\"\n";
            else
                data_out << "Satellite_3ds          = \"" + QFileInfo(this->vts_cic_para.Satellite_3ds).absoluteFilePath() + "\"\n";

            if(this->vts_cic_para.Satellite_quaternion.isEmpty())
                data_out << "Satellite_quaternion   = \"UNKNOWN\"\n";
            else
                data_out << "Satellite_quaternion   = \"" + QFileInfo(this->vts_cic_para.Satellite_quaternion).absoluteFilePath() + "\"\n";

            if(this->vts_cic_para.Satellite_position.isEmpty())
                data_out << "Satellite_position     = \"UNKNOWN\"\n";
            else
                data_out << "Satellite_position     = \"" + QFileInfo(this->vts_cic_para.Satellite_position).absoluteFilePath() + "\"\n";

            data_out    << "Satellite_parentpath   = \"" + this->vts_cic_para.Satellite_parentpath + "\"\n"
                        << "Satellite_ref_frame_A  = \"" + this->vts_cic_para.Satellite_ref_frame_A + "\"\n"
                        << "Satellite_ref_frame_B  = \"" + this->vts_cic_para.Satellite_ref_frame_B + "\"\n"
                        << "Satellite_attitude_dir = \"" + this->vts_cic_para.Satellite_attitude_dir + "\"\n"
                        << "Satellite_att_type     = \"" + this->vts_cic_para.Satellite_att_type + "\"\n"
                        << "Satellite_time_system  = \"" + this->vts_cic_para.Satellite_time_system + "\"\n"
                        << "\n"
                        << "------------------------------\n"
                        << "### Modularized parameters ###\n"
                        << "------------------------------\n"
                        << "===STELA module===\n"
                        << "STELA_software_location = \"" + QDir(this->st_stela.software_location).absolutePath() + "/\"\n"
                        << "\n"
                        << "===Easy Quaternion module===\n"
                        << "Easy_quat_output_location = \"" + QDir(this->st_easyquat.Output_location).absolutePath() + "/\"\n"
                        << "\n"
                        << "===Dynamic Quaternion module===\n"
                        << "Dyn_quat_para_setting     = \"" + QFileInfo(this->st_realquat.para_filename).absoluteFilePath() + "\"\n"
                        << "Dyn_quat_seq_inputs_file  = \"" + QFileInfo(this->st_realquat.Seq_inputs_filename).absoluteFilePath() + "\"\n"
                        << "Dyn_quat_output_location  = \"" + QDir(this->st_realquat.Output_location).absolutePath() + "/\"\n"
                        << "\n"
                        << "===Easy Trajectory module===\n"
                        << "Easy_traj_output_location = \"" + QDir(this->st_easytraj.Output_location).absolutePath() + "/\"\n"
                        << "\n"
                        << "===Dynamic Trajectory module===\n"
                        << "Dyn_traj_config           = \"" + QFileInfo(this->st_realtraj.traj_config_filename).absoluteFilePath() + "\"\n"
                        << "Dyn_host_traj_file        = \"" + QFileInfo(this->st_realtraj.host_traj_filename).absoluteFilePath() + "\"\n"
                        << "Dyn_traj_output_location  = \"" + QDir(this->st_realtraj.Output_location).absolutePath() + "/\"\n"
                        << "\n"
                        << "===VTS generation module===\n"
                        << "VTS_output_location       = \"" + QDir(this->vts_soft.Output_location).absolutePath() + "/\"\n"
                        << "\n"
                        << "===Extract Celestia===\n"
                        << "Celestia_output_location  = \"" + QDir(this->st_addons.Output_location).absolutePath() + "/\"\n";
            data_out.flush();
            savefile.close();
            return 1;
        }
    }
    return 0; //false

}


//====================================================
//====================PB clicked()====================
//====================================================

void DOCK_main::on_PB_Clearall_clicked()
{
    Clear_all_button();
    ui->textBrowser->append("Clear all parameters");
}

void DOCK_main::on_PB_LoadSce_clicked()
{
    this->Sce_filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Scenario File"),
                this->Sce_dirpath,
                "All files (*)"
                );
    if (!this->Sce_filename.isEmpty())
    {
        ui->line_configfile->setEnabled(true);
        ui->PB_LoadConfig->setEnabled(true);
        ui->PB_NewConfig->setEnabled(true);

        ui->textBrowser->append("Load Scenario file: " + this->Sce_filename);
        ui->Sce_line->setText(this->Sce_filename);

        QFile Sce_file(this->Sce_filename);
        if(!Sce_file.open(QIODevice::ReadOnly))
            QMessageBox::critical(0, "error", Sce_file.errorString());
        else
        {
            // Put parent path of loaded Scenario file into QString variable
            QDir Sce_dir(this->Sce_filename);
            Sce_dir.cdUp();
            this->Sce_dirpath = Sce_dir.path();
            // Read the context of loaded Scenario file
            QTextStream in (&Sce_file);
            this->Sce_content = in.readAll();
            Load_sce_para(this->Sce_content, this->Sce_dirpath);
            Load_con_para(this->Config_filename, this->Config_dirpath);
            this->Save_question_flag = 0;
        }
    }
}


void DOCK_main::on_PB_Reload_clicked()
{
    Load_sce_para(this->Sce_content, this->Sce_dirpath);
    Load_con_para(this->Config_filename, this->Config_dirpath);
    ui->textBrowser->append("Reload parameters");
}

void DOCK_main::on_PB_refresh_clicked()
{
    ui->textBrowser->clear();
}

void DOCK_main::on_PB_LoadConfig_clicked()
{
    this->Config_filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Configuration File"),
                this->Config_dirpath,
                "All files (*)"
                );
    if (!this->Config_filename.isEmpty())
    {
        QFile Con_file(this->Config_filename);
        if(!Con_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "Can not be loaded");
            this->Config_filename = "Error";
            this->Config_dirpath = "Error";
            ui->line_configfile->setText("");
        }
        else
        {
            ui->textBrowser->append("Change Config file: " + this->Config_filename);
            ui->line_configfile->setText(this->Config_filename);
            QDir Con_dir(this->Config_filename);
            Con_dir.cdUp();
            this->Config_dirpath = Con_dir.path();
            Load_con_para(this->Config_filename, this->Config_dirpath);
        }

    }
}


void DOCK_main::on_PB_LoadVTS_clicked()
{
    this->VTS_filename = QFileDialog::getOpenFileName(
                this,
                tr("Load VTS project .vts File"),
                this->VTS_dirpath,
                "All files (*.vts)"
                );
    if (!this->VTS_filename.isEmpty())
    {
        QFile _file(this->VTS_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "Can not be loaded");
            this->VTS_filename = "Error";
            this->VTS_dirpath = "Error";
            ui->line_VTS->setText("");
        }
        else
        {
            ui->textBrowser->append("Change VTS project file: " + this->VTS_filename);
            ui->line_VTS->setText(this->VTS_filename);
            QDir _dir(this->VTS_filename);
            _dir.cdUp();
            this->VTS_dirpath = _dir.path();
        }

    }
}


void DOCK_main::on_PB_LoadIDM_clicked()
{
    this->IDM_filename = QFileDialog::getOpenFileName(
                this,
                tr("Load IDM-CIC .xml File"),
                this->IDM_dirpath,
                "All files (*.xml)"
                );
    if (!this->IDM_filename.isEmpty())
    {
        QFile IDM_file(this->IDM_filename);
        if(!IDM_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "Can not be loaded");
            this->IDM_filename = "Error";
            this->IDM_dirpath = "Error";
            ui->line_IDMfile->setText("");
        }
        else
        {
            ui->textBrowser->append("Change IDM-CIC file: " + this->IDM_filename);
            ui->line_IDMfile->setText(this->IDM_filename);
            QDir IDM_dir(this->IDM_filename);
            IDM_dir.cdUp();
            this->IDM_dirpath = IDM_dir.path();
        }

    }
}

void DOCK_main::on_PB_NewSce_clicked()
{
    QString Sce_filename = QFileDialog::getSaveFileName(
                this,tr("Create new Scenario file"),this->Sce_dirpath,"All files (*)"
                );

    if (Sce_filename != NULL)
    {
        QFile newfile(Sce_filename);
        if(!newfile.open(QFile::WriteOnly | QFile::Text))
            QMessageBox::critical(0, "error", "Can not open or write the new Scenario file !");
        else
        {
            ui->line_configfile->setEnabled(true);
            ui->PB_LoadConfig->setEnabled(true);
            ui->PB_NewConfig->setEnabled(true);

            QTextStream data_out(&newfile);
            data_out << "=====================================\n"
                       << "=====DOCK v1.5 auto-gen Scenario=====\n"
                       << "=====================================\n"
                       << "Generated date: " << QDateTime::currentDateTime().toString() << "\n"
                       << "\n"
                       << "----------------------------\n"
                       << "### Necessary parameters ###\n"
                       << "----------------------------\n";

            data_out.flush();
            newfile.close();

            this->Sce_filename = Sce_filename;
            ui->textBrowser->append("Create a new Scenario file: " + this->Sce_filename);
            ui->Sce_line->setText(this->Sce_filename);

            QDir Sce_dir(this->Sce_filename);
            Sce_dir.cdUp();

            // Reset all para
            this->Sce_dirpath = Sce_dir.path();
            this->Sce_content = "";
            this->Config_filename = "";
            this->Config_dirpath = Default_input_dir;
            this->Config_content = "";
            this->Save_question_flag = 1;
            Clear_all_button();
            Reset_all_setting_structs();
        }
    }
}


void DOCK_main::on_PB_NewConfig_clicked()
{
    QString Con_filename = QFileDialog::getSaveFileName(
                this,tr("Create new Configuration file"),this->Config_dirpath,"All files (*)"
                );

    if (Con_filename != NULL)
    {
        QFile newfile(Con_filename);
        if(!newfile.open(QFile::WriteOnly | QFile::Text))
            QMessageBox::critical(0, "error", "Can not open or write the file !");
        else
        {
            ui->GB_module_selection->setEnabled(true);
            ui->line_VTS->setEnabled(true);
            ui->PB_LoadVTS->setEnabled(true);
            ui->line_IDMfile->setEnabled(true);
            ui->PB_LoadIDM->setEnabled(true);
            ui->PB_CCSDS->setEnabled(true);
            ui->GB_flags->setEnabled(true);
            ui->GB_sim_time->setEnabled(true);


            QTextStream data_out(&newfile);
            data_out << "==========================================\n"
                       << "=====DOCK v1.5 auto-gen Configuration=====\n"
                       << "==========================================\n"
                       << "Generated date: " << QDateTime::currentDateTime().toString() << "\n"
                       << "\n"
                       << "----------------------------\n"
                       << "### Necessary parameters ###\n"
                       << "----------------------------\n";

            newfile.flush();
            newfile.close();

            this->Config_filename = Con_filename;
            ui->textBrowser->append("Create a new Config file: " + this->Config_filename);
            ui->line_configfile->setText(this->Config_filename);

            QDir Con_dir(this->Config_filename);
            Con_dir.cdUp();
            this->Config_dirpath = Con_dir.path();
            this->Config_content = "";
        }
    }
}


void DOCK_main::on_PB_Save_clicked()
{
    bool _save = 1;
    if(this->Save_question_flag == 0)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Save files");
        msgBox.setText("[Waring] The original files will be covered !!");
        msgBox.setInformativeText("Do you want to save these changes?");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        msgBox.setCheckBox(new QCheckBox(tr("Do not show this message again")));
        _save = (msgBox.exec() == QMessageBox::Save);
        if(msgBox.checkBox()->isChecked())
            this->Save_question_flag = 1;
    }

    bool Save_Con_flag = 0;// 0 = false;
    bool Save_Sce_flag = 0;// 0 = false;
    if ( _save )
    {
        Save_Con_flag = Save_Con(this->Config_filename);
        if(Save_Con_flag) //success
        {
            ui->textBrowser->append("Save the Configuration file: Success!");
            // Put parent path of loaded Scenario file into QString variable
            QDir Con_dir(this->Config_filename);
            Con_dir.cdUp();
            this->Config_dirpath = Con_dir.absolutePath();
        }
        else
            ui->textBrowser->append("Save the Configuration file: Fail!");


        Save_Sce_flag = Save_Sce(this->Sce_filename);
        if(Save_Sce_flag) //success
        {
            ui->textBrowser->append("Save the Scenario file: Success!");
            // Put parent path of loaded Scenario file into QString variable
            QDir Sce_dir(this->Sce_filename);
            Sce_dir.cdUp();
            this->Sce_dirpath = Sce_dir.absolutePath();
        }
        else
            ui->textBrowser->append("Save the Scenario file: Fail!");
    }
    else
        return;

    if( (Save_Con_flag == 1) && (Save_Sce_flag == 1) )
    {
        // Read the context of loaded Scenario file
        QFile Sce_file(this->Sce_filename);
        Sce_file.open(QFile::ReadOnly | QFile::Text);
        QTextStream in (&Sce_file);
        this->Sce_content = in.readAll();
        Load_sce_para(this->Sce_content, this->Sce_dirpath);
        Load_con_para(this->Config_filename, this->Config_dirpath);
    }
}

void DOCK_main::on_PB_Save_as_clicked()
{
    bool Save_Sce_flag = 0;// 0 = false;
    bool Save_Con_flag = 0;// 0 = false;

    // For Configuration file
    QString Saveas_con_filename = QFileDialog::getSaveFileName(
                this,tr("Save as new Configuration file"),this->Config_dirpath,"All files (*)"
                );

    if(Saveas_con_filename != NULL)
    {
        QFile newfile(Saveas_con_filename);
        if(!newfile.open(QFile::WriteOnly | QFile::Text))
            QMessageBox::critical(0, "error", "Can not open or write the new Configuration file !");
        else
        {
            Save_Con_flag = Save_Con(Saveas_con_filename);
            if(Save_Con_flag) //success
            {
                ui->textBrowser->append("Save the new Configuration file: Success!");
                // Put parent path of loaded Configuration file into QString variable
                this->Config_filename = Saveas_con_filename;
                ui->line_configfile->setText(this->Config_filename);
                QDir _dir(this->Config_filename);
                _dir.cdUp();
                this->Config_dirpath = _dir.absolutePath();
            }
            else
            {
                ui->textBrowser->append("Save the new Configuration file: Fail!");
            }
        }
    }


    // For Scenario file
    QString Saveas_sce_filename = QFileDialog::getSaveFileName(
                this,tr("Save as new Scenario file"),this->Sce_dirpath,"All files (*)"
                );

    if(Saveas_sce_filename != NULL)
    {
        QFile newfile(Saveas_sce_filename);
        if(!newfile.open(QFile::WriteOnly | QFile::Text))
            QMessageBox::critical(0, "error", "Can not open or write the new Scenario file !");
        else
        {
            Save_Sce_flag = Save_Sce(Saveas_sce_filename);
            if(Save_Sce_flag) //success
            {
                ui->textBrowser->append("Save the new Scenario file: Success!");
                // Put parent path of loaded Scenario file into QString variable
                this->Sce_filename = Saveas_sce_filename;
                ui->Sce_line->setText(this->Sce_filename);
                QDir Sce_dir(this->Sce_filename);
                Sce_dir.cdUp();
                this->Sce_dirpath = Sce_dir.absolutePath();
            }
            else
            {
                ui->textBrowser->append("Save the new Scenario file: Fail!");
            }
        }
    }



    if( (Save_Sce_flag == 1) && (Save_Con_flag == 1) )
    {
        // Read the context of loaded Scenario file
        QFile Sce_file(this->Sce_filename);
        Sce_file.open(QFile::ReadOnly | QFile::Text);
        QTextStream in (&Sce_file);
        this->Sce_content = in.readAll();
        Load_sce_para(this->Sce_content, this->Sce_dirpath);
        Load_con_para(this->Config_filename, this->Config_dirpath);
    }


}


void DOCK_main::on_PB_Exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit the GUI", "Quit DOCKS?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        qApp->quit();
    }
}

void DOCK_main::on_PB_curr_path_clicked()
{
    QDir curr;
    ui->textBrowser->append("Current path: " + curr.currentPath());
}

void DOCK_main::DOCKS_result_showout()
{
    QProcess *p = dynamic_cast<QProcess *>( sender() );

    if (p)
    {
        ui->textBrowser->insertPlainText(p->readAllStandardOutput());

        //--Always scroll down the "textBrowser"---
        QScrollBar *sb = ui->textBrowser->verticalScrollBar();
        sb->setValue(sb->maximum());
    }
}

void DOCK_main::on_PB_Check_Exe_clicked()
{
    if( (this->Sce_filename.isEmpty()) || (this->Config_filename.isEmpty()) )
    {
        QMessageBox::critical(0, "error", "Please check Scenario or/and Configuration file !");
        ui->textBrowser->append("Scenario or/and Configuration files error");
        return;
    }

    ui->textBrowser->clear();

    // check if the "simulation" tab is empty or not
    if(ui->line_start_MJDdate->text().isEmpty())
        ui->line_start_MJDdate->setValue(Default_start_date);
    if(ui->line_start_MJDsec->text().isEmpty())
        ui->line_start_MJDsec->setValue(Default_start_sec);
    if(ui->line_end_MJDdate->text().isEmpty())
        ui->line_end_MJDdate->setValue(Default_end_date);
    if(ui->line_end_MJDsec->text().isEmpty())
        ui->line_end_MJDsec->setValue(Default_end_sec);
    if(ui->line_stepsize->text().isEmpty())
        ui->line_stepsize->setValue(Default_step_size);

    bool Temp_Sce_flag = 0;// 0 = false;
    bool Temp_Con_flag = 0;// 0 = false;

    QDir _curr;
    QString Temp_Sce_filename = _curr.currentPath() + "/Qt-GUI/bin/docks_sce.temp";
    QString Temp_Con_filename = _curr.currentPath() + "/Qt-GUI/bin/docks_con.temp";

    QString Backup_Con_filename = this->Config_filename;
    this->Config_filename = Temp_Con_filename;
    Temp_Sce_flag = Save_Sce(Temp_Sce_filename);
    Temp_Con_flag = Save_Con(Temp_Con_filename);
    this->Config_filename = Backup_Con_filename;

    if( (Temp_Sce_flag) && (Temp_Con_flag) )
    {
        ui->textBrowser->append("Create Scenario or/and Configuration temp files: success");

        QProcess *p = new QProcess( this );
        if (p)
        {
            p->setEnvironment( QProcess::systemEnvironment() );
            p->setProcessChannelMode( QProcess::MergedChannels );

            QString command = "cd;cd Software/DOCK_v1-5;./dock '";
            command += Temp_Sce_filename;
            command += "'";
            p->start( "sh", QStringList() << "-c" << command );
            p->waitForStarted();
            connect( p, SIGNAL(readyReadStandardOutput()), this, SLOT(DOCKS_result_showout()) );
        }
        else
            p->close();
    }
    else
    {
        ui->textBrowser->append("Create Scenario or/and Configuration temp files: error");
    }

}

//====================================================
//====================CB clicked()====================
//====================================================
void DOCK_main::on_CB_EasyQuat_clicked()
{
    if(ui->CB_EasyQuat->isChecked())
    {
        ui->RB_EasyQuat->setEnabled(true);
        ui->RB_EasyQuat->setChecked(true);
        ui->TB_EasyQuat->setEnabled(true);
        on_TB_EasyQuat_clicked();
    }
    else
    {
        ui->RB_EasyQuat->setChecked(false);
        ui->RB_EasyQuat->setAutoExclusive(true);
        ui->RB_EasyQuat->setEnabled(false);
        ui->RB_RealQuat->setChecked(true); // Force to select the other choice
        ui->TB_EasyQuat->setEnabled(false);
    }
}

void DOCK_main::on_CB_RealQuat_clicked()
{
    if(ui->CB_RealQuat->isChecked())
    {
        ui->RB_RealQuat->setEnabled(true);
        ui->RB_RealQuat->setChecked(true);
        ui->TB_RealQuat->setEnabled(true);
        on_TB_RealQuat_clicked();
    }
    else
    {
        ui->RB_RealQuat->setChecked(false);
        ui->RB_RealQuat->setAutoExclusive(true);
        ui->RB_RealQuat->setEnabled(false);
        ui->RB_EasyQuat->setChecked(true); // Force to select the other choice
        ui->TB_RealQuat->setEnabled(false);
    }
}

void DOCK_main::on_CB_EasyTraj_clicked()
{
    if(ui->CB_EasyTraj->isChecked())
    {
        ui->RB_EasyTraj->setEnabled(true);
        ui->RB_EasyTraj->setChecked(true);
        ui->TB_EasyTraj->setEnabled(true);
        on_TB_EasyTraj_clicked();
    }
    else
    {
        ui->RB_EasyTraj->setChecked(false);
        ui->RB_EasyTraj->setAutoExclusive(true);
        ui->RB_EasyTraj->setEnabled(false);
        ui->TB_EasyTraj->setEnabled(false);
        if( (! ui->RB_RealTraj->isChecked()) && (! ui->RB_STELA->isChecked()) )
        {

            if (ui->CB_RealTraj->isChecked())
                ui->RB_RealTraj->setChecked(true);
            else if(ui->CB_STELA->isChecked())
                ui->RB_STELA->setChecked(true);
        }
    }
}

void DOCK_main::on_CB_RealTraj_clicked()
{
    if(ui->CB_RealTraj->isChecked())
    {
        ui->RB_RealTraj->setEnabled(true);
        ui->RB_RealTraj->setChecked(true);
        ui->TB_RealTraj->setEnabled(true);
        on_TB_RealTraj_clicked();
    }
    else
    {
        ui->RB_RealTraj->setChecked(false);
        ui->RB_RealTraj->setAutoExclusive(true);
        ui->RB_RealTraj->setEnabled(false);
        ui->TB_RealTraj->setEnabled(false);
        if( (! ui->RB_EasyTraj->isChecked()) && (! ui->RB_STELA->isChecked()) )
        {
            if (ui->CB_EasyTraj->isChecked())
                ui->RB_EasyTraj->setChecked(true);
            else if(ui->CB_STELA->isChecked())
                ui->RB_STELA->setChecked(true);
        }
    }
}

void DOCK_main::on_CB_STELA_clicked()
{
    if(ui->CB_STELA->isChecked())
    {
        ui->RB_STELA->setEnabled(true);
        ui->RB_STELA->setChecked(true);
        ui->TB_STELA->setEnabled(true);
        on_TB_STELA_clicked();
    }
    else
    {
        ui->RB_STELA->setChecked(false);
        ui->RB_STELA->setAutoExclusive(true);
        ui->RB_STELA->setEnabled(false);
        ui->TB_STELA->setEnabled(false);
        if( (! ui->RB_EasyTraj->isChecked()) && (! ui->RB_RealTraj->isChecked()) )
        {
            if (ui->CB_EasyTraj->isChecked())
                ui->RB_EasyTraj->setChecked(true);
            else if(ui->CB_RealTraj->isChecked())
                ui->RB_RealTraj->setChecked(true);
        }
    }
}

void DOCK_main::on_CB_ProdVTS_clicked()
{
    if(ui->CB_ProdVTS->isChecked())
    {
        ui->TB_ProdVTS->setEnabled(true);
        on_TB_ProdVTS_clicked();
    }
    else
    {
        ui->TB_ProdVTS->setEnabled(false);
    }
}

void DOCK_main::on_CB_ExeVTS_clicked()
{
    if(ui->CB_ExeVTS->isChecked())
    {
        ui->TB_ExeVTS->setEnabled(true);
        on_TB_ExeVTS_clicked();
    }
    else
    {
        ui->TB_ExeVTS->setEnabled(false);
    }
}

void DOCK_main::on_CB_Addons_clicked()
{
    if(ui->CB_Addons->isChecked())
    {
        ui->TB_Addons->setEnabled(true);
        on_TB_Addons_clicked();
    }
    else
    {
        ui->TB_Addons->setEnabled(false);
    }
}

void DOCK_main::on_CB_keep_temp_clicked()
{
    if(ui->CB_keep_temp->isChecked())
        this->Keep_temp_file = 1;
    else
        this->Keep_temp_file = 0;
}

void DOCK_main::on_CB_keep_debug_clicked()
{
    if(ui->CB_keep_debug->isChecked())
        this->Keep_debug_file = 1;
    else
        this->Keep_debug_file = 0;
}


//====================================================
//===================Action trigger===================
//====================================================

void DOCK_main::on_actionAbout_triggered()
{
    QMessageBox::about (this, "About DOCKS",
        "<img src=\"CERES_logo.png\"><I></I><center>Observatoire de Paris (CERES)<p></p>Developer: Hao-Chih,Lin<p></p>Advisor: Boris Segret<p></p>Copyright &copy;2015 v1.5.1</center>");
}


void DOCK_main::on_actionLicense_triggered()
{
    QMessageBox::about (this, "The license of DOCKS",
    "<center>Copyright &copy;2015 Hao-Chih,Lin & Boris Segret"
    "<br>"
    "<br>This Qt-GUI is part of DOCKS."
    "<br>"
    "<br>DOCKS is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version."
    "<br>"
    "<br>DOCKS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details."
    "<br>"
    "<br>You should have received a copy of the GNU Lesser General Public License along with DOCKS."
    "<br>If not, see http://www.gnu.org/licenses/lgpl.html/."
    "</center>");
}

void DOCK_main::on_actionNew_triggered()
{
    on_PB_NewSce_clicked();
}

void DOCK_main::on_actionOpen_triggered()
{
    on_PB_LoadSce_clicked();
}

void DOCK_main::on_actionSave_triggered()
{
    on_PB_Save_clicked();
}

void DOCK_main::on_actionSave_as_triggered()
{
    on_PB_Save_as_clicked();
}


void DOCK_main::on_actionExit_triggered()
{
    on_PB_Exit_clicked();
}

//=======================================================
//===================editingFinished()===================
//=======================================================
void DOCK_main::on_Sce_line_editingFinished()
{
    QString Sce_line_return = ui->Sce_line->text();
    if(Sce_line_return == this->Sce_filename)
        return;

    if (!Sce_line_return.isEmpty())
    {
        QFile Sce_file(Sce_line_return);
        if(!Sce_file.open(QIODevice::ReadOnly))
        {
            ui->Sce_line->blockSignals(true); // Fix the twice triggered issue when using "editingFinished()"
            QMessageBox::critical(0, "error", Sce_file.errorString());
            ui->Sce_line->blockSignals(false);
            ui->Sce_line->setText(this->Sce_filename);
            ui->textBrowser->append("Load Scenario file Fail! : " + Sce_line_return);
            ui->textBrowser->append("Back to previous sucessed file name.");
        }
        else
        {
            QDir Sce_dir(Sce_line_return);
            this->Sce_filename = Sce_dir.absolutePath();
            ui->textBrowser->append("Load Scenario file: " + this->Sce_filename);
            // Put parent path of loaded Scenario file into QString variable
            Sce_dir.cdUp();
            this->Sce_dirpath = Sce_dir.path();
            // Read the context of loaded Scenario file
            QTextStream in (&Sce_file);
            this->Sce_content = in.readAll();
            Load_sce_para(this->Sce_content, this->Sce_dirpath);
            Load_con_para(this->Config_filename, this->Config_dirpath);
            this->Save_question_flag = 0;
        }
    }
}

void DOCK_main::on_line_configfile_editingFinished()
{
    QString Con_line_return = ui->line_configfile->text();
    if(Con_line_return == this->Config_filename)
        return;

    if (!Con_line_return.isEmpty())
    {
        QFile Con_file(Con_line_return);
        if(!Con_file.open(QIODevice::ReadOnly))
        {
            ui->line_configfile->blockSignals(true);
            QMessageBox::critical(0, "error", Con_file.errorString());
            ui->line_configfile->blockSignals(false);
            ui->line_configfile->setText(this->Config_filename);
            ui->textBrowser->append("Load Configuration file Fail!");
            ui->textBrowser->append("Back to previous sucessed file name:");
            ui->textBrowser->append(this->Config_filename);
        }
        else
        {
            QDir Con_dir(Con_line_return);
            this->Config_filename = Con_dir.absolutePath();
            ui->textBrowser->append("Load Config file: " + this->Config_filename);

            // Put parent path of loaded Configuration file into QString variable
            Con_dir.cdUp();
            this->Config_dirpath = Con_dir.path();
            Load_con_para(this->Config_filename, this->Config_dirpath);
        }
    }
}



void DOCK_main::on_line_VTS_editingFinished()
{
    QString line_return = ui->line_VTS->text();
    if(line_return == this->VTS_filename)
        return;

    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_VTS->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_VTS->blockSignals(false);
            ui->line_VTS->setText(this->VTS_filename);
            ui->textBrowser->append("Load VTS project file Fail!");
            ui->textBrowser->append("Back to previous sucessed file name:");
            ui->textBrowser->append("   " + this->VTS_filename);
        }
        else
        {
            QDir _dir(line_return);
            this->VTS_filename = _dir.absolutePath();
            ui->textBrowser->append("Change VTS file: " + this->VTS_filename);
            _dir.cdUp();
            this->VTS_dirpath = _dir.path();
        }
    }
}


void DOCK_main::on_line_IDMfile_editingFinished()
{
    QString IDM_line_return = ui->line_IDMfile->text();
    if(IDM_line_return == this->IDM_filename)
        return;

    if (!IDM_line_return.isEmpty())
    {
        QFile IDM_file(IDM_line_return);
        if(!IDM_file.open(QIODevice::ReadOnly))
        {
            ui->line_IDMfile->blockSignals(true);
            QMessageBox::critical(0, "error", IDM_file.errorString());
            ui->line_IDMfile->blockSignals(false);
            ui->line_IDMfile->setText(this->IDM_filename);
            ui->textBrowser->append("Load IDM-CIC file Fail!");
            ui->textBrowser->append("Back to previous sucessed file name:");
            ui->textBrowser->append("   " + this->IDM_filename);
        }
        else
        {
            QDir IDM_dir(IDM_line_return);
            this->IDM_filename = IDM_dir.absolutePath();
            ui->textBrowser->append("Change IDM file: " + this->IDM_filename);
            // Put parent path of loaded Configuration file into QString variable
            IDM_dir.cdUp();
            this->IDM_dirpath = IDM_dir.path();
        }
    }
}


//=======================================================
//===================valueChanged()===================
//=======================================================

void DOCK_main::on_line_start_MJDdate_valueChanged(int arg1)
{
    this->sim_start_date = arg1;
}

void DOCK_main::on_line_start_MJDsec_valueChanged(double arg1)
{
    if(arg1 >= 86400.0)
    {
        ui->line_start_MJDsec->setValue(0.0);
        this->sim_start_sec = 0.0;
    }
    else
        this->sim_start_sec = arg1;
}



void DOCK_main::on_line_end_MJDdate_valueChanged(int arg1)
{
    this->sim_end_date = arg1;
}

void DOCK_main::on_line_end_MJDsec_valueChanged(double arg1)
{
    if(arg1 >= 86400.0)
    {
        ui->line_end_MJDsec->setValue(0.0);
        this->sim_end_sec = 0.0;
    }
    else
        this->sim_end_sec = arg1;
}

void DOCK_main::on_line_stepsize_valueChanged(double arg1)
{
    this->sim_step_size = arg1;
}

//====================================================
//====================TB clicked()====================
//====================================================

void DOCK_main::on_TB_EasyQuat_clicked()
{    

    if(this->w_EasyQuat.exec()) //true
    {
        this->w_EasyQuat.Export_result(this->st_easyquat);
        if(this->st_easyquat.Seq_inputs_flag) // true
        {
            ui->textBrowser->append("Change EasyQuat setting: Success !!");
            ui->textBrowser->append("Use the seq-inputs file: " + this->st_easyquat.Seq_inputs_filename);
        }
        else
            ui->textBrowser->append("Change EasyQuat setting: Success !!  (Use simple setting) ");
    }
    else
        ui->textBrowser->append("Change EasyQuat setting: Fail !!");
}


void DOCK_main::on_TB_RealQuat_clicked()
{
    if(this->w_RealQuat.exec()) //true
    {
        this->w_RealQuat.Export_result(this->st_realquat);
        ui->textBrowser->append("Change RealQuat setting: Success !!");
    }
    else
        ui->textBrowser->append("Change RealQuat setting: Fail !!");
}



void DOCK_main::on_TB_EasyTraj_clicked()
{
    if(this->w_EasyTraj.exec()) //true
    {
        this->w_EasyTraj.Export_result(this->st_easytraj);
        ui->textBrowser->append("Change EasyTraj setting: Success !!");
    }
    else
        ui->textBrowser->append("Change EasyTraj setting: Fail !!");
}

void DOCK_main::on_TB_RealTraj_clicked()
{
    if(this->w_RealTraj.exec()) //true
    {
        this->w_RealTraj.Export_result(this->st_realtraj);
        ui->textBrowser->append("Change RealTraj setting: Success !!");
    }
    else
        ui->textBrowser->append("Change RealTraj setting: Fail !!");
}

void DOCK_main::on_TB_STELA_clicked()
{
    if(this->w_STELA.exec()) //true
    {
        this->w_STELA.Export_result(this->st_stela);
        ui->textBrowser->append("Change STELA setting: Success !!");
    }
    else
        ui->textBrowser->append("Change STELA setting: Fail !!");
}

void DOCK_main::on_TB_ProdVTS_clicked()
{
    if(this->w_ProdVTS.exec()) //true
    {
        this->w_ProdVTS.Export_result(this->vts_soft);
        ui->textBrowser->append("Change ProdVTS setting: Success !!");
    }
    else
        ui->textBrowser->append("Change ProdVTS setting: Fail !!");
}


void DOCK_main::on_TB_ExeVTS_clicked()
{
    if(this->w_ExeVTS.exec()) //true
    {
        this->w_ExeVTS.Export_result(this->vts_soft);
        ui->textBrowser->append("Change ExeVTS setting: Success !!");
    }
    else
        ui->textBrowser->append("Change ExeVTS setting: Fail !!");
}

void DOCK_main::on_TB_Addons_clicked()
{
    if(this->w_AddOns.exec()) //true
    {
        this->w_AddOns.Export_result(this->st_addons);
        ui->textBrowser->append("Change AddOns setting: Success !!");
    }
    else
        ui->textBrowser->append("Change AddOns setting: Fail !!");
}



void DOCK_main::on_PB_CCSDS_clicked()
{
    if(this->w_CCSDS.exec()) //true
    {
        this->w_CCSDS.Export_result(this->vts_cic_para);
        ui->textBrowser->append("Change CCSDS setting: Success !!");
    }
    else
        ui->textBrowser->append("Change CCSDS setting: Fail !!");
}

