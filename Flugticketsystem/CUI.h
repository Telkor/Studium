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
    void menuAnzeigen();
    void ticketBerechnen();
    void ticketAnzeigen();
    void ticketBezahlen();
    void ticketAusdrucken();
    void zeigeMenus();
    void addKunde();
    bool anmelden();
    bool loginPruefen();
    void flugSuchen();
    void registrieren();
    void fluglisteAnzeigen();
    void flugBuchen();
    
private:
    vector<Kunde> kundenliste;
    Flugliste* flugliste = new Flugliste;
    vector<Ticket> ticketliste;
    vector<Buchung> buchungsliste;
    bool login;
};

