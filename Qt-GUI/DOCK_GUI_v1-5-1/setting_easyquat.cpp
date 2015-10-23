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

#include "setting_easyquat.h"
#include "ui_setting_easyquat.h"



Setting_EasyQuat::Setting_EasyQuat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_EasyQuat)
{
    ui->setupUi(this);
}

Setting_EasyQuat::~Setting_EasyQuat()
{
    delete ui;
}

void Setting_EasyQuat::setEnabled_all(bool seq_inputs_flag)
{
    if(seq_inputs_flag)
    {
        ui->CB_sed_inputs->setChecked(true);
        ui->line_seq_inputs->setEnabled(true);
        ui->PB_Load_seq_inputs->setEnabled(true);

        ui->PB_load_fr_Sce->setEnabled(false);
        ui->line_start_MJDdate->setEnabled(false);
        ui->line_start_MJDsec->setEnabled(false);
        ui->line_end_MJDdate->setEnabled(false);
        ui->line_end_MJDsec->setEnabled(false);
        ui->line_ang_x->setEnabled(false);
        ui->line_ang_y->setEnabled(false);
        ui->line_ang_z->setEnabled(false);
        ui->line_quat_w->setEnabled(false);
        ui->line_quat_x->setEnabled(false);
        ui->line_quat_y->setEnabled(false);
        ui->line_quat_z->setEnabled(false);
        ui->line_stepsize->setEnabled(false);
    }
    else
    {
        ui->CB_sed_inputs->setChecked(false);
        ui->line_seq_inputs->setEnabled(false);
        ui->PB_Load_seq_inputs->setEnabled(false);

        ui->PB_load_fr_Sce->setEnabled(true);
        ui->line_start_MJDdate->setEnabled(true);
        ui->line_start_MJDsec->setEnabled(true);
        ui->line_end_MJDdate->setEnabled(true);
        ui->line_end_MJDsec->setEnabled(true);
        ui->line_ang_x->setEnabled(true);
        ui->line_ang_y->setEnabled(true);
        ui->line_ang_z->setEnabled(true);
        ui->line_quat_w->setEnabled(true);
        ui->line_quat_x->setEnabled(true);
        ui->line_quat_y->setEnabled(true);
        ui->line_quat_z->setEnabled(true);
        ui->line_stepsize->setEnabled(true);
    }

}

