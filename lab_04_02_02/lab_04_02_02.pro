TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        create_fst_sre.c \
        main.c \
        my_strtok.c \
        working_with_words.c

HEADERS += \
    create_fst_str.h \
    my_strtok.h \
    working_with_words.h
