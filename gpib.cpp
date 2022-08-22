/* KARL MACHA/ Bachelorthesis/ Sommersemester 2017/ Fachhochschule Dortmund
 * In diesem Programm wird die Grapgische Oberfläche in gpib.ui codiert. Die einzelnen Elemente sind mit Name und einer
 *  Endung des Widgets hinterlegt. Beispielsweise könnte ein PushButton, mit welchem das Programm beendet wird ClosePB heißen.
 * Den Code kann man den Memberfunktions entnehmen.
*/

//Eingebundene Bibliotheken für das GUI
#include "gpib.h"          //Einbidung des Headers vom der Klasse GPIB
#include "ui_gpib.h"       //Verknüpfung mit dem UserInterface
#include "QString"         //Einbidung von QString, um den Datentyp String nutzen zu können
#include "qvector.h"       //Bibliothek, mit  welcher der Datentyp Vektor eingebunden wird
#include "qfile.h"         //Hiermit kann der Datentyp File eingelesen und kopiert werden
#include <QTime>           //Stadartfunktion, um mit der aktuellen Zeit und Datum arbeiten zu können
#include "qcolor.h"
#include "qwt_plot.h"      // Ermöglicht die Einbindung von QWT-Plot Widgets
#include "qwt_plot_curve.h"     //Ermöglicht die Erstellung von Kurven im Zusammenhang mit Zahlenwerten
#include "qwt_plot_grid.h"      //Bindet das Tool ein, mit welchem Raster für Diagramme entwickelt werden können
#include "SILIB_GPIB_Interfaces.h"  //Einbindung des GPIB Adapters und die Nutzung mit einem Interface
#include "SILIB_GPIB_Device.h"      //Einbidung des GPIB- Adapters
#include "Silib_GPIB_Keithley2000.h"    //Einbidung des Multimeters Keithley 2000
#include "Silib_GPIB_Keithley24xx.h"    //Einbidung des Sourcemeters Keithley 2401
#include "sldo65.h"                     //Einbindung der Funktionen aus SLDO65

#include "Silib_GPIB_Keithley246x.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include "testboard.h"

#include "fhdo_usb_interface.h"
#include "fhdo_usb_device.h"
#include "fhdo_usb_keithleydmm6500.h"

// Für das UserInterface (UI) zu erzeugende Objekte zusammen mit den zugehörigen Destruktoren

gpib::gpib(QWidget *parent) ://Constructor
    QMainWindow(parent),
    ui(new Ui::gpib)
{
    ui->setupUi(this);
    z = new sldo65();
}

gpib::~gpib() //Destructor
{
    delete ui;
    delete z;
}


