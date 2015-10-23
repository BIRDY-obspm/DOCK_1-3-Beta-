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

#ifndef SETTING_PRODVTS_H
#define SETTING_PRODVTS_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include "setting_dialog_struct.h"

namespace Ui {
class Setting_ProdVTS;
}

class Setting_ProdVTS : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_ProdVTS(QWidget *parent = 0);
    ~Setting_ProdVTS();

private:
    Ui::Setting_ProdVTS *ui;
    QString output_location;
    QString default_output_location;
    bool first_launch_flag = 0;
    bool VTS_keep_app_setting;

public slots:
    void Import_default(VTS_Soft &vts_soft, bool reset = 0);
    void Export_result(VTS_Soft &vts_soft);

private slots:
    void on_PB_output_location_clicked();
    void on_PB_OK_clicked();
    void on_PB_Cancel_clicked();
    void on_line_output_location_editingFinished();
};

#endif // SETTING_PRODVTS_H
