// M.Eng. Andreas Stiller changed most of the SCPI-commands due to incompatibility of 240X SCPI-commands to 246X
// 26.06.2017 


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


#include "Silib_GPIB_Keithley246x.h"

//------------------------------------------------------------------------------
// Keithley 246X SMU
//------------------------------------------------------------------------------
// To do:
//------------------------------------------------------------------------------

TGPIB_Keithley246X::TGPIB_Keithley246X (TGPIB_Interface * If, int id): TGPIB_Device (If, id)
{
  MyName   = "Keithley Multimeter Type 246X with ID = " + MyId;
  DeviceStatus = UNKNOWN;

  if (!DeviceResponds()) {
		isOk = false;
    MyIf = NULL;
    return;
  }

// Initilize Source and set to 0V, 0.1mA limit
	Send(":SOUR:FUNC:MODE VOLT");
	DeviceStatus = VOLTAGEMODE;
    //Send(":SOUR:VOLT:MODE FIXED");
	Send(":SOUR:VOLT:RANG:AUTO ON");
	Send(":SOUR:VOLT:LEV:IMM 0");
    Send(":SOURCE:VOLTAGE:ILIMIT 1");


// Measure only current and voltage

  Send(":SOUR:VOLT:READ:BACK 1");		// Stiller:	When you use the actual source value (source readback on), the instrument measures the actual source value
						// 		immediately before making the device under test measurement.
  //Send(":SENS:FUNC:OFF:ALL");
  //Send(":SENS:FUNC:ON  'VOLT:DC','CURR:DC'");
  Send(":SENS:VOLT:AVER:STAT OFF");



// Only Output voltage and current
  Send(":FORM:DATA ASCII");


}
//---------------------------------------------------------------------------
TGPIB_Keithley246X::~TGPIB_Keithley246X()
{
  SwitchOff();
}
//---------------------------------------------------------------------------
bool TGPIB_Keithley246X::DeviceResponds()
{
    std::string GoodResult = "KEITHLEY INSTRUMENTS,MODEL 246";
	std::string Result = SendAndReceive("*IDN?");
  	Result.resize(GoodResult.length());
	return (Result == GoodResult);
}
//---------------------------------------------------------------------------
void TGPIB_Keithley246X::SetVoltage (double voltage, double maxcurrent)
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
		//Send(":SOUR:VOLT:MODE FIXED");
 }

 Send(":SOUR:VOLT:RANG:AUTO ON");

		TempV = ":SOUR:VOLT:LEVEL:IMM ";//Befehlskette des Meßgerät
		TempV = TempV + ssV.str(); 	//Umwandeln des Datenstroms 
						//nach String und anhängen an
 						//Variable
		TempC =	":SOUR:VOLT:ILIMIT ";
		TempC = TempC + ssC.str();		
		//Temp = Temp + ssI.str();
	if (maxcurrent!=0) Send(TempC);
    Send(":SOUR:VOLT:RANG:AUTO ON");
	Send(TempV);
