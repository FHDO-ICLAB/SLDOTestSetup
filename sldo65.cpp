//============================================================================
// Name        : sldo65.cpp
// Author      : Michael Karagounis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "sldo65.h"
#include "QString"
#include "qwt_plot.h"
#include "qwt_plot_curve.h"


#include "gpib.h"

using namespace std;


sldo65::sldo65 ()
{

 //Alte Multimeter mit ID, Sourcemeter und GPIB als USB_Schnittstelle
        gpib = new TGPIB_Interface_USB();

        keith = new TGPIB_Keithley2000(gpib,16);

        source = new TGPIB_Keithley240x(gpib,12);
        source3 = new TGPIB_Keithley240x(gpib,13);
        source2 = new TGPIB_Keithley246X(gpib,30);

 //Neu eingeführte Multimeter mit Seriennummer und USB als Schnittstelle

        usb = new USB_Interface();


        keith2 = new KeithleyDMM6500(usb,"04408214");
        keith3 = new KeithleyDMM6500(usb,"04407708");
        keith4 = new KeithleyDMM6500(usb,"04408210");
        keith5 = new KeithleyDMM6500(usb,"04409223");
        keith6 = new KeithleyDMM6500(usb,"04408757");
        keith7 = new KeithleyDMM6500(usb,"04408823");
        keith8 = new KeithleyDMM6500(usb,"04414122");





}
sldo65::~sldo65 ()
{
        delete keith;
        delete keith2;
        delete keith3;
        delete keith4;
        delete keith5;
        delete keith6;
        delete keith7;
        delete keith8;
        delete usb; //usb objekt muss gelöscht werden

        delete source;
        delete source2;
        delete source3;
        delete gpib;
}



//Die Memberfunctions ab hier wurden von Karl Macha entwickelt, um die graphische Oberfläche zu realisieren //Stiller: Verbesserungen jeglicher Art seither!

//Testfunction zum Überprüfen des Auslesens der Multimeter!
double sldo65::testvoltage()
{
double mv_keith1;

keith->SetSpeed(FAST);
mv_keith1=keith->MeasureVoltage();

return mv_keith1;
}

double sldo65::testvoltage2()
{
double mv_keith2;

keith2->SetSpeed(FAST);
mv_keith2=keith2->MeasureVoltage();

return mv_keith2;
}

double sldo65::testvoltage3()
{
double mv_keith3;

keith3->SetSpeed(FAST);
mv_keith3=keith3->MeasureVoltage();

return mv_keith3;
}

double sldo65::testvoltage4()
{
double mv_keith4;

keith4->SetSpeed(FAST);
mv_keith4=keith4->MeasureVoltage();

return mv_keith4;
}

double sldo65::testvoltage5()
{
double mv_keith5;

keith5->SetSpeed(FAST);
mv_keith5=keith5->MeasureVoltage();

return mv_keith5;
}

double sldo65::testvoltage6()
{
double mv_keith6;

keith6->SetSpeed(FAST);
mv_keith6=keith6->MeasureVoltage();

return mv_keith6;
}

double sldo65::testvoltage7()
{
double mv_keith7;

keith7->SetSpeed(FAST);
mv_keith7=keith7->MeasureVoltage();

return mv_keith7;
}


//Neu für Messung mit 7 Multimetern
std::vector<double> sldo65::lineregvol(double start, double stop, double step, double limit)  //k2400 // paralelle Messung mehrerer Werte
{

//Deklarationen der in dieser Memberfunction genutzten Variablen
    std::vector<double> y;
    double a,b,c,d,e,f,g,i;

 keith->SetSpeed(FAST);                 //Das Multimeter wird mit einem schnellen Abtastwert (FAST) eingeschaltet
 source->SetSpeed(MEDIUM);              // Das Sourcemeter wird mit einem mittelschnellen Abtastwert eingeschaltet
 source->SetVoltage(start,limit);          //Das Sourcemeter wird für eine Messung der Spannung geschaltet mit dem Anfangswert start in V und dem begrenzten Stromwert von 1A

    source -> SwitchOn();               //Das Sourcemeter wird eingeschaltet

  for (i=start;i<stop;i=i+step)         //Deklaration von Schleife. Für die Übergebenen Parameter start, end, step wird hier ein Messdurchlauf realisiert
   {source->SetVoltage(i,limit);          //Messwert für i wird an das Sourcemeter übergeben

      a= keith->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith auf a
      a= keith->MeasureVoltage();
      a= keith->MeasureVoltage();
      a= keith->MeasureVoltage();

      b= keith2->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith2 auf b


      c= keith3->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith3 auf c


      d= keith4->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf d


      e= keith5->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf e


      f= keith6->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf f

      g= keith7->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf g



       y.push_back(i);                  //Der momentane Wert von i wird in den Vektor y geschoben
       y.push_back(a);                  //Der momentane Wert von a wird in den Vektor y geschoben
       y.push_back(b);                  //Der momentane Wert von b wird in den Vektor y geschoben
       y.push_back(c);                  //Der momentane Wert von c wird in den Vektor y geschoben
       y.push_back(d);                  //Der momentane Wert von d wird in den Vektor y geschoben
       y.push_back(e);                  //Der momentane Wert von e wird in den Vektor y geschoben
       y.push_back(f);                  //Der momentane Wert von f wird in den Vektor y geschoben
       y.push_back(g);                  //Der momentane Wert von g wird in den Vektor y geschoben
    };
       source -> SwitchOff();          //Stiller: ausschalten
       source -> Beep();               //Beep ;)
       return y;                        //Der Vektor y wird an das Programm übergeben
};

