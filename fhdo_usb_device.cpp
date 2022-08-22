#include "fhdo_usb_device.h"
#include <QCoreApplication>
#include <iostream>
#include <string>
#include "QString"
#include <QFile>
#include "qfile.h"
#include <QDebug>
#include <QTextStream>

using namespace std;


USB_Device::~USB_Device()
{
}

USB_Device::USB_Device (USB_Interface * If, QString SerNr)
{
 /* stringstream ss;
  MyIf   = If;
  MySerNr   = SerNr;
  isOk = false;
  ss << "Device with GPIB address " <<(MySerNr);
  MyName = ss.str();
  isOk = MyIf->NewDevice (MySerNr);*/

  MyIf = If;
  MySerNr = SerNr;
  //isOk = false;
  qDebug()<< "Device with Serialnumber "<<MySerNr;
  MyName = " Device with Serialnumber " + MySerNr;
  isOk = MyIf ->identify(MySerNr);

}



void USB_Device::Send (QString Str)    // return false if error
{
  MyIf->Send(MySerNr, Str);
}


QString USB_Device::SendAndReceive (QString Msg)
{
  return MyIf->SendAndReceive(MySerNr, Msg);
}


void USB_Device::ErrorMsg (QString Msg)
{
  MyIf->ErrorMsg(Msg, MySerNr);
}


QString USB_Device::GetName()
{
  return MyName;
}


QString USB_Device::Receive ()    // return false if error
{
}

/*
void USB_Device::ResetAndClear()
{
  if (isOk.length()==0)
  {
    Send("*RST");            // reset Device
    Send("*CLS");            // Clear Status register
  }
}*/






//***Überflüssig***/
/*




byte* USB_Device::ReceiveBinary (byte *data, int size)    // return false if error
{
  MyIf->ReceiveBinary(MyId, data, size);
  return data;
}




*/