void gpib::on_start_button_clicked()
{
    double a1,a2,a3,a4,a5,a6,a7;
    QString y1,y2,y3,y4,y5,y6,y7;

    double s, e, st, r1,r2,r3,r4,r5,r6,r7,r8,r9, delay,limit,crange,vrange;                                      //Die verwendeten reelen Zahlen vom Typ Double
    int i;
    std::vector<double> a, h1,h2,h3,h4,h5,h6,h7,h8,h9;                                //Deklaration der Vektoren: In b wird der Vektor mit Messwerten gefüllt, in h1 und h2 werden zwei Vektoren für die Zeichung der Kurve erstellt
    QString x1,x2,x3,x4,x5,x6,x7,x8,x9,y,x,w,g,notiz;                                 // Stiller Notiz eingefügt //Deklaration der Benötigten String Dateien
    QString ch_name_16,ch_name_17,ch_name_18,ch_name_19,ch_name_20,ch_name_21,ch_name_22,names;    //Zorn Kanalnamen eingefügt //Ausgaben der Multimeter
    QwtPlotCurve series1,series2,series3,series4,series5,series6,series7,series8;                                        //Deklaration der Kurve für das Diagramm
    QwtPlotGrid raster;                                          //Deklaration des Rasters für das Diagramm

    if (ui->cb_test_mult->isChecked())
    {       a1 = z->testvoltage();
            a2 = z->testvoltage2();
            a3 = z->testvoltage3();
            a4 = z->testvoltage4();
            a5 = z->testvoltage5();
            a6 = z->testvoltage6();
            a7 = z->testvoltage7();

            y1= QString::number(a1);
            y2= QString::number(a2);
            y3= QString::number(a3);
            y4= QString::number(a4);
            y5= QString::number(a5);
            y6= QString::number(a6);
            y7= QString::number(a7);


            ui->outkeith->setText(y1);
            ui->outkeith2->setText(y2);
            ui->outkeith3->setText(y3);
            ui->outkeith4->setText(y4);
            ui->outkeith5->setText(y5);
            ui->outkeith6->setText(y6);
            ui->outkeith7->setText(y7);
     }
    else if (ui->cb_loadreg->isChecked() || ui-> cb_linereg_curr ->isChecked() || ui-> cb_linereg_vol ->isChecked())
    {

        raster.setPen(Qt::gray);                            //Setzt die Farbe des Rasters in Grau
        raster.attach(ui->plot);                            //Einfügen der Raster im Diagramm
        //Deklaration der Eingaben
        s= ui->startLE->text().toDouble();            //Startwert der Messung
        e=ui->endLE->text().toDouble();               //Endwert der Messung
        st=ui->stepLE->text().toDouble();             //Schrittweite der Messung
        limit=ui->limitLE->text().toDouble();
        w= ui->n->text();                             //Name für das File muss hier im ui eingetippt werden (Name.txt)


        if (ui->cb_loadreg->isChecked())
        {
            ui->plot->setAxisTitle(QwtPlot::xBottom, "I(A)");   //Beschriftung der X-Achse mit I für Strom
            ui->plot->setAxisTitle(QwtPlot::yLeft, "U(V)");     //Bechriftung der Y-Achse mit U für Spannung
          if (ui->cb_k2400->isChecked())
          {
             a=z->loadreg(s, e, st, limit);                        //K2400 //per Memberfunktion loadreg von z(code in sldo65.cpp) soll der Vector b für die Ausgabe im UI erstellt werden
          }
          else
          {
             a=z->loadreg2460(s, e, st, limit);                       //K2460 //per Memberfunktion loadreg von z(code in sldo65.cpp) soll der Vector b für die Ausgabe im UI erstellt werden
          }
         }
        else if(ui-> cb_linereg_curr ->isChecked())
        {
            ui->plot->setAxisTitle(QwtPlot::xBottom, "I(A)");            //Beschriftung der X-Achse mit I für Strom
            ui->plot->setAxisTitle(QwtPlot::yLeft, "U(V)");              //Bechriftung der Y-Achse mit U für Spannung

            if (ui->cb_k2400->isChecked())
            {
                 a=z->lineregcur(s, e, st, limit);                              //K2400 //per Memberfunktion lineregcur von z(code in sldo65.cpp) soll der Vector b für die Ausgabe im UI erstellt werden
            }
            else
            {
                 a=z->lineregcur2460(s, e, st,limit);                             //K2460 //per Memberfunktion lineregcur von z(code in sldo65.cpp) soll der Vector b für die Ausgabe im UI erstellt werden
            }
        }
        else if(ui-> cb_linereg_vol ->isChecked())
        {
            ui->plot->setAxisTitle(QwtPlot::xBottom, "Uin(V)");             //Beschriftung der X-Achse mit U für Spannung
            ui->plot->setAxisTitle(QwtPlot::yLeft, "Uout(V)");              //Stiller Spannugnen Bechriftung der Y-Achse

            if (ui->cb_k2400->isChecked())
            {
               a=z->lineregvol(s, e, st,limit);   //Stiller K2400//per Memberfunktion lineregvol von z(code in sldo65.cpp) soll der Vector a für die Ausgabe im UI erstellt werden
            }
            else
            {
               a=z->lineregvol2460(s, e, st,limit);  //Stiller K2460 //per Memberfunktion lineregvol von z(code in sldo65.cpp) soll der Vector a für die Ausgabe im UI erstellt werden
            }
        }




          for (i=0; i<a.size()+1; i=i+8)                    //Stiller Änderung von i<a.size() da sonst letzter Wert in Diagramm fehlte //Schleifendurchlauf für die Erstellung der Ausgabe, des Graphes sowie der Hinterlegung in einer Datei
          {
            r1=a[i];                                        //r1-r5 sind Hilfvariablen, welchen die einzelnen Werte des Vektors a zugewiesen werden, um diese später bei x1, x2 in einen String zu konvertieren
            r2=a[i+1];
            r3=a[i+2];
            r4=a[i+3];
            r5=a[i+4];
            r6=a[i+5];
            r7=a[i+6];
            r8=a[i+7];

            h1.push_back(a[i]);                             //h1, h2 sind die Vektoren für das Diagramm, welche den Verlauf des Graphen angeben. Denen werden die einzelnen Werte von a zugewiesen
            h2.push_back(a[i+1]);                           //Bsp: a[0]=h1[0], a[1]=h2[0],usw.
            h3.push_back(a[i+2]);
            h4.push_back(a[i+3]);
            h5.push_back(a[i+4]);
            h6.push_back(a[i+5]);
            h7.push_back(a[i+6]);
            h8.push_back(a[i+7]);

            x1=QString::number(r1);                         //Umwandlung der Variablen r1,r2 in eine QSTRingvariable x1,x2
            x2=QString::number(r2);
            x3=QString::number(r3);
            x4=QString::number(r4);
            x5=QString::number(r5);
            x6=QString::number(r6);
            x7=QString::number(r7);
            x8=QString::number(r8);
            x=x1+"\t"+x2;                                   //Addition der Strings x1-x5 in x um die Ausgabe durchzuführen
            x=x+"\t"+x3;
            x=x+"\t"+x4;
            x=x+"\t"+x5;
            x=x+"\t"+x6;
            x=x+"\t"+x7;
            x=x+"\t"+x8;

            if((ui-> cb_linereg_curr ->isChecked()) && (!(ui->cb_k2400->isChecked())))// only executed when reference current measuremen is activated
            {
             r9=a[i+8];
             h9.push_back(a[i+8]);
             x9=QString::number(r9);
             x=x+"\t"+x9;
             series1.setRawSamples(&h1[0],&h2[0],i/9);       //die Kurve series1 wird gezeichnet
             series2.setRawSamples(&h1[0],&h3[0],i/9);
             series3.setRawSamples(&h1[0],&h4[0],i/9);
             series4.setRawSamples(&h1[0],&h5[0],i/9);
             series5.setRawSamples(&h1[0],&h6[0],i/9);
             series6.setRawSamples(&h1[0],&h7[0],i/9);
             series7.setRawSamples(&h1[0],&h8[0],i/9);
             series8.setRawSamples(&h1[0],&h9[0],i/9);
             i=i+1;
            }
            else
            {
             series1.setRawSamples(&h1[0],&h2[0],i/8);       //die Kurve series1 wird gezeichnet
             series2.setRawSamples(&h1[0],&h3[0],i/8);
             series3.setRawSamples(&h1[0],&h4[0],i/8);
             series4.setRawSamples(&h1[0],&h5[0],i/8);
             series5.setRawSamples(&h1[0],&h6[0],i/8);
             series6.setRawSamples(&h1[0],&h7[0],i/8);
             series7.setRawSamples(&h1[0],&h8[0],i/8);
            }

            if(i<a.size())                                  //Stiller ansonsten wird ein Wert zuviel ausgegeben
            {

            g=g+x+"\n";                                    // g ist der String, welcher die Ausgabe für die gesamten Messswerte für das File Speichert
            }


          };
          series1.setPen(Qt::blue);                           //Setzt die Linie der Kurve series1 in die Farbe Blau
          series2.setPen(Qt::red);                            //Setzt die Linie der Kurve series1 in die Farbe Rot
          series3.setPen(Qt::green);                          //Setzt die Linie der Kurve series1 in die Farbe Grünün
          series4.setPen(Qt::black);                         //Setzt die Linie der Kurve series1 in die Farbe Gelb
          series5.setPen(Qt::darkYellow);
          series6.setPen(Qt::darkMagenta);
          series7.setPen(Qt::darkCyan);

        series1.attach(ui->plot);                           //Die Kurven werden in das Diagramm Plot eingefügt
        series2.attach(ui->plot);
        series3.attach(ui->plot);
        series4.attach(ui->plot);
        series5.attach(ui->plot);
        series6.attach(ui->plot);
        series7.attach(ui->plot);

        if((ui-> cb_linereg_curr ->isChecked()) && !(ui->cb_k2400->isChecked())) // only executed when reference current measuremen is activated
        {
         series8.setPen(Qt::darkGreen);
         series7.attach(ui->plot);
        }

         ui->plot->replot();                                //Die Kurve wird im Plot eingezeichnet

         this->repaint();

             notiz= ui->Notiz_LE->text();                       //Stiller: Auslesen des Notizfeldes und speichern in Variable notiz
             ch_name_16 = ui->channel_names_le_16->text();               //Stiller: Auslesen der Kanalnamen Variable 16
             ch_name_17 = ui->channel_names_le_17->text();               //Stiller: Auslesen der Kanalnamen Variable 17
             ch_name_18 = ui->channel_names_le_18->text();               //Stiller: Auslesen der Kanalnamen Variable 18
             ch_name_19 = ui->channel_names_le_19->text();               //Stiller: Auslesen der Kanalnamen Variable 19
             ch_name_20 = ui->channel_names_le_20->text();               //Stiller: Auslesen der Kanalnamen Variable 20
             ch_name_21 = ui->channel_names_le_21->text();               //Stiller: Auslesen der Kanalnamen Variable 21
             ch_name_22 = ui->channel_names_le_22->text();               //Stiller: Auslesen der Kanalnamen Variable 22

             names=ch_name_16+"\t"+ch_name_17;                           //Addition der Strings der Kanalnamen
             names=names+"\t"+ch_name_18;
             names=names+"\t"+ch_name_19;
             names=names+"\t"+ch_name_20;
             names=names+"\t"+ch_name_21;
             names=names+"\t"+ch_name_22;

             QFile data(w);                                 //Eine *.txt wird mit dem Namen aus dem String w (Z.214) erstellt
               {
                 //for writing line by line to text file
                 if (data.open(QIODevice::WriteOnly | QIODevice::Append))
                 {
                     QTextStream out(&data);                            //In der Variable out werden die *FILE Ausgaben gespeichert

                     if (ui->cb_loadreg->isChecked())
                     {
                     out << "Load Regulation ";                         //Load Reg wird im *File hinterlegt
                      }
                     else if(ui-> cb_linereg_curr ->isChecked())
                     {
                     out << "Line Regulation Current ";                         //Line Reg Cur wird im *File hinterlegt
                     }
                     else if(ui-> cb_linereg_vol ->isChecked())
                     {
                     out << "Line Regulation Voltage ";                         //Line Reg Volwird im *File hinterlegt
                     }



                     //Stiller Anmerken welche SMU läuft
                     if (ui->cb_k2400->isChecked())
                     {
                         out << "using Keithley 2400 ";
                     }
                     else
                     {
                         out << "using Keithley 2460 ";
                     }
                     out << QTime::currentTime().toString();            //Uhrzeit der Messung wird in der Datei hinterlegt
                     out << " ";                                        //Tabulatorleerschritt wird im file hinterlegt
                     out << QDate::currentDate().toString() << endl;    //Datum der Messung wird in der Datei hinterlegt
                     out << "" << endl;
                     out << notiz << endl;                              //Stiller : Ausgabe der Notiz aus der GUI im Logfile für Anmerkungen was gerade gemessen wird.
                     out << "" << endl;

                     if (ui->cb_loadreg->isChecked())
                     {

                     out << "I(A)\t" + names << endl;                   //Stiller : Ausgabe Loadreg
                      }
                     else if(ui-> cb_linereg_curr ->isChecked())
                     {
                     out << "I(A)\t" + names << endl;                   //Stiller : Ausgabe LineReg Current
                     }
                     else if(ui-> cb_linereg_vol ->isChecked())
                     {
                     out << "U(V)\t" + names << endl;                   //Stiller : Ausgabe Line Reg Voltage
                     }

                     out << g <<endl;                                   //Die Messwerte werden in der Datei hinterlegt
                     data.close();                                      //Die Datei wird geschlossen
                 }
                 }
    }

     else if (ui->cb_start_ramp->isChecked())
    {


        s= ui->ramp_start_le->text().toDouble();            //Startwert der Rampe
        e=ui->ramp_end_le->text().toDouble();               //Endwert der Rampe
        st=ui->ramp_step_le->text().toDouble();             //Schritte der Rampe
        delay=ui->ramp_delay_le->text().toDouble();         //Delay zwischen den Rampen
        limit=ui->limitLE->text().toDouble();
        crange=ui->crangeLE->text().toDouble();
        vrange=ui->vrangeLE->text().toDouble();

        if (ui->cb_ramp_current->isChecked())
        {
            double res;
            res=z->CSweep(delay, st, s, e, limit, crange, vrange);

        }
        else if (ui->cb_ramp_voltage->isChecked())
        {
            double res;
            res=z->VSweep(delay, st, s, e, limit, crange, vrange);
        }
    }
    else if (ui->cb_stop_ramp->isChecked())
    {
        double res;
        res=z->StopSweep();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Bitte wählen Sie einen Test aus!");
        msgBox.exec();
    }
}

