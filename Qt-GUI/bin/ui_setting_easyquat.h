/********************************************************************************
** Form generated from reading UI file 'setting_easyquat.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_EASYQUAT_H
#define UI_SETTING_EASYQUAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_Setting_EasyQuat
{
public:
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *CB_sed_inputs;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *line_seq_inputs;
    QPushButton *PB_Load_seq_inputs;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_3;
    QLabel *label_starttime;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *PB_load_fr_Sce;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_MJDdate_st;
    QSpinBox *line_start_MJDdate;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_MJDsec_st;
    QDoubleSpinBox *line_start_MJDsec;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Endtime;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_MJDdate_end;
    QSpinBox *line_end_MJDdate;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_MJDsec_end;
    QDoubleSpinBox *line_end_MJDsec;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_Stepsize;
    QDoubleSpinBox *line_stepsize;
    QLabel *label_sec;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Stepsize_2;
    QLabel *label_sec_2;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *line_quat_w;
    QDoubleSpinBox *line_quat_x;
    QDoubleSpinBox *line_quat_y;
    QDoubleSpinBox *line_quat_z;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Stepsize_3;
    QLabel *label_sec_3;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *line_ang_x;
    QDoubleSpinBox *line_ang_y;
    QDoubleSpinBox *line_ang_z;
    QLabel *label_sec_4;
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

    void setupUi(QDialog *Setting_EasyQuat)
    {
        if (Setting_EasyQuat->objectName().isEmpty())
            Setting_EasyQuat->setObjectName(QStringLiteral("Setting_EasyQuat"));
        Setting_EasyQuat->resize(350, 557);
        gridLayout_4 = new QGridLayout(Setting_EasyQuat);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        CB_sed_inputs = new QCheckBox(Setting_EasyQuat);
        CB_sed_inputs->setObjectName(QStringLiteral("CB_sed_inputs"));

        verticalLayout_4->addWidget(CB_sed_inputs);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        line_seq_inputs = new QLineEdit(Setting_EasyQuat);
        line_seq_inputs->setObjectName(QStringLiteral("line_seq_inputs"));
        QFont font;
        font.setPointSize(9);
        line_seq_inputs->setFont(font);

        horizontalLayout_12->addWidget(line_seq_inputs);

        PB_Load_seq_inputs = new QPushButton(Setting_EasyQuat);
        PB_Load_seq_inputs->setObjectName(QStringLiteral("PB_Load_seq_inputs"));
        PB_Load_seq_inputs->setFont(font);

        horizontalLayout_12->addWidget(PB_Load_seq_inputs);


        verticalLayout_4->addLayout(horizontalLayout_12);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_12 = new QGroupBox(Setting_EasyQuat);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setPointSize(9);
        groupBox_12->setFont(font1);
        gridLayout_3 = new QGridLayout(groupBox_12);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_starttime = new QLabel(groupBox_12);
        label_starttime->setObjectName(QStringLiteral("label_starttime"));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(true);
        font2.setUnderline(true);
        font2.setWeight(50);
        label_starttime->setFont(font2);

        gridLayout_3->addWidget(label_starttime, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        PB_load_fr_Sce = new QPushButton(groupBox_12);
        PB_load_fr_Sce->setObjectName(QStringLiteral("PB_load_fr_Sce"));
        QFont font3;
        font3.setPointSize(8);
        PB_load_fr_Sce->setFont(font3);

        gridLayout_3->addWidget(PB_load_fr_Sce, 0, 2, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_MJDdate_st = new QLabel(groupBox_12);
        label_MJDdate_st->setObjectName(QStringLiteral("label_MJDdate_st"));

        horizontalLayout_7->addWidget(label_MJDdate_st);

        line_start_MJDdate = new QSpinBox(groupBox_12);
        line_start_MJDdate->setObjectName(QStringLiteral("line_start_MJDdate"));
        line_start_MJDdate->setMaximum(999999);

        horizontalLayout_7->addWidget(line_start_MJDdate);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label_MJDsec_st = new QLabel(groupBox_12);
        label_MJDsec_st->setObjectName(QStringLiteral("label_MJDsec_st"));

        horizontalLayout_7->addWidget(label_MJDsec_st);

        line_start_MJDsec = new QDoubleSpinBox(groupBox_12);
        line_start_MJDsec->setObjectName(QStringLiteral("line_start_MJDsec"));
        line_start_MJDsec->setDecimals(3);
        line_start_MJDsec->setMaximum(86400);
        line_start_MJDsec->setSingleStep(0.1);

        horizontalLayout_7->addWidget(line_start_MJDsec);


        horizontalLayout_14->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        horizontalLayout_14->addLayout(horizontalLayout_6);


        gridLayout_3->addLayout(horizontalLayout_14, 1, 0, 1, 3);

        label_Endtime = new QLabel(groupBox_12);
        label_Endtime->setObjectName(QStringLiteral("label_Endtime"));
        QFont font4;
        font4.setItalic(true);
        font4.setUnderline(true);
        label_Endtime->setFont(font4);

        gridLayout_3->addWidget(label_Endtime, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_MJDdate_end = new QLabel(groupBox_12);
        label_MJDdate_end->setObjectName(QStringLiteral("label_MJDdate_end"));

        horizontalLayout_11->addWidget(label_MJDdate_end);

        line_end_MJDdate = new QSpinBox(groupBox_12);
        line_end_MJDdate->setObjectName(QStringLiteral("line_end_MJDdate"));
        line_end_MJDdate->setMaximum(999999);

        horizontalLayout_11->addWidget(line_end_MJDdate);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        label_MJDsec_end = new QLabel(groupBox_12);
        label_MJDsec_end->setObjectName(QStringLiteral("label_MJDsec_end"));

        horizontalLayout_9->addWidget(label_MJDsec_end);

        line_end_MJDsec = new QDoubleSpinBox(groupBox_12);
        line_end_MJDsec->setObjectName(QStringLiteral("line_end_MJDsec"));
        line_end_MJDsec->setDecimals(3);
        line_end_MJDsec->setMaximum(86400);
        line_end_MJDsec->setSingleStep(0.1);

        horizontalLayout_9->addWidget(line_end_MJDsec);


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
        label_Stepsize->setFont(font4);

        horizontalLayout_10->addWidget(label_Stepsize);

        line_stepsize = new QDoubleSpinBox(groupBox_12);
        line_stepsize->setObjectName(QStringLiteral("line_stepsize"));
        line_stepsize->setDecimals(3);
        line_stepsize->setMaximum(999);
        line_stepsize->setSingleStep(0.1);

        horizontalLayout_10->addWidget(line_stepsize);

        label_sec = new QLabel(groupBox_12);
        label_sec->setObjectName(QStringLiteral("label_sec"));

        horizontalLayout_10->addWidget(label_sec);


        gridLayout_3->addLayout(horizontalLayout_10, 4, 0, 1, 3);


        verticalLayout_2->addWidget(groupBox_12);

        groupBox_13 = new QGroupBox(Setting_EasyQuat);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setFont(font1);
        gridLayout = new QGridLayout(groupBox_13);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Stepsize_2 = new QLabel(groupBox_13);
        label_Stepsize_2->setObjectName(QStringLiteral("label_Stepsize_2"));

        horizontalLayout->addWidget(label_Stepsize_2);

        label_sec_2 = new QLabel(groupBox_13);
        label_sec_2->setObjectName(QStringLiteral("label_sec_2"));

        horizontalLayout->addWidget(label_sec_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        line_quat_w = new QDoubleSpinBox(groupBox_13);
        line_quat_w->setObjectName(QStringLiteral("line_quat_w"));
        line_quat_w->setDecimals(3);
        line_quat_w->setMinimum(-1);
        line_quat_w->setMaximum(1);
        line_quat_w->setSingleStep(0.01);

        horizontalLayout_2->addWidget(line_quat_w);

        line_quat_x = new QDoubleSpinBox(groupBox_13);
        line_quat_x->setObjectName(QStringLiteral("line_quat_x"));
        line_quat_x->setDecimals(3);
        line_quat_x->setMinimum(-1);
        line_quat_x->setMaximum(1);
        line_quat_x->setSingleStep(0.01);

        horizontalLayout_2->addWidget(line_quat_x);

        line_quat_y = new QDoubleSpinBox(groupBox_13);
        line_quat_y->setObjectName(QStringLiteral("line_quat_y"));
        line_quat_y->setDecimals(3);
        line_quat_y->setMinimum(-1);
        line_quat_y->setMaximum(1);
        line_quat_y->setSingleStep(0.01);

        horizontalLayout_2->addWidget(line_quat_y);

        line_quat_z = new QDoubleSpinBox(groupBox_13);
        line_quat_z->setObjectName(QStringLiteral("line_quat_z"));
        line_quat_z->setDecimals(3);
        line_quat_z->setMinimum(-1);
        line_quat_z->setMaximum(1);
        line_quat_z->setSingleStep(0.01);

        horizontalLayout_2->addWidget(line_quat_z);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_13);

        groupBox_14 = new QGroupBox(Setting_EasyQuat);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        groupBox_14->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox_14);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Stepsize_3 = new QLabel(groupBox_14);
        label_Stepsize_3->setObjectName(QStringLiteral("label_Stepsize_3"));

        horizontalLayout_3->addWidget(label_Stepsize_3);

        label_sec_3 = new QLabel(groupBox_14);
        label_sec_3->setObjectName(QStringLiteral("label_sec_3"));

        horizontalLayout_3->addWidget(label_sec_3);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        line_ang_x = new QDoubleSpinBox(groupBox_14);
        line_ang_x->setObjectName(QStringLiteral("line_ang_x"));
        line_ang_x->setDecimals(3);
        line_ang_x->setMinimum(-999);
        line_ang_x->setMaximum(999);
        line_ang_x->setSingleStep(0.01);

        horizontalLayout_4->addWidget(line_ang_x);

        line_ang_y = new QDoubleSpinBox(groupBox_14);
        line_ang_y->setObjectName(QStringLiteral("line_ang_y"));
        line_ang_y->setDecimals(3);
        line_ang_y->setMinimum(-999);
        line_ang_y->setMaximum(999);
        line_ang_y->setSingleStep(0.01);

        horizontalLayout_4->addWidget(line_ang_y);

        line_ang_z = new QDoubleSpinBox(groupBox_14);
        line_ang_z->setObjectName(QStringLiteral("line_ang_z"));
        line_ang_z->setDecimals(3);
        line_ang_z->setMinimum(-999);
        line_ang_z->setMaximum(999);
        line_ang_z->setSingleStep(0.01);

        horizontalLayout_4->addWidget(line_ang_z);

        label_sec_4 = new QLabel(groupBox_14);
        label_sec_4->setObjectName(QStringLiteral("label_sec_4"));

        horizontalLayout_4->addWidget(label_sec_4);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_14);


        verticalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label = new QLabel(Setting_EasyQuat);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_6->addWidget(label);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        line_output_location = new QLineEdit(Setting_EasyQuat);
        line_output_location->setObjectName(QStringLiteral("line_output_location"));
        line_output_location->setFont(font);

        horizontalLayout_13->addWidget(line_output_location);

        PB_output_location = new QPushButton(Setting_EasyQuat);
        PB_output_location->setObjectName(QStringLiteral("PB_output_location"));
        PB_output_location->setFont(font);

        horizontalLayout_13->addWidget(PB_output_location);


        verticalLayout_6->addLayout(horizontalLayout_13);


        verticalLayout_7->addLayout(verticalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        PB_OK = new QPushButton(Setting_EasyQuat);
        PB_OK->setObjectName(QStringLiteral("PB_OK"));

        horizontalLayout_5->addWidget(PB_OK);

        PB_cancel = new QPushButton(Setting_EasyQuat);
        PB_cancel->setObjectName(QStringLiteral("PB_cancel"));

        horizontalLayout_5->addWidget(PB_cancel);

        PB_clearall = new QPushButton(Setting_EasyQuat);
        PB_clearall->setObjectName(QStringLiteral("PB_clearall"));

        horizontalLayout_5->addWidget(PB_clearall);


        verticalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_8->addLayout(verticalLayout_7);


        gridLayout_4->addLayout(verticalLayout_8, 0, 0, 1, 1);

        QWidget::setTabOrder(CB_sed_inputs, line_seq_inputs);
        QWidget::setTabOrder(line_seq_inputs, PB_Load_seq_inputs);
        QWidget::setTabOrder(PB_Load_seq_inputs, PB_load_fr_Sce);
        QWidget::setTabOrder(PB_load_fr_Sce, PB_OK);
        QWidget::setTabOrder(PB_OK, PB_cancel);
        QWidget::setTabOrder(PB_cancel, PB_clearall);

        retranslateUi(Setting_EasyQuat);

        QMetaObject::connectSlotsByName(Setting_EasyQuat);
    } // setupUi

    void retranslateUi(QDialog *Setting_EasyQuat)
    {
        Setting_EasyQuat->setWindowTitle(QApplication::translate("Setting_EasyQuat", "Dialog", 0));
        CB_sed_inputs->setText(QApplication::translate("Setting_EasyQuat", "Read sequence-inputs file", 0));
        PB_Load_seq_inputs->setText(QApplication::translate("Setting_EasyQuat", "Load", 0));
        groupBox_12->setTitle(QApplication::translate("Setting_EasyQuat", "Simulation parameters", 0));
        label_starttime->setText(QApplication::translate("Setting_EasyQuat", "Start time", 0));
        PB_load_fr_Sce->setText(QApplication::translate("Setting_EasyQuat", "Same as Sce", 0));
        label_MJDdate_st->setText(QApplication::translate("Setting_EasyQuat", "MJD date:", 0));
        label_MJDsec_st->setText(QApplication::translate("Setting_EasyQuat", "MJD sec:", 0));
        label_Endtime->setText(QApplication::translate("Setting_EasyQuat", "End time", 0));
        label_MJDdate_end->setText(QApplication::translate("Setting_EasyQuat", "MJD date:", 0));
        label_MJDsec_end->setText(QApplication::translate("Setting_EasyQuat", "MJD sec:", 0));
        label_Stepsize->setText(QApplication::translate("Setting_EasyQuat", "Step size", 0));
        label_sec->setText(QApplication::translate("Setting_EasyQuat", "(sec)", 0));
        groupBox_13->setTitle(QApplication::translate("Setting_EasyQuat", "Initial condition", 0));
        label_Stepsize_2->setText(QApplication::translate("Setting_EasyQuat", "Quaternion:", 0));
        label_sec_2->setText(QApplication::translate("Setting_EasyQuat", "(w + xi + yj + zk)", 0));
        groupBox_14->setTitle(QApplication::translate("Setting_EasyQuat", "Spinning rate", 0));
        label_Stepsize_3->setText(QApplication::translate("Setting_EasyQuat", "Angular Velocite:", 0));
        label_sec_3->setText(QApplication::translate("Setting_EasyQuat", "(xi + yj + zk)", 0));
        label_sec_4->setText(QApplication::translate("Setting_EasyQuat", "(rad/s)", 0));
        label->setText(QApplication::translate("Setting_EasyQuat", "Output location:", 0));
        PB_output_location->setText(QApplication::translate("Setting_EasyQuat", "Change", 0));
        PB_OK->setText(QApplication::translate("Setting_EasyQuat", "OK", 0));
        PB_cancel->setText(QApplication::translate("Setting_EasyQuat", "Cancel", 0));
        PB_clearall->setText(QApplication::translate("Setting_EasyQuat", "Clear all", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting_EasyQuat: public Ui_Setting_EasyQuat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_EASYQUAT_H
