#-------------------------------------------------
#
# Project created by QtCreator 2016-03-23T20:49:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DerpSharp
TEMPLATE = app


SOURCES += main.cpp \
    core/application.cpp \
    core/parser.cpp \
    core/token.cpp \
    core/interpreter.cpp

HEADERS  += \
    core/application.h \
    core/parser.h \
    core/token.h \
    core/interpreter.h
