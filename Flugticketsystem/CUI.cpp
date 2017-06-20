#include "CUI.h"

CUI::CUI() {

    
}

CUI::~CUI() {
}

void CUI::zeigeMenus(){
    string eingabe;
    while (true) {
        cout << "1. Registrieren" << "\n";
        cout << "2. Flug suchen" << "\n";
        cout << "3. Flug buchen" << "\n";
        cout << "4. gekaufte Tickets anzeigen" << "\n";
        cout << "5. Programm beenden" << "\n";
        cin >> eingabe;
        
        if (eingabe == "1")
            registrieren();
        
        if (eingabe == "2")
            flugSuchen();
        
        if (eingabe == "3")
            flugBuchen();
        
        if (eingabe == "4")
            ticketAnzeigen();
        
        if (eingabe == "5")
            break;
        
    }
}

void CUI::registrieren(){
    string vorname;
    string name;
    string email;
    string passwort;
    string gebDatum;
    string IBAN;
    
    cout << "\n";
    cout << "Vorname: " << "\n";
    cin >> vorname;
    cout << "Nachname: " << "\n";
    cin >> name;
    cout << "Email: " << "\n";
    cin >> email;
    cout << "Passwort: " << "\n";
    cin >> passwort;
    cout << "Geburtsdatum: " << "\n";
    cin >> gebDatum;
    cout << "IBAN: " << "\n";
    cin >> IBAN;
    cout << "\n";
    
    Kunde k(vorname, name, email, passwort, gebDatum, IBAN);
    kundenliste.push_back(k);
    login = true;
    cout << "Sie sind jetzt eingeloggt" << "\n";
}

bool CUI::loginPruefen(){
    if (!login)
        return false;
    else 
        return true;
}

void CUI::flugSuchen(){
    string abflug;
    string zielflug;
    string ab;
    string zi;
    cout << "Von wo moechten Sie losfliegen?: " << "\n";
    cin.ignore();
    getline(cin, abflug);
    cout << "Wohin moechten SSSSSie hinfliegen" << "\n";
    getline(cin, zielflug);
    
    for (int i = 0; i < flugliste->size(); i++){
        string ab = flugliste->getAbFlughafen(i);
        string zi = flugliste->getZielFlughafen(i);
        
        flugliste->print(i);
        if (flugliste->getAbFlughafen(i) == abflug){
            if (flugliste->getZielFlughafen(i) == zielflug)
                flugliste->print(i);
        }
            
    }

}

void CUI::ticketAnzeigen(){
    for (int i = 0; i < ticketliste.size(); i++){
        ticketliste.at(i).print();
    }
}

void CUI::flugBuchen(){
    int flgnr;
    string rk;
    cout << "Welchen Flug moechten sie buchen?: " << "\n";
    cin >> flgnr;
    cout << "In welcher Reiseklasse moechten sie fliegen?(economy/buisness/firstClass): " << "\n";
    cin >> rk;
    
    Ticket t;
    
    for (int i = 0; i < flugliste->size(); i++){
        if (flugliste->getflugnummer(i) == flgnr){
            t.setFlug(flugliste->at(i));
            t.setReiseklasse(rk);
            ticketliste.push_back(t);
        }
    }
}