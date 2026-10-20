QT += core gui widgets testlib
TEMPLATE = app
CONFIG += testcase c++17
TARGET = tst_guitest

INCLUDEPATH += ../../include ../../src/app
LIBS += -L$$OUT_PWD/../../src/lib -lpatrivision_core

HEADERS += ../../src/app/MainWindow.h
SOURCES += tst_guitest.cpp ../../src/app/MainWindow.cpp
