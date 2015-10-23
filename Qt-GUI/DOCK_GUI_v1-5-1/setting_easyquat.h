#ifndef SETTING_EASYQUAT_H
#define SETTING_EASYQUAT_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <math.h>

#include "setting_dialog_struct.h"

namespace Ui {
class Setting_EasyQuat;
}

class Setting_EasyQuat : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_EasyQuat(QWidget *parent = 0);
    ~Setting_EasyQuat();

private:
    bool finish_flag = 0;
    bool Seq_inputs_flag;
    bool first_launch_flag = 0; // 0-> first launch
    QString Seq_inputs_filename;
    QString Seq_inputs_dirpath;
    QString Output_location;
    QString Default_output_location;

    int Start_MJD_date;
    double Start_MJD_sec;
    int End_MJD_date;
    double End_MJD_sec;
    double Step_size;
    double quat_w, quat_x, quat_y, quat_z;
    double ang_x, ang_y, ang_z;

    int Sce_Start_MJD_date;
    double Sce_Start_MJD_sec;
    int Sce_End_MJD_date;
    double Sce_End_MJD_sec;
    double Sce_Step_size;

    int sim_start_date;
    double sim_start_sec;
    int sim_end_date;
    double sim_end_sec;
    double sim_step_size;

public slots:
    void Import_default(st_EasyQuat &st_easyquat, bool reset = 0);
    void Export_result(st_EasyQuat &st_easyquat);

private slots:
    void clear_all();
    void reload(bool seq_inputs_flag);
    void setEnabled_all(bool seq_inputs_flag);
    void on_CB_sed_inputs_clicked();

    void on_PB_load_fr_Sce_clicked();
    void on_PB_OK_clicked();
    void on_PB_Load_seq_inputs_clicked();
    void on_PB_output_location_clicked();
    void on_PB_clearall_clicked();
    void on_PB_cancel_clicked();

    void on_line_seq_inputs_editingFinished();
    void on_line_output_location_editingFinished();

    void on_line_start_MJDdate_valueChanged(int arg1);
    void on_line_start_MJDsec_valueChanged(double arg1);
    void on_line_end_MJDdate_valueChanged(int arg1);
    void on_line_end_MJDsec_valueChanged(double arg1);
    void on_line_stepsize_valueChanged(double arg1);
    void on_line_quat_w_valueChanged(double arg1);
    void on_line_quat_x_valueChanged(double arg1);
    void on_line_quat_y_valueChanged(double arg1);
    void on_line_quat_z_valueChanged(double arg1);
    void on_line_ang_x_valueChanged(double arg1);
    void on_line_ang_y_valueChanged(double arg1);
    void on_line_ang_z_valueChanged(double arg1);

private:
    Ui::Setting_EasyQuat *ui;
};

#endif // SETTING_EASYQUAT_H
