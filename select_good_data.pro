#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T10:17:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = select_good_data
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$quote(D:\LIB\Qwt-6.1.2\include)

LIBS +=   $$quote(D:\LIB\Qwt-6.1.2\lib\qwt.lib)
