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

#include "setting_easytraj.h"
#include "ui_setting_easytraj.h"

Setting_EasyTraj::Setting_EasyTraj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_EasyTraj)
{
    ui->setupUi(this);

    ui->comboBox_type->addItem("Keplerian");
    ui->comboBox_type->addItem("Circular");
}

Setting_EasyTraj::~Setting_EasyTraj()
{
    delete ui;
}

void Setting_EasyTraj::Import_default(st_EasyTraj &st_easytraj, bool reset)
{
    if(reset == 1)
        this->first_launch_flag = 0;
    if(this->first_launch_flag == 0)
    {
        this->sim_start_date = st_easytraj.sim_start_date;
        this->sim_start_sec = st_easytraj.sim_start_sec;
        this->sim_end_date = st_easytraj.sim_end_date;
        this->sim_end_sec = st_easytraj.sim_end_sec;
        this->sim_step_size = st_easytraj.sim_step_size;

        this->Start_MJD_date = this->Sce_Start_MJD_date = st_easytraj.Sce_Start_MJD_date;
        this->Start_MJD_sec = this->Sce_Start_MJD_sec = st_easytraj.Sce_Start_MJD_sec;
        this->End_MJD_date = this->Sce_End_MJD_date = st_easytraj.Sce_End_MJD_date;
        this->End_MJD_sec = this->Sce_End_MJD_sec = st_easytraj.Sce_End_MJD_sec;
        this->Step_size = this->Sce_Step_size = st_easytraj.Sce_Step_size;

        if(st_easytraj.Easy_traj_type == "Circular")
            this->Easy_traj_type = "Circular";
        else
            this->Easy_traj_type = "Keplerian";
        this->Easy_traj_anm = st_easytraj.Easy_traj_anm;
        this->Easy_traj_ecc = st_easytraj.Easy_traj_ecc;
        this->Easy_traj_gom = st_easytraj.Easy_traj_gom;
        this->Easy_traj_inc = st_easytraj.Easy_traj_inc;
        this->Easy_traj_pom = st_easytraj.Easy_traj_pom;
        this->Easy_traj_sma = st_easytraj.Easy_traj_sma;

        this->Output_location = st_easytraj.Default_output_location;
        this->Default_output_location = st_easytraj.Default_output_location;

        ui->SB_start_MJDdate->setValue(this->Sce_Start_MJD_date);
        ui->SB_start_MJDsec->setValue(this->Sce_Start_MJD_sec);
        ui->SB_end_MJDdate->setValue(this->Sce_End_MJD_date);
        ui->SB_end_MJDsec->setValue(this->Sce_End_MJD_sec);
        ui->SB_stepsize->setValue(this->Sce_Step_size);
        ui->comboBox_type->setCurrentText(this->Easy_traj_type);
        ui->SB_anm->setValue(this->Easy_traj_anm);
        ui->SB_ecc->setValue(this->Easy_traj_ecc);
        ui->SB_gom->setValue(this->Easy_traj_gom);
        ui->SB_inc->setValue(this->Easy_traj_inc);
        ui->SB_pom->setValue(this->Easy_traj_pom);
        ui->SB_sma->setValue(this->Easy_traj_sma);
        ui->line_output_location->setText(this->Default_output_location);

        this->first_launch_flag = 1;
        this->finish_flag = 1;
    }
}

void Setting_EasyTraj::Export_result(st_EasyTraj &st_easytraj)
{
    st_easytraj.Sce_Start_MJD_date = this->Start_MJD_date;
    st_easytraj.Sce_Start_MJD_sec = this->Start_MJD_sec;
    st_easytraj.Sce_End_MJD_date = this->End_MJD_date;
    st_easytraj.Sce_End_MJD_sec = this->End_MJD_sec;
    st_easytraj.Sce_Step_size = this->Step_size;

    st_easytraj.Easy_traj_type = this->Easy_traj_type;
    st_easytraj.Easy_traj_anm = this->Easy_traj_anm;
    st_easytraj.Easy_traj_ecc = this->Easy_traj_ecc;
    st_easytraj.Easy_traj_gom = this->Easy_traj_gom;
    st_easytraj.Easy_traj_inc = this->Easy_traj_inc;
    st_easytraj.Easy_traj_pom = this->Easy_traj_pom;
    st_easytraj.Easy_traj_sma = this->Easy_traj_sma;

    st_easytraj.Output_location = this->Output_location;
}


void Setting_EasyTraj::on_PB_load_fr_Sce_clicked()
{
    ui->SB_start_MJDdate->setValue(this->sim_start_date);
    ui->SB_start_MJDsec->setValue(this->sim_start_sec);
    ui->SB_end_MJDdate->setValue(this->sim_end_date);
    ui->SB_end_MJDsec->setValue(this->sim_end_sec);
    ui->SB_stepsize->setValue(this->sim_step_size);

    this->finish_flag = 0;
}

void Setting_EasyTraj::on_PB_output_location_clicked()
{
    QString _output_path = QFileDialog::getExistingDirectory(
                this,
                tr("Select output folder"),
                this->Output_location,
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
                ui->line_output_location->setText(QDir(this->Default_output_location).absolutePath());
        }
        else
            ui->line_output_location->setText(_dir.absolutePath());
    }
    else
        ui->line_output_location->setText(QDir(this->Default_output_location).absolutePath());

    this->finish_flag = 0;

}

