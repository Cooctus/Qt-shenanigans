TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 5)
QT += widgets
SOURCES +=  main.cpp \
    header.cpp

HEADERS += \
    header.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Downloads/muparser-2.2.5/lib/release/ -lmuparser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Downloads/muparser-2.2.5/lib/debug/ -lmuparser
else:unix: LIBS += -L$$PWD/../Downloads/muparser-2.2.5/lib/ -lmuparser

INCLUDEPATH += $$PWD/../Downloads/muparser-2.2.5/include
DEPENDPATH += $$PWD/../Downloads/muparser-2.2.5/include
