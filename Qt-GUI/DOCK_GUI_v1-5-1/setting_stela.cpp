#include "setting_stela.h"
#include "ui_setting_stela.h"

Setting_STELA::Setting_STELA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_STELA)
{
    ui->setupUi(this);
}

Setting_STELA::~Setting_STELA()
{
    delete ui;
}

void Setting_STELA::Import_default(st_STELA &st_stela, bool reset)
{
    if(reset == 1)
    {
        this->first_launch_flag = 0;
    }

    if(this->first_launch_flag == 0)
    {
        this->software_location = st_stela.software_location;
        this->default_software_location = st_stela.default_software_location;

        ui->line_soft_location->setText(this->default_software_location);

        this->first_launch_flag = 1;
    }
}

void Setting_STELA::Export_result(st_STELA &st_stela)
{
    st_stela.software_location = this->software_location;
}

void Setting_STELA::on_PB_soft_location_clicked()
{
    QString _software_dir = QFileDialog::getExistingDirectory(
                this,
                tr("Select STELA soft location"),
                this->software_location,
                QFileDialog::ShowDirsOnly
                );
    if (!_software_dir.isEmpty())
    {
        QFileInfo _file(_software_dir + "/bin/stela.sh");
        if(!_file.exists())
        {
            QMessageBox::critical(0, "error", "STELA exe file not found !!");
            ui->line_soft_location->setText("");
        }
        else
        {
            ui->line_soft_location->setText(_software_dir);
            this->software_location = _software_dir;
        }

    }
}

void Setting_STELA::on_PB_OK_clicked()
{
    if(  ui->line_soft_location->text().isEmpty() )
    {
        QMessageBox::critical(0, "error", "Please check again the software location of STELA !!");
        return ;
    }
    else
    {
        if( on_line_soft_location_editingFinished() )
        {
            this->software_location = ui->line_soft_location->text();
            QDialog::accept();
        }
        else
            return;
    }
}

void Setting_STELA::on_PB_Cancel_clicked()
{
    ui->line_soft_location->setText(this->software_location);
    QDialog::reject();
}

bool Setting_STELA::on_line_soft_location_editingFinished()
{
    QString line_return = ui->line_soft_location->text();
    if (!line_return.isEmpty())
    {
        QFileInfo _file(line_return + "/bin/stela.sh");
        if(!_file.exists())
        {
            ui->line_soft_location->blockSignals(true);
            QMessageBox::critical(0, "error", "STELA exe file not found");
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
}
