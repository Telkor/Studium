#ifndef TICKET_H
#define	TICKET_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

enum Status {open, closed, duplicate}; 

class Ticket {
public:
    string text;
    string owner;
    Status status;
    int id;
    
    Ticket();
    Ticket(string, string);
    
    
private:
    static int eindeutigeid = 1;
};


#endif	/* TICKET_H */

