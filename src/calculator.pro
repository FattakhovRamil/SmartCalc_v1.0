QT       += core gui printsupport
QT += charts
QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditWindow.cpp \
    depositWindow.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    s21_smartCalc.c

HEADERS += \
    creditWindow.h \
    depositWindow.h \
    mainwindow.h \
    qcustomplot.h \
    s21_smartCalc.h

FORMS += \
    creditWindow.ui \
    depositWindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
