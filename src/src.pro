TARGET=shorty

DESTDIR=../bin

QT += quick

SOURCES += \
    main.cpp \
    shorty.cpp

OTHER_FILES += \
    main.qml \
    FilmStrip.qml

CONFIG -= app_bundle

HEADERS += \
    shorty.h

