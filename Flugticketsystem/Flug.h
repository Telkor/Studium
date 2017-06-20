#ifndef FLUG_H
#define FLUG_H
#include <iostream>
//#include <string>

using namespace std;

class Flug {
public:
    Flug();
    Flug(int m_flugnummer, string m_abflugFlughafen, string m_zielFlughafen, string m_datum, float m_flugpreis);
    virtual ~Flug();
    string getAbflugFlughafen();
    string getZielFlughafen();
    void print();
    int getflugnummmer();
    
private:
    string abflugFlughafen;
    string zielFlughafen;
    string datum;
    int flugnummer;
    float flugpreis;
};

#endif /* FLUG_H */

