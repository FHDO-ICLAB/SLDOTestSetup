//---------------------------------------------------------------------------
// precompiled headers - for faster comilation
#ifdef USE_GLOBALS
	#include "Globals.h"
#else
	#ifdef USE_INVISIBLE_GLOBALS
		#include <Globals.h>
		// globals.h has to be included in Include search path (project options)
		// for this to work, doesn't show overcrowded class explorer
	#endif
#endif


#include "Silib_GPIB_Keithley24xx.h"

//------------------------------------------------------------------------------
// Keithley 24xx SMU
//------------------------------------------------------------------------------
// To do:
//------------------------------------------------------------------------------

TGPIB_Keithley240x::TGPIB_Keithley240x (TGPIB_Interface * If, int id): TGPIB_Device (If, id)
{
  MyName   = "Keithley Multimeter Type 2400 with ID = " + MyId;
  DeviceStatus = UNKNOWN;

  if (!DeviceResponds()) {
		isOk = false;
    MyIf = NULL;
    return;
  }

// Initilize Source and set to 0V, 0.1mA limit
	Send(":SOUR:FUNC:MODE VOLT");
	DeviceStatus = VOLTAGEMODE;
	Send(":SOUR:VOLT:MODE FIXED");
	Send(":SOUR:VOLT:RANG:AUTO ON");
	Send(":SOUR:VOLT:LEV:IMM 0");
    //Send(":SENSE:CURR:PROT 0.0001");
    //Send(":SENSE:CURR:PROT AUTO");

// Measure only current and voltage
  Send(":SENS:FUNC:CONC ON");
  Send(":SENS:FUNC:OFF:ALL");
  Send(":SENS:FUNC:ON  'VOLT:DC','CURR:DC'");
  Send(":SENS:AVER:STAT OFF");

// Only Output voltage and current
  Send(":FORM:DATA ASCII");
  Send(":FORM:ELEM VOLT,CURR");

// Output on
//  Send(":OUTP ON");

}
//---------------------------------------------------------------------------
TGPIB_Keithley240x::~TGPIB_Keithley240x()
{
  SwitchOff();
}
//---------------------------------------------------------------------------
bool TGPIB_Keithley240x::DeviceResponds()
{
//	std::string GoodResult = "KEITHLEY INSTRUMENTS INC.,MODEL 2400";
    std::string GoodResult = "KEITHLEY INSTRUMENTS INC.,MODEL 240";
	std::string Result = SendAndReceive("*IDN?");
  	Result.resize(GoodResult.length());
	return (Result == GoodResult);
}
//---------------------------------------------------------------------------
void TGPIB_Keithley240x::SetVoltage (double voltage, double maxcurrent)
{
 std::string TempV;	//lokale Variable für die Spannung
 std::string TempC;	//lokale Variable für den Strom
// char DS = DecimalSeparator;
// DecimalSeparator = '.';

std::stringstream ssV; 	//Erzeuge Datenstrom vom Typ String
ssV << voltage;		//Übertrage den Inhalt der Variable in den DStrom
std::stringstream ssC;	//Erzeuge Datenstrom vom Typ String
ssC << maxcurrent;	//Übertrage den Inhalt der Variable in den DStrom


 if (DeviceStatus != VOLTAGEMODE) {
        Send(":SOUR:FUNC:MODE VOLT");
		DeviceStatus = VOLTAGEMODE;
		Send(":SOUR:VOLT:MODE FIXED");
 }
 //Stiller: Auto Range funktioniert nicht wie erwartet, ohne Anpassungen des Sense Range wird der Strom limitiert
 Send(":SOUR:VOLT:RANG:AUTO ON");
 //Send("SENS:FUNC \"CURR\"");   //Stiller 12.10.17 Test
 //Send(":SENS:CURR:RANG 1"); // Set Voltage range
 //Ende
		TempV = ":SOUR:VOLT:LEVEL:IMM ";//Befehlskette des Meßgerät
		TempV = TempV + ssV.str(); 	//Umwandeln des Datenstroms 
						//nach String und anhängen an
 						//Variable
		TempC =	":SENSE:CURR:PROT ";
		TempC = TempC + ssC.str();		
		//Temp = Temp + ssI.str();
	if (maxcurrent!=0) Send(TempC);
    Send(":SOUR:VOLT:RANG:AUTO ON");
	Send(TempV);
//	Send(":OUTP ON");
//	DecimalSeparator = DS;
}

