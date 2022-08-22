#ifndef FHDO_USB_DEVICE_H
#define FHDO_USB_DEVICE_H

#include <QFile>
#include <QString>
#include "fhdo_usb_interface.h"
#ifndef VOLT_CUR_UNIT
#define VOLT_CUR_UNIT
enum TVoltageUnit {VOLT, MILLIVOLT, MICROVOLT};
enum TCurrentUnit {AMP,  MILLIAMP,  MICROAMP, NANOAMP};
#endif

using namespace std;


class USB_Device
{
public:

              ~USB_Device();

               USB_Device   (USB_Interface * If, QString SerNr); //

      QString           GetName();
      QString              isOk;

protected:
      void              Send       (QString Str); // Error checked in Interface
      QString       SendAndReceive (QString Str); // return false if error
      USB_Interface   * MyIf;                            // My interface
      QString           MySerNr;                         // My Serialnumber of device
      QString           MyName;                          // My Name (like 'Keithley2000')*/

      QString           Receive ();
      void              ErrorMsg       (QString SerNr);
     // void				ResetAndClear();                  // performs reset and clear on device
};






#endif // FHDO_USB_DEVICE_H


      /*
            byte *            ReceiveBinary  (byte* data, int size);


            ;*/

