#ifndef SILIB_GPIB_Keithley24xx_H
#define SILIB_GPIB_Keithley24xx_H
#include "SILIB_GPIB_Interfaces.h"
#include "SILIB_GPIB_Device.h"
#include <cstdlib>

const int GPIB_ID_K240x = 12;

#ifndef KEITHLEY
#define KEITHLEY
enum TDeviceStatus {UNKNOWN, VOLTAGEMODE, CURRENTMODE};
enum TDeviceSpeed  {FAST, MEDIUM, SLOW};
enum TDeviceRange  {AUTO};
#endif // KEITHLEY

class TGPIB_Keithley240x: public TGPIB_Device
{
public:
          TGPIB_Keithley240x (TGPIB_Interface * If, int id = GPIB_ID_K240x);
          ~TGPIB_Keithley240x ();

   void   SetCurrentRange1mA (void);

   void   SetVoltage         (double voltage, double maxcurrent=0);
   void   SetCurrent         (double current, double maxvoltage=0);
   void   Measure            (double &current, double &voltage, TVoltageUnit VoltUnit = VOLT, TCurrentUnit CurrUnit = MILLIAMP);

   // void   SweepVoltage       (double Start, double Stop, int N);

   void   SwitchOff();
   void 	SwitchOn();
   void   Beep();

   void   SetSpeed           (TDeviceSpeed Speed);
   // void   SetRange           (TDeviceRange Range);

   void   DisplayText        (std::string Message);
   void   DisplayOff         (void);
   bool   DeviceResponds     ();           // Test if device responds

private:
   TDeviceStatus DeviceStatus;             // Remember setting of Multimeter
};

#endif
