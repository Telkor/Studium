#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Lied.h"


using namespace std;

int menu(vector<Lied>& liste){
    Lied li;
    string eingabe;
   
   
    
    while(true){
    cout << endl << "********** Musikblibothek Version 0.1 **********" << endl;
    cout <<"Hauptmenue" << endl;
    cout <<"1. (N)euen Eintrag anlegen" << endl;
    cout <<"2. (D)etails eines Eintrages anzeigen" << endl;
    cout <<"3. Einen Eintrag (l)oeschen" << endl;
    cout <<"4. Einen Eintrag (b)earbeiten" << endl;
    cout <<"5. Einen Eintrag (s)uchen" << endl;   
    cout <<"6. (A)lle Eintraege anzeigen" << endl;
    
    cout <<" " << endl;    
    
    cout <<"0. Programm beenden" <<endl;
    
    cin >> eingabe;
    
    if (eingabe == "1" | eingabe == "N" | eingabe == "n"){
        cout << "Sie befinden sich im Menuepunkt Neuen Eintrag anlegen" << endl << endl;
        li.eintraganlegen(liste, li);
        
        
    }
    
    if (eingabe == "2" | eingabe == "D" | eingabe == "d"){
        cout << "Sie befinden sich im Menuepunkt Details eines Eintrages anzeigen." << endl << endl;
        li.eintraganzeigen(liste, li);
    }
    
    if (eingabe == "3" | eingabe == "L" | eingabe == "l"){
        cout << "Sie befinden sich im Menuepunkt Einen Eintrag loeschen-" << endl << endl;
        li.eintragloeschen(liste, li);
    }
    
    if (eingabe == "4" | eingabe == "B" | eingabe == "b"){
        cout << "Sie befinden sich im Menuepunkt Neuen Eintrag anlegen." << endl << endl;
        li.eintragbearbeiten(liste, li);
    }
    
     if (eingabe == "5" | eingabe == "S" | eingabe == "s"){
        cout << "Sie befinden sich im Menuepunkt Einen Eintrag suchen." << endl << endl;
        
    }
    
     if (eingabe == "6" | eingabe == "A" | eingabe == "a"){
        cout << "Sie befinden sich im Menuepunkt Alle Eintraege anzeigen." << endl << endl;
        li.alleeintraganzeigen(liste,li); //a.print();
    }
    
    if (eingabe == "0"){
        return 0;
    }
    
    }
}

int main() {
   vector<Lied> liste; 
   menu(liste); 
   
   
   
   return 0;
}