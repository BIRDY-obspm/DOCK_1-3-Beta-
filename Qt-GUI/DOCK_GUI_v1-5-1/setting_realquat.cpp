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

#include "setting_realquat.h"
#include "ui_setting_realquat.h"

Setting_RealQuat::Setting_RealQuat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_RealQuat)
{
    ui->setupUi(this);
}

Setting_RealQuat::~Setting_RealQuat()
{
    delete ui;
}

void Setting_RealQuat::Import_default(st_RealQuat &st_easyquat, bool reset)
{
    if(reset == 1)
    {
        this->first_launch_flag = 0;
    }

    if(this->first_launch_flag == 0)
    {
        this->para_filename = st_easyquat.para_filename;
        this->para_dirpath = st_easyquat.para_dirpath;
        this->seq_input_filename = st_easyquat.Seq_inputs_filename;
        this->seq_input_dirpath = st_easyquat.Seq_inputs_dirpath;
        this->output_location = st_easyquat.Output_location;
        this->default_output_location = st_easyquat.Default_output_location;

        ui->line_para_file->setText(this->para_filename);
        ui->line_seq_file->setText(this->seq_input_filename);
        ui->line_output->setText(this->default_output_location);

        this->first_launch_flag = 1;
    }
}


void Setting_RealQuat::Export_result(st_RealQuat &st_realquat)
{
    st_realquat.Output_location = this->output_location;
    st_realquat.para_filename = this->para_filename;
    st_realquat.para_dirpath = this->para_dirpath;
    st_realquat.Seq_inputs_filename = this->seq_input_filename;
    st_realquat.Seq_inputs_dirpath = this->seq_input_dirpath;
}


void Setting_RealQuat::on_PB_OK_clicked()
{
    if(  (ui->line_output->text().isEmpty()) || (ui->line_para_file->text().isEmpty()) || (ui->line_seq_file->text().isEmpty())   )
    {
        QMessageBox::critical(0, "error", "Please check again the definition of parameters !!");
        return ;
    }
    else
    {
        this->para_filename = ui->line_para_file->text();
        this->seq_input_filename = ui->line_seq_file->text();
        this->output_location = ui->line_output->text();
        QDialog::accept();
    }
}

void Setting_RealQuat::on_PB_Cancel_clicked()
{
    ui->line_para_file->setText(this->para_filename);
    ui->line_seq_file->setText(this->seq_input_filename);
    ui->line_output->setText(this->output_location);
    QDialog::reject();
}

void Setting_RealQuat::on_line_para_file_editingFinished()
{
    QString line_return = ui->line_para_file->text();
    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_para_file->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_para_file->blockSignals(false);
            ui->line_para_file->setText("");
        }
        else
        {
            QDir _dir(line_return);
            ui->line_para_file->setText(_dir.absolutePath());
        }
    }
}

void Setting_RealQuat::on_line_seq_file_editingFinished()
{
    QString line_return = ui->line_seq_file->text();
    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_seq_file->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_seq_file->blockSignals(false);
            ui->line_seq_file->setText("");
        }
        else
        {
            QDir _dir(line_return);
            ui->line_seq_file->setText(_dir.absolutePath());
        }
    }
}

void Setting_RealQuat::on_line_output_editingFinished()
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

void Setting_RealQuat::on_PB_para_file_clicked()
{
    QString _filename = QFileDialog::getOpenFileName(
                this,
                tr("Load AOCS parameters File"),
                this->para_dirpath,
                "All files (*)"
                );
    if (!_filename.isEmpty())
    {
        QFile _file(_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "File not found !!");
            ui->line_para_file->setText("");
        }
        else
        {
            ui->line_para_file->setText(_filename);
            QDir _dir(_filename);
            _dir.cdUp();
            this->para_dirpath = _dir.path();
        }

    }
}

void Setting_RealQuat::on_PB_seq_file_clicked()
{
    QString _filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Seq-inputs File"),
                this->seq_input_dirpath,
                "All files (*)"
                );
    if (!_filename.isEmpty())
    {
        QFile _file(_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "File not found !!");
            ui->line_seq_file->setText("");
        }
        else
        {
            ui->line_seq_file->setText(_filename);
            QDir _dir(_filename);
            _dir.cdUp();
            this->seq_input_dirpath = _dir.path();
        }

    }
}

void Setting_RealQuat::on_PB_output_clicked()
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
