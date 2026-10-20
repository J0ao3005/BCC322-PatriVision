QT += core gui widgets
TEMPLATE = app
CONFIG += c++17
TARGET = PatriVisionApp

INCLUDEPATH += ../../include
LIBS += -L../lib -lpatrivision_core

HEADERS += MainWindow.h
SOURCES += main.cpp MainWindow.cpp
