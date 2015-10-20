/********************************************************************************
** Form generated from reading UI file 'setting_easytraj.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_EASYTRAJ_H
#define UI_SETTING_EASYTRAJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Setting_EasyTraj
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_3;
    QLabel *label_starttime;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *PB_load_fr_Sce;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_MJDdate_st;
    QSpinBox *SB_start_MJDdate;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_MJDsec_st;
    QDoubleSpinBox *SB_start_MJDsec;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Endtime;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_MJDdate_end;
    QSpinBox *SB_end_MJDdate;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_MJDsec_end;
    QDoubleSpinBox *SB_end_MJDsec;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_Stepsize;
    QDoubleSpinBox *SB_stepsize;
    QLabel *label_sec;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_sec_8;
    QDoubleSpinBox *SB_inc;
    QLabel *label_sec_9;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_sec_14;
    QDoubleSpinBox *SB_anm;
    QLabel *label_sec_15;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_sec_10;
    QDoubleSpinBox *SB_pom;
    QLabel *label_sec_11;
    QLabel *label_Stepsize_2;
    QComboBox *comboBox_type;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_sec_6;
    QDoubleSpinBox *SB_ecc;
    QLabel *label_sec_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_sec_2;
    QDoubleSpinBox *SB_sma;
    QLabel *label_sec_5;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_sec_12;
    QDoubleSpinBox *SB_gom;
    QLabel *label_sec_13;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *line_output_location;
    QPushButton *PB_output_location;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *PB_OK;
    QPushButton *PB_cancel;
    QPushButton *PB_clearall;

    void setupUi(QDialog *Setting_EasyTraj)
    {
        if (Setting_EasyTraj->objectName().isEmpty())
            Setting_EasyTraj->setObjectName(QStringLiteral("Setting_EasyTraj"));
        Setting_EasyTraj->resize(346, 567);
        gridLayout_2 = new QGridLayout(Setting_EasyTraj);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_12 = new QGroupBox(Setting_EasyTraj);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(9);
        groupBox_12->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_12);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_starttime = new QLabel(groupBox_12);
        label_starttime->setObjectName(QStringLiteral("label_starttime"));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(true);
        font1.setUnderline(true);
        font1.setWeight(50);
        label_starttime->setFont(font1);

        gridLayout_3->addWidget(label_starttime, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        PB_load_fr_Sce = new QPushButton(groupBox_12);
        PB_load_fr_Sce->setObjectName(QStringLiteral("PB_load_fr_Sce"));
        QFont font2;
        font2.setPointSize(8);
        PB_load_fr_Sce->setFont(font2);

        gridLayout_3->addWidget(PB_load_fr_Sce, 0, 2, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_MJDdate_st = new QLabel(groupBox_12);
        label_MJDdate_st->setObjectName(QStringLiteral("label_MJDdate_st"));

        horizontalLayout_7->addWidget(label_MJDdate_st);

        SB_start_MJDdate = new QSpinBox(groupBox_12);
        SB_start_MJDdate->setObjectName(QStringLiteral("SB_start_MJDdate"));
        SB_start_MJDdate->setMaximum(999999);

        horizontalLayout_7->addWidget(SB_start_MJDdate);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label_MJDsec_st = new QLabel(groupBox_12);
        label_MJDsec_st->setObjectName(QStringLiteral("label_MJDsec_st"));

        horizontalLayout_7->addWidget(label_MJDsec_st);

        SB_start_MJDsec = new QDoubleSpinBox(groupBox_12);
        SB_start_MJDsec->setObjectName(QStringLiteral("SB_start_MJDsec"));
        SB_start_MJDsec->setDecimals(3);
        SB_start_MJDsec->setMaximum(86400);
        SB_start_MJDsec->setSingleStep(0.1);

        horizontalLayout_7->addWidget(SB_start_MJDsec);


        horizontalLayout_14->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        horizontalLayout_14->addLayout(horizontalLayout_6);


        gridLayout_3->addLayout(horizontalLayout_14, 1, 0, 1, 3);

        label_Endtime = new QLabel(groupBox_12);
        label_Endtime->setObjectName(QStringLiteral("label_Endtime"));
        QFont font3;
        font3.setItalic(true);
        font3.setUnderline(true);
        label_Endtime->setFont(font3);

        gridLayout_3->addWidget(label_Endtime, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_MJDdate_end = new QLabel(groupBox_12);
        label_MJDdate_end->setObjectName(QStringLiteral("label_MJDdate_end"));

        horizontalLayout_11->addWidget(label_MJDdate_end);

        SB_end_MJDdate = new QSpinBox(groupBox_12);
        SB_end_MJDdate->setObjectName(QStringLiteral("SB_end_MJDdate"));
        SB_end_MJDdate->setMaximum(999999);

        horizontalLayout_11->addWidget(SB_end_MJDdate);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        label_MJDsec_end = new QLabel(groupBox_12);
        label_MJDsec_end->setObjectName(QStringLiteral("label_MJDsec_end"));

        horizontalLayout_9->addWidget(label_MJDsec_end);

        SB_end_MJDsec = new QDoubleSpinBox(groupBox_12);
        SB_end_MJDsec->setObjectName(QStringLiteral("SB_end_MJDsec"));
        SB_end_MJDsec->setDecimals(3);
        SB_end_MJDsec->setMaximum(86400);
        SB_end_MJDsec->setSingleStep(0.1);

        horizontalLayout_9->addWidget(SB_end_MJDsec);


        horizontalLayout_11->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        horizontalLayout_11->addLayout(horizontalLayout_8);


        gridLayout_3->addLayout(horizontalLayout_11, 3, 0, 1, 3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_Stepsize = new QLabel(groupBox_12);
        label_Stepsize->setObjectName(QStringLiteral("label_Stepsize"));
        label_Stepsize->setFont(font3);

        horizontalLayout_10->addWidget(label_Stepsize);

        SB_stepsize = new QDoubleSpinBox(groupBox_12);
        SB_stepsize->setObjectName(QStringLiteral("SB_stepsize"));
        SB_stepsize->setDecimals(3);
        SB_stepsize->setMaximum(999);
        SB_stepsize->setSingleStep(0.1);

        horizontalLayout_10->addWidget(SB_stepsize);

        label_sec = new QLabel(groupBox_12);
        label_sec->setObjectName(QStringLiteral("label_sec"));

        horizontalLayout_10->addWidget(label_sec);


        gridLayout_3->addLayout(horizontalLayout_10, 4, 0, 1, 3);


        verticalLayout->addWidget(groupBox_12);

        groupBox_13 = new QGroupBox(Setting_EasyTraj);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setFont(font);
        gridLayout = new QGridLayout(groupBox_13);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_sec_8 = new QLabel(groupBox_13);
        label_sec_8->setObjectName(QStringLiteral("label_sec_8"));

        horizontalLayout_16->addWidget(label_sec_8);

        SB_inc = new QDoubleSpinBox(groupBox_13);
        SB_inc->setObjectName(QStringLiteral("SB_inc"));
        SB_inc->setDecimals(3);
        SB_inc->setMinimum(0);
        SB_inc->setMaximum(180);
        SB_inc->setSingleStep(1);
        SB_inc->setValue(0);

        horizontalLayout_16->addWidget(SB_inc);

        label_sec_9 = new QLabel(groupBox_13);
        label_sec_9->setObjectName(QStringLiteral("label_sec_9"));

        horizontalLayout_16->addWidget(label_sec_9);


        gridLayout->addLayout(horizontalLayout_16, 5, 0, 1, 2);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_sec_14 = new QLabel(groupBox_13);
        label_sec_14->setObjectName(QStringLiteral("label_sec_14"));

        horizontalLayout_19->addWidget(label_sec_14);

        SB_anm = new QDoubleSpinBox(groupBox_13);
        SB_anm->setObjectName(QStringLiteral("SB_anm"));
        SB_anm->setDecimals(3);
        SB_anm->setMinimum(0);
        SB_anm->setMaximum(360);
        SB_anm->setSingleStep(1);
        SB_anm->setValue(0);

        horizontalLayout_19->addWidget(SB_anm);

        label_sec_15 = new QLabel(groupBox_13);
        label_sec_15->setObjectName(QStringLiteral("label_sec_15"));

        horizontalLayout_19->addWidget(label_sec_15);


        gridLayout->addLayout(horizontalLayout_19, 4, 0, 1, 2);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_sec_10 = new QLabel(groupBox_13);
        label_sec_10->setObjectName(QStringLiteral("label_sec_10"));

        horizontalLayout_17->addWidget(label_sec_10);

        SB_pom = new QDoubleSpinBox(groupBox_13);
        SB_pom->setObjectName(QStringLiteral("SB_pom"));
        SB_pom->setDecimals(3);
        SB_pom->setMinimum(0);
        SB_pom->setMaximum(360);
        SB_pom->setSingleStep(1);
        SB_pom->setValue(0);

        horizontalLayout_17->addWidget(SB_pom);

        label_sec_11 = new QLabel(groupBox_13);
        label_sec_11->setObjectName(QStringLiteral("label_sec_11"));

        horizontalLayout_17->addWidget(label_sec_11);


        gridLayout->addLayout(horizontalLayout_17, 3, 0, 1, 2);

        label_Stepsize_2 = new QLabel(groupBox_13);
        label_Stepsize_2->setObjectName(QStringLiteral("label_Stepsize_2"));

        gridLayout->addWidget(label_Stepsize_2, 0, 0, 1, 1);

        comboBox_type = new QComboBox(groupBox_13);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        gridLayout->addWidget(comboBox_type, 0, 1, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_sec_6 = new QLabel(groupBox_13);
        label_sec_6->setObjectName(QStringLiteral("label_sec_6"));

        horizontalLayout_15->addWidget(label_sec_6);

        SB_ecc = new QDoubleSpinBox(groupBox_13);
        SB_ecc->setObjectName(QStringLiteral("SB_ecc"));
        SB_ecc->setDecimals(4);
        SB_ecc->setMinimum(0);
        SB_ecc->setMaximum(1);
        SB_ecc->setSingleStep(0.01);
        SB_ecc->setValue(0);

        horizontalLayout_15->addWidget(SB_ecc);

        label_sec_7 = new QLabel(groupBox_13);
        label_sec_7->setObjectName(QStringLiteral("label_sec_7"));

        horizontalLayout_15->addWidget(label_sec_7);


        gridLayout->addLayout(horizontalLayout_15, 2, 0, 1, 2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_sec_2 = new QLabel(groupBox_13);
        label_sec_2->setObjectName(QStringLiteral("label_sec_2"));

        horizontalLayout_12->addWidget(label_sec_2);

        SB_sma = new QDoubleSpinBox(groupBox_13);
        SB_sma->setObjectName(QStringLiteral("SB_sma"));
        SB_sma->setDecimals(2);
        SB_sma->setMinimum(0);
        SB_sma->setMaximum(1e+07);
        SB_sma->setSingleStep(10);
        SB_sma->setValue(7000);

        horizontalLayout_12->addWidget(SB_sma);

        label_sec_5 = new QLabel(groupBox_13);
        label_sec_5->setObjectName(QStringLiteral("label_sec_5"));

        horizontalLayout_12->addWidget(label_sec_5);


        gridLayout->addLayout(horizontalLayout_12, 1, 0, 1, 2);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_sec_12 = new QLabel(groupBox_13);
        label_sec_12->setObjectName(QStringLiteral("label_sec_12"));

        horizontalLayout_18->addWidget(label_sec_12);

        SB_gom = new QDoubleSpinBox(groupBox_13);
        SB_gom->setObjectName(QStringLiteral("SB_gom"));
        SB_gom->setDecimals(3);
        SB_gom->setMinimum(0);
        SB_gom->setMaximum(360);
        SB_gom->setSingleStep(1);
        SB_gom->setValue(0);

        horizontalLayout_18->addWidget(SB_gom);

        label_sec_13 = new QLabel(groupBox_13);
        label_sec_13->setObjectName(QStringLiteral("label_sec_13"));

        horizontalLayout_18->addWidget(label_sec_13);


        gridLayout->addLayout(horizontalLayout_18, 6, 0, 1, 2);


        verticalLayout->addWidget(groupBox_13);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label = new QLabel(Setting_EasyTraj);
        label->setObjectName(QStringLiteral("label"));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);

        verticalLayout_6->addWidget(label);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        line_output_location = new QLineEdit(Setting_EasyTraj);
        line_output_location->setObjectName(QStringLiteral("line_output_location"));
        QFont font5;
        font5.setPointSize(9);
        line_output_location->setFont(font5);

        horizontalLayout_13->addWidget(line_output_location);

        PB_output_location = new QPushButton(Setting_EasyTraj);
        PB_output_location->setObjectName(QStringLiteral("PB_output_location"));
        PB_output_location->setFont(font5);

        horizontalLayout_13->addWidget(PB_output_location);


        verticalLayout_6->addLayout(horizontalLayout_13);


        verticalLayout_7->addLayout(verticalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        PB_OK = new QPushButton(Setting_EasyTraj);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        horizontalLayout_5->addWidget(PB_OK);

        PB_cancel = new QPushButton(Setting_EasyTraj);
        PB_cancel->setObjectName(QStringLiteral("PB_cancel"));

        horizontalLayout_5->addWidget(PB_cancel);

        PB_clearall = new QPushButton(Setting_EasyTraj);
        PB_clearall->setObjectName(QStringLiteral("PB_clearall"));

        horizontalLayout_5->addWidget(PB_clearall);


        verticalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(verticalLayout_7);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Setting_EasyTraj);

        QMetaObject::connectSlotsByName(Setting_EasyTraj);
    } // setupUi

    void retranslateUi(QDialog *Setting_EasyTraj)
    {
        Setting_EasyTraj->setWindowTitle(QApplication::translate("Setting_EasyTraj", "Dialog", 0));
        groupBox_12->setTitle(QApplication::translate("Setting_EasyTraj", "Simulation parameters", 0));
        label_starttime->setText(QApplication::translate("Setting_EasyTraj", "Start time", 0));
        PB_load_fr_Sce->setText(QApplication::translate("Setting_EasyTraj", "Same as Sce", 0));
        label_MJDdate_st->setText(QApplication::translate("Setting_EasyTraj", "MJD date:", 0));
        label_MJDsec_st->setText(QApplication::translate("Setting_EasyTraj", "MJD sec:", 0));
        label_Endtime->setText(QApplication::translate("Setting_EasyTraj", "End time", 0));
        label_MJDdate_end->setText(QApplication::translate("Setting_EasyTraj", "MJD date:", 0));
        label_MJDsec_end->setText(QApplication::translate("Setting_EasyTraj", "MJD sec:", 0));
        label_Stepsize->setText(QApplication::translate("Setting_EasyTraj", "Step size", 0));
        label_sec->setText(QApplication::translate("Setting_EasyTraj", "(sec)", 0));
        groupBox_13->setTitle(QApplication::translate("Setting_EasyTraj", "Orbital elements", 0));
        label_sec_8->setText(QApplication::translate("Setting_EasyTraj", "Inclination:                     ", 0));
        label_sec_9->setText(QApplication::translate("Setting_EasyTraj", "(deg)", 0));
        label_sec_14->setText(QApplication::translate("Setting_EasyTraj", "Mean anomaly:             ", 0));
        label_sec_15->setText(QApplication::translate("Setting_EasyTraj", "(deg)", 0));
        label_sec_10->setText(QApplication::translate("Setting_EasyTraj", "Argument of perigee:", 0));
        label_sec_11->setText(QApplication::translate("Setting_EasyTraj", "(deg)", 0));
        label_Stepsize_2->setText(QApplication::translate("Setting_EasyTraj", "Trajectory type:", 0));
        label_sec_6->setText(QApplication::translate("Setting_EasyTraj", "Eccentricity:                   ", 0));
        label_sec_7->setText(QApplication::translate("Setting_EasyTraj", "(%)    ", 0));
        label_sec_2->setText(QApplication::translate("Setting_EasyTraj", "Semi major axis:           ", 0));
        label_sec_5->setText(QApplication::translate("Setting_EasyTraj", "(km)", 0));
        label_sec_12->setText(QApplication::translate("Setting_EasyTraj", "RAAN:                             ", 0));
        label_sec_13->setText(QApplication::translate("Setting_EasyTraj", "(deg)", 0));
        label->setText(QApplication::translate("Setting_EasyTraj", "Output location:", 0));
        PB_output_location->setText(QApplication::translate("Setting_EasyTraj", "Change", 0));
        PB_OK->setText(QApplication::translate("Setting_EasyTraj", "OK", 0));
        PB_cancel->setText(QApplication::translate("Setting_EasyTraj", "Cancel", 0));
        PB_clearall->setText(QApplication::translate("Setting_EasyTraj", "Clear all", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_EasyTraj: public Ui_Setting_EasyTraj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_EASYTRAJ_H
