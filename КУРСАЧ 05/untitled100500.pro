#-------------------------------------------------
#
# Project created by QtCreator 2018-02-01T16:24:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled100500
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
        mainwindow.cpp \
    byte.cpp \
    dword.cpp \
    memory.cpp \
    ROM_memory.cpp \
    stack_block.cpp \
    word.cpp \
    helpdialog.cpp \
    infodialog.cpp

HEADERS += \
        mainwindow.h \
    byte.h \
    dword.h \
    memory.h \
    ROM_memory.h \
    stack_block.h \
    word.h \
    helpdialog.h \
    infodialog.h

FORMS += \
        mainwindow.ui \
    helpdialog.ui \
    infodialog.ui

QMAKE_CXXFLAGS += -std=c++11
