QT       -= core gui

TARGET = mysql
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../../core/src
INCLUDEPATH += ../../network/src
#INCLUDEPATH += ../../libraries/mysqlconn/include
INCLUDEPATH += ../../lib/mysql-connector-c/include


HEADERS += \
    ../src/mysql.h

SOURCES += \
    ../src/mysql.cpp
