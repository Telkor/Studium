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
    Buchung(string m_email, string kartennummer, bool m_verkauft, bool m_usedkk);
    virtual ~Buchung();
private:
    string email;
    string IBAN;
    string kreditkarte;
    bool verkauft;
    bool usedKreditkarte;

};

#endif	/* BUCHUNG_H */

