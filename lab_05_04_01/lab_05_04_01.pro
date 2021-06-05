TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        del.c \
        main.c \
        print.c \
        sort.c

DISTFILES +=

HEADERS += \
    del.h \
    print.h \
    sort.h \
    struct.h
