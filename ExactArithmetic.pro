TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lboost_unit_test_framework

SOURCES += \
        boosttests.cpp \
        gcd.cpp \
        integer.cpp \
        main.cpp \
        rational.cpp

HEADERS += \
    dividebyzeroerror.h \
    gcd.h \
    integer.h \
    rational.h