void gpib::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Testsoftware for SLDO characterization. Created by M.Eng. Andreas Stiller. Dortmund 2017-2019. Special thanks to B.Eng. Karl Macha and B.Eng. Jendrik Zorn for helping improve the software.");
    msgBox.exec();
}

void gpib::on_actionExit_triggered()
{
    this->close();
}

void gpib::on_actionOpen_triggered()
{
    QString str_fileName = QFileDialog::getOpenFileName(this,tr("Select Simulation Data"),"/",tr("All (*)"));
    QFileInfo fileNameInfo (str_fileName);

    QString str_fileName_short = fileNameInfo.fileName();          // returns filename
    QString str_absoluteFilePath = fileNameInfo.absoluteFilePath();   // returns path

    ui->n->setText(str_fileName);
}

void gpib::on_actionTestchips_triggered() //neues UI soll angezeigt werden mit Testchip A-Eigenschaften
{
       testboard =new TestBoard(this);
       testboard->show();
}


//Buttomabfragen ab hier, damit nie mehr als ein Button geklickt ist

void gpib::on_cb_k2400_clicked()
{
    if (ui->cb_k2400->isChecked())
    {
       ui->cb_k2460->setChecked(0);
    }
    else
    {
       ui->cb_k2460->setChecked(1);
    }
}