void Setting_EasyTraj::on_PB_OK_clicked()
{
    if(   (ui->SB_start_MJDdate->text().isEmpty()) || (ui->SB_start_MJDsec->text().isEmpty()) || (ui->SB_end_MJDdate->text().isEmpty()) || (ui->SB_end_MJDsec->text().isEmpty())
       || (ui->comboBox_type->currentText().isEmpty()) || (ui->SB_anm->text().isEmpty()) || (ui->SB_ecc->text().isEmpty()) || (ui->SB_gom->text().isEmpty()) || (ui->SB_inc->text().isEmpty())
       || (ui->SB_pom->text().isEmpty()) || (ui->SB_sma->text().isEmpty()) || (ui->SB_stepsize->text().isEmpty()) || (ui->line_output_location->text().isEmpty())  )
    {
        QMessageBox::critical(0, "error", "Please check again the definition of parameters !!");
        return ;
    }
    else
    {
        this->Start_MJD_date = ui->SB_start_MJDdate->value();
        this->Start_MJD_sec  = ui->SB_start_MJDsec->value();
        this->End_MJD_date   = ui->SB_end_MJDdate->value();
        this->End_MJD_sec    = ui->SB_end_MJDsec->value();
        this->Step_size      = ui->SB_stepsize->value();

        this->Easy_traj_type = ui->comboBox_type->currentText();
        this->Easy_traj_anm = ui->SB_anm->value();
        this->Easy_traj_ecc = ui->SB_ecc->value();
        this->Easy_traj_gom = ui->SB_gom->value();
        this->Easy_traj_inc = ui->SB_inc->value();
        this->Easy_traj_pom = ui->SB_pom->value();
        this->Easy_traj_sma = ui->SB_sma->value();

        this->Output_location = ui->line_output_location->text();

        this->finish_flag = 1;

        QDialog::accept();
    }


}

void Setting_EasyTraj::on_PB_cancel_clicked()
{
    if (this->finish_flag == 1) //true: without any change
    {
        QDialog::reject();
    }
    else
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Exit without saving", "Quit the setting panel without saving?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            ui->SB_start_MJDdate->setValue(this->Start_MJD_date);
            ui->SB_start_MJDsec->setValue(this->Start_MJD_sec);
            ui->SB_end_MJDdate->setValue(this->End_MJD_date);
            ui->SB_end_MJDsec->setValue(this->End_MJD_sec);
            ui->SB_stepsize->setValue(this->Step_size);
            ui->comboBox_type->setCurrentText(this->Easy_traj_type);
            ui->SB_anm->setValue(this->Easy_traj_anm);
            ui->SB_ecc->setValue(this->Easy_traj_ecc);
            ui->SB_gom->setValue(this->Easy_traj_gom);
            ui->SB_inc->setValue(this->Easy_traj_inc);
            ui->SB_pom->setValue(this->Easy_traj_pom);
            ui->SB_sma->setValue(this->Easy_traj_sma);
            ui->line_output_location->setText(this->Output_location);

            this->finish_flag = 1;
            QDialog::reject();
        }
        else
            return;
    }
}

void Setting_EasyTraj::on_PB_clearall_clicked()
{
    ui->SB_start_MJDdate->clear();
    ui->SB_start_MJDsec->clear();
    ui->SB_end_MJDdate->clear();
    ui->SB_end_MJDsec->clear();
    ui->SB_stepsize->clear();
    ui->comboBox_type->setCurrentIndex(0);
    ui->SB_anm->clear();
    ui->SB_ecc->clear();
    ui->SB_gom->clear();
    ui->SB_inc->clear();
    ui->SB_pom->clear();
    ui->SB_sma->clear();
    ui->line_output_location->clear();

    this->finish_flag = 0;
}

void Setting_EasyTraj::on_comboBox_type_currentTextChanged(const QString &arg1)
{
    this->finish_flag = 0;
    if(arg1 != "Circular")
        ui->comboBox_type->setCurrentText("Keplerian");
}

void Setting_EasyTraj::on_SB_start_MJDdate_valueChanged(int arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_SB_start_MJDsec_valueChanged(double arg1)
{
    this->finish_flag = 0;
    if( arg1 >= 86400.0)
        ui->SB_start_MJDsec->setValue(0.0);
}

void Setting_EasyTraj::on_SB_end_MJDdate_valueChanged(int arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_SB_end_MJDsec_valueChanged(double arg1)
{
    this->finish_flag = 0;
    if( arg1 >= 86400.0)
        ui->SB_end_MJDsec->setValue(0.0);
}

void Setting_EasyTraj::on_SB_stepsize_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_SB_sma_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_SB_ecc_valueChanged(double arg1)
{
    if( arg1 >= 1.0 )
        ui->SB_ecc->setValue(1.0);
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_SB_pom_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_SB_anm_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_SB_inc_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_SB_gom_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyTraj::on_line_output_location_editingFinished()
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
                ui->line_output_location->setText(QDir(this->Default_output_location).absolutePath());
        }
        else
            ui->line_output_location->setText(_dir.absolutePath());
    }
    else
        ui->line_output_location->setText(QDir(this->Default_output_location).absolutePath());

}
