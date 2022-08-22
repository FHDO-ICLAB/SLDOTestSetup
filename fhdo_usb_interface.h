#ifndef FHDO_USB_INTERFACE_H
#define FHDO_USB_INTERFACE_H

#include <QCoreApplication>
#include <iostream>
#include <string>
#include "QString"
#include <QFile>
#include "qfile.h"
#include <QDebug>
#include <QTextStream>
#include <gpib/ib.h>

using namespace std;

const int MAXDEVICE_USB = 16;        // maximum number of devices on one interface


class USB_Interface
{
public:
    USB_Interface();
    ~USB_Interface();


    QString identify(QString SerNr);
    void Send(QString SerNr, QString Msg);
    QString SendAndReceive (QString SerNr, QString Msg);
    void ErrorMsg (QString SerNr, QString Msg);

};



#endif // FHDO_USB_INTERFACE_H



