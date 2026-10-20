QT += core
TEMPLATE = lib
CONFIG += shared c++17
TARGET = patrivision_core
INCLUDEPATH += ../../include

HEADERS += ../../include/IVistoria.h \
           ../../include/IPatriVisionService.h \
           VistoriaImpl.h \
           PatriVisionServiceImpl.h

SOURCES += VistoriaImpl.cpp \
           PatriVisionServiceImpl.cpp
