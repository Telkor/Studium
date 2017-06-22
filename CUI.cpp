#include "CUI.h"

using namespace std;

CUI::CUI() {    
    login = false;   
}

CUI::~CUI() {
}

void CUI::zeigeMenu(){
    string eingabe;
    while (true) {                                          //Menu wird so lange ausgegeben bis eine gültige eingabe erfolt 
        cout << "1. Registrieren" << "\n";
        cout << "2. Anmelden" << "\n";
        cout << "3. Flug suchen" << "\n";
        cout << "4. Flug buchen" << "\n";
        cout << "5. gekaufte Tickets anzeigen" << "\n";
        cout << "6. Ausloggen" << "\n";
        cout << "7. Programm beenden" << "\n";
        cin >> eingabe;
        
        if (eingabe == "1" && login == false)
            registrieren();
        else if (eingabe == "1" && login == true)
            cout << "\n" << "Sie sind angemeldet. Registrierung nicht moeglich." << "\n";
        
        if (eingabe == "2" && login == false)
            anmelden();
        else if (eingabe == "2" && login == true)
            cout << "\n" << "Sie sind bereits angemeldet." << "\n";
        
        if (eingabe == "3")
            flugSuchen();
        
        if (eingabe == "4" && login == true)
            flugBuchen();
        else if (eingabe == "4" && login == false)
            cout << "\n"<<  "Sie muessen sich erst anmelden." << "\n" << "\n";
        
        if (eingabe == "5")
            ticketAnzeigen();
        
        if (eingabe == "6" && login == true){
            login = false;                                                      //User loggt sich aus
            cout << "\n" << "Sie haben sich ausgeloggt." << "\n";
        }
        else if(eingabe == "6" && login == false){
            cout << "\n" << "Sie sind bereits ausgeloggt." << "\n";
        }
        
        if (eingabe == "7")
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
    
    Kunde k(vorname, name, email, passwort, gebDatum, IBAN);    //legt Kundenobjekt mit jeweiligen Eingaben an
    kundenliste.push_back(k);                                   //pusht Kundenobjekt in Vector "kundenliste"
}

bool CUI::loginPruefen(){
    if (!login)                 // gibt false zurueck falls ungleich login
        return false;
    else 
        return true;
}

void CUI::flugSuchen(){
    string abflug;
    string zielflug;
    int count = 0;
    cout << "Von wo moechten Sie losfliegen?: " << "\n";
    cin >> abflug;
    cout << "Wohin moechten Sie hinfliegen?" << "\n";
    cin >> zielflug;
    
    for (int i = 0; i < flugliste->size(); i++){  //durchsucht den Vektor nach passenden Fluegen und gibt diese aus
        
        if (flugliste->getAbFlughafen(i) == abflug){
            if (flugliste->getZielFlughafen(i) == zielflug){                                    //Falls Eingabe Abflughafen und Zielflughafen gefunden wurde, wird das jeweilige Objekt ausgegeben
                cout << "Flugnummer: " << flugliste->at(i).getFlugnummer() << "\n";
                cout << "Abflugflughafen: " << flugliste->at(i).getAbflugFlughafen() << "\n";
                cout << "Zielflughafen: " << flugliste->at(i).getZielFlughafen() << "\n";
                cout << "Datum: " << flugliste->at(i).getDatum() << "\n";
                cout << "Flugpreis pro Ticket: " << flugliste->at(i).getFlugpreis() << "\n" << "\n";
                count++;                                                                                // Zaehlt hoch, sobald ein Ergebnis gefunden wurde
            }
        }      
    
        else if (flugliste->getAbFlughafen(i) != abflug && i == flugliste->size() - 1 && count == 0){   
            cout << "\n" << "Diese Flugverbindung existiert nicht." << "\n" << "\n";                    // Ausgabe falls keine passenden Fluege gefunden werden konnten
            break;
        }             
    }
}

void CUI::ticketAnzeigen(){                             //Ausgabe der gekauften Tickets                                                                                                                 
    for (int i = 0; i < ticketliste.size(); i++){
        
        cout << "Flugnummer: " << ticketliste.at(i).getFlug().getFlugnummer() << "\n";
        cout << "Abflugflughafen: " << ticketliste.at(i).getFlug().getAbflugFlughafen() << "\n";
        cout << "Zielflughafen: " << ticketliste.at(i).getFlug().getZielFlughafen() << "\n";
        cout << "Datum: " << ticketliste.at(i).getFlug().getDatum() << "\n";
        cout << "Flugpreis pro Ticket: " << ticketliste.at(i).getFlug().getFlugpreis() << "\n";              
        cout << "Reiseklasse: " << ticketliste.at(i).getReiseKlasse() << "\n";
        cout << "Ticketanzahl: " << ticketliste.at(i).getAnzahl() << "\n";
        cout << "Gesamtpreis: " << ticketliste.at(i).getAnzahl()*ticketliste.at(i).getFlug().getFlugpreis() << "\n" << "\n";    //Anzahl an Tickets * Flugpreis fuer den jeweiligen Flug.  
    }
}

void CUI::flugBuchen(){   
    
    string flgnr;
    string rk;
    string zahlungstyp;
    int tk;
    bool usedkk = false;
    string kartennummer = kundenliste.at(kunde).getIBAN();  //Standard Zahlungstyp ist EC-Karte (wird zum Erstellen des Buchungsobjektes benötigt)
    string kreditkarte;
    string email = kundenliste.at(kunde).getEmail();        //Bekommt E-Mail ueber Kundenliste
    
    cout << "Welchen Flug moechten sie buchen? (Flugnummer): " << "\n";
    cin >> flgnr;
    cout << "In welcher Reiseklasse moechten Sie fliegen?(economy/business/firstClass): " << "\n";
    cin >> rk;
    while(rk != "economy" && rk != "business" && rk != "firstClass"){           //liest solange ein, bis ein gueltiger Wert eingegeben wurde
        cout << "Bitte geben Sie eine gueltige Reiseklasse ein: " << "\n";
        cin >> rk;
    }
    cout << "Wieviele Tickets moechten Sie kaufen?"; //Anzahl an Tickets
    cin >> tk;
    cout << "Moechten Sie per Kreditkarte zahlen?";  //Fragt ab ob man mit Kreditkarte zahlen moechte(Zahlung per EC-Karte ist Standard)
    cin >> zahlungstyp;
    
    if (zahlungstyp == "Ja" || zahlungstyp == "ja"){            
        cout << "Bitte geben sie ihre Kreditkartennummer ein: " << "\n";
        cin >> kreditkarte;
        kartennummer = kreditkarte;
    }
    
    Ticket t;                                      //Ticketobjekt wird angelegt
    Buchung b(email , kartennummer, true, usedkk); //Buchungsobjekt wird angelegt
    
   
    
    for (int i = 0; i < flugliste->size(); i++){        //Durchlaeuft fluglist fuer Buechung
        if (flugliste->getFlugnummer(i) == flgnr){      
            t.setFlug(flugliste->at(i));                //setzt Flug an der Stelle wo flgnr identisch mit getFlugnummer(i))
            t.setReiseklasse(rk);
            t.setAnzahl(tk);
            t.setBuchung(b);
            ticketliste.push_back(t);
            buchungsliste.push_back(b);
            
            cout << "\n" << "Ihr Flug wurde gebucht. Ihr Zahlungsbeleg wird per E-Mail versendet." << "\n" << "\n"; //Hier wuerde die Buchungsbestaetigung per E-Mail kommen.
            break;
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
        if (email == kundenliste.at(i).getEmail() && passwort == kundenliste.at(i).getPasswort()){ //Anmeldung erfolgt falls E-Mail und Passwort ueberein stimmen
            login = true;                                                                          //login wird true gesetzt
            kunde = i;                                                                                      
            cout << "\n" << "Sie sind jetzt angemeldet!" << "\n";
            break;
        }   
    }
    if (login == false)
        cout << "\n" << "Falsche Email oder falsches Passwort eingegeben!" << "\n" << "\n";
}