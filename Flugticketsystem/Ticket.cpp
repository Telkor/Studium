#include "Ticket.h"

Ticket::Ticket() {
}

Ticket::~Ticket() {
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

string Ticket::getReiseKlasse(){
    return reiseKlasse;
}

int Ticket::getAnzahl(){
    return anzahl;
}

void Ticket::setBuchung(Buchung m_buchung){
    buchung = m_buchung;
}

Flug Ticket::getFlug(){
    return flug;
}
        