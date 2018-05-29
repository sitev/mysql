QT       -= core gui

TARGET = mysql
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../../core/src
INCLUDEPATH += ../../logger/src
INCLUDEPATH += ../../network/src
#INCLUDEPATH += ../../libraries/mysqlconn/include
#INCLUDEPATH += ../../lib/mysql-connector-c/include
INCLUDEPATH += ../../lib/mysqlconn/include



HEADERS += \
    ../src/mysql.h

SOURCES += \
    ../src/mysql.cpp

LIBS += C:\projects\cjso\core\build-core-Desktop_Qt_5_10_1_MSVC2017_64bit-Debug\debug\core.lib \
    C:\projects\cjso\logger\build-logger-Desktop_Qt_5_10_1_MSVC2017_64bit-Debug\debug\logger.lib \
    C:\projects\lib\mysqlconn\lib\libmysql.lib
