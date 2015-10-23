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

#include "setting_prodvts.h"
#include "ui_setting_prodvts.h"

Setting_ProdVTS::Setting_ProdVTS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_ProdVTS)
{
    ui->setupUi(this);
}

Setting_ProdVTS::~Setting_ProdVTS()
{
    delete ui;
}

void Setting_ProdVTS::Import_default(VTS_Soft &vts_soft, bool reset)
{
    if(reset == 1)
    {
        this->first_launch_flag = 0;
    }

    if(this->first_launch_flag == 0)
    {
        this->output_location = vts_soft.Output_location;
        this->default_output_location = vts_soft.Default_output_location;
        this->VTS_keep_app_setting = vts_soft.VTS_keep_app_setting;

        ui->line_output_location->setText(this->default_output_location);

        if(this->VTS_keep_app_setting == 1)
            ui->CB_keep_apps->setChecked(1);
        else
            ui->CB_keep_apps->setChecked(0);

        this->first_launch_flag = 1;
    }
}

void Setting_ProdVTS::Export_result(VTS_Soft &vts_soft)
{
        vts_soft.Output_location = this->output_location;
        vts_soft.VTS_keep_app_setting = this->VTS_keep_app_setting;
}

void Setting_ProdVTS::on_PB_output_location_clicked()
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
                ui->line_output_location->setText(_dir.absolutePath());
            }
            else
                ui->line_output_location->setText(QDir(this->default_output_location).absolutePath());
        }
        else
            ui->line_output_location->setText(_dir.absolutePath());

    }
    else
        ui->line_output_location->setText(QDir(this->default_output_location).absolutePath());
}

void Setting_ProdVTS::on_PB_OK_clicked()
{
    if( ui->line_output_location->text().isEmpty() )
    {
        QMessageBox::critical(0, "error", "Please check again the definition of output folder !!");
        return ;
    }
    else
    {
        this->output_location = ui->line_output_location->text();
        this->VTS_keep_app_setting = ui->CB_keep_apps->isChecked();
        QDialog::accept();
    }
}

void Setting_ProdVTS::on_PB_Cancel_clicked()
{
    ui->line_output_location->setText(this->output_location);
    ui->CB_keep_apps->setChecked(this->VTS_keep_app_setting);
    QDialog::reject();
}

void Setting_ProdVTS::on_line_output_location_editingFinished()
{
    QString line_return = ui->line_output_location->text();
    if (!line_return.isEmpty())
    {
        QDir _dir(line_return);
        if(!_dir.exists())
        {
            ui->line_output_location->blockSignals(true);
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Warning", "Directory is not exist, do you want to create it?", QMessageBox::Yes|QMessageBox::No);
            ui->line_output_location->blockSignals(false);

            if (reply == QMessageBox::Yes)
            {
                _dir.mkpath(".");
                ui->line_output_location->setText(_dir.absolutePath());
            }
            else
                ui->line_output_location->setText(QDir(this->default_output_location).absolutePath());
        }
        else
            ui->line_output_location->setText(_dir.absolutePath());
    }
    else
        ui->line_output_location->setText(QDir(this->default_output_location).absolutePath());
}

