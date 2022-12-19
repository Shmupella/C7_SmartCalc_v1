QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/calculate.c \
    ../src/main_calc.c \
    ../src/parcer.c \
    ../src/polish_notation.c \
    ../src/stack.c \
    ../src/validation.c \
    calculate.c \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../src/calculate.h \
    ../src/main_calc.h \
    ../src/parcer.h \
    ../src/polish_notation.h \
    ../src/stack.h \
    ../src/validation.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
