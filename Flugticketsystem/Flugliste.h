#ifndef FLUGLISTE_H
#define FLUGLISTE_H
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Flug.h"

using namespace std;

class Flug;

class Flugliste {
public:
    Flugliste();
    virtual ~Flugliste();
    void fluegeEinlesen(Flug a);
    void flugSuchen();
    void print(int index);
    int size();
    string getAbFlughafen(int index);
    string getZielFlughafen(int index);
    int getflugnummer(int index);
    Flug at(int index);
private:
    vector<Flug> flugliste;
};

#endif /* FLUGLISTE_H */

