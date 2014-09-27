#-------------------------------------------------
#
# Project created by QtCreator 2014-09-13T10:52:16
#
#-------------------------------------------------

QT       -= gui

TARGET = Logger
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    AsynchronousLogger.cpp \
    SynchronousLogger.cpp \
    Test.cpp \
    LoggerUtil.cpp \
    ThreadSafeQueue.cpp

HEADERS += \
    AsynchronousLogger.h \
    ConsoleLog.h \
    FileLog.h \
    ILogger.h \
    SynchronousLogger.h \
    ILoggingSource.h \
    LoggerUtil.h \
    ThreadSafeQueue.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
