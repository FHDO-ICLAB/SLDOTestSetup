#ifndef SILIB_GPIB_Interfaces_H
#define SILIB_GPIB_Interfaces_H
#include <gpib/ib.h>
#include "stdio.h"
#include "string"
#include "sstream"



//----------------------------------------------------------------------------
//
//                        SILIB_GPIB_Interfaces.h
//
//----------------------------------------------------------------------------
//
// classes to access IEEE488 (GPIB) with different interfaces
//
//
//
//									HK    02/09  adapted for use within Visual Studio
//          				MaKo	06/05	 TGPIB_Interface_HP::NewDevice updated for
//															 Agilent IO Toolbox V14;
//															 TGPIB_Interface_HP::IFListen added		
// History: V1.2:   HK    26/04  added bus scan functionality  (USB interface)
// History: V1.1:   HK    03/04  some changes, added binary read (USB interface)
// History: V1.0:   Pefi  07/01  first version
//
//----------------------------------------------------------------------------

//#include "stdafx.h"					

typedef unsigned char byte;

#define GPIB_ERROR 0x8000

const int MAXDEVICE = 32;        // maximum number of devices on one interface

//----------------------------------------------------------------------------
// General interface (parent class)
//----------------------------------------------------------------------------

class TGPIB_Interface
{
public:
               TGPIB_Interface(); // constructor

  virtual bool NewDevice      (int id) = 0;               // add a Device
  void         RemoveDevice   (int id);

  void         SendDebugTo    (std::string text);         // Send debug Messages

  void         Send           (int id, std::string Msg);   // Send command to device
  std::string  SendAndReceive (int id, std::string  Msg);
  byte*        ReceiveBinary  (int id, byte *Data, int size);  // receive binary data for faster communication
  int          Listen (int id, byte *buffer, int size);
  int          SearchDevices(std::string  *DevList);
  int			     GetNumberOfDevices();
	void         ClearDevice(int id);

  void         ErrorMsg       (std::string  Msg, int id);           // Output error Message

protected:
  virtual void       IFSend            (int id, std::string  Msg) = 0;
  virtual std::string IFSendAndReceive  (int id, std::string  Msg) = 0;
  virtual byte     * IFReceiveBinary   (int id, byte *Data, int size)=0;
  virtual int        IFListen (int id, byte *buffer, int size) = 0;
  virtual int        IFSearchDevices (std::string  *DevList) = 0;
  bool         DeviceExists[MAXDEVICE];
	int          numDev;
	int         MyDevHndl[MAXDEVICE];
  void OutputDebugStringA(const char *s);



private:
  std::string    * DebugOut;
  std::string    * ErrorOut;
};

//----------------------------------------------------------------------------
// HP PCI interface
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// Keithley USB interface
//----------------------------------------------------------------------------
//
// Each NI-488.2 call updates four global variables:
// - the status word (ibsta)
// - the error variable (iberr)
// - the count variables (ibcnt and ibcntl).
// The application should check for errors after each call by looking at ibsta.
//
//----------------------------------------------------------------------------

//#ifdef GPIB_Interface_USB     

//#include "National_Instruments_Decl-32.h"
//#include "Decl-32.h"

class TGPIB_Interface_USB: public TGPIB_Interface
{
public:
              TGPIB_Interface_USB();
             ~TGPIB_Interface_USB(void);
bool          NewDevice                   (int id);
int						NumberOfDevices();

protected:
  void        IFSend            (int id, std::string  Msg);
  std::string   IFSendAndReceive  (int id, std::string  Msg);
  byte     *  IFReceiveBinary   (int id, byte *Data, int size);
  int         IFListen (int id, byte *buffer, int size);
  int        IFSearchDevices (std::string  *DevList);


private:

};
//#endif // GPIB_USB

//----------------------------------------------------------------------------
// Keithley PCI interface
//----------------------------------------------------------------------------

/*
extern "C" {
  extern void      _cdecl ieee488_initialize (long int,long int);
  extern long int  _cdecl ieee488_send       (long int,char *,unsigned long,long int *);
  extern long int  _cdecl ieee488_enter      (char *,unsigned long,unsigned long *,long int,long int  *);
}

class TGPIB_Interface_KEITHLEY_PCI: public TGPIB_Interface
{
public:
              TGPIB_Interface_KEITHLEY_PCI();    // constructor
             ~TGPIB_Interface_KEITHLEY_PCI();    // destructor
protected:
  void        IFSend            (int id, std::string Msg);
  std::string  IFSendAndReceive  (int id, std::string Msg);
private:

};
*/

#endif
