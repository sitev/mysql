#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T13:43:38
#
#-------------------------------------------------

QT       -= core gui

TARGET = cjMySQL
TEMPLATE = lib
CONFIG += c++14 staticlib

HEADERS += ../src/cjMySQL.h \
    ../src/sql/mysql/client_plugin.h \
    ../src/sql/mysql/plugin_auth_common.h \
    ../src/sql/binary_log_types.h \
    ../src/sql/my_alloc.h \
    ../src/sql/my_command.h \
    ../src/sql/my_list.h \
    ../src/sql/mysql.h \
    ../src/sql/mysql_com.h \
    ../src/sql/mysql_time.h \
    ../src/sql/mysql_version.h \
    ../src/sql/typelib.h

SOURCES += ../src/cjMySQL.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