std::vector<double> sldo65::lineregvol2460(double start, double stop, double step, double limit)  //k2460 // paralelle Messung mehrerer Werte
{

//Deklarationen der in dieser Memberfunction genutzten Variablen
    std::vector<double> y;
    double a,b,c,d,e,f,g,i;

 keith->SetSpeed(FAST);                 //Das Multimeter wird mit einem schnellen Abtastwert (FAST) eingeschaltet
 source2->SetSpeed(MEDIUM);              // Das Sourcemeter wird mit einem mittelschnellen Abtastwert eingeschaltet
 source2->SetVoltage(start,limit);          //Das Sourcemeter wird für eine Messung der Spannung geschaltet mit dem Anfangswert start in V und dem begrenzten Stromwert von 1A

    source2 -> SwitchOn();               //Das Sourcemeter wird eingeschaltet

  for (i=start;i<stop;i=i+step)         //Deklaration von Schleife. Für die Übergebenen Parameter start, end, step wird hier ein Messdurchlauf realisiert
   {source2->SetVoltage(i,limit);          //Messwert für i wird an das Sourcemeter übergeben

      a= keith->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith auf a
      a= keith->MeasureVoltage();
      a= keith->MeasureVoltage();
      a= keith->MeasureVoltage();

      b= keith2->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith2 auf b


      c= keith3->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith3 auf c


      d= keith4->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf d


      e= keith5->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith5 auf e


      f= keith6->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith6 auf f


      g= keith7->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith7 auf g



       y.push_back(i);                  //Der momentane Wert von i wird in den Vektor y geschoben
       y.push_back(a);                  //Der momentane Wert von a wird in den Vektor y geschoben
       y.push_back(b);                  //Der momentane Wert von b wird in den Vektor y geschoben
       y.push_back(c);                  //Der momentane Wert von c wird in den Vektor y geschoben
       y.push_back(d);                  //Der momentane Wert von d wird in den Vektor y geschoben
       y.push_back(e);                  //Der momentane Wert von e wird in den Vektor y geschoben
       y.push_back(f);                  //Der momentane Wert von f wird in den Vektor y geschoben
       y.push_back(g);                  //Der momentane Wert von g wird in den Vektor y geschoben
    };
       source2 -> SwitchOff();          //Stiller: ausschalten
       source2 -> Beep();               //Beep ;)
       return y;                        //Der Vektor y wird an das Programm übergeben
};

std::vector<double>sldo65::loadreg(double start,double stop,double step, double limit) //k2400
{
    std::vector<double> y;
        double a, b,c,d,e,f,g,i;

        keith->SetSpeed(FAST);
        source->SetSpeed(MEDIUM);
        source->SetCurrent(start*(-1.0),limit);       //Das Sourcemeter wird für eine Messung des Stromes geschaltet mit dem Anfangswert start in A und dem begrenzten Spannungswert von 1.2V
        source -> SwitchOn();                       //Das Sourcemeter wird eingeschaltet
       a= keith->MeasureVoltage();                 //Zuweisung dces aktuell gemessenen Spannungswert am Multimeter zu a
     for (i=start;i<stop;i=i+step)                 //Deklaration von Schleife. Für die Übergebenen Parameter start, end, step wird hier ein Messdurchlauf realisiert
     {source->SetCurrent((-1.0*i),limit);            //Das Sourcemeter wird für eine Messung des Stromes geschaltet mit dem Anfangswert start in A und dem begrenzten Spannungswert von 1.2V

         a= keith->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith auf a
         a= keith->MeasureVoltage();
         a= keith->MeasureVoltage();
         a= keith->MeasureVoltage();

         b= keith2->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith2 auf b

         c= keith3->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith3 auf c

         d= keith4->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf d


         e= keith5->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf e


         f= keith6->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf f

         g= keith7->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf g



          y.push_back(i);                  //Der momentane Wert von i wird in den Vektor y geschoben
          y.push_back(a);                  //Der momentane Wert von a wird in den Vektor y geschoben
          y.push_back(b);                  //Der momentane Wert von b wird in den Vektor y geschoben
          y.push_back(c);                  //Der momentane Wert von c wird in den Vektor y geschoben
          y.push_back(d);                  //Der momentane Wert von d wird in den Vektor y geschoben
          y.push_back(e);                  //Der momentane Wert von e wird in den Vektor y geschoben
          y.push_back(f);                  //Der momentane Wert von f wird in den Vektor y geschoben
          y.push_back(g);                  //Der momentane Wert von g wird in den Vektor y geschoben
         }
     source -> SwitchOff();          //Stiller: ausschalten
     source -> Beep();               //Beep ;)
     return y;                     //Der Vektor y wird an das Programm übergeben

};

