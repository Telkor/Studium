#ifndef TICKET_H
#define	TICKET_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

enum Status{open, closed, duplicate}; 

class Ticket{
public:
    
    Ticket();
    Ticket(string ownerName, string description);
    string getText() const;
    string getOwner() const;
    int getId() const;
    Status getStatus() const;
    string getShort();
    string getStatusAsString() const;
    void print();
    void setPriority(int prio);
    int getPriority()const;
    void setOwner(string own);
    void setText(string mtext);
    void static setEinid();
    
    
    
private:
    string text;
    string owner;
    Status status;
    int id;
    static int eindeutigeid;
    int priority;
};



#endif	/* TICKET_H */