void Setting_EasyQuat::Import_default(st_EasyQuat &st_easyquat, bool reset)
{
    this->Seq_inputs_flag = st_easyquat.Seq_inputs_flag;

    if(reset == 1)
    {
        this->first_launch_flag = 0;
    }

    if(this->first_launch_flag == 0)
    {
        this->sim_start_date = st_easyquat.sim_start_date;
        this->sim_start_sec = st_easyquat.sim_start_sec;
        this->sim_end_date = st_easyquat.sim_end_date;
        this->sim_end_sec = st_easyquat.sim_end_sec;
        this->sim_step_size = st_easyquat.sim_step_size;

        this->Start_MJD_date = this->Sce_Start_MJD_date = st_easyquat.Sce_Start_MJD_date;
        this->Start_MJD_sec = this->Sce_Start_MJD_sec = st_easyquat.Sce_Start_MJD_sec;
        this->End_MJD_date = this->Sce_End_MJD_date = st_easyquat.Sce_End_MJD_date;
        this->End_MJD_sec = this->Sce_End_MJD_sec = st_easyquat.Sce_End_MJD_sec;
        this->Step_size = this->Sce_Step_size = st_easyquat.Sce_Step_size;
        this->quat_w = st_easyquat.quat_w;
        this->quat_x = st_easyquat.quat_x;
        this->quat_y = st_easyquat.quat_y;
        this->quat_z = st_easyquat.quat_z;
        this->ang_x = st_easyquat.ang_x;
        this->ang_y = st_easyquat.ang_y;
        this->ang_z = st_easyquat.ang_z;
        this->Seq_inputs_dirpath = st_easyquat.Seq_inputs_dirpath;
        this->Output_location = st_easyquat.Default_output_location;
        this->Default_output_location = st_easyquat.Default_output_location;


        ui->line_start_MJDdate->setValue(this->Sce_Start_MJD_date);
        ui->line_start_MJDsec->setValue(this->Sce_Start_MJD_sec);
        ui->line_end_MJDdate->setValue(this->Sce_End_MJD_date);
        ui->line_end_MJDsec->setValue(this->Sce_End_MJD_sec);
        ui->line_stepsize->setValue(this->Sce_Step_size);
        ui->line_ang_x->setValue(this->ang_x);
        ui->line_ang_y->setValue(this->ang_y);
        ui->line_ang_z->setValue(this->ang_z);
        ui->line_quat_w->setValue(this->quat_w);
        ui->line_quat_x->setValue(this->quat_x);
        ui->line_quat_y->setValue(this->quat_y);
        ui->line_quat_z->setValue(this->quat_z);
        ui->line_output_location->setText(this->Default_output_location);

        if (!st_easyquat.Seq_inputs_flag) //false
        {
            setEnabled_all(st_easyquat.Seq_inputs_flag);
        }
        else
        {
            setEnabled_all(st_easyquat.Seq_inputs_flag);
            this->Seq_inputs_filename = st_easyquat.Seq_inputs_filename;
            ui->line_seq_inputs->setText(this->Seq_inputs_filename);
        }
        this->finish_flag = 1; //true
        this->first_launch_flag = 1;
    }

}


void Setting_EasyQuat::Export_result(st_EasyQuat &st_easyquat)
{
    st_easyquat.Sce_Start_MJD_date = this->Start_MJD_date;
    st_easyquat.Sce_Start_MJD_sec = this->Start_MJD_sec;
    st_easyquat.Sce_End_MJD_date = this->End_MJD_date;
    st_easyquat.Sce_End_MJD_sec = this->End_MJD_sec;
    st_easyquat.Sce_Step_size = this->Step_size;
    st_easyquat.quat_w = this->quat_w;
    st_easyquat.quat_x = this->quat_x;
    st_easyquat.quat_y = this->quat_y;
    st_easyquat.quat_z = this->quat_z;
    st_easyquat.ang_x = this->ang_x;
    st_easyquat.ang_y = this->ang_y;
    st_easyquat.ang_z = this->ang_z;
    st_easyquat.Seq_inputs_dirpath = this->Seq_inputs_dirpath;
    st_easyquat.Seq_inputs_filename = this->Seq_inputs_filename;
    st_easyquat.Output_location = this->Output_location;
    st_easyquat.Seq_inputs_flag = this->Seq_inputs_flag;
}



void Setting_EasyQuat::reload(bool seq_inputs_flag)
{
    if(seq_inputs_flag)
    {
        setEnabled_all(seq_inputs_flag);
        ui->line_seq_inputs->setText(this->Seq_inputs_filename);
    }
    else
    {
        setEnabled_all(seq_inputs_flag);
        ui->line_start_MJDdate->setValue(this->Start_MJD_date);
        ui->line_start_MJDsec->setValue(this->Start_MJD_sec);
        ui->line_end_MJDdate->setValue(this->End_MJD_date);
        ui->line_end_MJDsec->setValue(this->End_MJD_sec);
        ui->line_stepsize->setValue(this->Step_size);
        ui->line_ang_x->setValue(this->ang_x);
        ui->line_ang_y->setValue(this->ang_y);
        ui->line_ang_z->setValue(this->ang_z);
        ui->line_quat_w->setValue(this->quat_w);
        ui->line_quat_x->setValue(this->quat_x);
        ui->line_quat_y->setValue(this->quat_y);
        ui->line_quat_z->setValue(this->quat_z);
    }
    ui->line_output_location->setText(this->Output_location);

}


