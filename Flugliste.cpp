#include "Flugliste.h"
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Flugliste::Flugliste() {   
  flugEinlesen();                                                               // einlesen der Fluege
}

Flugliste::~Flugliste() {
}

void Flugliste::flugEinlesen(){   
    int i = 0;
    double preis;
    int groesse;
    string flugnummer;
    string abflug;                                                              //Deklaration der Variablen welche wir benoetigen
    string ziel;
    string datum;
    ifstream file;
    string line;
    file.open("Flugliste.txt");                                                 //Oeffnet unsere Flugliste.txt
    if(file.is_open()){                                                         //Falls Flugliste.txt offen ist
        
    file >> groesse;                                                            //Liest die erste Zahl(groesse) der Textdatei ein bzw. speichert sie in groesse ein
       
        for (int i = 0; i < groesse; i++){                                      //solange i kleiner als groesse
               file >> flugnummer >> abflug >> ziel >> datum >> preis;          //Liest die einzelnen Woerter der .txt und speichert sie in den jeweiligen Variablen wieder
        
        Flug f(flugnummer, abflug, ziel, datum, preis);                         //legt Flugobjekt mit eingelesenen Variablen an
        flugliste.push_back(f);                                                 //pusht Flugobjekt in den jeweiligen Vektor
        
        }     
}
}

int Flugliste::size(){
    return flugliste.size();    //gibt size der Flugliste zurück
}

string Flugliste::getAbFlughafen(int index){                //Gibt Abflughafen abhaengig vom Index zurueck
    return flugliste.at(index).getAbflugFlughafen();
}

string Flugliste::getZielFlughafen(int index){          //Gibt Zielflughafen abhaengig vom Index zurueck
    return flugliste.at(index).getZielFlughafen();
}

string Flugliste::getFlugnummer(int index){         //Gibt Flugnummer abhaengig vom Index zurueck
    return flugliste.at(index).getFlugnummer();
}

Flug Flugliste::at(int index){          //Gibt Flug abhaengig vom Index zurueck
    return flugliste.at(index);
}