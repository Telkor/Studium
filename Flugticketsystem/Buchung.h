#ifndef BUCHUNG_H
#define BUCHUNG_H
#include <iostream>
#include <string>

using namespace std;


class Buchung {
public:
    Buchung();
    virtual ~Buchung();
    void zahlungsBelegErstellen();
    
private:
    string email;
    time_t datum;
    bool verkauft;
    string IBAN;
};

#endif /* BUCHUNG_H */

