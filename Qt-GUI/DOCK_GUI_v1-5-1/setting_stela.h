#ifndef SETTING_STELA_H
#define SETTING_STELA_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include "setting_dialog_struct.h"

namespace Ui {
class Setting_STELA;
}

class Setting_STELA : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_STELA(QWidget *parent = 0);
    ~Setting_STELA();

private:
    Ui::Setting_STELA *ui;
    QString software_location;
    QString default_software_location;
    bool first_launch_flag = 0;

public slots:
    void Import_default(st_STELA &st_stela, bool reset = 0);
    void Export_result(st_STELA &st_stela);

private slots:
    void on_PB_soft_location_clicked();
    void on_PB_OK_clicked();
    void on_PB_Cancel_clicked();
    bool on_line_soft_location_editingFinished();
};

#endif // SETTING_STELA_H
