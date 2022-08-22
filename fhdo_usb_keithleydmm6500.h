#ifndef FHDO_USB_KEITHLEYDMM6500_H
#define FHDO_USB_KEITHLEYDMM6500_H

#include "fhdo_usb_interface.h"
#include "fhdo_usb_device.h"
#include <stdio.h>
#include <string>
#include <QString>

using namespace std;

#ifndef KEITHLEY
#define KEITHLEY
enum TDeviceStatus {UNKNOWN, VOLTAGEMODE, CURRENTMODE};
enum TDeviceSpeed  {FAST, MEDIUM, SLOW};
enum TDeviceRange  {AUTO};
#endif // KEITHLEY

class KeithleyDMM6500: public USB_Device     //Vererbung Device
{
public:

          ~KeithleyDMM6500();


          KeithleyDMM6500 (USB_Interface * If, QString SerNr);  //GPIB_ID_K2000

   double MeasureCurrent     (TCurrentUnit Unit = MILLIAMP);
   double MeasureVoltage     (TVoltageUnit Unit = VOLT);
   void   SetSpeed           (TDeviceSpeed Speed);
   void   SetRange           (TDeviceRange Range);

   void   DisplayText        (QString Msg);
   void   DisplayOff         (void);

private:
   bool   DeviceResponds     ();           // Test if device responds
   TDeviceStatus DeviceStatus;             // Remember setting of Multimeter
};

#endif // FHDO_USB_KEITHLEYDMM6500_H