void gpib::on_cb_k2460_clicked()
{
    if (ui->cb_k2460->isChecked())
    {
       ui->cb_k2400->setChecked(0);
    }
    else
    {
       ui->cb_k2400->setChecked(1);
    }
}



void gpib::on_cb_ramp_current_clicked()
{
    if (ui->cb_ramp_current->isChecked())
    {
       ui->cb_ramp_voltage->setChecked(0);
    }
    else
    {
       ui->cb_ramp_voltage->setChecked(1);
    }
}


void gpib::on_cb_ramp_voltage_clicked()
{
    if (ui->cb_ramp_voltage->isChecked())
    {
       ui->cb_ramp_current->setChecked(0);
    }
    else
    {
       ui->cb_ramp_current->setChecked(1);
    }
}


void gpib::on_cb_linereg_vol_clicked()
{
    if (ui->cb_linereg_vol->isChecked())
    {
       ui->cb_linereg_curr->setChecked(0);
       ui->cb_start_ramp->setChecked(0);
       ui->cb_test_mult->setChecked(0);
       ui->cb_loadreg->setChecked(0);
       ui->cb_stop_ramp->setChecked(0);

	//Sweep Felder aktivieren       
	ui->startLE->setEnabled(1);
       ui->endLE->setEnabled(1);
       ui->stepLE->setEnabled(1);
       ui->cb_k2460->setEnabled(1);
	ui->cb_k2400->setEnabled(1);
	ui->label_9->setEnabled(1);
	ui->label_29->setEnabled(1);
	ui->label->setEnabled(1);
	ui->label_2->setEnabled(1);
	ui->label_3->setEnabled(1);

	//Ramp Felder deaktivieren

	ui->label_23->setDisabled(1);
	ui->label_28->setDisabled(1);
	ui->label_24->setDisabled(1);
	ui->label_27->setDisabled(1);
	ui->label_26->setDisabled(1);
	ui->label_25->setDisabled(1);
	ui->cb_ramp_current->setDisabled(1);
	ui->cb_ramp_voltage->setDisabled(1);
	ui->ramp_delay_le->setDisabled(1);
	ui->ramp_step_le->setDisabled(1);
	ui->ramp_start_le->setDisabled(1);
    ui->ramp_end_le->setDisabled(1);
    }

}

