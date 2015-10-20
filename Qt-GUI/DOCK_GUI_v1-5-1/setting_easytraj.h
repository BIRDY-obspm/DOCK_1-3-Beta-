#ifndef SETTING_EASYTRAJ_H
#define SETTING_EASYTRAJ_H

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
class Setting_EasyTraj;
}

class Setting_EasyTraj : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_EasyTraj(QWidget *parent = 0);
    ~Setting_EasyTraj();

private:
    Ui::Setting_EasyTraj *ui;
    QString Output_location;
    QString Default_output_location;

    int Start_MJD_date;
    double Start_MJD_sec;
    int End_MJD_date;
    double End_MJD_sec;
    int Sce_Start_MJD_date;
    double Sce_Start_MJD_sec;
    int Sce_End_MJD_date;
    double Sce_End_MJD_sec;
    double Sce_Step_size;
    double Step_size;

    QString Easy_traj_type;
    double Easy_traj_sma;
    double Easy_traj_ecc;
    double Easy_traj_inc;
    double Easy_traj_pom;
    double Easy_traj_gom;
    double Easy_traj_anm;

    int sim_start_date;
    double sim_start_sec;
    int sim_end_date;
    double sim_end_sec;
    double sim_step_size;

    bool first_launch_flag = 0; // 0-> first launch
    bool finish_flag = 0; // 1-> finished, 0-> not finished

public slots:
    void Import_default(st_EasyTraj &st_easytraj, bool reset = 0);
    void Export_result(st_EasyTraj &st_easytraj);

private slots:
    void on_PB_load_fr_Sce_clicked();
    void on_PB_output_location_clicked();
    void on_PB_OK_clicked();
    void on_PB_cancel_clicked();
    void on_PB_clearall_clicked();
    void on_comboBox_type_currentTextChanged(const QString &arg1);
    void on_SB_start_MJDdate_valueChanged(int arg1);
    void on_SB_start_MJDsec_valueChanged(double arg1);
    void on_SB_end_MJDdate_valueChanged(int arg1);
    void on_SB_end_MJDsec_valueChanged(double arg1);
    void on_SB_stepsize_valueChanged(double arg1);
    void on_SB_sma_valueChanged(double arg1);
    void on_SB_ecc_valueChanged(double arg1);
    void on_SB_pom_valueChanged(double arg1);
    void on_SB_anm_valueChanged(double arg1);
    void on_SB_inc_valueChanged(double arg1);
    void on_SB_gom_valueChanged(double arg1);
    void on_line_output_location_editingFinished();
};

#endif // SETTING_EASYTRAJ_H
