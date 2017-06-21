#include "Flug.h"

Flug::Flug(){
    
}

Flug::Flug(string m_flugnummer, string m_abflugFlughafen, string m_zielFlughafen, string m_datum /*, int m_flugpreis */) {
    abflugFlughafen = m_abflugFlughafen;
    zielFlughafen = m_zielFlughafen;
    datum = m_datum;
    flugnummer = m_flugnummer;
    //flugpreis = m_flugpreis;
}

Flug::~Flug() {
}

string Flug::getAbflugFlughafen(){
    return abflugFlughafen;
}

string Flug::getZielFlughafen(){
    return zielFlughafen;
}

void Flug::print(){
    cout << "Flugnummer: " << flugnummer << "\n";
    cout << "Abflugflughafen: " << abflugFlughafen << "\n";
    cout << "Zielflughafen: " << zielFlughafen << "\n";
    cout << "Datum: " << datum << "\n";
    cout << "Flugpreis: " << flugpreis << "\n";
    cout << "\n";
}

string Flug::getflugnummmer(){
    return flugnummer;
}