#include "fhdo_usb_interface.h"
#include <QCoreApplication>
#include <iostream>
#include <string>
#include "QString"
#include <QFile>
#include "qfile.h"
#include <QDebug>
#include <QTextStream>
#include <vector>

using namespace std;




USB_Interface::USB_Interface()
{
}

USB_Interface::~USB_Interface()
{
}

QString USB_Interface::identify(QString SerNr)                                             //Mit der identify-Funktion werden die soll die USB-Stelle der
{
        QString IDNdata = "/dev/usbtmc";                                                    //Pfad wird als String abgelegt
        QStringList list;
        QString device;                                                                     //Liste mit String für die einzelnden IDs


   //**Weitere Multimeter hier bitte ergänzen**//
        //DMM6500.insert(0, "04408210");                        //Die Variable aus der Qlist von DMM6500 bekommt Seriennummer eines Multimeters Zugewiesen
        //DMM6500.insert(1, "04407708");                        //insert:Fügt den Wert an der Indexposition i in die Liste ein.
        //DMM6500.insert(2, "04408214");                        //d.h.links die Zahl zeigt an welcher Stelle der String bei list ist(Indexposition). Rechts ist die Stringzuweisung


       for(int i=0;i<MAXDEVICE_USB;i++)                                                             //Schleife überprüft ob und welche Geräte angeschlossen sind
       {
           list.append(IDNdata + QString::number(i));                                    //Die Laufvariable i als String, wird an den String IDNdata angehängt
                                                                                         //das ganze wird dann als Strings in List abgespeichert
           QFile DC1data(list.at(i));                                                    //File-Datei mit dem Pfad aus list wird geöffnet
            {
             if (DC1data.exists(list.at(i)))                                             //vor Schleifendurchlauf soll erst überprüft werden, ob überhaupt ein Gerät angeschlossen
               {                                                                         //ein Gerät angeschlossen ist. Falls nicht der Fall -> Schleife wird terminiert

                if (DC1data.open(QIODevice::WriteOnly))
                {

                    QTextStream out(&DC1data);                                             //Befehl ID-Abfrage wird dem Gerät zugesendet/geschrieben
                    out <<"*IDN?\r\n";
                    DC1data.close();

                }
               }

              }

           QFile DC2data(list.at(i));
            {
             if (DC2data.exists(list.at(i)))
               {

                if (DC2data.open(QIODevice::ReadOnly))                                     //Der Befehl vom Gerät soll ausgelesen werden
                {

                    QString line = DC2data.readLine();                                     //List = Aufzählung von usb-Stellen
                    QStringList listSplited = line.split(',');                             //Der String mit dem ID, wird nach Kommer gesplitet und nur die Serienummer wird aufgenommen


                               if(SerNr==listSplited.at(2))                                //Hier wird die Seriennummer dem Inhalt der Variable listSplited verglichen
                               {                                                           //die IDs werden überprüft, ob sie übereinstimmen
                                 //qDebug() <<"\r"<< SerNr;
                                 device = "/dev/usbtmc" + QString::number(i);              //Zusätzlicher QString wird erzeugt. Die USB-Stelle wird zugewiesen.
                                 break;                                                    //USB-Stelle,dh. der Pfad wird abgespeicher
                                                                                            //
                                }

                          DC2data.close();



                    }


              }
             }

       }


       return device;                                                                       //Der Pfad der entsprechenden Geräte wird zurückgegeben

}


void USB_Interface::Send(QString SerNr, QString Msg)                                   //Die Funktion send sendet nur den Befehl an das angeschlossene Gerät
{
               QString device;
               device = identify(SerNr);

               QFile Pfad1(device);
               {
                   if(!Pfad1.exists(device))
                   {
                       qDebug()<< "Komunikation abgebrochen oder Gerät nicht angeschlossen\r\n";
                   }

                  else
                      {
               QFile Pfad2(device);                                     //QFile zum öffnen des Pfades
               {
                   if (Pfad2.open(QIODevice::WriteOnly))
                   {
                       QTextStream out(&Pfad2);
                       out<<Msg;
                       Pfad2.close();
                   }
               }
                      }
               }
}



QString USB_Interface::SendAndReceive(QString SerNr, QString Msg)
{
               QString device;
               QString Result;

               device = identify(SerNr);

       QFile Pfad1(device);
       {
                   if(!Pfad1.exists(device))
                   {
                       qDebug()<< "Komunikation abgebrochen oder Gerät nicht angeschlossen\r\n";
                   }


               else {
               QFile Pfad2(device);                                     //QFile zum öffnen des Pfades
               {
                   if (Pfad2.open(QIODevice::WriteOnly))
                   {
                       QTextStream out(&Pfad2);
                       out<<Msg;
                       Pfad2.close();
                   }
               }


               QFile Pfad3(device);
               {
                   if(Pfad3.open(QIODevice::ReadOnly))
                   {
                       Result = Pfad3.readLine();
                       Pfad3.close();

                   }
               }
                          }

       }
               return Result;
}

void USB_Interface::ErrorMsg(QString SerNr, QString Msg)
{
    QString error = identify(SerNr);

    if(error.length()==0)
    {
        qDebug()<<"No device with this serialnumber ";
    }

}