//---------------------------------------------------------------------------
void TGPIB_Keithley240x::SetCurrent (double current, double maxvoltage)
{
 std::string TempV;	//lokale Variable für die Spannung
 std::string TempC;	//lokale Variable für den Strom

// current given in AMPERE!
//	char temp = DecimalSeparator;
//	DecimalSeparator = '.';

std::stringstream ssV; 	//Erzeuge Datenstrom vom Typ String
ssV << maxvoltage;		//Übertrage den Inhalt der Variable in den DStrom
std::stringstream ssC;	//Erzeuge Datenstrom vom Typ String
ssC << current;	//Übertrage den Inhalt der Variable in den DStrom


	if (DeviceStatus != CURRENTMODE) {
		Send(":SOUR:FUNC:MODE CURR");
		DeviceStatus = CURRENTMODE;
		Send(":SOUR:CURR:MODE FIXED");
		Send(":SOUR:VOLT:LEVEL:IMM 0");
        Send(":SOUR:CURR:RANG:AUTO ON");
         //Stiller: Auto Range funktioniert nicht wie erwartet, ohne Anpassungen des Sense Range wird die Spannung limitiertr
        Send(":SENS:VOLT:RANG 2"); // Set Voltage range
        //Ende
}
		TempV = ":SENSE:VOLT:PROT ";	//Befehlskette des Meßgerät
		TempV = TempV + ssV.str(); 	//Umwandeln des Datenstroms 
						//nach String und anhängen an
 						//Variable
		TempC = ":SOUR:CURR:LEVEL:IMM ";	
		TempC = TempC + ssC.str(); 	
	

	if (maxvoltage!=0) Send(TempV);
    Send(":SOUR:CURR:RANG:AUTO ON");
	Send(TempC);
//DecimalSeparator = temp;
}
//---------------------------------------------------------------------------
void TGPIB_Keithley240x::Measure(double &current, double &voltage, TVoltageUnit VoltUnit, TCurrentUnit CurrUnit)
{
  std::string Res = SendAndReceive(":READ?");
//  char temp = DecimalSeparator;
//  DecimalSeparator = '.';
  if (Res != "Error" && Res != "") {

	voltage = std::atof(Res.substr(1,13).c_str());
	current = std::atof(Res.substr(15,13).c_str());
//    voltage = Res.substr(1,13).ToDouble();
//    current = Res.substr(15,13).ToDouble();
  };
 // DecimalSeparator = temp;
/*
  switch (CurrUnit) {
    case AMP:                      break;
    case MILLIAMP: current *= 1e3; break;
    case MICROAMP: current *= 1e6; break;
    case NANOAMP:  current *= 1e9; break;
    default:                       break;
  }

  switch (VoltUnit) {
    case VOLT:                      break;
    case MILLIVOLT: voltage *= 1e3; break;
    case MICROVOLT: voltage *= 1e6; break;
    default:                        break;
  }*/
}
//---------------------------------------------------------------------------
/*
void TGPIB_Keithley240x::SweepVoltage (double * Volt, double * Curr, double Start, double Stop, int N)
{

  Send("*RST");
  Send(":SOUR:FUNC:MODE VOLT");
  Send(":SOUR:VOLT:MODE FIXED");
  Send(":SOUR:VOLT:RANG 2.0");
  Send(":SENSE:CURR:PROT 0.001");

  Send(":SENS:FUNC:Conc Off");
  Send(":SENS:FUNC 'Curr:DC'");
  Send(":FORM:ELEM Curr");

  Send(":SOUR:VOLT:LEVEL:IMM " + std::string(Start));
  Send(":OUTP ON");

  double step = (N==1) ? 0 : (Stop-Start) / (double) (N-1);
  for (int i=0; i<N; i++) {
    double v = Start + i * step;
    Send(":SOUR:VOLT:LEVEL:IMM " + std::string(v));
    std::string Res = SendAndReceive(":READ?");
    Volt[i] = v;
    Curr[i] = Res.ToDouble();
  }
  Send(":OUTP OFF");
}
*/
//---------------------------------------------------------------------------
void TGPIB_Keithley240x::SetSpeed (TDeviceSpeed Speed)
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
//---------------------------------------------------------------------------
void TGPIB_Keithley240x::DisplayText (std::string Msg)
{
  const unsigned int MAXLEN = 12;
  if (Msg.length() > MAXLEN) Msg = Msg.substr(0,MAXLEN);

  Send(":DISPLAY:TEXT:DATA \"" + Msg + "\"");
  Send(":DISPLAY:TEXT:STATE ON");

}
//---------------------------------------------------------------------------
void TGPIB_Keithley240x::DisplayOff (void)
{
  Send(":DISPLAY:TEXT:STATE OFF");
}
//---------------------------------------------------------------------------
void TGPIB_Keithley240x::SwitchOff (void)
{
  Send(":OUTP OFF");
}
//---------------------------------------------------------------------------
void TGPIB_Keithley240x::SwitchOn (void)
{
  Send(":OUTP ON");
}
//---------------------------------------------------------------------------
void TGPIB_Keithley240x::Beep (void)
{
  Send(":System:Beeper 500, 2");
  Send(":System:Beeper 20000, 2");
  Send(":System:Beeper 500, 2");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

