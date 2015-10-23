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

#include "setting_ccsds.h"
#include "ui_setting_ccsds.h"

Setting_CCSDS::Setting_CCSDS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_CCSDS)
{
    ui->setupUi(this);

    ui->comboBox_frameA->addItem("EME2000");
    ui->comboBox_frameA->addItem("ICRF");
    ui->comboBox_frameA->addItem("SC_BODY_1");
    ui->comboBox_frameA->addItem("SC_BODY_2");
    ui->comboBox_frameA->addItem("SC_BODY_3");

    ui->comboBox_frameB->addItem("SC_BODY_1");
    ui->comboBox_frameB->addItem("SC_BODY_2");
    ui->comboBox_frameB->addItem("SC_BODY_3");
    ui->comboBox_frameB->addItem("EME2000");
    ui->comboBox_frameB->addItem("ICRF");

    ui->comboBox_dir->addItem("A2B");
    ui->comboBox_dir->addItem("B2A");

    ui->comboBox_type->addItem("QUATERNION");

    ui->comboBox_time->addItem("UTC");
    ui->comboBox_time->addItem("TT");
    ui->comboBox_time->addItem("TAI");
    ui->comboBox_time->addItem("TDB");
    ui->comboBox_time->addItem("TCB");
}

Setting_CCSDS::~Setting_CCSDS()
{
    delete ui;
}

//In header file, the default value of "reset" already was set as "0", can not define in here again
void Setting_CCSDS::Import_default(VTS_CIC_para &vts_cic, bool reset)
{
    if(reset == 1)
        this->first_launch_flag = 0;
    if(this->first_launch_flag == 0)
    {
        this->Satellite_name = vts_cic.Satellite_name;
        this->Satellite_Axes = vts_cic.Satellite_Axes;
        this->Satellite_3ds = vts_cic.Satellite_3ds;
        this->Satellite_quaternion = vts_cic.Satellite_quaternion;
        this->Satellite_position = vts_cic.Satellite_position;
        this->Satellite_parentpath = vts_cic.Satellite_parentpath;

        if(   (vts_cic.Satellite_ref_frame_A != "ICRF") && (vts_cic.Satellite_ref_frame_A != "EME2000") && (vts_cic.Satellite_ref_frame_A != "SC_BODY_1")
           && (vts_cic.Satellite_ref_frame_A != "SC_BODY_2") && (vts_cic.Satellite_ref_frame_A != "SC_BODY_3")    )
            this->Satellite_ref_frame_A = "EME2000";
        else
            this->Satellite_ref_frame_A = vts_cic.Satellite_ref_frame_A;

        if(   (vts_cic.Satellite_ref_frame_B != "ICRF") && (vts_cic.Satellite_ref_frame_B != "EME2000") && (vts_cic.Satellite_ref_frame_B != "SC_BODY_1")
           && (vts_cic.Satellite_ref_frame_B != "SC_BODY_2") && (vts_cic.Satellite_ref_frame_B != "SC_BODY_3")    )
            this->Satellite_ref_frame_B = "SC_BODY_1";
        else
            this->Satellite_ref_frame_B = vts_cic.Satellite_ref_frame_B;

        if( (vts_cic.Satellite_attitude_dir != "A2B") && (vts_cic.Satellite_attitude_dir != "B2A")  )
            this->Satellite_attitude_dir = "A2B";
        else
            this->Satellite_attitude_dir = vts_cic.Satellite_attitude_dir;

        // Currently, DOCKS only support "QUATERNION"
        this->Satellite_att_type = "QUATERNION";

        if(   (vts_cic.Satellite_time_system != "UTC") && (vts_cic.Satellite_time_system != "TT") && (vts_cic.Satellite_time_system != "TAI")
           && (vts_cic.Satellite_time_system != "TDB") && (vts_cic.Satellite_time_system != "TCB")    )
            this->Satellite_time_system = "UTC";
        else
            this->Satellite_time_system = vts_cic.Satellite_time_system;

        ui->line_Satellite_name->setText(this->Satellite_name);
        ui->line_Satellite_Axes->setText(this->Satellite_Axes);
        ui->line_Satellite_3ds->setText(this->Satellite_3ds);
        ui->line_Satellite_quaternion->setText(this->Satellite_quaternion);
        ui->line_Satellite_position->setText(this->Satellite_position);
        ui->line_Satellite_parentpath->setText(this->Satellite_parentpath);
        ui->comboBox_frameA->setCurrentText(this->Satellite_ref_frame_A);
        ui->comboBox_frameB->setCurrentText(this->Satellite_ref_frame_B);
        ui->comboBox_dir->setCurrentText(this->Satellite_attitude_dir);
        ui->comboBox_type->setCurrentText(this->Satellite_att_type);
        ui->comboBox_time->setCurrentText(this->Satellite_time_system);

        this->first_launch_flag = 1;
        this->finish_flag = 1;
    }
}

