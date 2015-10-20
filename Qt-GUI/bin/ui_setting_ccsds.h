/********************************************************************************
** Form generated from reading UI file 'setting_ccsds.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_CCSDS_H
#define UI_SETTING_CCSDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Setting_CCSDS
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *line_Satellite_3ds;
    QPushButton *PB_Satellite_3ds;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *line_Satellite_quaternion;
    QPushButton *PB_Satellite_quaternion;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *line_Satellite_position;
    QPushButton *PB_Satellite_position;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *line_Satellite_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *line_Satellite_Axes;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *line_Satellite_parentpath;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *comboBox_frameA;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *comboBox_frameB;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QComboBox *comboBox_dir;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QComboBox *comboBox_type;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QComboBox *comboBox_time;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *PB_OK;
    QPushButton *PB_Cancel;
    QPushButton *PB_Clear_all;

    void setupUi(QDialog *Setting_CCSDS)
    {
        if (Setting_CCSDS->objectName().isEmpty())
            Setting_CCSDS->setObjectName(QStringLiteral("Setting_CCSDS"));
        Setting_CCSDS->resize(325, 507);
        gridLayout = new QGridLayout(Setting_CCSDS);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(Setting_CCSDS);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        line_Satellite_3ds = new QLineEdit(Setting_CCSDS);
        line_Satellite_3ds->setObjectName(QStringLiteral("line_Satellite_3ds"));

        horizontalLayout->addWidget(line_Satellite_3ds);

        PB_Satellite_3ds = new QPushButton(Setting_CCSDS);
        PB_Satellite_3ds->setObjectName(QStringLiteral("PB_Satellite_3ds"));

        horizontalLayout->addWidget(PB_Satellite_3ds);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(Setting_CCSDS);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        line_Satellite_quaternion = new QLineEdit(Setting_CCSDS);
        line_Satellite_quaternion->setObjectName(QStringLiteral("line_Satellite_quaternion"));

        horizontalLayout_4->addWidget(line_Satellite_quaternion);

        PB_Satellite_quaternion = new QPushButton(Setting_CCSDS);
        PB_Satellite_quaternion->setObjectName(QStringLiteral("PB_Satellite_quaternion"));

        horizontalLayout_4->addWidget(PB_Satellite_quaternion);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(Setting_CCSDS);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        line_Satellite_position = new QLineEdit(Setting_CCSDS);
        line_Satellite_position->setObjectName(QStringLiteral("line_Satellite_position"));

        horizontalLayout_5->addWidget(line_Satellite_position);

        PB_Satellite_position = new QPushButton(Setting_CCSDS);
        PB_Satellite_position->setObjectName(QStringLiteral("PB_Satellite_position"));

        horizontalLayout_5->addWidget(PB_Satellite_position);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(Setting_CCSDS);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        line_Satellite_name = new QLineEdit(Setting_CCSDS);
        line_Satellite_name->setObjectName(QStringLiteral("line_Satellite_name"));

        horizontalLayout_3->addWidget(line_Satellite_name);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Setting_CCSDS);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        line_Satellite_Axes = new QLineEdit(Setting_CCSDS);
        line_Satellite_Axes->setObjectName(QStringLiteral("line_Satellite_Axes"));

        horizontalLayout_2->addWidget(line_Satellite_Axes);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(Setting_CCSDS);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        line_Satellite_parentpath = new QLineEdit(Setting_CCSDS);
        line_Satellite_parentpath->setObjectName(QStringLiteral("line_Satellite_parentpath"));

        horizontalLayout_6->addWidget(line_Satellite_parentpath);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(Setting_CCSDS);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        comboBox_frameA = new QComboBox(Setting_CCSDS);
        comboBox_frameA->setObjectName(QStringLiteral("comboBox_frameA"));

        horizontalLayout_7->addWidget(comboBox_frameA);


        gridLayout->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(Setting_CCSDS);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        comboBox_frameB = new QComboBox(Setting_CCSDS);
        comboBox_frameB->setObjectName(QStringLiteral("comboBox_frameB"));

        horizontalLayout_8->addWidget(comboBox_frameB);


        gridLayout->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(Setting_CCSDS);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        comboBox_dir = new QComboBox(Setting_CCSDS);
        comboBox_dir->setObjectName(QStringLiteral("comboBox_dir"));

        horizontalLayout_9->addWidget(comboBox_dir);


        gridLayout->addLayout(horizontalLayout_9, 8, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(Setting_CCSDS);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_10->addWidget(label_10);

        comboBox_type = new QComboBox(Setting_CCSDS);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        horizontalLayout_10->addWidget(comboBox_type);


        gridLayout->addLayout(horizontalLayout_10, 9, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(Setting_CCSDS);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_11->addWidget(label_11);

        comboBox_time = new QComboBox(Setting_CCSDS);
        comboBox_time->setObjectName(QStringLiteral("comboBox_time"));

        horizontalLayout_11->addWidget(comboBox_time);


        gridLayout->addLayout(horizontalLayout_11, 10, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        PB_OK = new QPushButton(Setting_CCSDS);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        horizontalLayout_12->addWidget(PB_OK);

        PB_Cancel = new QPushButton(Setting_CCSDS);
        PB_Cancel->setObjectName(QStringLiteral("PB_Cancel"));

        horizontalLayout_12->addWidget(PB_Cancel);

        PB_Clear_all = new QPushButton(Setting_CCSDS);
        PB_Clear_all->setObjectName(QStringLiteral("PB_Clear_all"));

        horizontalLayout_12->addWidget(PB_Clear_all);


        gridLayout->addLayout(horizontalLayout_12, 11, 0, 1, 1);

        label->raise();
        line_Satellite_name->raise();
        line_Satellite_Axes->raise();
        label_2->raise();
        label_3->raise();
        line_Satellite_3ds->raise();
        PB_Satellite_3ds->raise();
        label->raise();
        label_7->raise();
        label_8->raise();
        comboBox_frameA->raise();
        comboBox_frameB->raise();
        PB_OK->raise();
        PB_Cancel->raise();
        PB_Clear_all->raise();

        retranslateUi(Setting_CCSDS);

        QMetaObject::connectSlotsByName(Setting_CCSDS);
    } // setupUi

    void retranslateUi(QDialog *Setting_CCSDS)
    {
        Setting_CCSDS->setWindowTitle(QApplication::translate("Setting_CCSDS", "Dialog", 0));
        label_3->setText(QApplication::translate("Setting_CCSDS", "Satellite 3ds file:", 0));
        PB_Satellite_3ds->setText(QApplication::translate("Setting_CCSDS", "Change", 0));
        label_4->setText(QApplication::translate("Setting_CCSDS", "Satellite quaternion file:", 0));
        PB_Satellite_quaternion->setText(QApplication::translate("Setting_CCSDS", "Change", 0));
        label_5->setText(QApplication::translate("Setting_CCSDS", "Satellite position file:", 0));
        PB_Satellite_position->setText(QApplication::translate("Setting_CCSDS", "Change", 0));
        label->setText(QApplication::translate("Setting_CCSDS", "Satellite name:", 0));
        label_2->setText(QApplication::translate("Setting_CCSDS", "Satellite axes:", 0));
        label_6->setText(QApplication::translate("Setting_CCSDS", "Satellite parentpath:", 0));
        label_7->setText(QApplication::translate("Setting_CCSDS", "Satellite ref_frame_A:", 0));
        label_8->setText(QApplication::translate("Setting_CCSDS", "Satellite ref_frame_B:", 0));
        label_9->setText(QApplication::translate("Setting_CCSDS", "Satellite attitude_dir:", 0));
        label_10->setText(QApplication::translate("Setting_CCSDS", "Satellite att_type:", 0));
        label_11->setText(QApplication::translate("Setting_CCSDS", "Satellite time_system:", 0));
        PB_OK->setText(QApplication::translate("Setting_CCSDS", "OK", 0));
        PB_Cancel->setText(QApplication::translate("Setting_CCSDS", "Cancel", 0));
        PB_Clear_all->setText(QApplication::translate("Setting_CCSDS", "Clear all", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_CCSDS: public Ui_Setting_CCSDS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_CCSDS_H