void Setting_EasyQuat::clear_all()
{
    ui->line_seq_inputs->clear();
    ui->line_start_MJDdate->clear();
    ui->line_start_MJDsec->clear();
    ui->line_end_MJDdate->clear();
    ui->line_end_MJDsec->clear();
    ui->line_ang_x->clear();
    ui->line_ang_y->clear();
    ui->line_ang_z->clear();
    ui->line_quat_w->clear();
    ui->line_quat_x->clear();
    ui->line_quat_y->clear();
    ui->line_quat_z->clear();
    ui->line_stepsize->clear();
    ui->line_output_location->clear();

    this->finish_flag = 0; //false
}

//====================================================
//====================CB clicked()====================
//====================================================

void Setting_EasyQuat::on_CB_sed_inputs_clicked()
{
    if(ui->CB_sed_inputs->isChecked())
    {
        setEnabled_all(ui->CB_sed_inputs->isChecked());
        this->finish_flag = 0; //false
    }
    else
    {
        setEnabled_all(ui->CB_sed_inputs->isChecked());
        this->finish_flag = 0; //false
    }
}


//====================================================
//====================PB clicked()====================
//====================================================


void Setting_EasyQuat::on_PB_load_fr_Sce_clicked()
{
    ui->line_start_MJDdate->setValue(this->sim_start_date);
    ui->line_start_MJDsec->setValue(this->sim_start_sec);
    ui->line_end_MJDdate->setValue(this->sim_end_date);
    ui->line_end_MJDsec->setValue(this->sim_end_sec);
    ui->line_stepsize->setValue(this->sim_step_size);
    this->finish_flag = 0; //false
}



void Setting_EasyQuat::on_PB_Load_seq_inputs_clicked()
{
    QString _filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Seq-inputs File"),
                this->Seq_inputs_dirpath,
                "All files (*)"
                );
    if (!_filename.isEmpty())
    {
        QFile _file(_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "File not found !!");
            ui->line_seq_inputs->setText("Not found");
            this->finish_flag = 0; //false
        }
        else
        {
            ui->line_seq_inputs->setText(_filename);
            QDir _dir(_filename);
            _dir.cdUp();
            this->Seq_inputs_dirpath = _dir.path();
            this->finish_flag = 0; //false
        }

    }
}


void Setting_EasyQuat::on_PB_output_location_clicked()
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
                this->finish_flag = 0;
            }
            else
            {
                ui->line_output_location->setText(QDir(this->Default_output_location).absolutePath());
            }
        }
        else
        {
            ui->line_output_location->setText(_dir.absolutePath());
            this->finish_flag = 0;
        }

    }
    else
        ui->line_output_location->setText(QDir(this->Default_output_location).absolutePath());
}


void Setting_EasyQuat::on_PB_clearall_clicked()
{
    clear_all();
}

