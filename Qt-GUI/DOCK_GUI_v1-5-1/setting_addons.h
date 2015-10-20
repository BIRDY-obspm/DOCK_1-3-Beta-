#ifndef SETTING_ADDONS_H
#define SETTING_ADDONS_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include "setting_dialog_struct.h"

namespace Ui {
class Setting_AddOns;
}

class Setting_AddOns : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_AddOns(QWidget *parent = 0);
    ~Setting_AddOns();

private:
    Ui::Setting_AddOns *ui;
    QString output_location;
    QString default_output_location;
    bool first_launch_flag = 0;

public slots:
    void Import_default(st_AddOns &st_addons, bool reset = 0);
    void Export_result(st_AddOns &st_addons);

private slots:
    void on_PB_output_location_clicked();
    void on_PB_OK_clicked();
    void on_PB_Cancel_clicked();
    void on_line_output_location_editingFinished();
};

#endif // SETTING_ADDONS_H
