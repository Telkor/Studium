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
    
    
private:
    string reiseKlasse;
    Flug* flug = new Flug;
    Buchung* buchung = new Buchung;
};

#endif /* TICKET_H */

