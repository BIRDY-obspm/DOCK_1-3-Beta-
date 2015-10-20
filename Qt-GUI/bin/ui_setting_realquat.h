/********************************************************************************
** Form generated from reading UI file 'setting_realquat.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_REALQUAT_H
#define UI_SETTING_REALQUAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Setting_RealQuat
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *line_para_file;
    QPushButton *PB_para_file;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *line_seq_file;
    QPushButton *PB_seq_file;
    QFormLayout *formLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *line_output;
    QPushButton *PB_output;
    QHBoxLayout *horizontalLayout;
    QPushButton *PB_OK;
    QPushButton *PB_Cancel;

    void setupUi(QDialog *Setting_RealQuat)
    {
        if (Setting_RealQuat->objectName().isEmpty())
            Setting_RealQuat->setObjectName(QStringLiteral("Setting_RealQuat"));
        Setting_RealQuat->resize(265, 259);
        gridLayout = new QGridLayout(Setting_RealQuat);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(Setting_RealQuat);
        label->setObjectName(QStringLiteral("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        line_para_file = new QLineEdit(Setting_RealQuat);
        line_para_file->setObjectName(QStringLiteral("line_para_file"));

        horizontalLayout_2->addWidget(line_para_file);

        PB_para_file = new QPushButton(Setting_RealQuat);
        PB_para_file->setObjectName(QStringLiteral("PB_para_file"));

        horizontalLayout_2->addWidget(PB_para_file);


        formLayout_3->setLayout(1, QFormLayout::LabelRole, horizontalLayout_2);


        verticalLayout->addLayout(formLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(Setting_RealQuat);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        line_seq_file = new QLineEdit(Setting_RealQuat);
        line_seq_file->setObjectName(QStringLiteral("line_seq_file"));

        horizontalLayout_3->addWidget(line_seq_file);

        PB_seq_file = new QPushButton(Setting_RealQuat);
        PB_seq_file->setObjectName(QStringLiteral("PB_seq_file"));

        horizontalLayout_3->addWidget(PB_seq_file);


        formLayout_2->setLayout(1, QFormLayout::LabelRole, horizontalLayout_3);


        verticalLayout->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(Setting_RealQuat);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        line_output = new QLineEdit(Setting_RealQuat);
        line_output->setObjectName(QStringLiteral("line_output"));

        horizontalLayout_4->addWidget(line_output);

        PB_output = new QPushButton(Setting_RealQuat);
        PB_output->setObjectName(QStringLiteral("PB_output"));

        horizontalLayout_4->addWidget(PB_output);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_4);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PB_OK = new QPushButton(Setting_RealQuat);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        horizontalLayout->addWidget(PB_OK);

        PB_Cancel = new QPushButton(Setting_RealQuat);
        PB_Cancel->setObjectName(QStringLiteral("PB_Cancel"));

        horizontalLayout->addWidget(PB_Cancel);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Setting_RealQuat);

        QMetaObject::connectSlotsByName(Setting_RealQuat);
    } // setupUi

    void retranslateUi(QDialog *Setting_RealQuat)
    {
        Setting_RealQuat->setWindowTitle(QApplication::translate("Setting_RealQuat", "Dialog", 0));
        label->setText(QApplication::translate("Setting_RealQuat", "AOCS parameters file:", 0));
        PB_para_file->setText(QApplication::translate("Setting_RealQuat", "change", 0));
        label_2->setText(QApplication::translate("Setting_RealQuat", "Sequence inputs file:", 0));
        PB_seq_file->setText(QApplication::translate("Setting_RealQuat", "change", 0));
        label_3->setText(QApplication::translate("Setting_RealQuat", "Output location:", 0));
        PB_output->setText(QApplication::translate("Setting_RealQuat", "change", 0));
        PB_OK->setText(QApplication::translate("Setting_RealQuat", "OK", 0));
        PB_Cancel->setText(QApplication::translate("Setting_RealQuat", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_RealQuat: public Ui_Setting_RealQuat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_REALQUAT_H
