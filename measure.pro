#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T15:06:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = measure
TEMPLATE = app


SOURCES +=\
        gpib.cpp \
    Silib_GPIB_Device.cpp \
    SILIB_GPIB_Interfaces.cpp \
    Silib_GPIB_Keithley24xx.cpp \
    Silib_GPIB_Keithley2000.cpp \
    sldo65.cpp \
    main_gpib.cpp \
    Silib_GPIB_Keithley246x.cpp \
    testboard.cpp \
    fhdo_usb_interface.cpp \
    fhdo_usb_device.cpp \
    fhdo_usb_keithleydmm6500.cpp

HEADERS  += gpib.h \
    SILIB_GPIB_Device.h \
    SILIB_GPIB_Interfaces.h \
    Silib_GPIB_Keithley24xx.h \
    Silib_GPIB_Keithley2000.h \
    sldo65.h \
    Silib_GPIB_Keithley246x.h \
    testboard.h \
    fhdo_usb_interface.h \
    fhdo_usb_device.h \
    fhdo_usb_keithleydmm6500.h

FORMS    += gpib.ui \
    testboard.ui

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lgpib

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

#Stiller: QWT einfügen!
QWT_LOCATION = /usr/local/qwt-6.1.4-svn
INCLUDEPATH''= $${QWT_LOCATION}/include/
LIBS += -L$${QWT_LOCATION}/lib -lqwt

RESOURCES += \
    resources.qrc
