#include "Flug.h"

Flug::Flug(){
    
}

Flug::Flug(string m_flugnummer, string m_abflugFlughafen, string m_zielFlughafen, string m_datum , double m_flugpreis) {
    abflugFlughafen = m_abflugFlughafen;
    zielFlughafen = m_zielFlughafen;
    datum = m_datum;
    flugnummer = m_flugnummer;
    flugpreis = m_flugpreis;
}

Flug::~Flug() {
}

string Flug::getAbflugFlughafen(){
    return abflugFlughafen;
}

string Flug::getZielFlughafen(){
    return zielFlughafen;
}

string Flug::getFlugnummer(){
    return flugnummer;
}

string Flug::setFlugnummer(string flugnr){
    flugnummer =  flugnr;
}

double Flug::getFlugpreis(){
    return flugpreis;
}

string Flug::getDatum(){
    return datum;
}