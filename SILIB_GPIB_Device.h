#ifndef SILIB_GPIB_Device_H
#define SILIB_GPIB_Device_H

#include "SILIB_GPIB_Interfaces.h"
typedef unsigned char byte;

#ifndef VOLT_CUR_UNIT
#define VOLT_CUR_UNIT
enum TVoltageUnit {VOLT, MILLIVOLT, MICROVOLT};
enum TCurrentUnit {AMP,  MILLIAMP,  MICROAMP, NANOAMP};
#endif
//----------------------------------------------------------------------------
// general GPIB device
//----------------------------------------------------------------------------

class TGPIB_Device
{
public:
                    TGPIB_Device   (TGPIB_Interface * If, int Id);
  std::string        GetName();
  bool              isOk; 
protected:
  void              Send           (std::string Str); // Error checked in Interface
  std::string       SendAndReceive (std::string Str); // return false if error
  std::string       Receive ();
  byte *            ReceiveBinary  (byte* data, int size);
  void							ResetAndClear(); // performs reset and clear on device

  void              ErrorMsg       (std::string Msg);

  TGPIB_Interface * MyIf;                            // My interface
  int               MyId;                            // My GPIB Id
  std::string        MyName;                          // My Name (like 'Keithley2000')
};

#endif
