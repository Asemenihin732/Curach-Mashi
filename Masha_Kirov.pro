QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog1.cpp \
    main.cpp \
    mainwindow.cpp \
    tablemodel.cpp \
    ventil.cpp \


HEADERS += \
    dialog1.h \
    mainwindow.h \
    tablemodel.h \
    ventil.h \


FORMS += \
    dialog1.ui \
    mainwindow.ui

TRANSLATIONS += \
    QtLanguage_ru.ts\
    QtLanguage_ch.ts\
    QtLanguage_en.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