void gpib::on_cb_linereg_curr_clicked()
{
    if (ui->cb_linereg_curr->isChecked())
    {
       ui->cb_linereg_vol->setChecked(0);
       ui->cb_start_ramp->setChecked(0);
       ui->cb_test_mult->setChecked(0);
       ui->cb_loadreg->setChecked(0);
       ui->cb_stop_ramp->setChecked(0);


	//Sweep Felder aktivieren       
	ui->startLE->setEnabled(1);
       ui->endLE->setEnabled(1);
       ui->stepLE->setEnabled(1);
       ui->cb_k2460->setEnabled(1);
	ui->cb_k2400->setEnabled(1);
	ui->label_9->setEnabled(1);
	ui->label_29->setEnabled(1);
	ui->label->setEnabled(1);
	ui->label_2->setEnabled(1);
	ui->label_3->setEnabled(1);

	//Ramp Felder deaktivieren

	ui->label_23->setDisabled(1);
	ui->label_28->setDisabled(1);
	ui->label_24->setDisabled(1);
	ui->label_27->setDisabled(1);
	ui->label_26->setDisabled(1);
	ui->label_25->setDisabled(1);
	ui->cb_ramp_current->setDisabled(1);
	ui->cb_ramp_voltage->setDisabled(1);
	ui->ramp_delay_le->setDisabled(1);
	ui->ramp_step_le->setDisabled(1);
	ui->ramp_start_le->setDisabled(1);
	ui->ramp_end_le->setDisabled(1);
    }
}