void Setting_CCSDS::Export_result(VTS_CIC_para &vts_cic)
{
    vts_cic.Satellite_name = this->Satellite_name;
    vts_cic.Satellite_Axes = this->Satellite_Axes;
    vts_cic.Satellite_3ds = this->Satellite_3ds;
    vts_cic.Satellite_quaternion = this->Satellite_quaternion;
    vts_cic.Satellite_position = this->Satellite_position;
    vts_cic.Satellite_parentpath = this->Satellite_parentpath;
    vts_cic.Satellite_ref_frame_A = this->Satellite_ref_frame_A;
    vts_cic.Satellite_ref_frame_B = this->Satellite_ref_frame_B;
    vts_cic.Satellite_attitude_dir = this->Satellite_attitude_dir;
    vts_cic.Satellite_att_type = this->Satellite_att_type;
    vts_cic.Satellite_time_system = this->Satellite_time_system;
}

void Setting_CCSDS::on_PB_Satellite_3ds_clicked()
{
    QString _filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Satellite 3ds File"),
                this->Satellite_3ds_dir,
                ".3ds files (*.3ds)"
                );
    if (!_filename.isEmpty())
    {
        QFile _file(_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "File not found !!");
            ui->line_Satellite_3ds->setText("");
            this->finish_flag = 0; //false
        }
        else
        {
            ui->line_Satellite_3ds->setText(_filename);
            QDir _dir(_filename);
            _dir.cdUp();
            this->Satellite_3ds_dir = _dir.path();
            this->finish_flag = 0; //false
        }

    }
}

void Setting_CCSDS::on_PB_Satellite_quaternion_clicked()
{
    QString _filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Satellite Quaternion File"),
                this->Satellite_quaternion_dir,
                "All files (*)"
                );
    if (!_filename.isEmpty())
    {
        QFile _file(_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "File not found !!");
            ui->line_Satellite_quaternion->setText("");
            this->finish_flag = 0; //false
        }
        else
        {
            ui->line_Satellite_quaternion->setText(_filename);
            QDir _dir(_filename);
            _dir.cdUp();
            this->Satellite_quaternion_dir = _dir.path();
            this->finish_flag = 0; //false
        }

    }
}

void Setting_CCSDS::on_PB_Satellite_position_clicked()
{
    QString _filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Satellite Position File"),
                this->Satellite_position_dir,
                "All files (*)"
                );
    if (!_filename.isEmpty())
    {
        QFile _file(_filename);
        if(!_file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "error", "File not found !!");
            ui->line_Satellite_position->setText("");
            this->finish_flag = 0; //false
        }
        else
        {
            ui->line_Satellite_position->setText(_filename);
            QDir _dir(_filename);
            _dir.cdUp();
            this->Satellite_position_dir = _dir.path();
            this->finish_flag = 0; //false
        }

    }
}

void Setting_CCSDS::on_PB_OK_clicked()
{
    if(   (ui->line_Satellite_3ds->text().isEmpty()) || (ui->line_Satellite_Axes->text().isEmpty()) || (ui->line_Satellite_name->text().isEmpty()) || (ui->line_Satellite_parentpath->text().isEmpty())
       || (ui->comboBox_dir->currentText().isEmpty()) || (ui->comboBox_frameA->currentText().isEmpty()) || (ui->comboBox_frameB->currentText().isEmpty())
       || (ui->comboBox_time->currentText().isEmpty()) || (ui->comboBox_type->currentText().isEmpty())  )
    {
        QMessageBox::critical(0, "error", "Please check again the definition of parameters !!");
        return ;
    }
    else
    {
        this->Satellite_name = ui->line_Satellite_name->text();
        this->Satellite_Axes = ui->line_Satellite_Axes->text();
        this->Satellite_3ds = ui->line_Satellite_3ds->text();
        this->Satellite_quaternion = ui->line_Satellite_quaternion->text();
        this->Satellite_position = ui->line_Satellite_position->text();
        this->Satellite_parentpath = ui->line_Satellite_parentpath->text();
        this->Satellite_ref_frame_A = ui->comboBox_frameA->currentText();
        this->Satellite_ref_frame_B = ui->comboBox_frameB->currentText();
        this->Satellite_attitude_dir = ui->comboBox_dir->currentText();
        this->Satellite_att_type = ui->comboBox_type->currentText();
        this->Satellite_time_system = ui->comboBox_time->currentText();

        this->finish_flag = 1;

        QDialog::accept();
    }
}

