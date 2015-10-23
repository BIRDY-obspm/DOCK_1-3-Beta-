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

#include "setting_realtraj.h"
#include "ui_setting_realtraj.h"

Setting_RealTraj::Setting_RealTraj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_RealTraj)
{
    ui->setupUi(this);
}

Setting_RealTraj::~Setting_RealTraj()
{
    delete ui;
}

void Setting_RealTraj::Import_default(st_RealTraj &st_realtraj, bool reset)
{
    if(reset == 1)
    {
        this->first_launch_flag = 0;
    }

    if(this->first_launch_flag == 0)
    {
        this->traj_config_filename = st_realtraj.traj_config_filename;
        this->traj_config_dirpath = st_realtraj.traj_config_dirpath;
        this->host_traj_filename = st_realtraj.host_traj_filename;
        this->host_traj_dirpath = st_realtraj.host_traj_dirpath;
        this->output_location = st_realtraj.Output_location;
        this->default_output_location = st_realtraj.Default_output_location;

        ui->line_traj_config->setText(this->traj_config_filename);
        ui->line_host_traj->setText(this->host_traj_filename);
        ui->line_output->setText(this->default_output_location);

        this->first_launch_flag = 1;
    }
}

void Setting_RealTraj::Export_result(st_RealTraj &st_realtraj)
{
    st_realtraj.Output_location = this->output_location;
    st_realtraj.traj_config_filename = this->traj_config_filename;
    st_realtraj.traj_config_dirpath = this->traj_config_dirpath;
    st_realtraj.host_traj_filename = this->host_traj_filename;
    st_realtraj.host_traj_dirpath = this->host_traj_dirpath;
}

void Setting_RealTraj::on_PB_traj_config_clicked()
{
    QString _filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Trajectory config File"),
                this->traj_config_dirpath,
                "All files (*)"
                );
    if (!_filename.isEmpty())
    {
        QFile _file(_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "File not found !!");
            ui->line_traj_config->setText("");
        }
        else
        {
            ui->line_traj_config->setText(_filename);
            QDir _dir(_filename);
            _dir.cdUp();
            this->traj_config_dirpath = _dir.path();
        }

    }
}

void Setting_RealTraj::on_PB_host_traj_clicked()
{
    QString _filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Host trajectory File"),
                this->host_traj_dirpath,
                "All files (*)"
                );
    if (!_filename.isEmpty())
    {
        QFile _file(_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "File not found !!");
            ui->line_host_traj->setText("");
        }
        else
        {
            ui->line_host_traj->setText(_filename);
            QDir _dir(_filename);
            _dir.cdUp();
            this->host_traj_dirpath = _dir.path();
        }

    }
}

void Setting_RealTraj::on_PB_output_clicked()
{
    QString _output_path = QFileDialog::getExistingDirectory(
                this,
                tr("Select output folder"),
                this->output_location,
                QFileDialog::ShowDirsOnly
                );
    if (!_output_path.isEmpty())
    {
        QDir _dir(_output_path);
        if(!_dir.exists())
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Warning", "Directory is not exist, do you want to create it?", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes)
            {
                _dir.mkpath(".");
                ui->line_output->setText(_dir.absolutePath());
            }
            else
                ui->line_output->setText(QDir(this->default_output_location).absolutePath());
        }
        else
            ui->line_output->setText(_dir.absolutePath());

    }
    else
        ui->line_output->setText(QDir(this->default_output_location).absolutePath());

}

void Setting_RealTraj::on_PB_OK_clicked()
{
    if(  (ui->line_output->text().isEmpty()) || (ui->line_host_traj->text().isEmpty()) || (ui->line_traj_config->text().isEmpty())   )
    {
        QMessageBox::critical(0, "error", "Please check again the definition of parameters !!");
        return ;
    }
    else
    {
        this->traj_config_filename = ui->line_traj_config->text();
        this->host_traj_filename = ui->line_host_traj->text();
        this->output_location = ui->line_output->text();
        QDialog::accept();
    }
}

void Setting_RealTraj::on_PB_Cancel_clicked()
{
    ui->line_traj_config->setText(this->traj_config_filename);
    ui->line_host_traj->setText(this->host_traj_filename);
    ui->line_output->setText(this->output_location);
    QDialog::reject();
}

void Setting_RealTraj::on_line_traj_config_editingFinished()
{
    QString line_return = ui->line_traj_config->text();
    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_traj_config->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_traj_config->blockSignals(false);
            ui->line_traj_config->setText("");
        }
        else
        {
            QDir _dir(line_return);
            ui->line_traj_config->setText(_dir.absolutePath());
        }
    }
}

void Setting_RealTraj::on_line_host_traj_editingFinished()
{
    QString line_return = ui->line_host_traj->text();
    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_host_traj->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_host_traj->blockSignals(false);
            ui->line_host_traj->setText("");
        }
        else
        {
            QDir _dir(line_return);
            ui->line_host_traj->setText(_dir.absolutePath());
        }
    }
}

void Setting_RealTraj::on_line_output_editingFinished()
{
    QString line_return = ui->line_output->text();
    if (!line_return.isEmpty())
    {
        QDir _dir(line_return);
        if(!_dir.exists())
        {
            ui->line_output->blockSignals(true);
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Warning", "Directory is not exist, do you want to create it?", QMessageBox::Yes|QMessageBox::No);
            ui->line_output->blockSignals(false);

            if (reply == QMessageBox::Yes)
            {
                _dir.mkpath(".");
                ui->line_output->setText(_dir.absolutePath());
            }
            else
                ui->line_output->setText(QDir(this->default_output_location).absolutePath());
        }
        else
            ui->line_output->setText(_dir.absolutePath());
    }
    else
        ui->line_output->setText(QDir(this->default_output_location).absolutePath());

}