void gpib::on_cb_start_ramp_clicked()
{
    if (ui->cb_start_ramp->isChecked())
    {
       ui->cb_linereg_vol->setChecked(0);
       ui->cb_linereg_curr->setChecked(0);
       ui->cb_test_mult->setChecked(0);
       ui->cb_loadreg->setChecked(0);
       ui->cb_stop_ramp->setChecked(0);;

	//Sweep Felder deaktivieren       
	ui->startLE->setDisabled(1);
       ui->endLE->setDisabled(1);
       ui->stepLE->setDisabled(1);
       ui->cb_k2460->setDisabled(1);
	ui->cb_k2400->setDisabled(1);
	ui->label_9->setDisabled(1);
	ui->label_29->setDisabled(1);
	ui->label->setDisabled(1);
	ui->label_2->setDisabled(1);
	ui->label_3->setDisabled(1);

	//Ramp Felder aktivieren

	ui->label_23->setEnabled(1);
	ui->label_28->setEnabled(1);
	ui->label_24->setEnabled(1);
	ui->label_27->setEnabled(1);
	ui->label_26->setEnabled(1);
	ui->label_25->setEnabled(1);
	ui->cb_ramp_current->setEnabled(1);
	ui->cb_ramp_voltage->setEnabled(1);
	ui->ramp_delay_le->setEnabled(1);
	ui->ramp_step_le->setEnabled(1);
	ui->ramp_start_le->setEnabled(1);
	ui->ramp_end_le->setEnabled(1);



    }
}

