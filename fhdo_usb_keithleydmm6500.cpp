#ifdef USE_GLOBALS
    #include "Globals.h"
#else
    #ifdef USE_INVISIBLE_GLOBALS
        #include <Globals.h>
    #endif
#endif

#include "fhdo_usb_keithleydmm6500.h"
//#include "fhdo_usb_device.h"
#include <QFile>
#include "qfile.h"
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>
#include "QString"
#include <iostream>

using namespace std;

//USB_KeithleyDMM6500::


KeithleyDMM6500::~KeithleyDMM6500()
{
}



KeithleyDMM6500::KeithleyDMM6500 (USB_Interface * If, QString SerNr): USB_Device (If, SerNr)
{

  MyName   = "Keithley Multimeter Type 2000 with ID = " + MySerNr;
  DeviceStatus = UNKNOWN;

  if (!DeviceResponds()) {

    MyIf = NULL;
  }
}

bool KeithleyDMM6500::DeviceResponds()
{
  QString GoodResult = "KEITHLEY INSTRUMENTS INC.,MODEL 2000";

  QString Result = SendAndReceive("*IDN?");
  Result.resize(GoodResult.length());

  return (Result == GoodResult);
}

double KeithleyDMM6500::MeasureVoltage  (TVoltageUnit Unit)
{
   double voltage;

   if (DeviceStatus != VOLTAGEMODE) {      // configure for voltage measurement
     Send(":SENSE:FUNC 'VOLT:DC'");
     DeviceStatus = VOLTAGEMODE;           // flag new status
   }

   QString Res = SendAndReceive(":SENSE:DATA:FRESH?");


    qDebug()<<" "<<Res;
    voltage = Res.toDouble();


   switch (Unit) {
     case MILLIVOLT: voltage *= 1e3; break;
     case MICROVOLT: voltage *= 1e6; break;
     default:                        break;
   }
   return voltage;
}

double KeithleyDMM6500::MeasureCurrent (TCurrentUnit Unit)
{
   double current;

   if (DeviceStatus != CURRENTMODE) {      // configure for current measurement
     Send(":SENSE:FUNC 'CURR:DC'");
     DeviceStatus = CURRENTMODE;
   }


   QString Res = SendAndReceive(":SENSE:DATA:FRESH?");

   qDebug()<<" "<<Res;
   current = Res.toDouble();

   switch (Unit) {
     case MILLIAMP: current *= 1e3; break;
     case MICROAMP: current *= 1e6; break;
     case NANOAMP:  current *= 1e9; break;
     default:                       break;
   }
   return current;
}

void KeithleyDMM6500::SetSpeed (TDeviceSpeed Speed)
{
  switch (Speed) {
    case FAST:
      Send (":SENSE:VOLTAGE:NPLC 0.1");
      Send (":SENSE:CURRENT:NPLC 0.1");
    break;
    case MEDIUM:
      Send (":SENSE:VOLTAGE:NPLC 1");
      Send (":SENSE:CURRENT:NPLC 1");
    break;
    case SLOW:
      Send (":SENSE:VOLTAGE:NPLC 10");
      Send (":SENSE:CURRENT:NPLC 10");
    break;
    default: break;
  }
}

void KeithleyDMM6500::DisplayText (QString Msg)
{
  const unsigned int MAXLEN = 12;
  if (Msg.length() > MAXLEN) Msg = Msg.mid(0,MAXLEN);
  //if (Msg.length() > MAXLEN) Msg = Msg.substr(0,MAXLEN);

  Send(":DISPLAY:TEXT:DATA \"" + Msg + "\"");
  Send(":DISPLAY:TEXT:STATE ON");

}

void KeithleyDMM6500::DisplayOff (void)
{
  Send(":DISPLAY:TEXT:STATE OFF");
}


