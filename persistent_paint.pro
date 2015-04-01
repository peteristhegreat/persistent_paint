#-------------------------------------------------
#
# Project created by QtCreator 2015-03-31T19:30:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = persistent_paint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintwidget.cpp

HEADERS  += mainwindow.h \
    paintwidget.h

FORMS    += mainwindow.ui
