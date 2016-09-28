#-------------------------------------------------
#
# Project created by QtCreator 2015-06-18T17:22:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EnumOpen3000Table
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    buildvectorfromopen3000.cpp \
    ByteOrder.cpp

HEADERS  += mainwindow.h \
    buildvectorfromopen3000.h \
    ByteOrder.h

FORMS    += mainwindow.ui
RC_FILE = wd.rc
