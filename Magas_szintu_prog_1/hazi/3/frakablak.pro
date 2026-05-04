TEMPLATE = app
CONFIG += c++17 console
CONFIG -= app_bundle
CONFIG -= qt

# But we are using Qt!
QT += core gui widgets

SOURCES += \
    frakablak.cpp \
    frakszal.cpp \
    main.cpp

HEADERS += \
    frakablak.h \
    frakszal.h
