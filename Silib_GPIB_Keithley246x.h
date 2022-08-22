#ifndef SILIB_GPIB_Keithley246X_H
#define SILIB_GPIB_Keithley246X_H
#include "SILIB_GPIB_Interfaces.h"
#include "SILIB_GPIB_Device.h"
#include <cstdlib>

const int GPIB_ID_K246X = 30;

#ifndef KEITHLEY
#define KEITHLEY
enum TDeviceStatus {UNKNOWN, VOLTAGEMODE, CURRENTMODE};
enum TDeviceSpeed  {FAST, MEDIUM, SLOW};
enum TDeviceRange  {AUTO};
#endif // KEITHLEY

class TGPIB_Keithley246X: public TGPIB_Device
{
public:
          TGPIB_Keithley246X (TGPIB_Interface * If, int id = GPIB_ID_K246X);
          ~TGPIB_Keithley246X ();

   void   SetCurrentRange1mA (void);

   void   SetVoltage         (double voltage, double maxcurrent=0);
   void   SetCurrent         (double current, double maxvoltage=0);
   void   Measure            (double &current, double &voltage, TVoltageUnit VoltUnit = VOLT, TCurrentUnit CurrUnit = MILLIAMP);
   double   VSweep              (double &delay, double &steps, double &start, double &end, double &limit, double &vrange, double &crange);
   double   CSweep              (double &delay, double &steps, double &start, double &end, double &limit, double &vrange, double &crange);

   // void   SweepVoltage       (double Start, double Stop, int N);

   void   SwitchOff();
   void   SwitchOn();
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
