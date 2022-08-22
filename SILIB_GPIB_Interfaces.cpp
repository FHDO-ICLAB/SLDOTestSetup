//#include "stdafx.h"
#include "SILIB_GPIB_Interfaces.h"

//----------------------------------------------------------------------------
//
//                         SILIB_GPIB_Interfaces.cpp
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// General interface (parent class)
//----------------------------------------------------------------------------




TGPIB_Interface::TGPIB_Interface ()
{
  for (int id=0; id<MAXDEVICE; id++)
    DeviceExists[id] = false;
}

void TGPIB_Interface::RemoveDevice (int id)
{
  DeviceExists[id] = false;
}

void TGPIB_Interface::OutputDebugStringA(const char *s)
{
 printf("%s\n",s);
}

void TGPIB_Interface::SendDebugTo (std::string text)
{
  OutputDebugStringA(text.c_str());
}

void TGPIB_Interface::Send (int id, std::string  Msg)
{
	std::stringstream ss; 
	ss << "Send to  " << id << ": " << Msg;
	OutputDebugStringA(ss.str().c_str());

  if (DeviceExists[id]) {
  //if (true) {
   IFSend (id, Msg);
//	  OutputDebugStringA("Debug!!!");
  } else {
    OutputDebugStringA("Device does not exist");
  }
}

byte * TGPIB_Interface::ReceiveBinary (int id, byte *Data, int size)
{
	std::stringstream ss; 
	ss << "Receiving binary data from device " << id << "..." ;
	OutputDebugStringA(ss.str().c_str());

  if (DeviceExists[id])
  {
    IFReceiveBinary (id, Data, size);
  }
  else
  {
    OutputDebugStringA("Device does not exist");
  }
  return Data;
}

int TGPIB_Interface::Listen(int id, byte *buffer, int size)
{
  int nBytes;
	std::stringstream ss; 
	ss << "Listening to device " << id << " ..." ;
	OutputDebugStringA(ss.str().c_str());

  if (DeviceExists[id])
  {
    nBytes = IFListen (id, buffer, size);
  }
  else
  {
    OutputDebugStringA("Device does not exist");
    return 0;
  }
  return nBytes;
}

std::string  TGPIB_Interface::SendAndReceive (int id, std::string  Msg)
{
  std::string  Result = "";

  if (DeviceExists[id]) 
	{
    Result = IFSendAndReceive(id, Msg);
    if (DebugOut != NULL) 
		{
	    std::stringstream ss; 
			ss << "Send to  " << id << ": " << Msg << std::endl
				<< "Rec from " << id << ": " << Result << std::endl;
	    OutputDebugStringA(ss.str().c_str());
    }
  } 
	else 
	{
    ErrorMsg("Device does not exist", id);
  }
  return Result;
}

int TGPIB_Interface::SearchDevices (std::string *DevList)
{
  return IFSearchDevices(DevList);
}

int	TGPIB_Interface::GetNumberOfDevices()
{
	return numDev;
}

void	TGPIB_Interface::ClearDevice(int id)
{
	ibclr(MyDevHndl[id]);
}

void TGPIB_Interface::ErrorMsg (std::string  Msg, int id)
{
  std::stringstream ss; 
	ss << "Device "<< id << ", Error: " << Msg << std::endl;
	OutputDebugStringA(ss.str().c_str());
}

//----------------------------------------------------------------------------
// HP PCI interface
//---------------------------------------------------------------------------libgpib.la-
#ifndef GPIB_Interface_USB
/*void SICLCALLBACK ErrorHandler (INST DevHndl, int error)
{
  char tbuffer[500];

  sprintf(tbuffer, "Device id=%d, error = %d:%s", DevHndl, error, igeterrstr(error));
  Application->MessageBox("GPIB_Interface::ErrorHandler", tbuffer, MB_ICONWARNING);
}*/


#endif
//----------------------------------------------------------------------------
//  KEITHLEY USB interface
//----------------------------------------------------------------------------

//#ifdef GPIB_Interface_USB

TGPIB_Interface_USB::TGPIB_Interface_USB(): TGPIB_Interface ()
{
}

TGPIB_Interface_USB::~TGPIB_Interface_USB(void)
{
}

bool TGPIB_Interface_USB::NewDevice (int id)
{
  MyDevHndl[id] = ibdev(0, id, 0, T1s, 1, 0);      // last: EOTMODE, EOSMODE
	if (ibsta & ERR)
  {
    ErrorMsg("Unable to open device driver, ID ", id);
    return false;
  }
  else
  {
    DeviceExists[id] = true;
		ibstop(MyDevHndl[id]);
    return true;
  }
}

void TGPIB_Interface_USB::IFSend (int id, std::string  Msg)
{
	ibwrt (MyDevHndl[id], (void *)Msg.c_str(), Msg.size());
  if (ibsta & ERR)
    ErrorMsg("IFSend", id);
}

