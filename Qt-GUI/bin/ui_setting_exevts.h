/********************************************************************************
** Form generated from reading UI file 'setting_exevts.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_EXEVTS_H
#define UI_SETTING_EXEVTS_H

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

class Ui_Setting_ExeVTS
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_soft_location;
    QPushButton *PB_soft_location;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_OK;
    QPushButton *PB_Cancel;

    void setupUi(QDialog *Setting_ExeVTS)
    {
        if (Setting_ExeVTS->objectName().isEmpty())
            Setting_ExeVTS->setObjectName(QStringLiteral("Setting_ExeVTS"));
        Setting_ExeVTS->resize(301, 101);
        gridLayout = new QGridLayout(Setting_ExeVTS);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Setting_ExeVTS);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        line_soft_location = new QLineEdit(Setting_ExeVTS);
        line_soft_location->setObjectName(QStringLiteral("line_soft_location"));

        gridLayout->addWidget(line_soft_location, 1, 0, 1, 2);

        PB_soft_location = new QPushButton(Setting_ExeVTS);
        PB_soft_location->setObjectName(QStringLiteral("PB_soft_location"));

        gridLayout->addWidget(PB_soft_location, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        PB_OK = new QPushButton(Setting_ExeVTS);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        gridLayout->addWidget(PB_OK, 2, 1, 1, 1);

        PB_Cancel = new QPushButton(Setting_ExeVTS);
        PB_Cancel->setObjectName(QStringLiteral("PB_Cancel"));

        gridLayout->addWidget(PB_Cancel, 2, 2, 1, 1);

        QWidget::setTabOrder(PB_soft_location, line_soft_location);
        QWidget::setTabOrder(line_soft_location, PB_OK);
        QWidget::setTabOrder(PB_OK, PB_Cancel);

        retranslateUi(Setting_ExeVTS);

        QMetaObject::connectSlotsByName(Setting_ExeVTS);
    } // setupUi

    void retranslateUi(QDialog *Setting_ExeVTS)
    {
        Setting_ExeVTS->setWindowTitle(QApplication::translate("Setting_ExeVTS", "Dialog", 0));
        label->setText(QApplication::translate("Setting_ExeVTS", "VTS Software location:", 0));
        PB_soft_location->setText(QApplication::translate("Setting_ExeVTS", "Change", 0));
        PB_OK->setText(QApplication::translate("Setting_ExeVTS", "OK", 0));
        PB_Cancel->setText(QApplication::translate("Setting_ExeVTS", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_ExeVTS: public Ui_Setting_ExeVTS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_EXEVTS_H
