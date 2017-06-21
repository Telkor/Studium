#include "CUI.h"

CUI::CUI() {
    
    login = false;
    
}

CUI::~CUI() {
}

void CUI::zeigeMenus(){
    string eingabe;
    while (true) {
        cout << "1. Registrieren" << "\n";
        cout << "2. Anmelden" << "\n";
        cout << "3. Flug suchen" << "\n";
        cout << "4. Flug buchen" << "\n";
        cout << "5. gekaufte Tickets anzeigen" << "\n";
        cout << "6. Programm beenden" << "\n";
        cin >> eingabe;
        
        if (eingabe == "1" && login == false)
            registrieren();
        else if (eingabe == "1" && login == true)
            cout << "\n" << "Sie sind angemeldet. Registrierung nicht moeglich!" << "\n";
        
        if (eingabe == "2" && login == false)
            anmelden();
        else if (eingabe == "2" && login == true)
            cout << "\n" << "Sie sind bereits angemeldet!" << "\n";
        
        if (eingabe == "3")
            flugSuchen();
        
        if (eingabe == "4" && login == true)
            flugBuchen();
        else if (eingabe == "4" && login == false)
            cout << "\n"<<  "Sie muessen sich erst anmelden!" << "\n" << "\n";
        
        if (eingabe == "5")
            ticketAnzeigen();
        
        if (eingabe == "6")
            break;
        
        if (eingabe == "o")
            for (int i = 0; i < flugliste->size(); i++){
                flugliste->print(i);
            }
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
    login = false;
    //cout << "\n" << "Sie sind jetzt angemeldet" << "\n";
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
    cout << "Wohin moechten Sie hinfliegen?" << "\n";
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
    
    string flgnr;
    string rk;
    cout << "Welchen Flug moechten sie buchen?: " << "\n";
    cin >> flgnr;
    cout << "In welcher Reiseklasse moechten sie fliegen?(economy/businless/firstClass): " << "\n";
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

bool CUI::anmelden(){
    string email;
    string passwort;
    cout << "Email: " << "\n";
    cin >> email;
    cout << "Passwort: " << "\n";
    cin >> passwort;
    
    for (int i = 0; i < kundenliste.size(); i++){
        if (email == kundenliste.at(i).getEmail() && passwort == kundenliste.at(i).getPasswort()){
            login = true;
            cout << "\n" << "Sie sind jetzt angemeldet!" << "\n";
        }   
    }
    if (login == false)
        cout << "\n" << "Falsche Email oder falsches Passwort eingegeben!" << "\n" << "\n";
}