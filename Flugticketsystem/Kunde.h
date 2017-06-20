#ifndef KUNDE_H
#define KUNDE_H
#include <iostream>
#include <string>

using namespace std;

class Kunde {
public:
    Kunde(string m_vorname, string m_name, string m_email, string m_passwort, string m_gebDatum, string m_IBAN);
    virtual ~Kunde();
    string getName();
    
private:
    string vorname;
    string name;
    string email;
    string passwort;
    string gebDatum;
    string IBAN;
};

#endif /* KUNDE_H */

