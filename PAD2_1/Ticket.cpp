/* 
 * File:   Ticket.cpp
 * Author: fs
 *
 * Created on 14. April 2017, 16:39
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;

Ticket::Ticket(){
    
}

Ticket::Ticket(string ownerName, string description){
    owner = ownerName;
    id = eindeutigeid;
    status = open;
    
}

string Ticket::getext() const{
    return text;
}

string Ticket::getOwner() const{
    return owner;
}

int Ticket::getId() const{
        return id;
    }

Status Ticket::getStatus() const{
        return Status;
    }

string Ticket::getShort(){
       
    //text.find('.')
    return text.substr(0, 2);
        //Nur bis zum ersten .
    }

string Ticket::getStatusAsString() const{

        switch(status){
            case open: return "open";
            case closed: return "closed";
            case duplicate: return "duplicate";
            default: return "Status unbekannt";
        }
    }   

void Ticket::print() const{
    cout << "Beschreibung:" << text << endl;
    cout << "Besitzer: " << owner << endl;
    cout << "ID:" << id << endl;
    cout << "Status:" << getStatusAsString() << endl;
}



/*
 * 
 
int main(int argc, char** argv) {

    return 0;
}
*/
