#include "Ticket.h"

Ticket::Ticket() {
}

Ticket::~Ticket() {
}

void Ticket::print(){
    cout << "Reiseklasse: " << reiseKlasse << "\n";
    cout << "Ticketanzahl: " << anzahl << "\n";
    cout << "Gesamtpreis: " << anzahl*flug.getFlugpreis() << "\n";
    flug.print();
    
}

void Ticket::setFlug(Flug m_flug){
    flug = m_flug;
}

void Ticket::setReiseklasse(string rk){
    reiseKlasse = rk;
}

void Ticket::setAnzahl(int m_anzahl){
    anzahl = m_anzahl;
}