/********************************************************************************
** Form generated from reading UI file 'setting_stela.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_STELA_H
#define UI_SETTING_STELA_H

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

class Ui_Setting_STELA
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_soft_location;
    QPushButton *PB_soft_location;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_OK;
    QPushButton *PB_Cancel;

    void setupUi(QDialog *Setting_STELA)
    {
        if (Setting_STELA->objectName().isEmpty())
            Setting_STELA->setObjectName(QStringLiteral("Setting_STELA"));
        Setting_STELA->resize(317, 101);
        gridLayout = new QGridLayout(Setting_STELA);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Setting_STELA);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        line_soft_location = new QLineEdit(Setting_STELA);
        line_soft_location->setObjectName(QStringLiteral("line_soft_location"));

        gridLayout->addWidget(line_soft_location, 1, 0, 1, 2);

        PB_soft_location = new QPushButton(Setting_STELA);
        PB_soft_location->setObjectName(QStringLiteral("PB_soft_location"));

        gridLayout->addWidget(PB_soft_location, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        PB_OK = new QPushButton(Setting_STELA);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        gridLayout->addWidget(PB_OK, 2, 1, 1, 1);

        PB_Cancel = new QPushButton(Setting_STELA);
        PB_Cancel->setObjectName(QStringLiteral("PB_Cancel"));

        gridLayout->addWidget(PB_Cancel, 2, 2, 1, 1);

        QWidget::setTabOrder(PB_soft_location, line_soft_location);
        QWidget::setTabOrder(line_soft_location, PB_OK);
        QWidget::setTabOrder(PB_OK, PB_Cancel);

        retranslateUi(Setting_STELA);

        QMetaObject::connectSlotsByName(Setting_STELA);
    } // setupUi

    void retranslateUi(QDialog *Setting_STELA)
    {
        Setting_STELA->setWindowTitle(QApplication::translate("Setting_STELA", "Dialog", 0));
        label->setText(QApplication::translate("Setting_STELA", "STELA Software location:", 0));
        PB_soft_location->setText(QApplication::translate("Setting_STELA", "Change", 0));
        PB_OK->setText(QApplication::translate("Setting_STELA", "OK", 0));
        PB_Cancel->setText(QApplication::translate("Setting_STELA", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_STELA: public Ui_Setting_STELA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_STELA_H
