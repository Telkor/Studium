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
    void print();
    void setFlug(Flug m_flug);
    void setReiseklasse(string rk);
    void setAnzahl(int m_anzahl);
    
private:
    string reiseKlasse;
    Flug flug;
    Buchung buchung;
    int anzahl;
};

#endif /* TICKET_H */

