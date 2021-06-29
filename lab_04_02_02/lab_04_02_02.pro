TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        create_fst_sre.c \
        main.c \
        my_strtok.c \
        remove_word_from_str.c \
        strcmp_mod.c

HEADERS += \
    create_fst_str.h \
    my_strtok.h \
    remove_word_from_str.h \
    strcmp_mod.h
