#-------------------------------------------------
#
# Project created by QtCreator 2018-03-25T16:58:25
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mini-projet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    walldialog.cpp

HEADERS  += mainwindow.h \
    walldialog.h

FORMS    += mainwindow.ui \
    walldialog.ui
