#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T05:40:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DOCK_GUI_v1-5-1
TEMPLATE = app


SOURCES += main.cpp\
        dock_main.cpp \
    setting_easyquat.cpp \
    setting_realquat.cpp \
    setting_easytraj.cpp \
    setting_realtraj.cpp \
    setting_stela.cpp \
    setting_prodvts.cpp \
    setting_exevts.cpp \
    setting_addons.cpp \
    setting_ccsds.cpp

HEADERS  += dock_main.h \
    setting_easyquat.h \
    setting_dialog_struct.h \
    setting_realquat.h \
    setting_easytraj.h \
    setting_realtraj.h \
    setting_stela.h \
    setting_prodvts.h \
    setting_exevts.h \
    setting_addons.h \
    setting_ccsds.h

FORMS    += dock_main.ui \
    setting_easyquat.ui \
    setting_realquat.ui \
    setting_easytraj.ui \
    setting_realtraj.ui \
    setting_stela.ui \
    setting_prodvts.ui \
    setting_exevts.ui \
    setting_addons.ui \
    setting_ccsds.ui

CONFIG += c++11
