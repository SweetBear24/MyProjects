#-------------------------------------------------
#
# Project created by QtCreator 2023-09-12T10:33:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LB3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        sdiprogram_lybarskiy_zimin.cpp \
    docwindow_lybarskiy_zimin.cpp

HEADERS += \
        sdiprogram_lybarskiy_zimin.h \
    docwindow_lybarskiy_zimin.h

FORMS += \
        sdiprogram_lybarskiy_zimin.ui
