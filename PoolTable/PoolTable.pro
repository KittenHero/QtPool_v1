#-------------------------------------------------
#
# Project created by QtCreator 2018-04-23T23:26:07
#
#-------------------------------------------------

QT       += core gui
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PoolTable
TEMPLATE = app


SOURCES += main.cpp \
    dialog.cpp \
    poolgame.cpp \
    stageonetable.cpp \
    stageoneball.cpp \
    stageonefactory.cpp \
    gamebuilder.cpp \
    initializer.cpp

HEADERS  += dialog.h \
    poolgame.h \
    table.h \
    ball.h \
    stageonetable.h \
    stageoneball.h \
    abstractfactory.h \
    stageonefactory.h \
    gamebuilder.h \
    initializer.h

