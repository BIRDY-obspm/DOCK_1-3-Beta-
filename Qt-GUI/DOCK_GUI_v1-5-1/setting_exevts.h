#ifndef SETTING_EXEVTS_H
#define SETTING_EXEVTS_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include "setting_dialog_struct.h"

namespace Ui {
class Setting_ExeVTS;
}

class Setting_ExeVTS : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_ExeVTS(QWidget *parent = 0);
    ~Setting_ExeVTS();

private:
    Ui::Setting_ExeVTS *ui;
    QString software_location;
    QString default_software_location;
    bool first_launch_flag = 0;

public slots:
    void Import_default(VTS_Soft &vts_soft, bool reset = 0);
    void Export_result(VTS_Soft &vts_soft);

private slots:
    void on_PB_soft_location_clicked();
    void on_PB_OK_clicked();
    void on_PB_Cancel_clicked();
    bool on_line_soft_location_editingFinished();
};

#endif // SETTING_EXEVTS_H
