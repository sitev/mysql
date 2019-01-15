QT       -= core gui

TARGET = mysql
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../../core/src
INCLUDEPATH += ../../logger/src
INCLUDEPATH += ../../network/src
INCLUDEPATH += ../../../lib/mysqlconn/include


HEADERS += \
    ../src/mysql.h

SOURCES += \
    ../src/mysql.cpp
