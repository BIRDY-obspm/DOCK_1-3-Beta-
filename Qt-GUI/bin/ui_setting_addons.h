/********************************************************************************
** Form generated from reading UI file 'setting_addons.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_ADDONS_H
#define UI_SETTING_ADDONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Setting_AddOns
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_output_location;
    QPushButton *PB_output_location;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_OK;
    QPushButton *PB_Cancel;

    void setupUi(QDialog *Setting_AddOns)
    {
        if (Setting_AddOns->objectName().isEmpty())
            Setting_AddOns->setObjectName(QStringLiteral("Setting_AddOns"));
        Setting_AddOns->resize(372, 101);
        gridLayout = new QGridLayout(Setting_AddOns);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Setting_AddOns);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        line_output_location = new QLineEdit(Setting_AddOns);
        line_output_location->setObjectName(QStringLiteral("line_output_location"));

        gridLayout->addWidget(line_output_location, 1, 0, 1, 2);

        PB_output_location = new QPushButton(Setting_AddOns);
        PB_output_location->setObjectName(QStringLiteral("PB_output_location"));

        gridLayout->addWidget(PB_output_location, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(169, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        PB_OK = new QPushButton(Setting_AddOns);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        gridLayout->addWidget(PB_OK, 2, 1, 1, 1);

        PB_Cancel = new QPushButton(Setting_AddOns);
        PB_Cancel->setObjectName(QStringLiteral("PB_Cancel"));

        gridLayout->addWidget(PB_Cancel, 2, 2, 1, 1);

        QWidget::setTabOrder(PB_output_location, line_output_location);
        QWidget::setTabOrder(line_output_location, PB_OK);
        QWidget::setTabOrder(PB_OK, PB_Cancel);

        retranslateUi(Setting_AddOns);

        QMetaObject::connectSlotsByName(Setting_AddOns);
    } // setupUi

    void retranslateUi(QDialog *Setting_AddOns)
    {
        Setting_AddOns->setWindowTitle(QApplication::translate("Setting_AddOns", "Dialog", 0));
        label->setText(QApplication::translate("Setting_AddOns", "Celestia Add-ons extract output folder:", 0));
        PB_output_location->setText(QApplication::translate("Setting_AddOns", "Change", 0));
        PB_OK->setText(QApplication::translate("Setting_AddOns", "OK", 0));
        PB_Cancel->setText(QApplication::translate("Setting_AddOns", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_AddOns: public Ui_Setting_AddOns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_ADDONS_H
