include(../../simcubelibrary.pri)

QT -= gui

DEFINES += DOCX_LIBRARY

SOURCES += \
    document.cpp \
    shared.cpp \
    text.cpp \
    blkcntnr.cpp \
    documentpart.cpp \
    opc/part.cpp \
    opc/packuri.cpp \
    opc/opcpackage.cpp

HEADERS +=\
    docx_global.h \
    document.h \
    shared.h \
    text.h \
    blkcntnr.h \
    documentpart.h \
    opc/part.h \
    opc/packuri.h \
    opc/opcpackage.h
