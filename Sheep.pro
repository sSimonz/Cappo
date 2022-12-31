#-------------------------------------------------
#
# Project created by QtCreator 2022-09-30T11:02:10
#
#-------------------------------------------------

QT       += core gui svg multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sheep
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        PlayWidget.cpp \
        cardlabel.cpp \
        comm/CXmlLanguage.cpp \
        comm/customcombobox.cpp \
        dataconfig.cpp \
        dialog.cpp \
        main.cpp \
        mainwindow.cpp \
        timelistwidget.cpp \
        waitingdialog.cpp

HEADERS += \
        PlayWidget.h \
        cardlabel.h \
        comm/CXmlLanguage.h \
        comm/customcombobox.h \
        comm/xmllanguageid.h \
        dataconfig.h \
        dialog.h \
        mainwindow.h \
        timelistwidget.h \
        waitingdialog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

RC_ICONS = main.ico

CONFIG += debug_and_release
CONFIG(debug, debug|release) {
DESTDIR = $$PWD/./bin/Debug/
}else{
DESTDIR = $$PWD/./bin/Release/
}

FORMS += \
    waitingdialog.ui