byte * TGPIB_Interface_USB::IFReceiveBinary (int id, byte *Data, int size)
{

  ibrd (MyDevHndl[id], Data, size);
  if (ibsta & ERR)
  {
    ErrorMsg("Unable to read data from device ID ", id);
  }
  return Data;
}

int TGPIB_Interface_USB::IFListen (int id, byte *buffer, int size)
{
  ReceiveSetup (0, id);
  if (ibsta & ERR)
  {
		ErrorMsg("Unable prepare listen mode. ERROR " , ibsta);
    return 0;
  }
  RcvRespMsg (0, buffer, size, STOPend);
  if (ibsta & ERR)
  {
    ErrorMsg("Unable to listen to device " , id);
    return 0;
  }
  SendIFC (0);
  return ibcntl;
}


std::string  TGPIB_Interface_USB::IFSendAndReceive (int id, std::string  Msg)
{
//	Msg.append("\n");
  ibwrt (MyDevHndl[id], (void *)Msg.c_str(), Msg.size());

  const int ARRAYSIZE = 5000;
  char      ValueStr[ARRAYSIZE + 1];

  ibrd (MyDevHndl[id], ValueStr, ARRAYSIZE);
  if (ibsta & ERR)
  {
    ErrorMsg("Unable to read data from device ", id);
  }
  ValueStr[ibcntl - 1] = '\0';

  return std::string (ValueStr);
}

int TGPIB_Interface_USB::IFSearchDevices (std::string  *DevList)
{
  #define MAX_DEV_ADD   31
  Addr4882_t addlist[MAX_DEV_ADD];
  Addr4882_t resultlist[MAX_DEV_ADD];
  int tmpDev;
  std::stringstream ss; 

  const int ARRAYSIZE = 5000;
  char      ValueStr[ARRAYSIZE + 1];


  for (int i = 0; i < MAX_DEV_ADD - 1; i++)
    addlist[i] = i + 1;

  addlist[MAX_DEV_ADD - 1] = NOADDR;  // terminate list

  // reset interface
  SendIFC(0);
  // scan GPIB bus for listeners
  FindLstn(0, addlist, resultlist, MAX_DEV_ADD - 1);

  numDev = ibcntl;

  //
  for (int i = 0; i < numDev; i++)
  {
    tmpDev = ibdev(0, resultlist[i], 0, T1s, 1, 0);
    // default command
		ibclr(tmpDev);
    ibwrt(tmpDev, "*IDN?", 5);
    ibrd (tmpDev, ValueStr, ARRAYSIZE);
    if (ibcntl > 1)
		{
			ValueStr[ibcntl - 1] = '\0';
			ss << "ADD " << resultlist[i] << ": " << ValueStr;
			DevList[i] = ss.str().c_str();      
		}
/*	
		// older HP DC Source and Switch Matrix syntax
    ibclr(tmpDev);
    ibwrt(tmpDev, "ID ;", 4);
    ibrd (tmpDev, ValueStr, ARRAYSIZE);
    if (ibcntl > 1)
		{
			ValueStr[ibcntl - 1] = '\0';
			ss << "ADD " << resultlist[i] << ": " << ValueStr;
			DevList[i] = ss.str().c_str();      
		}

    ibclr(tmpDev);
    ibwrt(tmpDev, "ID \n", 4);
    ibrd (tmpDev, ValueStr, ARRAYSIZE);
    if (ibcntl > 1)
		{
			ValueStr[ibcntl - 1] = '\0';
			ss << "ADD " << resultlist[i] << ": " << ValueStr;
			DevList[i] = ss.str().c_str();      
		}

	*/
    if (ibsta & ERR)
			ErrorMsg("Unable to read data from device " ,i);
	
 }

  return ibcntl;
}


//#endif // GPIB_Interface_USB


//----------------------------------------------------------------------------
//
//  KEITHLEY PCI interface
//
//----------------------------------------------------------------------------

/*
TGPIB_Interface_KEITHLEY::TGPIB_Interface_KEITHLEY(void)
{
  ieee488_initialize (21,0);        // make PC a controller at address 21
}

void TGPIB_Interface_KEITHLEY::IFSend    (int id, std::string Msg)
{
}

std::string  TGPIB_Interface_KEITHLEY::IFSendAndReceive (int id, std::string  Msg)
{
  return "Mist";
}
*/

//   ieee488_initialize (21,0);      // make PC a controller at address 21
//  BB_delay(100);                  // wait until ready
//      ieee488_send(DeviceId, str, 0xFFFF, &status);
/*
     if (status == 0) {
       return true;                          // sucess -> no error
     } else {
       ErrorMsg(ERR_FATAL, DeviceName.c_str(), "Bad status returned");
       return false;
     }
   } else {                                  // Device does not exist
     return false;                           //  -> return error
   }

*/
