#ifndef LIED_H
#define	LIED_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum genre {pop, rock, klassik, hard_rock};

class Lied{
   public:
    string titel;
    string interpret;
    int erscheinungsjahr;
    int laenge;
    genre g;
    int eintrag = 0;
    
    
    void eintraganlegen(vector<Lied>& liste, Lied li);
    void eintraganzeigen(vector<Lied>& liste, Lied li);
    void alleeintraganzeigen(vector<Lied>& liste, Lied li);
    void eintragloeschen(vector<Lied>& liste, Lied li);
    void eintragbearbeiten(vector<Lied>& liste, Lied li);
};



#endif	/* LIED_H */