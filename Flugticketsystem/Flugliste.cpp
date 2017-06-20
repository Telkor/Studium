#include <string>
#include <cstdlib>
#include <iostream>
#include "Flugliste.h"

using namespace std;

Flugliste::Flugliste() {
    Flug* f1 = new Flug(101, "Frankfurt", "New York Airport", "21.07", 599.99);
    Flug* f2 = new Flug(394, "Berlin Flughafen", "Paris Flughafen", "13.05", 300.00);
    
   
//    flugliste->fluegeEinlesen(f1);
//    flugliste->fluegeEinlesen(f2);
    flugliste.push_back(f1);
    flugliste.push_back(f2);
    
    
}

Flugliste::~Flugliste() {
}

void Flugliste::fluegeEinlesen(Flug* a){  
        flugliste.push_back(a);
}

void Flugliste::print(int index){
    flugliste.at(index)->print();
}

int Flugliste::size(){
    return flugliste.size();
}

string Flugliste::getAbFlughafen(int index){
    return flugliste.at(index)->getAbflugFlughafen();
}

string Flugliste::getZielFlughafen(int index){
    return flugliste.at(index)->getZielFlughafen();
}

int Flugliste::getflugnummer(int index){
    return flugliste.at(index)->getflugnummmer();
}

Flug* Flugliste::at(int index){
    return flugliste.at(index);
}