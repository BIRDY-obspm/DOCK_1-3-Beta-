#ifndef SETTING_REALTRAJ_H
#define SETTING_REALTRAJ_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include "setting_dialog_struct.h"

namespace Ui {
class Setting_RealTraj;
}

class Setting_RealTraj : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_RealTraj(QWidget *parent = 0);
    ~Setting_RealTraj();

private:
    Ui::Setting_RealTraj *ui;
    QString traj_config_filename;
    QString traj_config_dirpath;
    QString host_traj_filename;
    QString host_traj_dirpath;
    QString output_location;
    QString default_output_location;
    bool first_launch_flag = 0;

public slots:
    void Import_default(st_RealTraj &st_realtraj, bool reset = 0);
    void Export_result(st_RealTraj &st_realtraj);

private slots:
    void on_PB_traj_config_clicked();
    void on_PB_host_traj_clicked();
    void on_PB_output_clicked();
    void on_PB_OK_clicked();
    void on_PB_Cancel_clicked();
    void on_line_traj_config_editingFinished();
    void on_line_host_traj_editingFinished();
    void on_line_output_editingFinished();
};

#endif // SETTING_REALTRAJ_H