void Setting_EasyQuat::on_PB_OK_clicked()
{
    this->Output_location = ui->line_output_location->text();

    if (!ui->CB_sed_inputs->isChecked())
    {
        if( (ui->line_start_MJDdate->text().isEmpty())||(ui->line_start_MJDsec->text().isEmpty())||(ui->line_end_MJDdate->text().isEmpty())||(ui->line_end_MJDsec->text().isEmpty())
          ||(ui->line_stepsize->text().isEmpty())||(ui->line_quat_w->text().isEmpty())||(ui->line_quat_x->text().isEmpty())||(ui->line_quat_y->text().isEmpty())
          ||(ui->line_quat_z->text().isEmpty())||(ui->line_ang_x->text().isEmpty())||(ui->line_ang_y->text().isEmpty())||(ui->line_ang_z->text().isEmpty())   )
        {
            QMessageBox::critical(0, "error", "Please check again the definition of parameters !!");
            this->finish_flag = 0; //false
            return ;
        }
        else
        {
            this->Start_MJD_date = ui->line_start_MJDdate->value();
            this->Start_MJD_sec  = ui->line_start_MJDsec->value();
            this->End_MJD_date   = ui->line_end_MJDdate->value();
            this->End_MJD_sec    = ui->line_end_MJDsec->value();
            this->Step_size      = ui->line_stepsize->value();
            this->quat_w = ui->line_quat_w->value();
            this->quat_x = ui->line_quat_x->value();
            this->quat_y = ui->line_quat_y->value();
            this->quat_z = ui->line_quat_z->value();
            double nom = sqrt(this->quat_w*this->quat_w + this->quat_x*this->quat_x + this->quat_y*this->quat_y + this->quat_z*this->quat_z);
            this->quat_w = this->quat_w / nom;
            this->quat_x = this->quat_x / nom;
            this->quat_y = this->quat_y / nom;
            this->quat_z = this->quat_z / nom;


            this->ang_x = ui->line_ang_x->value();
            this->ang_y = ui->line_ang_y->value();
            this->ang_z = ui->line_ang_z->value();

            this->Seq_inputs_flag = 0;
            this->finish_flag = 1; //true

            QDialog::accept();
        }
    }
    else
    {
        if ( (ui->line_seq_inputs->text() == "Not found") || (ui->line_seq_inputs->text().isEmpty()) )
        {
            QMessageBox::critical(0, "error", "Seq-inputs file not found !!");
            this->finish_flag = 0; //false
            return ;
        }
        else
        {
            this->Seq_inputs_filename = ui->line_seq_inputs->text();
            this->finish_flag = 1; //true
            this->Seq_inputs_flag = 1;
            QDialog::accept();
        }
    }

}



void Setting_EasyQuat::on_PB_cancel_clicked()
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
            reload(this->Seq_inputs_flag);
            QDialog::reject();
            this->finish_flag = 1;
        }
        else
            return;
    }
}

//=======================================================
//===================editingFinished()===================
//=======================================================
void Setting_EasyQuat::on_line_seq_inputs_editingFinished()
{
    QString line_return = ui->line_seq_inputs->text();
    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_seq_inputs->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_seq_inputs->blockSignals(false);
            ui->line_seq_inputs->setText("Not found");
        }
        else
        {
            QDir _dir(line_return);
            ui->line_seq_inputs->setText(_dir.absolutePath());
            this->finish_flag = 0;
        }
    }
}


void Setting_EasyQuat::on_line_output_location_editingFinished()
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
                this->finish_flag = 0;
            }
            else
            {
                ui->line_output_location->setText(QDir(this->Default_output_location).absolutePath());
            }
        }
        else
        {
            ui->line_output_location->setText(_dir.absolutePath());
            this->finish_flag = 0;
        }
    }
    else
        ui->line_output_location->setText(QDir(this->Default_output_location).absolutePath());
}



//===================================================================
//===================valueChanged(int/double arg1)===================
//===================================================================
void Setting_EasyQuat::on_line_start_MJDdate_valueChanged(int arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_start_MJDsec_valueChanged(double arg1)
{
    this->finish_flag = 0;
    if( arg1 >= 86400.0)
        ui->line_start_MJDsec->setValue(0.0);
}

void Setting_EasyQuat::on_line_end_MJDdate_valueChanged(int arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_end_MJDsec_valueChanged(double arg1)
{
    this->finish_flag = 0;
    if( arg1 >= 86400.0)
        ui->line_end_MJDsec->setValue(0.0);
}

void Setting_EasyQuat::on_line_stepsize_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_quat_w_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_quat_x_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_quat_y_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_quat_z_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_ang_x_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_ang_y_valueChanged(double arg1)
{
    this->finish_flag = 0;
}

void Setting_EasyQuat::on_line_ang_z_valueChanged(double arg1)
{
    this->finish_flag = 0;
}
