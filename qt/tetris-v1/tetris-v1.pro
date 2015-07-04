TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
LIBS +=-lpthread

SOURCES += \
    cubePoint.cpp \
    cur.cpp \
    game.cpp \
    graph.cpp \
    rand.cpp \
    score.cpp

HEADERS += \
    cubePoint.h \
    cur.h \
    game.h \
    graph.h \
    rand.h \
    score.h

