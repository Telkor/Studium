/* 
 * File:   CUI.cpp
 * Author: fs
 * 
 * Created on 3. Januar 2018, 18:19
 */

#include "CUI.h"

using namespace std;

CUI::CUI() {
    
    NamenEinlesen();
    Ort_Dateiname = "Ortsnamen.txt";
    
}


CUI::~CUI() {
    
    NamenSchreiben();
    for(auto ortsname : Ortsname){
        delete ortsname;
    }
}

int CUI::zeigeMenu(){
    
    while(true){
    cout <<  "\n" << "1. Neuen Ort (mit Namen) hinzufügen \n";
    cout << "2. Ort löschen \n";
    cout << "3. Neue Namen aus Textdatei einlesen \n";
    cout << "4. Alle Namen in Textdatei schreiben \n";
    cout << "5. Alle Namen ausgeben \n";
    cout << "6. Start- und Zielort eingeben \n";
    cout << "7. Beenden \n \n";
    
    cout.flush();
    cin >> ws;
    int c = cin.peek();
    
    //if(c == EOF) return 1;
    if(isdigit(c)){
        int n;
        cin >> n;
        cout << "Sie haben den " << n << ". Menüpunkt ausgewählt." "\n";
        
        switch(n){
            case 1: Ortneu(); break;
            case 2: Ortloeschen(); break;
            case 3: NamenEinlesen(); break;
            case 4: NamenSchreiben(); break;
            case 5: NamenAusgeben(); break;
            case 6: StartZielEingeben(); break;
            case 7: return false; break;
        }
            
    }
    else{
        cout << "Sie müssen eine Zahl eingeben. \n \n";
        cin.ignore();
    }
    }
    

}

void CUI::Ortneu(){
    string* eingabe = new string;
    
    cout << "Geben Sie einen Neuen Ort an:  \n";
    
    cin >> *eingabe;
    Ortsname.push_back(eingabe);
    
 /*   if(Ortsname.size() == 0)
        Ortsname.push_back(eingabe);
    
    else{
        for(unsigned int i = 0; i < Ortsname.size(); i++){
            if(eingabe == Ortsname.at(i))
            cout << "Dieser Ort existiert bereits. \n";
        else
            Ortsname.push_back(eingabe);
        }
    } */
}

void CUI::Ortloeschen(){
    string eingabe;
    
    cout << "Welchen Ort möchten Sie löschen? \n";
    cin >> eingabe;
    for(unsigned int i = 0; i < Ortsname.size(); i++)
        if(eingabe == *Ortsname.at(i)){
            Ortsname.erase(Ortsname.begin()+i);
            
            cout << "Ortsname wurde gelöscht.";
        }
}

void CUI::NamenEinlesen(){
 
    ifstream input(Ort_Dateiname.c_str(), ios::in | ios::binary);
    int anzahlOrteInDatei = 0;
    input.read((char*) &anzahlOrteInDatei, sizeof (int));
    int zeichenlaenge = 0;
    for (int i = 0; i < anzahlOrteInDatei; i++)
    {
        input.read((char*) &zeichenlaenge, sizeof (int));
        char buf[zeichenlaenge];
        input.read((char*) &buf, zeichenlaenge);
        string* tmp = new string;
        Ortsname.push_back(tmp);
        (*Ortsname.back()).assign(buf, zeichenlaenge);
    }
    input.close(); 
    

    
   // cout << "Orte wurden eingelesen. \n";
      
    /* 
    ifstream file;
    int anzahlOrte;
    
    string* ortsname = new string;
    file.open("ort.txt");
    
    if(file.is_open()){
        file >> anzahlOrte;
        
        for(int i = 0; i < anzahlOrte; i++){
            while(!file.eof()){
         //       getline(file, ortsname);
                // file >> ortsname;
                Ortsname.push_back(ortsname);  
            }
        }
        file.close();
    }
    else
        cerr << "Datei konnte nicht geöffnet werden.";
    
    
    */
}


void CUI::NamenSchreiben(){

    ofstream output(Ort_Dateiname.c_str(), ios::out | ios::binary);
    int anzahlOrte = Ortsname.size();
    output.write((char*) &anzahlOrte, sizeof (int));
    int zeichenlaenge = 0;
    for (unsigned int i = 0; i < Ortsname.size(); i++)
    {
        zeichenlaenge = (*Ortsname[i]).size();
        output.write((char*) &zeichenlaenge, sizeof (int));
        output.write((char*) (*Ortsname[i]).c_str(), zeichenlaenge);
    }
    output.close();
   // cout << "Orte wurden in Datei geschrieben \n";
}

void CUI::NamenAusgeben(){
        
    cout << "Ortsnamen: ";
    for(unsigned int i = 0; i < Ortsname.size(); i++)
        cout << "\n" << *Ortsname.at(i);
}

void CUI::StartZielEingeben(){
    string start;
    string ziel;
    
    cout << "Start: \n";
    cin >> start;
    
    for(unsigned int i = 0; i < Ortsname.size(); i++){
        if(start == *Ortsname.at(i))
            cout << "Start gefunden. Geben Sie ihr Ziel an: \n";   
        }         
        
//        else{
//            cout << "Start wurde nicht gefunden. \n";
//       }
        cin >> ziel;
        for(unsigned int i = 0; i < Ortsname.size(); i++){
            if(ziel == *Ortsname.at(i))
                cout << "Ziel wurde gefunden. Route wird erstellt. \n";
//            else
//                cout << "Ziel wurde nicht gefunden. \n";
        } 
     
}

/*
int CUI::Beenden(){
    return 0;
} 
*/