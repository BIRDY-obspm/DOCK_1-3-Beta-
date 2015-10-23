/********************************************************************************
** Form generated from reading UI file 'dock_main.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCK_MAIN_H
#define UI_DOCK_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DOCK_main
{
public:
    QAction *actionAbout;
    QAction *actionLicense;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionNew;
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *PB_refresh;
    QPushButton *PB_curr_path;
    QPushButton *PB_stopProcess;
    QSpacerItem *horizontalSpacer_5;
    QProgressBar *progressBar;
    QPushButton *PB_Exit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *PB_NewSce;
    QPushButton *PB_LoadSce;
    QLineEdit *Sce_line;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *GB_module_selection;
    QGridLayout *gridLayout_3;
    QGroupBox *Group_attitude;
    QGridLayout *gridLayout;
    QCheckBox *CB_RealQuat;
    QCheckBox *CB_EasyQuat;
    QRadioButton *RB_RealQuat;
    QRadioButton *RB_EasyQuat;
    QToolButton *TB_EasyQuat;
    QToolButton *TB_RealQuat;
    QGroupBox *Group_position;
    QGridLayout *gridLayout_2;
    QCheckBox *CB_EasyTraj;
    QRadioButton *RB_EasyTraj;
    QToolButton *TB_EasyTraj;
    QCheckBox *CB_RealTraj;
    QRadioButton *RB_RealTraj;
    QToolButton *TB_RealTraj;
    QCheckBox *CB_STELA;
    QRadioButton *RB_STELA;
    QToolButton *TB_STELA;
    QGroupBox *Group_vts;
    QFormLayout *formLayout;
    QCheckBox *CB_ProdVTS;
    QToolButton *TB_ProdVTS;
    QCheckBox *CB_ExeVTS;
    QToolButton *TB_ExeVTS;
    QCheckBox *CB_Addons;
    QToolButton *TB_Addons;
    QPushButton *PB_Clearall;
    QPushButton *PB_Reload;
    QPushButton *PB_Check_Exe;
    QPushButton *PB_Save;
    QPushButton *PB_Save_as;
    QGroupBox *GB_general_setting;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *IDM_label_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *PB_CCSDS;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *line_IDMfile;
    QPushButton *PB_LoadIDM;
    QGroupBox *GB_flags;
    QFormLayout *formLayout_9;
    QCheckBox *CB_keep_temp;
    QCheckBox *CB_keep_debug;
    QLabel *Config_label;
    QGroupBox *GB_sim_time;
    QGridLayout *gridLayout_5;
    QLabel *label_starttime;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_MJDdate_st;
    QSpinBox *line_start_MJDdate;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_MJDsec_st;
    QDoubleSpinBox *line_start_MJDsec;
    QLabel *label_Endtime;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_MJDdate_end;
    QSpinBox *line_end_MJDdate;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_MJDsec_end;
    QDoubleSpinBox *line_end_MJDsec;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_Stepsize;
    QDoubleSpinBox *line_stepsize;
    QLabel *label_sec;
    QLabel *IDM_label_2;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *line_VTS;
    QPushButton *PB_LoadVTS;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PB_LoadConfig;
    QPushButton *PB_NewConfig;
    QLabel *IDM_label;
    QLineEdit *line_configfile;
    QMenuBar *menuBar;
    QMenu *menuDOCK_GUI_v1_5;
    QMenu *menuInfo;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DOCK_main)
    {
        if (DOCK_main->objectName().isEmpty())
            DOCK_main->setObjectName(QStringLiteral("DOCK_main"));
        DOCK_main->resize(1243, 641);
        actionAbout = new QAction(DOCK_main);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLicense = new QAction(DOCK_main);
        actionLicense->setObjectName(QStringLiteral("actionLicense"));
        actionOpen = new QAction(DOCK_main);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(DOCK_main);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(DOCK_main);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionNew = new QAction(DOCK_main);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionExit = new QAction(DOCK_main);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(DOCK_main);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(520, 10, 711, 581));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_4->addWidget(textBrowser);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        PB_refresh = new QPushButton(layoutWidget);
        PB_refresh->setObjectName(QStringLiteral("PB_refresh"));

        horizontalLayout_13->addWidget(PB_refresh);

        PB_curr_path = new QPushButton(layoutWidget);
        PB_curr_path->setObjectName(QStringLiteral("PB_curr_path"));

        horizontalLayout_13->addWidget(PB_curr_path);

        PB_stopProcess = new QPushButton(layoutWidget);
        PB_stopProcess->setObjectName(QStringLiteral("PB_stopProcess"));

        horizontalLayout_13->addWidget(PB_stopProcess);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_13->addWidget(progressBar);

        PB_Exit = new QPushButton(layoutWidget);
        PB_Exit->setObjectName(QStringLiteral("PB_Exit"));

        horizontalLayout_13->addWidget(PB_Exit);


        verticalLayout_4->addLayout(horizontalLayout_13);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 10, 501, 585));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        PB_NewSce = new QPushButton(layoutWidget1);
        PB_NewSce->setObjectName(QStringLiteral("PB_NewSce"));

        horizontalLayout_5->addWidget(PB_NewSce);

        PB_LoadSce = new QPushButton(layoutWidget1);
        PB_LoadSce->setObjectName(QStringLiteral("PB_LoadSce"));

        horizontalLayout_5->addWidget(PB_LoadSce);

        Sce_line = new QLineEdit(layoutWidget1);
        Sce_line->setObjectName(QStringLiteral("Sce_line"));

        horizontalLayout_5->addWidget(Sce_line);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        GB_module_selection = new QGroupBox(layoutWidget1);
        GB_module_selection->setObjectName(QStringLiteral("GB_module_selection"));
        GB_module_selection->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(GB_module_selection);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Group_attitude = new QGroupBox(GB_module_selection);
        Group_attitude->setObjectName(QStringLiteral("Group_attitude"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(9);
        Group_attitude->setFont(font);
        gridLayout = new QGridLayout(Group_attitude);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        CB_RealQuat = new QCheckBox(Group_attitude);
        CB_RealQuat->setObjectName(QStringLiteral("CB_RealQuat"));

        gridLayout->addWidget(CB_RealQuat, 2, 0, 2, 1);

        CB_EasyQuat = new QCheckBox(Group_attitude);
        CB_EasyQuat->setObjectName(QStringLiteral("CB_EasyQuat"));

        gridLayout->addWidget(CB_EasyQuat, 0, 0, 2, 1);

        RB_RealQuat = new QRadioButton(Group_attitude);
        RB_RealQuat->setObjectName(QStringLiteral("RB_RealQuat"));

        gridLayout->addWidget(RB_RealQuat, 2, 1, 2, 2);

        RB_EasyQuat = new QRadioButton(Group_attitude);
        RB_EasyQuat->setObjectName(QStringLiteral("RB_EasyQuat"));

        gridLayout->addWidget(RB_EasyQuat, 0, 1, 2, 2);

        TB_EasyQuat = new QToolButton(Group_attitude);
        TB_EasyQuat->setObjectName(QStringLiteral("TB_EasyQuat"));

        gridLayout->addWidget(TB_EasyQuat, 0, 3, 2, 1);

        TB_RealQuat = new QToolButton(Group_attitude);
        TB_RealQuat->setObjectName(QStringLiteral("TB_RealQuat"));

        gridLayout->addWidget(TB_RealQuat, 2, 3, 2, 1);


        gridLayout_3->addWidget(Group_attitude, 0, 0, 1, 2);

        Group_position = new QGroupBox(GB_module_selection);
        Group_position->setObjectName(QStringLiteral("Group_position"));
        Group_position->setFont(font);
        gridLayout_2 = new QGridLayout(Group_position);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        CB_EasyTraj = new QCheckBox(Group_position);
        CB_EasyTraj->setObjectName(QStringLiteral("CB_EasyTraj"));

        gridLayout_2->addWidget(CB_EasyTraj, 0, 0, 1, 1);

        RB_EasyTraj = new QRadioButton(Group_position);
        RB_EasyTraj->setObjectName(QStringLiteral("RB_EasyTraj"));

        gridLayout_2->addWidget(RB_EasyTraj, 0, 1, 1, 1);

        TB_EasyTraj = new QToolButton(Group_position);
        TB_EasyTraj->setObjectName(QStringLiteral("TB_EasyTraj"));

        gridLayout_2->addWidget(TB_EasyTraj, 0, 2, 1, 1);

        CB_RealTraj = new QCheckBox(Group_position);
        CB_RealTraj->setObjectName(QStringLiteral("CB_RealTraj"));

        gridLayout_2->addWidget(CB_RealTraj, 1, 0, 1, 1);

        RB_RealTraj = new QRadioButton(Group_position);
        RB_RealTraj->setObjectName(QStringLiteral("RB_RealTraj"));

        gridLayout_2->addWidget(RB_RealTraj, 1, 1, 1, 1);

        TB_RealTraj = new QToolButton(Group_position);
        TB_RealTraj->setObjectName(QStringLiteral("TB_RealTraj"));

        gridLayout_2->addWidget(TB_RealTraj, 1, 2, 1, 1);

        CB_STELA = new QCheckBox(Group_position);
        CB_STELA->setObjectName(QStringLiteral("CB_STELA"));

        gridLayout_2->addWidget(CB_STELA, 2, 0, 1, 1);

        RB_STELA = new QRadioButton(Group_position);
        RB_STELA->setObjectName(QStringLiteral("RB_STELA"));

        gridLayout_2->addWidget(RB_STELA, 2, 1, 1, 1);

        TB_STELA = new QToolButton(Group_position);
        TB_STELA->setObjectName(QStringLiteral("TB_STELA"));

        gridLayout_2->addWidget(TB_STELA, 2, 2, 1, 1);


        gridLayout_3->addWidget(Group_position, 1, 0, 1, 2);

        Group_vts = new QGroupBox(GB_module_selection);
        Group_vts->setObjectName(QStringLiteral("Group_vts"));
        Group_vts->setFont(font);
        formLayout = new QFormLayout(Group_vts);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        CB_ProdVTS = new QCheckBox(Group_vts);
        CB_ProdVTS->setObjectName(QStringLiteral("CB_ProdVTS"));

        formLayout->setWidget(0, QFormLayout::LabelRole, CB_ProdVTS);

        TB_ProdVTS = new QToolButton(Group_vts);
        TB_ProdVTS->setObjectName(QStringLiteral("TB_ProdVTS"));

        formLayout->setWidget(0, QFormLayout::FieldRole, TB_ProdVTS);

        CB_ExeVTS = new QCheckBox(Group_vts);
        CB_ExeVTS->setObjectName(QStringLiteral("CB_ExeVTS"));

        formLayout->setWidget(1, QFormLayout::LabelRole, CB_ExeVTS);

        TB_ExeVTS = new QToolButton(Group_vts);
        TB_ExeVTS->setObjectName(QStringLiteral("TB_ExeVTS"));

        formLayout->setWidget(1, QFormLayout::FieldRole, TB_ExeVTS);

        CB_Addons = new QCheckBox(Group_vts);
        CB_Addons->setObjectName(QStringLiteral("CB_Addons"));

        formLayout->setWidget(2, QFormLayout::LabelRole, CB_Addons);

        TB_Addons = new QToolButton(Group_vts);
        TB_Addons->setObjectName(QStringLiteral("TB_Addons"));

        formLayout->setWidget(2, QFormLayout::FieldRole, TB_Addons);


        gridLayout_3->addWidget(Group_vts, 2, 0, 1, 2);

        PB_Clearall = new QPushButton(GB_module_selection);
        PB_Clearall->setObjectName(QStringLiteral("PB_Clearall"));

        gridLayout_3->addWidget(PB_Clearall, 3, 0, 1, 1);

        PB_Reload = new QPushButton(GB_module_selection);
        PB_Reload->setObjectName(QStringLiteral("PB_Reload"));

        gridLayout_3->addWidget(PB_Reload, 3, 1, 1, 1);

        PB_Check_Exe = new QPushButton(GB_module_selection);
        PB_Check_Exe->setObjectName(QStringLiteral("PB_Check_Exe"));

        gridLayout_3->addWidget(PB_Check_Exe, 4, 0, 1, 2);

        PB_Save = new QPushButton(GB_module_selection);
        PB_Save->setObjectName(QStringLiteral("PB_Save"));

        gridLayout_3->addWidget(PB_Save, 5, 0, 1, 1);

        PB_Save_as = new QPushButton(GB_module_selection);
        PB_Save_as->setObjectName(QStringLiteral("PB_Save_as"));

        gridLayout_3->addWidget(PB_Save_as, 5, 1, 1, 1);


        horizontalLayout_14->addWidget(GB_module_selection);

        GB_general_setting = new QGroupBox(layoutWidget1);
        GB_general_setting->setObjectName(QStringLiteral("GB_general_setting"));
        GB_general_setting->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(GB_general_setting);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        IDM_label_3 = new QLabel(GB_general_setting);
        IDM_label_3->setObjectName(QStringLiteral("IDM_label_3"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        IDM_label_3->setFont(font1);

        horizontalLayout_11->addWidget(IDM_label_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        PB_CCSDS = new QPushButton(GB_general_setting);
        PB_CCSDS->setObjectName(QStringLiteral("PB_CCSDS"));
        QFont font2;
        font2.setPointSize(9);
        PB_CCSDS->setFont(font2);

        horizontalLayout_11->addWidget(PB_CCSDS);


        gridLayout_4->addLayout(horizontalLayout_11, 4, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        line_IDMfile = new QLineEdit(GB_general_setting);
        line_IDMfile->setObjectName(QStringLiteral("line_IDMfile"));
        line_IDMfile->setFont(font2);

        horizontalLayout_4->addWidget(line_IDMfile);

        PB_LoadIDM = new QPushButton(GB_general_setting);
        PB_LoadIDM->setObjectName(QStringLiteral("PB_LoadIDM"));
        PB_LoadIDM->setFont(font2);

        horizontalLayout_4->addWidget(PB_LoadIDM);


        gridLayout_4->addLayout(horizontalLayout_4, 6, 0, 1, 2);

        GB_flags = new QGroupBox(GB_general_setting);
        GB_flags->setObjectName(QStringLiteral("GB_flags"));
        GB_flags->setFont(font);
        formLayout_9 = new QFormLayout(GB_flags);
        formLayout_9->setSpacing(6);
        formLayout_9->setContentsMargins(11, 11, 11, 11);
        formLayout_9->setObjectName(QStringLiteral("formLayout_9"));
        formLayout_9->setHorizontalSpacing(6);
        formLayout_9->setVerticalSpacing(0);
        formLayout_9->setContentsMargins(0, 0, 0, 0);
        CB_keep_temp = new QCheckBox(GB_flags);
        CB_keep_temp->setObjectName(QStringLiteral("CB_keep_temp"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, CB_keep_temp);

        CB_keep_debug = new QCheckBox(GB_flags);
        CB_keep_debug->setObjectName(QStringLiteral("CB_keep_debug"));

        formLayout_9->setWidget(1, QFormLayout::LabelRole, CB_keep_debug);


        gridLayout_4->addWidget(GB_flags, 7, 0, 1, 2);

        Config_label = new QLabel(GB_general_setting);
        Config_label->setObjectName(QStringLiteral("Config_label"));
        Config_label->setFont(font1);

        gridLayout_4->addWidget(Config_label, 0, 0, 1, 1);

        GB_sim_time = new QGroupBox(GB_general_setting);
        GB_sim_time->setObjectName(QStringLiteral("GB_sim_time"));
        GB_sim_time->setFont(font);
        gridLayout_5 = new QGridLayout(GB_sim_time);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_starttime = new QLabel(GB_sim_time);
        label_starttime->setObjectName(QStringLiteral("label_starttime"));
        QFont font3;
        font3.setItalic(true);
        font3.setUnderline(true);
        label_starttime->setFont(font3);

        gridLayout_5->addWidget(label_starttime, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label_MJDdate_st = new QLabel(GB_sim_time);
        label_MJDdate_st->setObjectName(QStringLiteral("label_MJDdate_st"));

        horizontalLayout_6->addWidget(label_MJDdate_st);

        line_start_MJDdate = new QSpinBox(GB_sim_time);
        line_start_MJDdate->setObjectName(QStringLiteral("line_start_MJDdate"));
        line_start_MJDdate->setMaximum(999999);
        line_start_MJDdate->setDisplayIntegerBase(10);

        horizontalLayout_6->addWidget(line_start_MJDdate);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label_MJDsec_st = new QLabel(GB_sim_time);
        label_MJDsec_st->setObjectName(QStringLiteral("label_MJDsec_st"));

        horizontalLayout_7->addWidget(label_MJDsec_st);

        line_start_MJDsec = new QDoubleSpinBox(GB_sim_time);
        line_start_MJDsec->setObjectName(QStringLiteral("line_start_MJDsec"));
        line_start_MJDsec->setDecimals(3);
        line_start_MJDsec->setMaximum(86400);
        line_start_MJDsec->setSingleStep(0.1);

        horizontalLayout_7->addWidget(line_start_MJDsec);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout_5->addLayout(verticalLayout, 1, 0, 1, 1);

        label_Endtime = new QLabel(GB_sim_time);
        label_Endtime->setObjectName(QStringLiteral("label_Endtime"));
        label_Endtime->setFont(font3);

        gridLayout_5->addWidget(label_Endtime, 2, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        label_MJDdate_end = new QLabel(GB_sim_time);
        label_MJDdate_end->setObjectName(QStringLiteral("label_MJDdate_end"));

        horizontalLayout_8->addWidget(label_MJDdate_end);

        line_end_MJDdate = new QSpinBox(GB_sim_time);
        line_end_MJDdate->setObjectName(QStringLiteral("line_end_MJDdate"));
        line_end_MJDdate->setMaximum(999999);
        line_end_MJDdate->setDisplayIntegerBase(10);

        horizontalLayout_8->addWidget(line_end_MJDdate);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        label_MJDsec_end = new QLabel(GB_sim_time);
        label_MJDsec_end->setObjectName(QStringLiteral("label_MJDsec_end"));

        horizontalLayout_9->addWidget(label_MJDsec_end);

        line_end_MJDsec = new QDoubleSpinBox(GB_sim_time);
        line_end_MJDsec->setObjectName(QStringLiteral("line_end_MJDsec"));
        line_end_MJDsec->setDecimals(3);
        line_end_MJDsec->setMaximum(86400);
        line_end_MJDsec->setSingleStep(0.1);

        horizontalLayout_9->addWidget(line_end_MJDsec);


        verticalLayout_3->addLayout(horizontalLayout_9);


        gridLayout_5->addLayout(verticalLayout_3, 3, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_Stepsize = new QLabel(GB_sim_time);
        label_Stepsize->setObjectName(QStringLiteral("label_Stepsize"));
        label_Stepsize->setFont(font3);

        horizontalLayout_10->addWidget(label_Stepsize);

        line_stepsize = new QDoubleSpinBox(GB_sim_time);
        line_stepsize->setObjectName(QStringLiteral("line_stepsize"));
        line_stepsize->setDecimals(3);
        line_stepsize->setMaximum(9999);
        line_stepsize->setSingleStep(0.1);

        horizontalLayout_10->addWidget(line_stepsize);

        label_sec = new QLabel(GB_sim_time);
        label_sec->setObjectName(QStringLiteral("label_sec"));

        horizontalLayout_10->addWidget(label_sec);


        gridLayout_5->addLayout(horizontalLayout_10, 4, 0, 1, 1);


        gridLayout_4->addWidget(GB_sim_time, 8, 0, 1, 2);

        IDM_label_2 = new QLabel(GB_general_setting);
        IDM_label_2->setObjectName(QStringLiteral("IDM_label_2"));
        IDM_label_2->setFont(font1);

        gridLayout_4->addWidget(IDM_label_2, 2, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        line_VTS = new QLineEdit(GB_general_setting);
        line_VTS->setObjectName(QStringLiteral("line_VTS"));
        line_VTS->setFont(font2);

        horizontalLayout_12->addWidget(line_VTS);

        PB_LoadVTS = new QPushButton(GB_general_setting);
        PB_LoadVTS->setObjectName(QStringLiteral("PB_LoadVTS"));
        PB_LoadVTS->setFont(font2);

        horizontalLayout_12->addWidget(PB_LoadVTS);


        gridLayout_4->addLayout(horizontalLayout_12, 3, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        PB_LoadConfig = new QPushButton(GB_general_setting);
        PB_LoadConfig->setObjectName(QStringLiteral("PB_LoadConfig"));
        PB_LoadConfig->setFont(font2);

        horizontalLayout_3->addWidget(PB_LoadConfig);

        PB_NewConfig = new QPushButton(GB_general_setting);
        PB_NewConfig->setObjectName(QStringLiteral("PB_NewConfig"));
        PB_NewConfig->setFont(font2);

        horizontalLayout_3->addWidget(PB_NewConfig);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        IDM_label = new QLabel(GB_general_setting);
        IDM_label->setObjectName(QStringLiteral("IDM_label"));
        IDM_label->setFont(font1);

        gridLayout_4->addWidget(IDM_label, 5, 0, 1, 1);

        line_configfile = new QLineEdit(GB_general_setting);
        line_configfile->setObjectName(QStringLiteral("line_configfile"));
        line_configfile->setFont(font2);

        gridLayout_4->addWidget(line_configfile, 1, 0, 1, 1);

        IDM_label->raise();
        line_configfile->raise();
        Config_label->raise();
        GB_flags->raise();
        IDM_label_2->raise();
        GB_sim_time->raise();

        horizontalLayout_14->addWidget(GB_general_setting);


        verticalLayout_2->addLayout(horizontalLayout_14);

        DOCK_main->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DOCK_main);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1243, 25));
        menuDOCK_GUI_v1_5 = new QMenu(menuBar);
        menuDOCK_GUI_v1_5->setObjectName(QStringLiteral("menuDOCK_GUI_v1_5"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        DOCK_main->setMenuBar(menuBar);
        statusBar = new QStatusBar(DOCK_main);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DOCK_main->setStatusBar(statusBar);
        QWidget::setTabOrder(CB_EasyQuat, PB_Check_Exe);
        QWidget::setTabOrder(PB_Check_Exe, RB_EasyQuat);
        QWidget::setTabOrder(RB_EasyQuat, PB_Exit);
        QWidget::setTabOrder(PB_Exit, CB_Addons);
        QWidget::setTabOrder(CB_Addons, textBrowser);
        QWidget::setTabOrder(textBrowser, CB_ExeVTS);
        QWidget::setTabOrder(CB_ExeVTS, CB_RealQuat);
        QWidget::setTabOrder(CB_RealQuat, CB_EasyTraj);
        QWidget::setTabOrder(CB_EasyTraj, CB_RealTraj);
        QWidget::setTabOrder(CB_RealTraj, CB_STELA);
        QWidget::setTabOrder(CB_STELA, RB_RealQuat);
        QWidget::setTabOrder(RB_RealQuat, RB_EasyTraj);
        QWidget::setTabOrder(RB_EasyTraj, RB_RealTraj);
        QWidget::setTabOrder(RB_RealTraj, RB_STELA);
        QWidget::setTabOrder(RB_STELA, PB_Clearall);
        QWidget::setTabOrder(PB_Clearall, CB_ProdVTS);

        menuBar->addAction(menuDOCK_GUI_v1_5->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuDOCK_GUI_v1_5->addAction(actionNew);
        menuDOCK_GUI_v1_5->addAction(actionOpen);
        menuDOCK_GUI_v1_5->addAction(actionSave);
        menuDOCK_GUI_v1_5->addAction(actionSave_as);
        menuDOCK_GUI_v1_5->addAction(actionExit);
        menuInfo->addAction(actionAbout);
        menuInfo->addAction(actionLicense);

        retranslateUi(DOCK_main);

        QMetaObject::connectSlotsByName(DOCK_main);
    } // setupUi

    void retranslateUi(QMainWindow *DOCK_main)
    {
        DOCK_main->setWindowTitle(QApplication::translate("DOCK_main", "DOCK_main", 0));
        actionAbout->setText(QApplication::translate("DOCK_main", "About", 0));
        actionLicense->setText(QApplication::translate("DOCK_main", "License", 0));
        actionOpen->setText(QApplication::translate("DOCK_main", "Open Sce", 0));
        actionSave->setText(QApplication::translate("DOCK_main", "Save", 0));
        actionSave_as->setText(QApplication::translate("DOCK_main", "Save as", 0));
        actionNew->setText(QApplication::translate("DOCK_main", "New Sce", 0));
        actionExit->setText(QApplication::translate("DOCK_main", "Exit", 0));
        PB_refresh->setText(QApplication::translate("DOCK_main", "Clean console", 0));
        PB_curr_path->setText(QApplication::translate("DOCK_main", "Current path", 0));
        PB_stopProcess->setText(QApplication::translate("DOCK_main", "Stop process", 0));
        PB_Exit->setText(QApplication::translate("DOCK_main", "Exit", 0));
        PB_NewSce->setText(QApplication::translate("DOCK_main", "New", 0));
        PB_LoadSce->setText(QApplication::translate("DOCK_main", "Open", 0));
        GB_module_selection->setTitle(QApplication::translate("DOCK_main", "Modules selection", 0));
        Group_attitude->setTitle(QApplication::translate("DOCK_main", "Attitude", 0));
        CB_RealQuat->setText(QApplication::translate("DOCK_main", "Real Quaternion", 0));
        CB_EasyQuat->setText(QApplication::translate("DOCK_main", "Easy Quaternion", 0));
        RB_RealQuat->setText(QString());
        RB_EasyQuat->setText(QString());
        TB_EasyQuat->setText(QApplication::translate("DOCK_main", "...", 0));
        TB_RealQuat->setText(QApplication::translate("DOCK_main", "...", 0));
        Group_position->setTitle(QApplication::translate("DOCK_main", "Position", 0));
        CB_EasyTraj->setText(QApplication::translate("DOCK_main", "Easy Trajectory", 0));
        RB_EasyTraj->setText(QString());
        TB_EasyTraj->setText(QApplication::translate("DOCK_main", "...", 0));
        CB_RealTraj->setText(QApplication::translate("DOCK_main", "Trajectory Solver", 0));
        RB_RealTraj->setText(QString());
        TB_RealTraj->setText(QApplication::translate("DOCK_main", "...", 0));
        CB_STELA->setText(QApplication::translate("DOCK_main", "STELA", 0));
        RB_STELA->setText(QString());
        TB_STELA->setText(QApplication::translate("DOCK_main", "...", 0));
        Group_vts->setTitle(QApplication::translate("DOCK_main", "VTS", 0));
        CB_ProdVTS->setText(QApplication::translate("DOCK_main", "Produce VTS", 0));
        TB_ProdVTS->setText(QApplication::translate("DOCK_main", "...", 0));
        CB_ExeVTS->setText(QApplication::translate("DOCK_main", "Execute VTS", 0));
        TB_ExeVTS->setText(QApplication::translate("DOCK_main", "...", 0));
        CB_Addons->setText(QApplication::translate("DOCK_main", "Extract Add-ons", 0));
        TB_Addons->setText(QApplication::translate("DOCK_main", "...", 0));
        PB_Clearall->setText(QApplication::translate("DOCK_main", "Clear all", 0));
        PB_Reload->setText(QApplication::translate("DOCK_main", "Reload", 0));
        PB_Check_Exe->setText(QApplication::translate("DOCK_main", "Check and Execute", 0));
        PB_Save->setText(QApplication::translate("DOCK_main", "Save", 0));
        PB_Save_as->setText(QApplication::translate("DOCK_main", "Save as", 0));
        GB_general_setting->setTitle(QApplication::translate("DOCK_main", "General setting", 0));
        IDM_label_3->setText(QApplication::translate("DOCK_main", "Satellite CCSDS setting:", 0));
        PB_CCSDS->setText(QApplication::translate("DOCK_main", "Modify", 0));
        PB_LoadIDM->setText(QApplication::translate("DOCK_main", "Change", 0));
        GB_flags->setTitle(QApplication::translate("DOCK_main", "Flags (clicked is \"True\")", 0));
        CB_keep_temp->setText(QApplication::translate("DOCK_main", "Keep_temp_file", 0));
        CB_keep_debug->setText(QApplication::translate("DOCK_main", "Keep_debug_file", 0));
        Config_label->setText(QApplication::translate("DOCK_main", "Configuration file:", 0));
        GB_sim_time->setTitle(QApplication::translate("DOCK_main", "Simulation parameters", 0));
        label_starttime->setText(QApplication::translate("DOCK_main", "Start time", 0));
        label_MJDdate_st->setText(QApplication::translate("DOCK_main", "MJD date:", 0));
        label_MJDsec_st->setText(QApplication::translate("DOCK_main", "MJD sec:", 0));
        label_Endtime->setText(QApplication::translate("DOCK_main", "End time", 0));
        label_MJDdate_end->setText(QApplication::translate("DOCK_main", "MJD date:", 0));
        label_MJDsec_end->setText(QApplication::translate("DOCK_main", "MJD sec:", 0));
        label_Stepsize->setText(QApplication::translate("DOCK_main", "Step size", 0));
        label_sec->setText(QApplication::translate("DOCK_main", "(sec)", 0));
        IDM_label_2->setText(QApplication::translate("DOCK_main", "VTS project:", 0));
        PB_LoadVTS->setText(QApplication::translate("DOCK_main", "Change", 0));
        PB_LoadConfig->setText(QApplication::translate("DOCK_main", "Open", 0));
        PB_NewConfig->setText(QApplication::translate("DOCK_main", "New", 0));
        IDM_label->setText(QApplication::translate("DOCK_main", "IDM-CIC file:", 0));
        menuDOCK_GUI_v1_5->setTitle(QApplication::translate("DOCK_main", "File", 0));
        menuInfo->setTitle(QApplication::translate("DOCK_main", "Info", 0));
    } // retranslateUi

};

namespace Ui {
    class DOCK_main: public Ui_DOCK_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCK_MAIN_H
