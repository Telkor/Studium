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

int Ticket::eindeutigeid = 1;

Ticket::Ticket(){
    
}

Ticket::Ticket(string ownerName, string description){
    owner = ownerName;
    id = eindeutigeid;
    status = open;
    
}

string Ticket::getText() const{
    return text;
}

string Ticket::getOwner() const{
    return owner;
}

int Ticket::getId() const{
        return id;
    }

Status Ticket::getStatus() const{
        return status;
    }

string Ticket::getShort() const{
     
    /*
    size_t pos = text.find(".");
    string text2 = text.substr(0, text);
    text = text2;
    return text; */
    return text;
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

void Ticket::setPriority(int prio){
    priority = prio;
}
int Ticket::getPriority() const{
    return priority;
}