void Setting_CCSDS::on_PB_Cancel_clicked()
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
            ui->line_Satellite_name->setText(this->Satellite_name);
            ui->line_Satellite_Axes->setText(this->Satellite_Axes);
            ui->line_Satellite_3ds->setText(this->Satellite_3ds);
            ui->line_Satellite_quaternion->setText(this->Satellite_quaternion);
            ui->line_Satellite_position->setText(this->Satellite_position);
            ui->line_Satellite_parentpath->setText(this->Satellite_parentpath);
            ui->comboBox_frameA->setCurrentText(this->Satellite_ref_frame_A);
            ui->comboBox_frameB->setCurrentText(this->Satellite_ref_frame_B);
            ui->comboBox_dir->setCurrentText(this->Satellite_attitude_dir);
            ui->comboBox_type->setCurrentText(this->Satellite_att_type);
            ui->comboBox_time->setCurrentText(this->Satellite_time_system);

            this->finish_flag = 1;
            QDialog::reject();
        }
        else
            return;
    }
}

void Setting_CCSDS::on_PB_Clear_all_clicked()
{
    ui->line_Satellite_name->clear();
    ui->line_Satellite_Axes->clear();
    ui->line_Satellite_3ds->clear();
    ui->line_Satellite_quaternion->clear();
    ui->line_Satellite_position->clear();
    ui->line_Satellite_parentpath->clear();
    ui->comboBox_frameA->setCurrentIndex(0);
    ui->comboBox_frameB->setCurrentIndex(0);
    ui->comboBox_dir->setCurrentIndex(0);
    ui->comboBox_type->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex(0);

    this->finish_flag = 0;
}

void Setting_CCSDS::on_line_Satellite_3ds_editingFinished()
{
    QString line_return = ui->line_Satellite_3ds->text();
    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_Satellite_3ds->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_Satellite_3ds->blockSignals(false);
            ui->line_Satellite_3ds->setText("");
        }
        else
        {
            QDir _dir(line_return);
            ui->line_Satellite_3ds->setText(_dir.absolutePath());
            this->finish_flag = 0;
        }
    }
}

void Setting_CCSDS::on_line_Satellite_quaternion_editingFinished()
{
    QString line_return = ui->line_Satellite_quaternion->text();
    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_Satellite_quaternion->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_Satellite_quaternion->blockSignals(false);
            ui->line_Satellite_quaternion->setText("");
        }
        else
        {
            QDir _dir(line_return);
            ui->line_Satellite_quaternion->setText(_dir.absolutePath());
            this->finish_flag = 0;
        }
    }
}

void Setting_CCSDS::on_line_Satellite_position_editingFinished()
{
    QString line_return = ui->line_Satellite_position->text();
    if (!line_return.isEmpty())
    {
        QFile _file(line_return);
        if(!_file.open(QIODevice::ReadOnly))
        {
            ui->line_Satellite_position->blockSignals(true);
            QMessageBox::critical(0, "error", _file.errorString());
            ui->line_Satellite_position->blockSignals(false);
            ui->line_Satellite_position->setText("");
        }
        else
        {
            QDir _dir(line_return);
            ui->line_Satellite_position->setText(_dir.absolutePath());
            this->finish_flag = 0;
        }
    }
}

void Setting_CCSDS::on_line_Satellite_name_editingFinished()
{
    this->finish_flag = 0;
}

void Setting_CCSDS::on_line_Satellite_Axes_editingFinished()
{
    this->finish_flag = 0;
}

void Setting_CCSDS::on_line_Satellite_parentpath_editingFinished()
{
    this->finish_flag = 0;
}

void Setting_CCSDS::on_comboBox_frameA_currentTextChanged(const QString &arg1)
{
    this->finish_flag = 0;
    if(   (arg1 != "ICRF") && (arg1 != "EME2000") && (arg1!= "SC_BODY_1")
       && (arg1 != "SC_BODY_2") && (arg1 != "SC_BODY_3")    )
        ui->comboBox_frameA->setCurrentText("EME2000");
}

void Setting_CCSDS::on_comboBox_frameB_currentTextChanged(const QString &arg1)
{
    this->finish_flag = 0;
    if(   (arg1 != "ICRF") && (arg1 != "EME2000") && (arg1!= "SC_BODY_1")
       && (arg1 != "SC_BODY_2") && (arg1 != "SC_BODY_3")    )
        ui->comboBox_frameB->setCurrentText("EME2000");
}

void Setting_CCSDS::on_comboBox_dir_currentTextChanged(const QString &arg1)
{
    this->finish_flag = 0;
    if(   (arg1 != "A2B") && (arg1 != "B2A") )
        ui->comboBox_dir->setCurrentText("A2B");
}

void Setting_CCSDS::on_comboBox_type_currentTextChanged(const QString &arg1)
{
    this->finish_flag = 0;
    if( arg1 != "QUATERNION")
        ui->comboBox_type->setCurrentText("QUATERNION");
}

void Setting_CCSDS::on_comboBox_time_currentTextChanged(const QString &arg1)
{
    this->finish_flag = 0;
    if(   (arg1 != "UTC") && (arg1 != "TT") && (arg1 != "TAI")
       && (arg1 != "TDB") && (arg1 != "TCB")    )
        ui->comboBox_time->setCurrentText("UTC");
}
