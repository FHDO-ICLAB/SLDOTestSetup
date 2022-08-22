#ifndef SLDO65_H
#define SLDO65_H

#include <vector>
#include <iostream>
#include <string>
#include "Silib_GPIB_Keithley2000.h"
#include "Silib_GPIB_Keithley246x.h"
#include "Silib_GPIB_Keithley24xx.h"
#include "SILIB_GPIB_Interfaces.h"
#include "SILIB_GPIB_Device.h"
#include "QString"
#include "qwt_plot_curve.h"
#include "QTextEdit"

//Neueingebundene Klassen für die Multimeter DMM6500
#include "fhdo_usb_interface.h"
#include "fhdo_usb_device.h"
#include "fhdo_usb_keithleydmm6500.h"



class sldo65
{
	public:
		sldo65 ();
     ~sldo65();
		/*$PUBLIC_FUNCTIONS$*/

        //Karl Macha
        double testvoltage();
        double testvoltage2();
        double testvoltage3();
        double testvoltage4();
        double testvoltage5();
        double testvoltage6();
        double testvoltage7();

        std::vector<double> lineregvol(double start,double stop,double step, double limit);
        std::vector<double> lineregvol2460(double start,double stop,double step, double limit);
        std::vector<double> lineregcur(double start,double stop,double step, double limit);
        std::vector<double> lineregcur2460(double start,double stop,double step, double limit);
        std::vector<double> loadreg(double start,double stop,double step, double limit);
        std::vector<double> loadreg2460(double start,double stop,double step, double limit);
        double VSweep(double delay, double steps, double start, double end, double limit, double vrange, double crange);
        double CSweep(double delay, double steps, double start, double end, double limit, double vrange, double crange);
        double StopSweep();

        double vec1(double a);
        double vec2 (double a);
        // Karl Macha Ende


//    virtual void changeMode();

	protected:
		/*$PROTECTED_FUNCTIONS$*/
        void *hUSB;
        TGPIB_Interface_USB *gpib;
        TGPIB_Keithley2000 *keith;



        //Neue Geräte USB als Interface
        USB_Interface *usb;
        KeithleyDMM6500 *keith2;
        KeithleyDMM6500 *keith3;
        KeithleyDMM6500 *keith4;
        KeithleyDMM6500 *keith5;
        KeithleyDMM6500 *keith6;
        KeithleyDMM6500 *keith7;
        KeithleyDMM6500 *keith8;
        TGPIB_Keithley240x *source;
        TGPIB_Keithley246X *source2;
        TGPIB_Keithley240x *source3;


};

#endif // SLDO65_H