std::vector<double>sldo65::loadreg2460(double start,double stop,double step, double limit) //k2460
{
    std::vector<double> y;
        double a, b,c,d,e,f,g,i;

        keith->SetSpeed(FAST);
        source2->SetSpeed(MEDIUM);
        source2->SetCurrent(start*(-1.0),limit);       //Das Sourcemeter wird für eine Messung des Stromes geschaltet mit dem Anfangswert start in A und dem begrenzten Spannungswert von 1.2V
        source2 -> SwitchOn();                       //Das Sourcemeter wird eingeschaltet

       a= keith->MeasureVoltage();                 //Zuweisung dces aktuell gemessenen Spannungswert am Multimeter zu a
     for (i=start;i<stop;i=i+step)                 //Deklaration von Schleife. Für die Übergebenen Parameter start, end, step wird hier ein Messdurchlauf realisiert
     {source2->SetCurrent((-1.0*i),limit);            //Das Sourcemeter wird für eine Messung des Stromes geschaltet mit dem Anfangswert start in A und dem begrenzten Spannungswert von 1.2V

         a= keith->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith auf a
         a= keith->MeasureVoltage();
         a= keith->MeasureVoltage();
         a= keith->MeasureVoltage();

         b= keith2->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith2 auf b

         c= keith3->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith3 auf c


         d= keith4->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf d


         e= keith5->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf e


         f= keith6->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf f


         g= keith7->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf g



          y.push_back(i);                  //Der momentane Wert von i wird in den Vektor y geschoben
          y.push_back(a);                  //Der momentane Wert von a wird in den Vektor y geschoben
          y.push_back(b);                  //Der momentane Wert von b wird in den Vektor y geschoben
          y.push_back(c);                  //Der momentane Wert von c wird in den Vektor y geschoben
          y.push_back(d);                  //Der momentane Wert von d wird in den Vektor y geschoben
          y.push_back(e);                  //Der momentane Wert von e wird in den Vektor y geschoben
          y.push_back(f);                  //Der momentane Wert von f wird in den Vektor y geschoben
          y.push_back(g);                  //Der momentane Wert von g wird in den Vektor y geschoben
         }
     source2 -> SwitchOff();          //Stiller: ausschalten
     source2 -> Beep();               //Beep ;)
     return y;                     //Der Vektor y wird an das Programm übergeben

};

// Memberfunction lineregcur zur Erstellung eines vectors für die Darstellung im UI
std::vector<double> sldo65::lineregcur(double start,double stop,double step, double limit)    //k2400
{
    //Deklarationen der in dieser Memberfunction genutzten Variablen
std::vector<double> y;
double  a,b,c,d,e,f,g;

keith->SetSpeed(FAST);                  //Das Multimeter wird mit einem schnellen Abtastwert (FAST) eingeschaltet
source->SetSpeed(MEDIUM);               //Das Sourcemeter wird mit einem mittelschnellen Abtastwert eingeschaltet
source->SetCurrent(start,limit);          //Das Sourcemeter wird für eine Messung des Stromes geschaltet mit dem Anfangswert start in A und dem begrenzten Spannungswert von 2.1V



source -> SwitchOn();                   //Das Sourcemeter wird eingeschaltet


for (double i=start;i<=stop;i=i+step)   //Deklaration von Schleife. Für die Übergebenen Parameter start, end, step wird hier ein Messdurchlauf realisiert
{source->SetCurrent(i,limit);             //Das Sourcemeter wird für eine Messung des Stromes geschaltet mit dem Anfangswert start in A und dem begrenzten Spannungswert von 2.1V

    a= keith->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith auf a
    a= keith->MeasureVoltage();
    a= keith->MeasureVoltage();
    a= keith->MeasureVoltage();

    b= keith2->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith2 auf b


    c= keith3->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith3 auf c

    d= keith4->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf d


    e= keith5->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf e


    f= keith6->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf f

    g= keith7->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf g



     y.push_back(i);                  //Der momentane Wert von i wird in den Vektor y geschoben
     y.push_back(a);                  //Der momentane Wert von a wird in den Vektor y geschoben
     y.push_back(b);                  //Der momentane Wert von b wird in den Vektor y geschoben
     y.push_back(c);                  //Der momentane Wert von c wird in den Vektor y geschoben
     y.push_back(d);                  //Der momentane Wert von d wird in den Vektor y geschoben
     y.push_back(e);                  //Der momentane Wert von e wird in den Vektor y geschoben
     y.push_back(f);                  //Der momentane Wert von f wird in den Vektor y geschoben
     y.push_back(g);                  //Der momentane Wert von g wird in den Vektor y geschoben
}
   source -> SwitchOff();          //Stiller: ausschalten
   source -> Beep();               //Beep ;)
   return y; //Der Vektor y wird an das Programm übergeben
};


