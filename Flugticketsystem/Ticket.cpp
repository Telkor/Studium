#include "Ticket.h"

Ticket::Ticket() {
}

Ticket::~Ticket() {
}

void Ticket::print(){
    cout << "Reiseklasse: " << reiseKlasse << "\n";
    flug->print();
}

void Ticket::setFlug(Flug m_flug){
    flug = &m_flug;
}

void Ticket::setReiseklasse(string rk){
    reiseKlasse = rk;
}