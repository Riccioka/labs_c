TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        funcs.c \
        key.c \
        main.c \
        mysort.c \
        print_in_file.c \
        src/funcs.c \
        src/key.c \
        src/main.c \
        src/mysort.c \
        src/print_in_file.c \
        unit_tests/key_check.c \
        unit_tests/main_check.c \
        unit_tests/mysort_check.c

DISTFILES += \
    in_file.txt \
    out_file.txt

HEADERS += \
    funcs.h \
    inc/funcs.h \
    inc/key.h \
    inc/mysort.h \
    inc/print_in_file.h \
    key.h \
    mysort.h \
    print_in_file.h
