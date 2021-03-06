#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include "Flug.h"
#include "Buchung.h"

using namespace std;

class Ticket {
public:
    Ticket();
    virtual ~Ticket();
    void setFlug(Flug m_flug);
    void setReiseklasse(string rk);
    void setAnzahl(int m_anzahl);
    string getReiseKlasse();
    int getAnzahl();
    void setBuchung(Buchung m_buchung);
    Flug getFlug();
    
private:
    string reiseKlasse;
    Flug flug;
    Buchung buchung;
    int anzahl;
};

#endif /* TICKET_H */