void gpib::on_cb_test_mult_clicked()
{
    if (ui->cb_test_mult->isChecked())
    {
       ui->cb_linereg_vol->setChecked(0);
       ui->cb_linereg_curr->setChecked(0);
       ui->cb_start_ramp->setChecked(0);
       ui->cb_loadreg->setChecked(0);
       ui->cb_stop_ramp->setChecked(0);;

	//Sweep Felder deaktivieren       
	ui->startLE->setDisabled(1);
       ui->endLE->setDisabled(1);
       ui->stepLE->setDisabled(1);
       ui->cb_k2460->setDisabled(1);
	ui->cb_k2400->setDisabled(1);
	ui->label_9->setDisabled(1);
	ui->label_29->setDisabled(1);
	ui->label->setDisabled(1);
	ui->label_2->setDisabled(1);
	ui->label_3->setDisabled(1);

	//Ramp Felder deaktivieren

	ui->label_23->setDisabled(1);
	ui->label_28->setDisabled(1);
	ui->label_24->setDisabled(1);
	ui->label_27->setDisabled(1);
	ui->label_26->setDisabled(1);
	ui->label_25->setDisabled(1);
	ui->cb_ramp_current->setDisabled(1);
	ui->cb_ramp_voltage->setDisabled(1);
	ui->ramp_delay_le->setDisabled(1);
	ui->ramp_step_le->setDisabled(1);
	ui->ramp_start_le->setDisabled(1);
    ui->ramp_end_le->setDisabled(1);
    }
}

void gpib::on_cb_loadreg_clicked()
{
    if (ui->cb_loadreg->isChecked())
    {
       ui->cb_linereg_vol->setChecked(0);
       ui->cb_linereg_curr->setChecked(0);
       ui->cb_start_ramp->setChecked(0);
       ui->cb_test_mult->setChecked(0);
       ui->cb_stop_ramp->setChecked(0);

	//Sweep Felder aktivieren       
    ui->startLE->setEnabled(1);
       ui->endLE->setEnabled(1);
       ui->stepLE->setEnabled(1);

       ui->cb_k2460->setEnabled(1);
    ui->cb_k2400->setEnabled(1);
    ui->label_9->setEnabled(1);
    ui->label_29->setEnabled(1);
    ui->label->setEnabled(1);
    ui->label_2->setEnabled(1);
    ui->label_3->setEnabled(1);

	//Ramp Felder deaktivieren

    ui->label_23->setDisabled(1);
    ui->label_28->setDisabled(1);
    ui->label_24->setDisabled(1);
    ui->label_27->setDisabled(1);
    ui->label_26->setDisabled(1);
    ui->label_25->setDisabled(1);
    ui->cb_ramp_current->setDisabled(1);
    ui->cb_ramp_voltage->setDisabled(1);
    ui->ramp_delay_le->setDisabled(1);
    ui->ramp_step_le->setDisabled(1);
    ui->ramp_start_le->setDisabled(1);
    ui->ramp_end_le->setDisabled(1);
    }
}

void gpib::on_cb_stop_ramp_clicked()
{
    if (ui->cb_stop_ramp->isChecked())
    {
       ui->cb_linereg_vol->setChecked(0);
       ui->cb_linereg_curr->setChecked(0);
       ui->cb_test_mult->setChecked(0);
       ui->cb_loadreg->setChecked(0);
       ui->cb_start_ramp->setChecked(0);

    //Sweep Felder deaktivieren
    ui->startLE->setDisabled(1);
       ui->endLE->setDisabled(1);
       ui->stepLE->setDisabled(1);

       ui->cb_k2460->setDisabled(1);
    ui->cb_k2400->setDisabled(1);
    ui->label_9->setDisabled(1);
    ui->label_29->setDisabled(1);
    ui->label->setDisabled(1);
    ui->label_2->setDisabled(1);
    ui->label_3->setDisabled(1);

    //Ramp Felder aktivieren

    ui->label_23->setEnabled(1);
    ui->label_28->setEnabled(1);
    ui->label_24->setEnabled(1);
    ui->label_27->setEnabled(1);
    ui->label_26->setEnabled(1);
    ui->label_25->setEnabled(1);
    ui->cb_ramp_current->setEnabled(1);
    ui->cb_ramp_voltage->setEnabled(1);
    ui->ramp_delay_le->setEnabled(1);
    ui->ramp_step_le->setEnabled(1);
    ui->ramp_start_le->setEnabled(1);
    ui->ramp_end_le->setEnabled(1);
    }
}
