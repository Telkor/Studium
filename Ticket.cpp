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
    text = description;
    id = eindeutigeid;
    status = open;
    eindeutigeid += 1;
    
   
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

string Ticket::getShort(){
     
   
    size_t pos = text.find(".");
    string text2 = text.substr(0, pos);
    text = text2;
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

void Ticket::print(){
    cout << "Besitzer: " << owner << endl;
    cout << "Beschreibung: " << getShort() << endl;
    cout << "ID:" << id << endl;
    cout << "Status:" << getStatusAsString() << endl << endl;
}

void Ticket::setPriority(int prio){
    priority = prio;
}
int Ticket::getPriority() const{
    return priority;
}

void Ticket::setOwner(string own){
    owner = own;
}

void Ticket::setText(string mtext){
    text = mtext;
}

void Ticket::setEinid(){
    eindeutigeid += 1;
}