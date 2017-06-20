#include "Flug.h"

Flug::Flug(){
    
}

Flug::Flug(int m_flugnummer, string m_abflugFlughafen, string m_zielFlughafen, string m_datum, float m_flugpreis) {
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

void Flug::print(){
    cout << "Flugnummer: " << flugnummer << "\n";
    cout << "Abflugflughafen: " << abflugFlughafen << "\n";
    cout << "Zielflughafen: " << zielFlughafen << "\n";
    cout << "Datum: " << datum << "\n";
    cout << "Flugpreis: " << flugpreis << "\n";
    cout << "\n";
}

int Flug::getflugnummmer(){
    return flugnummer;
}