TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        create_words.c \
        main.c \
        transformation.c

HEADERS += \
    create_words.h \
    errors.h \
    transformation.h
