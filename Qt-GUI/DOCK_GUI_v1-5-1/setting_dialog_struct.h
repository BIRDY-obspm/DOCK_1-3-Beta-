#ifndef SETTING_DIALOG_STRUCT
#define SETTING_DIALOG_STRUCT

#include <QString>

#define Default_input_dir "Input"
#define Default_output_dir "Output"
#define Default_start_date 51200
#define Default_start_sec 0
#define Default_end_date 51200
#define Default_end_sec 500
#define Default_step_size 1

struct st_EasyQuat  //st means struct [Warning: this initialization way only available with C++11]
{
    QString Seq_inputs_filename = "";
    QString Seq_inputs_dirpath = Default_input_dir;
    QString Output_location = QString(Default_output_dir) + "/Easy_quat";
    QString Default_output_location = QString(Default_output_dir) + "/Easy_quat";

    bool Seq_inputs_flag = false;

    double quat_w = 1, quat_x = 0, quat_y = 0, quat_z = 0;
    double ang_x = 0.5, ang_y = 0, ang_z = 0;

    int Sce_Start_MJD_date = Default_start_date;
    double Sce_Start_MJD_sec = Default_start_sec;
    int Sce_End_MJD_date = Default_end_date;
    double Sce_End_MJD_sec = Default_end_sec;
    double Sce_Step_size = Default_step_size;

    // For "Same as Sce" button
    int sim_start_date = Default_start_date;
    double sim_start_sec = Default_start_sec;
    int sim_end_date = Default_end_date;
    double sim_end_sec = Default_end_sec;
    double sim_step_size = Default_step_size;
};

struct st_RealQuat
{
    QString Seq_inputs_filename = "";
    QString Seq_inputs_dirpath = Default_input_dir;
    QString para_filename = "";
    QString para_dirpath = Default_input_dir;
    QString Output_location = QString(Default_output_dir) + "/Dynamic_quat";
    QString Default_output_location = QString(Default_output_dir) + "/Dynamic_quat";
};


struct st_EasyTraj
{
    QString Output_location = QString(Default_output_dir) + "/Easy_traj";
    QString Default_output_location = QString(Default_output_dir) + "/Easy_traj";

    int Sce_Start_MJD_date = Default_start_date;
    double Sce_Start_MJD_sec = Default_start_sec;
    int Sce_End_MJD_date = Default_end_date;
    double Sce_End_MJD_sec = Default_end_sec;
    double Sce_Step_size = Default_step_size;

    int sim_start_date = Default_start_date;
    double sim_start_sec = Default_start_sec;
    int sim_end_date = Default_end_date;
    double sim_end_sec = Default_end_sec;
    double sim_step_size = Default_step_size;

    QString Easy_traj_type;
    double Easy_traj_sma = 10500;
    double Easy_traj_ecc = 0.001;
    double Easy_traj_inc = 45;
    double Easy_traj_pom = 90;
    double Easy_traj_gom = 240;
    double Easy_traj_anm = 0;
};


struct st_RealTraj
{
    QString traj_config_filename = "";
    QString traj_config_dirpath = Default_input_dir;
    QString host_traj_filename = "";
    QString host_traj_dirpath = Default_input_dir;
    QString Output_location = QString(Default_output_dir) + "/Dynamic_traj";
    QString Default_output_location = QString(Default_output_dir) + "/Dynamic_traj";
};


struct VTS_CIC_para
{
    QString Satellite_name = "DOCKS";
    QString Satellite_Axes = "DOCKS_ref/DOCKS_QswAxes";
    QString Satellite_3ds = "";
    QString Satellite_quaternion = "";
    QString Satellite_position = "";
    QString Satellite_parentpath = "Sol/Earth";
    QString Satellite_ref_frame_A = "EME2000";
    QString Satellite_ref_frame_B = "SC_BODY_1";
    QString Satellite_attitude_dir = "A2B";
    QString Satellite_att_type = "QUATERNION";
    QString Satellite_time_system = "UTC";
};

struct VTS_Soft
{
    bool VTS_keep_app_setting = 1; //True
    QString software_location = "../";
    QString default_software_location = "../";
    QString Output_location = QString(Default_output_dir) + "/VTS_gen";
    QString Default_output_location = QString(Default_output_dir) + "/VTS_gen";
};

struct st_STELA
{
    QString software_location = "../";
    QString default_software_location = "../";
};

struct st_AddOns
{
    QString Output_location = QString(Default_output_dir) + "/Celestia_Addon";
    QString Default_output_location = QString(Default_output_dir) + "/Celestia_Addon";
};

#endif // SETTING_DIALOG_STRUCT
