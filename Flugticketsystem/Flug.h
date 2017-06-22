#ifndef FLUG_H
#define FLUG_H
#include <iostream>
#include <string>

using namespace std;

class Flug {
public:
    Flug();
    Flug(string m_flugnummer, string m_abflugFlughafen, string m_zielFlughafen, string m_datum, double m_flugpreis);
    virtual ~Flug();
    string getAbflugFlughafen();
    string getZielFlughafen();
    void print();
    string getFlugnummer();
    string setFlugnummer(string flugnr);
    double getFlugpreis();
    
private:
    string abflugFlughafen;
    string zielFlughafen;
    string datum;
    string flugnummer;
    double flugpreis;
};

#endif /* FLUG_H */

