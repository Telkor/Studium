#include <cstdlib>
#include <iostream>
#include "PrioQueue.h"
#include "Ticket.h"
#include <string>

using namespace std;

int main() {
    PrioQueue q;
    
    
    while (true){
        
        string eingabe;
        string owner;
        string text;
        int x;
        
       
        
        cout << "1. Neues Ticket anlegen" << endl;
        cout << "2. Alle Tickets löschen" << endl;
        cout << "3. Nächstes Ticket aus der Queue anzeigen" << endl;
        cout << "4. Programm beenden" << endl;
        
        cin >> eingabe;
        
        if (eingabe == "1"){
            cout << "Bitte geben Sie ihren Namen ein:" << endl;
            //cin >> owner;
            
            cin.ignore(255, '\n');
            getline(cin, owner);
            
            cout << "Bitte beschreiben Sie das Problem:" << endl;
            //cin >> text;
            cin.ignore(255, '\n');
            getline(cin, text);
            
            cout << "Bitte geben Sie eine Priorität ein:" << endl;
            cin >> x;
            Ticket t(owner, text);
            q.push(t, x);
            
        }
        
        if (eingabe == "2"){
            q.deleteV();
        }
        
        if (eingabe == "3"){
            q.pop(); 
        }
        
        if (eingabe == "4"){
            return 0;
        }
        
    }
    
  /*
    Ticket t1("a","a");
    Ticket t2("b","b");
    Ticket t3("c","c");
    Ticket t4("d","d");
    Ticket t5("e","e");
    Ticket t6("f","f");
    Ticket t7("g","g");
    
    q.push(t1, 0);
    q.push(t2, 3);
    q.push(t3, 1);
    q.push(t4, 5);
    q.push(t5, 2);
    q.push(t6, 9);
    q.push(t7, 7);
    
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    
    
    
  */
    
    
    return 0;
}

