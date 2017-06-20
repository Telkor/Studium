#include "Kunde.h"

Kunde::Kunde(string m_vorname, string m_name, string m_email, string m_passwort, string m_gebDatum, string m_IBAN) {
    vorname = m_vorname;
    name = m_name;
    email = m_email;
    passwort = m_passwort;
    gebDatum = m_gebDatum;
    IBAN = m_IBAN;
    
}

Kunde::~Kunde() {
}

