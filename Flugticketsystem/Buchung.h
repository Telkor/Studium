/* 
 * File:   Buchung.h
 * Author: fs
 *
 * Created on 21. Juni 2017, 19:41
 */

#ifndef BUCHUNG_H
#define	BUCHUNG_H
#include "Kunde.h"

class Buchung {
public:
    
    
    Buchung();
    Buchung(const Buchung& orig);
    virtual ~Buchung();
    void zahlungsBelegErstellen();
private:
    string email;
    string datum;
    string IBAN;
    bool verkauft;

};

#endif	/* BUCHUNG_H */

