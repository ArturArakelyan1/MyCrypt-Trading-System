QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += sql
QT += charts

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ada.cpp \
    helpdialog.cpp \
    knuth.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    order.cpp \
    registerdialog.cpp \
    user.cpp \
    workinwind.cpp \
    stock.cpp \
    turing.cpp

HEADERS += \
    ada.h \
    helpdialog.h \
    knuth.h \
    logindialog.h \
    mainwindow.h \
    order.h \
    registerdialog.h \
    stock.h \
    turing.h \
    user.h \
    workinwind.h

FORMS += \
    helpdialog.ui \
    logindialog.ui \
    mainwindow.ui \
    registerdialog.ui \
    workinwind.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/resources.qrc