// Memberfunction lineregcur zur Erstellung eines vectors für die Darstellung im UI
//Zusätzliche Messung des Referenzstromes

std::vector<double> sldo65::lineregcur2460(double start,double stop,double step, double limit)    //k2400
{
    //Deklarationen der in dieser Memberfunction genutzten Variablen
std::vector<double> y;
double  a,b,c,d,e,f,g,h;

keith->SetSpeed(FAST);                  //Das Multimeter wird mit einem schnellen Abtastwert (FAST) eingeschaltet
source2->SetSpeed(MEDIUM);               //Das Sourcemeter wird mit einem mittelschnellen Abtastwert eingeschaltet
source2->SetCurrent(start,limit);          //Das Sourcemeter wird für eine Messung des Stromes geschaltet mit dem Anfangswert start in A und dem begrenzten Spannungswert von 2.1V



source2 -> SwitchOn();                   //Das Sourcemeter wird eingeschaltet


for (double i=start;i<=stop;i=i+step)   //Deklaration von Schleife. Für die Übergebenen Parameter start, end, step wird hier ein Messdurchlauf realisiert
{source2->SetCurrent(i,limit);             //Das Sourcemeter wird für eine Messung des Stromes geschaltet mit dem Anfangswert start in A und dem begrenzten Spannungswert von 2.1V

    a= keith->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith auf a
    a= keith->MeasureVoltage();
    a= keith->MeasureVoltage();
    a= keith->MeasureVoltage();

    b= keith2->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith2 auf b

    c= keith3->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith3 auf c


    d= keith4->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf d

    e= keith5->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf e

    f= keith6->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf f

    g= keith7->MeasureVoltage();       //Zuweisung des aktuell gemessenen Spannungswertes am Multimeter keith4 auf g

    h= keith8->MeasureCurrent();

     y.push_back(i);                  //Der momentane Wert von i wird in den Vektor y geschoben
     y.push_back(a);                  //Der momentane Wert von a wird in den Vektor y geschoben
     y.push_back(b);                  //Der momentane Wert von b wird in den Vektor y geschoben
     y.push_back(c);                  //Der momentane Wert von c wird in den Vektor y geschoben
     y.push_back(d);                  //Der momentane Wert von d wird in den Vektor y geschoben
     y.push_back(e);                  //Der momentane Wert von e wird in den Vektor y geschoben
     y.push_back(f);                  //Der momentane Wert von f wird in den Vektor y geschoben
     y.push_back(g);                  //Der momentane Wert von g wird in den Vektor y geschoben
     y.push_back(h);                  //Der momentane Stromwert von h wird in den Vektor y geschoben
}
   source2 -> SwitchOff();          //Stiller: ausschalten
   source2 -> Beep();               //Beep ;)
   return y; //Der Vektor y wird an das Programm übergeben
};

//Voltage Sweep Definition
double sldo65::VSweep(double delay, double steps, double start, double end, double limit, double vrange, double crange)    //k2400
{
   double r=1;
   source2 -> SwitchOff();                                //Stiller: ausschalten
   source2 -> VSweep(delay,steps,start,end, limit, vrange, crange);              //Voltage Sweep ;)
   return r;
};

//Current Sweep Definition
double sldo65::CSweep(double delay, double steps, double start, double end, double limit, double vrange, double crange)    //k2400
{
   double r=1;
   source2 -> SwitchOff();                                //Stiller: ausschalten
   source2 -> CSweep(delay,steps,start,end, limit, vrange, crange);              //Current Sweep ;)
   return r;
};

//Current Sweep Definition
double sldo65::StopSweep()    //k2400
{
   double r=1;
   source2 -> SwitchOff();                                //Stiller: ausschalten
   return r;
};
