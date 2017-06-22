#include "Buchung.h"

Buchung::Buchung(){
    
}

Buchung::Buchung(string m_email, string kartennummer, bool m_verkauft, bool m_usedkk) {
    email = m_email;
    
    if (m_usedkk == true)                                                       //Falls eine Kreditkarte genutzt wird, wird die Kreditkarte der Kartennummer gleichgesetzt.
        kreditkarte = kartennummer;
    else
        IBAN = kartennummer;
    
    verkauft = m_verkauft;
    usedKreditkarte = m_usedkk;
}

Buchung::~Buchung() {
}
