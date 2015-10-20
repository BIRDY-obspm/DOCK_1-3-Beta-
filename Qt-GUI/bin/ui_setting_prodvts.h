/********************************************************************************
** Form generated from reading UI file 'setting_prodvts.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_PRODVTS_H
#define UI_SETTING_PRODVTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Setting_ProdVTS
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_output_location;
    QPushButton *PB_output_location;
    QCheckBox *CB_keep_apps;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_OK;
    QPushButton *PB_Cancel;

    void setupUi(QDialog *Setting_ProdVTS)
    {
        if (Setting_ProdVTS->objectName().isEmpty())
            Setting_ProdVTS->setObjectName(QStringLiteral("Setting_ProdVTS"));
        Setting_ProdVTS->resize(264, 129);
        gridLayout = new QGridLayout(Setting_ProdVTS);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Setting_ProdVTS);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        line_output_location = new QLineEdit(Setting_ProdVTS);
        line_output_location->setObjectName(QStringLiteral("line_output_location"));

        gridLayout->addWidget(line_output_location, 1, 0, 1, 2);

        PB_output_location = new QPushButton(Setting_ProdVTS);
        PB_output_location->setObjectName(QStringLiteral("PB_output_location"));

        gridLayout->addWidget(PB_output_location, 1, 2, 1, 1);

        CB_keep_apps = new QCheckBox(Setting_ProdVTS);
        CB_keep_apps->setObjectName(QStringLiteral("CB_keep_apps"));

        gridLayout->addWidget(CB_keep_apps, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        PB_OK = new QPushButton(Setting_ProdVTS);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        gridLayout->addWidget(PB_OK, 3, 1, 1, 1);

        PB_Cancel = new QPushButton(Setting_ProdVTS);
        PB_Cancel->setObjectName(QStringLiteral("PB_Cancel"));

        gridLayout->addWidget(PB_Cancel, 3, 2, 1, 1);

        QWidget::setTabOrder(PB_output_location, line_output_location);
        QWidget::setTabOrder(line_output_location, CB_keep_apps);
        QWidget::setTabOrder(CB_keep_apps, PB_OK);
        QWidget::setTabOrder(PB_OK, PB_Cancel);

        retranslateUi(Setting_ProdVTS);

        QMetaObject::connectSlotsByName(Setting_ProdVTS);
    } // setupUi

    void retranslateUi(QDialog *Setting_ProdVTS)
    {
        Setting_ProdVTS->setWindowTitle(QApplication::translate("Setting_ProdVTS", "Dialog", 0));
        label->setText(QApplication::translate("Setting_ProdVTS", "VTS project file output location:", 0));
        PB_output_location->setText(QApplication::translate("Setting_ProdVTS", "Change", 0));
        CB_keep_apps->setText(QApplication::translate("Setting_ProdVTS", "Keep Apps setting", 0));
        PB_OK->setText(QApplication::translate("Setting_ProdVTS", "OK", 0));
        PB_Cancel->setText(QApplication::translate("Setting_ProdVTS", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_ProdVTS: public Ui_Setting_ProdVTS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_PRODVTS_H
