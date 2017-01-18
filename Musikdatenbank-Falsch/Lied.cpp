#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Lied.h"
#include "DynArray.h"

using namespace std;

    
void Lied::eintraganlegen(DynArray &a){
    string k;
    Lied li;
    
    cout << "Geben Sie einen Titel an: ";
    cin >> titel;
    li.titel = "Titel: " + titel;
    
    cout << "Geben Sie einen Interpreten an: ";
    cin >> interpret;
    li.interpret = "Interpret: " + interpret;
    
    cout << "Geben Sie ein Erscheinungsjahr an: ";
    cin >> erscheinungsjahr;
    li.erscheinungsjahr = erscheinungsjahr;
    
    cout << "Geben Sie eine laenge an: ";
    cin >> laenge;
    li.laenge = laenge;
    
    
    cout << "Geben sie ein Genre an:";
    cin >> k;
    
    if (k == "pop") {
        li.g = pop;
    }
        
    if (k == "rock") {
        li.g = rock;
    }
        
    if (k == "klassik") {
        li.g = klassik;
    }   
    if (k == "hard_rock") {
        li.g = hard_rock;    
    }
   
    eintrag = eintrag + 1;
    li.eintrag = eintrag;
    
    
   a.push_back(li);
    
    
    
}

    
   



void Lied::eintraganzeigen(vector<Lied>& liste, Lied li){
    int eintragsnr;
    
    
    cout << "Welchen Eintrag moechten Sie sehen?" << endl;
    cin >> eintragsnr;
    

        cout << liste[eintragsnr - 1].eintrag << ".Eintrag" << endl;
        cout << "Titel: " << liste[eintragsnr - 1].titel << endl;
        cout << "Interpret: " << liste[eintragsnr - 1].interpret << endl;
        cout << "Erscheinungsjahr: " << liste[eintragsnr - 1].erscheinungsjahr << endl;
        cout << "Laenge: " << liste[eintragsnr - 1].laenge << endl;
        
} 

void Lied::alleeintraganzeigen(vector<Lied>& liste, Lied li){
  
    
    
     
    for (int i = 0; i < liste.size(); i++){
        cout << endl << liste[i].eintrag << ".Eintrag" << endl;
        cout << "Titel: " << liste[i].titel << endl;
        cout << "Interpret: " << liste[i].interpret << endl;
        cout << "Erscheinungsjahr: " << liste[i].erscheinungsjahr << endl;
        cout << "Laenge: " << liste[i].laenge << endl;
        
        if (liste[i].g == pop) {
            cout << "Genre: Pop" << endl << endl;  
        }
        
        if (liste[i].g == rock) {
            cout << "Genre: Rock" << endl << endl;
        }
        
        if (liste[i].g == klassik) {
            cout << "Genre: Klassik" << endl << endl;
        }
        
        if (liste[i].g == hard_rock) {
            cout << "Genre: Hard Rock" << endl << endl;
        }
    } 
}

void Lied::eintragloeschen(vector<Lied>& liste, Lied li){
    int loeschen;
    
    cout << "Welchen Eintrag moechten Sie loeschen?";
    
    cin >> loeschen;
    
    liste.erase(liste.begin () + loeschen - 1);
    
    for  (int i = loeschen - 1; i < liste.size(); i++) {
        liste[i].eintrag--;
        
          
    }  
}

void Lied::eintragbearbeiten(vector<Lied>& liste, Lied li){
    int bearbeiten;
    string information;
    int bla;
    
    cout << "Welchen Entrag moechten Sie bearbeiten?" << endl;
    
    cin >> bearbeiten;
        
        cout << liste[bearbeiten - 1].eintrag << ".Eintrag" << endl;
        cout << liste[bearbeiten - 1].titel << endl;
        cout << liste[bearbeiten - 1].interpret << endl;
        cout << liste[bearbeiten - 1].erscheinungsjahr << endl;
        cout << liste[bearbeiten - 1].laenge << endl;
        
        if (liste[bearbeiten - 1].g == pop) {
            cout << "Genre: Pop" << endl << endl;  
        }
        
        if (liste[bearbeiten - 1].g == rock) {
            cout << "Genre: Rock" << endl << endl;
        }
        
        if (liste[bearbeiten - 1].g == klassik) {
            cout << "Genre: Klassik" << endl << endl;
        }
        
        if (liste[bearbeiten - 1].g == hard_rock) {
            cout << "Genre: Hard Rock" << endl << endl;
        }
        
        
        cout << "Welchhe Information wollen Sie bearbeiten?" << endl;
        
        cin >> information;
        
        if (information == "titel" | information == "Titel") {
            cout << "Geben Sie einen Titel an." << endl;
            cin >> titel;
            liste[bearbeiten - 1].titel = titel;
        }
        
        if (information == "interpret" | information == "Interpret") {
            cout << "Geben Sie einen Interpreten  an." << endl;
            cin >> interpret;
            liste[bearbeiten - 1].interpret = interpret;
        }
        
        if (information == "erscheinungsjahr" | information == "Erscheinungsjahr") {
            cout << "Geben Sie ein Erscheinungsjahr an." << endl;
            cin >> erscheinungsjahr;
            liste[bearbeiten - 1].erscheinungsjahr = erscheinungsjahr;
        }
        
        if (information == "laenge" | information == "Laenge") {
            cout << "Geben Sie die Laenge an." << endl;
            cin >> laenge;
            liste[bearbeiten - 1].laenge = laenge;
        }
        
        if (information == "genre" | information == "Genre") {
            cout << "Bitte geben Sie ein Genre an." << endl;
            cin >> information;
            
            if (information == "pop") { 
                g = pop;
            }  
            if (information == "rock") { 
                g = rock;
            } 
            if (information == "klassik") { 
                g = klassik;
            } 
            if (information == "hard_rock" | information == "hard rock") { 
                g = hard_rock;
            } 
            liste[bearbeiten-1].g = g;
            
          
        }
        
    
}
