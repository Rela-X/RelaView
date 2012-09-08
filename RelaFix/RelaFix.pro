#-------------------------------------------------
#
# Project created by QtCreator 2012-05-25T22:51:57
#
#-------------------------------------------------


TARGET = rflib

TEMPLATE = lib
CONFIG += staticlib


SOURCES += \
    src/tools.c \
    src/table.c \
    src/stack.c \
    src/relation.c \
    src/parser.tab.c \
    src/parse.c \
    src/operation.c \
    src/negation.c \
    src/list.c \
    src/lexer.c \
    src/function.c \
    src/formula.c \
    src/domain.c \
    src/array.c

INCLUDEPATH = inc/
HEADERS += \
    inc/tools.h \
    inc/table.h \
    inc/stack.h \
    inc/relation.h \
    inc/parser.tab.h \
    inc/parse.h \
    inc/operation.h \
    inc/negation.h \
    inc/list.h \
    inc/function.h \
    inc/formula.h \
    inc/domain.h \
    inc/defines.h \
    inc/array.h

OTHER_FILES += \
    src/parser.y


CONFIG(debug, debug|release){
    DESTDIR = build/debug
    OBJECTS_DIR = $${DESTDIR}/obj
    MOC_DIR = $${DESTDIR}/moc
    RCC_DIR = $${DESTDIR}/rcc
    UI_DIR = $${DESTDIR}/ui
}else{
    DESTDIR = build/release
    OBJECTS_DIR = $${DESTDIR}/obj
    MOC_DIR = $${DESTDIR}/moc
    RCC_DIR = $${DESTDIR}/rcc
    UI_DIR = $${DESTDIR}/ui
}



