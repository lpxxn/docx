include(../../simcubelibrary.pri)

QT -= gui
QT += xml

DEFINES += DOCX_LIBRARY

SOURCES += \
    document.cpp \
    shared.cpp \
    text.cpp \
    blkcntnr.cpp \
    documentpart.cpp \
    opc/part.cpp \
    opc/packuri.cpp \
    opc/opcpackage.cpp \
    package.cpp \
    opc/parts/corepropertiespart.cpp \
    opc/coreproperties.cpp \
    opc/oxml.cpp \
    opc/constants.cpp \
    documenttext.cpp \
    oxml/parts/oxmldocument.cpp \
    oxml/oxmltext.cpp \
    table.cpp \
    oxml/xmlchemy.cpp

HEADERS +=\
    docx_global.h \
    document.h \
    shared.h \
    text.h \
    blkcntnr.h \
    documentpart.h \
    opc/part.h \
    opc/packuri.h \
    opc/opcpackage.h \
    package.h \
    opc/parts/corepropertiespart.h \
    opc/coreproperties.h \
    opc/oxml.h \
    opc/constants.h \
    documenttext.h \
    oxml/parts/oxmldocument.h \
    oxml/oxmltext.h \
    table.h \
    oxml/xmlchemy.h
