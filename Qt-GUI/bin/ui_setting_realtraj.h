/********************************************************************************
** Form generated from reading UI file 'setting_realtraj.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_REALTRAJ_H
#define UI_SETTING_REALTRAJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting_RealTraj
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *line_traj_config;
    QPushButton *PB_traj_config;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *line_host_traj;
    QPushButton *PB_host_traj;
    QFormLayout *formLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *line_output;
    QPushButton *PB_output;
    QHBoxLayout *horizontalLayout;
    QPushButton *PB_OK;
    QPushButton *PB_Cancel;

    void setupUi(QDialog *Setting_RealTraj)
    {
        if (Setting_RealTraj->objectName().isEmpty())
            Setting_RealTraj->setObjectName(QStringLiteral("Setting_RealTraj"));
        Setting_RealTraj->resize(270, 235);
        layoutWidget = new QWidget(Setting_RealTraj);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 251, 213));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        line_traj_config = new QLineEdit(layoutWidget);
        line_traj_config->setObjectName(QStringLiteral("line_traj_config"));

        horizontalLayout_2->addWidget(line_traj_config);

        PB_traj_config = new QPushButton(layoutWidget);
        PB_traj_config->setObjectName(QStringLiteral("PB_traj_config"));

        horizontalLayout_2->addWidget(PB_traj_config);


        formLayout_3->setLayout(1, QFormLayout::LabelRole, horizontalLayout_2);


        verticalLayout->addLayout(formLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        line_host_traj = new QLineEdit(layoutWidget);
        line_host_traj->setObjectName(QStringLiteral("line_host_traj"));

        horizontalLayout_3->addWidget(line_host_traj);

        PB_host_traj = new QPushButton(layoutWidget);
        PB_host_traj->setObjectName(QStringLiteral("PB_host_traj"));

        horizontalLayout_3->addWidget(PB_host_traj);


        formLayout_2->setLayout(1, QFormLayout::LabelRole, horizontalLayout_3);


        verticalLayout->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        line_output = new QLineEdit(layoutWidget);
        line_output->setObjectName(QStringLiteral("line_output"));

        horizontalLayout_4->addWidget(line_output);

        PB_output = new QPushButton(layoutWidget);
        PB_output->setObjectName(QStringLiteral("PB_output"));

        horizontalLayout_4->addWidget(PB_output);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_4);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PB_OK = new QPushButton(layoutWidget);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        horizontalLayout->addWidget(PB_OK);

        PB_Cancel = new QPushButton(layoutWidget);
        PB_Cancel->setObjectName(QStringLiteral("PB_Cancel"));

        horizontalLayout->addWidget(PB_Cancel);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Setting_RealTraj);

        QMetaObject::connectSlotsByName(Setting_RealTraj);
    } // setupUi

    void retranslateUi(QDialog *Setting_RealTraj)
    {
        Setting_RealTraj->setWindowTitle(QApplication::translate("Setting_RealTraj", "Dialog", 0));
        label->setText(QApplication::translate("Setting_RealTraj", "Trajectory config file:", 0));
        PB_traj_config->setText(QApplication::translate("Setting_RealTraj", "change", 0));
        label_2->setText(QApplication::translate("Setting_RealTraj", "Host trajectory file:", 0));
        PB_host_traj->setText(QApplication::translate("Setting_RealTraj", "change", 0));
        label_3->setText(QApplication::translate("Setting_RealTraj", "Output location:", 0));
        PB_output->setText(QApplication::translate("Setting_RealTraj", "change", 0));
        PB_OK->setText(QApplication::translate("Setting_RealTraj", "OK", 0));
        PB_Cancel->setText(QApplication::translate("Setting_RealTraj", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_RealTraj: public Ui_Setting_RealTraj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_REALTRAJ_H
