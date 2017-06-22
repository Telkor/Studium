#include "Flugliste.h"
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Flugliste::Flugliste() {
    
  flugEinlesen();
  

    
    
    
    
    
    
    
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

void Flugliste::flugEinlesen(){  
     
    int i = 0;
    double preis;
    int groesse;
    string flugnummer;
    string abflug;
    string ziel;
    string datum;
    ifstream file;
    string line;
    file.open("Flugliste.txt");
    if(file.is_open()){
        
    file >> groesse;    
       
        for (int i = 0; i < groesse; i++){
               file >> flugnummer >> abflug >> ziel >> datum >> preis;
        
        Flug f(flugnummer, abflug, ziel, datum, preis);
        flugliste.push_back(f);
        
        }
          //Flug f(flugnummer, abflug, ziel, datum);
          // flugliste.push_back(f);
    }
        
        
        
        
     /*   while (std::getline(file,line)){
            std::cout << line << std::endl;
        }
        file.close();
    }  */
    
   
  /*  
    
    ifstream fluglist("Flugliste.txt", ios::in);
    //fluglist.open("Flugliste.txt", ios::in);
    int i = 0;
     string line;
    string flugnummer;
    string abflug;
    string ziel;
    string datum;
    //int preis;
    
   
    
    if (fluglist.good()){
        
       for (int i = 0; i < fluglist.eof(); i++){
               fluglist >> flugnummer >> abflug >> ziel >> datum;
        }
           Flug f(flugnummer, abflug, ziel, datum);
           flugliste.push_back(f);
       }
         
    
    
fluglist.close();
    
    
    
    
    
    //flugliste.push_back();  */
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

string Flugliste::getFlugnummer(int index){
    return flugliste.at(index).getFlugnummer();
}

Flug Flugliste::at(int index){
    return flugliste.at(index);
}