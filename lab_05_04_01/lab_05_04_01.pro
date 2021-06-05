TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bad_size.c \
        del.c \
        main.c \
        print.c \
        sort.c

DISTFILES +=

HEADERS += \
    bad_size.h \
    del.h \
    print.h \
    sort.h \
    struct.h
