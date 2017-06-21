#include <string>
#include <cstdlib>
#include <iostream>
#include "Flugliste.h"
#include <fstream>

using namespace std;

Flugliste::Flugliste() {
    
    ifstream fluglist;
    string line;   
    fluglist.open("Flugliste.txt");
    int i = 0;
    int flugnummer;
    string abflug;
    string ziel;
    string datum;
    int preis;
   
    
    if (fluglist.good()){
        
       for (int i = 0; i < fluglist.eof(); i++){
               fluglist >> flugnummer >> abflug >> ziel >> datum;
        }
           Flug f(flugnummer, abflug, ziel, datum);
           flugliste.push_back(f);
       }
         
    
    
fluglist.close();
    
    
    
    
    
    
    
    
    //    Flug* f1 = new Flug(101, "Frankfurt", "New York Airport", "21.07", 599.99);
//    Flug* f2 = new Flug(394, "Berlin Flughafen", "Paris Flughafen", "13.05", 300.00);
//    
//   
////    flugliste->fluegeEinlesen(f1);
////    flugliste->fluegeEinlesen(f2);
//    flugliste.push_back(f1);
//    flugliste.push_back(f2);
    
    
}

Flugliste::~Flugliste() {
}

void Flugliste::fluegeEinlesen(Flug a){  
        flugliste.push_back(a);
}

void Flugliste::print(int index){
    flugliste.at(index).print();
}

int Flugliste::size(){
    return flugliste.size();    //gibt size der Flugliste zurück
}

string Flugliste::getAbFlughafen(int index){
    return flugliste.at(index).getAbflugFlughafen();
}

string Flugliste::getZielFlughafen(int index){
    return flugliste.at(index).getZielFlughafen();
}

int Flugliste::getflugnummer(int index){
    return flugliste.at(index).getflugnummmer();
}

Flug Flugliste::at(int index){
    return flugliste.at(index);
}