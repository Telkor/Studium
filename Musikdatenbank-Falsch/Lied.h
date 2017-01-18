

#ifndef LIED_H
#define	LIED_H
#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "DynArray.h"

using namespace std;

enum genre {pop, rock, klassik, hard_rock};
class DynArray;
class Lied{
   public:
    string titel;
    string interpret;
    int erscheinungsjahr;
    int laenge;
    genre g;
    int eintrag;
    
    
    void eintraganlegen(DynArray &a);
    void eintraganzeigen(vector<Lied>& liste, Lied li);
    void alleeintraganzeigen(vector<Lied>& liste, Lied li);
    void eintragloeschen(vector<Lied>& liste, Lied li);
    void eintragbearbeiten(vector<Lied>& liste, Lied li);
};
#endif	/* LIED_H */