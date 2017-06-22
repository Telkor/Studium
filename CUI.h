#include <iostream>
#include <vector>
#include "Buchung.h"
#include "Flug.h"
#include "Flugliste.h"
#include "Kunde.h"
#include "Ticket.h"
#include <string>

using namespace std;

class CUI {
public:
    CUI();
    virtual ~CUI();
    void ticketAnzeigen();  // zeigt gekaufte Tickets an
    void zeigeMenu();       // zeigt das Menu an
    bool anmelden();        // Anmeldung des Benutzers
    bool loginPruefen();    // prueft ob man angemeldet ist
    void flugSuchen();      // lässt einen den Abflugort und den Zielflughafen eintippen und gibt alle passeden Fluege zurück
    void registrieren();    // Registrierung des Users
    void flugBuchen();      // Buchung eines Fluges
    
private:
    vector<Kunde> kundenliste;
    Flugliste* flugliste = new Flugliste;
    vector<Ticket> ticketliste;
    vector<Buchung> buchungsliste;
    bool login;     //bestimmt ob der Kunde eingeloggt ist oder nicht  
    int kunde;      //wird benutzt um den eingeloggten Kunden zu identifizieren
};

