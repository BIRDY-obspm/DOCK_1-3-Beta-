#include "setting_exevts.h"
#include "ui_setting_exevts.h"

Setting_ExeVTS::Setting_ExeVTS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_ExeVTS)
{
    ui->setupUi(this);
}

Setting_ExeVTS::~Setting_ExeVTS()
{
    delete ui;
}

void Setting_ExeVTS::Import_default(VTS_Soft &vts_soft, bool reset)
{
    if(reset == 1)
    {
        this->first_launch_flag = 0;
    }

    if(this->first_launch_flag == 0)
    {
        this->software_location = vts_soft.software_location;
        this->default_software_location = vts_soft.default_software_location;

        ui->line_soft_location->setText(this->default_software_location);

        this->first_launch_flag = 1;
    }
}

void Setting_ExeVTS::Export_result(VTS_Soft &vts_soft)
{
    vts_soft.software_location = this->software_location;
}

void Setting_ExeVTS::on_PB_soft_location_clicked()
{
    QString _software_dir = QFileDialog::getExistingDirectory(
                this,
                tr("Select VTS soft location"),
                this->software_location,
                QFileDialog::ShowDirsOnly
                );
    if (!_software_dir.isEmpty())
    {
        QFileInfo _file(_software_dir + "/startVTS");
        if(!_file.exists())
        {
            QMessageBox::critical(0, "error", "VTS exe file not found !!");
            ui->line_soft_location->setText("");
        }
        else
        {
            ui->line_soft_location->setText(_software_dir);
            this->software_location = _software_dir;
        }

    }
}

void Setting_ExeVTS::on_PB_OK_clicked()
{
    if(  ui->line_soft_location->text().isEmpty() )
    {
        QMessageBox::critical(0, "error", "Please check again the software location of VTS !!");
        return ;
    }
    else
    {
        if(on_line_soft_location_editingFinished())
        {
            this->software_location = ui->line_soft_location->text();
            QDialog::accept();
        }
        else
            return;
    }
}

void Setting_ExeVTS::on_PB_Cancel_clicked()
{
    ui->line_soft_location->setText(this->software_location);
    QDialog::reject();
}

bool Setting_ExeVTS::on_line_soft_location_editingFinished()
{
    QString line_return = ui->line_soft_location->text();
    if (!line_return.isEmpty())
    {
        QFileInfo _file(line_return + "/startVTS");
        if(!_file.exists())
        {
            ui->line_soft_location->blockSignals(true);
            QMessageBox::critical(0, "error", "VTS exe file not found");
            ui->line_soft_location->blockSignals(false);
            ui->line_soft_location->setText("");
            return false;
        }
        else
        {
            QDir _dir(line_return);
            ui->line_soft_location->setText(_dir.absolutePath());
            return true;
        }
    }
    else
        return false;
}
