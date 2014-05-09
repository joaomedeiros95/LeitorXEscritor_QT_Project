#-------------------------------------------------
#
# Project created by QtCreator 2014-05-07T20:07:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LeitorxEscritor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    semaforo.cpp \
    sobre.cpp \
    thread1.cpp \
    thread2.cpp

HEADERS  += mainwindow.h \
    semaforo.h \
    sobre.h \
    thread1.h \
    thread2.h

FORMS    += mainwindow.ui \
    sobre.ui