//	Send(":OUTP ON");
//	DecimalSeparator = DS;
}
//---------------------------------------------------------------------------
void TGPIB_Keithley246X::SetCurrent (double current, double maxvoltage)
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
		//Send(":SOUR:CURR:MODE FIXED");
		Send(":SOUR:VOLT:LEVEL:IMM 0");
        Send(":SOUR:CURR:RANG:AUTO ON");

}
		TempV = ":SOUR:CURR:VLIMIT ";	//Befehlskette des Meßgerät
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
void TGPIB_Keithley246X::Measure(double &current, double &voltage, TVoltageUnit VoltUnit, TCurrentUnit CurrUnit)
{
  std::string Res = SendAndReceive(":READ?");
//  char temp = DecimalSeparator;
//  DecimalSeparator = '.';
  if (Res != "Error" && Res != "") {

      //Test Stiller
      //cout << "DEBUGG" << endl;

    voltage = std::atof(Res.substr(1,13).c_str());
    //current = std::atof(Res.substr(15,13).c_str());


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
void TGPIB_Keithley246X::SweepVoltage (double * Volt, double * Curr, double Start, double Stop, int N)
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
void TGPIB_Keithley246X::SetSpeed (TDeviceSpeed Speed)
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
void TGPIB_Keithley246X::DisplayText (std::string Msg)
{
  const unsigned int MAXLEN = 12;
  if (Msg.length() > MAXLEN) Msg = Msg.substr(0,MAXLEN);

  Send(":DISPLAY:TEXT:DATA \"" + Msg + "\"");
  Send(":DISPLAY:TEXT:STATE ON");

}
//---------------------------------------------------------------------------
void TGPIB_Keithley246X::DisplayOff (void)
{
  Send(":DISPLAY:TEXT:STATE OFF");
}
//---------------------------------------------------------------------------
void TGPIB_Keithley246X::SwitchOff (void)
{
  Send(":OUTP OFF");
}
//---------------------------------------------------------------------------
void TGPIB_Keithley246X::SwitchOn (void)
{
  Send(":OUTP ON");
}
//---------------------------------------------------------------------------
void TGPIB_Keithley246X::Beep (void)
{
  Send(":System:Beeper 500, 2");
  Send(":System:Beeper 20000, 2");
  Send(":System:Beeper 500, 2");
}


//Stiller 24,04.2019 Testrrampe
double TGPIB_Keithley246X::VSweep(double &delay, double &steps, double &start, double &end, double &limit, double &crange, double &vrange)
{
   std::string string_delay;	//lokale Variable für delay
   std::string string_sweep;	//lokale Variable für sweep
   std::string string_limit;
   std::string string_crange;
   std::string string_vrange;

   std::stringstream sdelay;
   std::stringstream ssteps;
   std::stringstream sstart; 
   std::stringstream send;
   std::stringstream slimit;
   std::stringstream scrange;
   std::stringstream svrange;

   send << end;
   sdelay << delay;
   sstart << start;
   ssteps << steps;
   slimit << limit;
   scrange << crange;
   svrange << vrange;

   //Define Delay
   string_delay = "TRIGGER:BLOCK:DELAY:CONSTANT 6, ";
   string_delay = string_delay + sdelay.str();
   
   //Define Sweep
   string_sweep = "SOUR:SWE:VOLT:LIN ";
   string_sweep = string_sweep + sstart.str();
   string_sweep = string_sweep + ", ";
   string_sweep = string_sweep + send.str();
   string_sweep = string_sweep + ", ";
   string_sweep = string_sweep + ssteps.str();
   string_sweep = string_sweep + ", ";
   string_sweep = string_sweep + sdelay.str();

   string_limit = "SOUR:VOLT:ILIM ";
   string_limit = string_limit +slimit.str();

   string_vrange ="SOUR:VOLT:RANG ";
   string_vrange = string_vrange + svrange.str();

   string_crange ="SENS:CURR:RANG ";
   string_crange =string_crange + scrange.str();


    Send("*RST");
    Send("SOUR:FUNC VOLT");
    Send(string_vrange);    //Voltage Range einstellen
    Send(string_limit);
    Send("SENS:FUNC 'CURR'");
    Send(string_crange);    //Current Range einstellen
    //Send("SOUR:SWE:VOLT:LIN 0, 2, 100, 0.002");
    Send(string_sweep);
    Send("TRIGGER:LOAD 'Empty'");
    Send("TRIGGER:BLOCK:BUFFER:CLEAR 1");
    Send("TRIGGER:BLOCK:CONFIG:RECALL 2, 'VoltLinearSweepList'");
    Send("TRIGGER:BLOCK:SOURCE:STATE 3, 1");
    Send("TRIGGER:BLOCK:BRANCH:ALWAYS 4, 6");
    Send("TRIGGER:BLOCK:CONFIG:NEXT 5, 'VoltLinearSweepList'");


    Send(string_delay);
    Send("TRIGGER:BLOCK:BRANCH:COUNTER 7, 100, 5");
    Send("TRIGGER:BLOCK:BRANCH:ALWAYS 8,2");
    Send("TRIGGER:BLOCK:LIST?");
    Send("INITIATE");
}

//Stiller 26.04.2019 Testrrampe
double TGPIB_Keithley246X::CSweep(double &delay, double &steps, double &start, double &end, double &limit, double &crange, double &vrange)
{
   std::string string_delay;	//lokale Variable für delay
   std::string string_sweep;	//lokale Variable für sweep
   std::string string_limit;
   std::string string_crange;
   std::string string_vrange;

   std::stringstream sdelay;
   std::stringstream ssteps;
   std::stringstream sstart;
   std::stringstream send;
   std::stringstream slimit;
   std::stringstream scrange;
   std::stringstream svrange;

   send << end;
   sdelay << delay;
   sstart << start;
   ssteps << steps;
   slimit << limit;
   scrange << crange;
   svrange << vrange;

   //Define Delay
   string_delay = "TRIGGER:BLOCK:DELAY:CONSTANT 6, ";
   string_delay = string_delay + sdelay.str();

   //Define Sweep
   string_sweep = "SOUR:SWE:CURR:LIN ";
   string_sweep = string_sweep + sstart.str();
   string_sweep = string_sweep + ", ";
   string_sweep = string_sweep + send.str();
   string_sweep = string_sweep + ", ";
   string_sweep = string_sweep + ssteps.str();
   string_sweep = string_sweep + ", ";
   string_sweep = string_sweep + sdelay.str();

   string_limit = "SOUR:CURR:VLIM ";
   string_limit = string_limit +slimit.str();

   string_crange= "SOUR:CURR:RANG ";
   string_crange = string_crange + scrange.str();

   string_vrange= "SENS:Volt:RANG ";
   string_vrange = string_vrange + svrange.str();

    Send("*RST");
    Send("SOUR:FUNC CURR");
    Send(string_crange); //Current Range einstellen
    Send(string_limit);
    Send("SENS:FUNC 'Volt'");
    Send(string_vrange); //Voltage Range einstellen
    Send(string_sweep);
    Send("TRIGGER:LOAD 'Empty'");
    Send("TRIGGER:BLOCK:BUFFER:CLEAR 1");
    Send("TRIGGER:BLOCK:CONFIG:RECALL 2, 'CurrLinearSweepList'");
    Send("TRIGGER:BLOCK:SOURCE:STATE 3, 1");
    Send("TRIGGER:BLOCK:BRANCH:ALWAYS 4, 6");
    Send("TRIGGER:BLOCK:CONFIG:NEXT 5, 'CurrLinearSweepList'");


    Send(string_delay);
    Send("TRIGGER:BLOCK:BRANCH:COUNTER 7, 100, 5");
    Send("TRIGGER:BLOCK:BRANCH:ALWAYS 8,2");
    Send("TRIGGER:BLOCK:LIST?");
    Send("INITIATE");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

