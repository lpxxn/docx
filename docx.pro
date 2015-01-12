include(../../simcubelibrary.pri)

QT -= gui

DEFINES += DOCX_LIBRARY

SOURCES += \
    document.cpp \
    shared.cpp \
    text.cpp \
    blkcntnr.cpp \
    documentpart.cpp

HEADERS +=\
    docx_global.h \
    document.h \
    shared.h \
    text.h \
    blkcntnr.h \
    documentpart.h
