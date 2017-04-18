#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "PrioQueue.h"

using namespace std;

PrioQueue::PrioQueue(){
    
}

void PrioQueue::push(Ticket& t, int priority){
    int y = 0;
    t.setPriority(priority);
    
    if (TicketVector.size() == 0){  // Wird verwendet um das erste Objekt in den Vektor zu kopieren
            TicketVector.push_back(t);
            return;
    }
   
    if (TicketVector.size() > 0){ 
           for (int i = 0; i < TicketVector.size(); i++){
               //if (y == 1)
                   //break;
               if (TicketVector[i].getPriority() < priority && i == TicketVector.size() - 1){ // Sobald wir uns am Ende des Vektors befinden und das letztes Objekte eine höhere Prioritaet hat
                   TicketVector.push_back(t);    
                   //y++;
                   break;
               }
               else if (TicketVector[i].getPriority() >= priority){ // Ueberpruefen ob die Prioritaet kleiner ist als die Prioritaet des Objektes
                   if (i == TicketVector.size() - 1){       //weitere Ueberpruefung ob wir uns am ende des Objektes befinden
                       TicketVector.push_back(TicketVector[i]); //Letztes Obejekt hinten dranhängen
                       TicketVector[i] = t;     //Das vorletzte Objekt durch das Objekt t vertauschen
                       break;
                   }
                   if (i < TicketVector.size() - 1){        // Ueberpruefung das i sich nicht am Ende des Vektors befindet
                   for (int j = TicketVector.size() - 1; j > i; j--){   //j fängt am Ende des Vektors an
                       if (j == TicketVector.size() - 1)    //Ueberpruefung ob sich j am Ende des Vektors befindet
                           TicketVector.push_back(TicketVector[j]);     //Das letztes Objekt wird nochmal am Ende hinzugefügt
                       else     
                           TicketVector[j + 1] = TicketVector[j];       // alle anderen Objekte werden nach rechts kopiert
                   } 
                   }  
                   TicketVector[i + 1] = TicketVector[i];   // das letzte Objekte auf die das neue Objekt kopiert werden soll wir nach rechts kopiert
                   TicketVector[i] = t;     //auf der Stelle i wird das neue Objekt kopiert
                   break;
               }
              
           }
   
    }
}

void PrioQueue::pop(){
    if (TicketVector.size() == 0){
        cout << "Keine Tickets vorhanden" << endl << endl;
        
        return;
    }
    else    
    TicketVector[0].print();
    
    for (int i = 1; i < TicketVector.size(); i++) {
        TicketVector[i - 1] = TicketVector[i];
    }
    TicketVector.erase(TicketVector.end());    
}

void PrioQueue::deleteV(){
    TicketVector.erase(TicketVector.begin(), TicketVector.end());
    cout << "Alle Tickets geloescht" << endl << endl;
}