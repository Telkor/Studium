/* 
 * File:   PrioQueue.h
 * Author: fs
 *
 * Created on 15. April 2017, 20:04
 */

#ifndef PRIOQUEUE_H
#define	PRIOQUEUE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <vector>
#include "Ticket.h"

using namespace std;

//template <class T>
class PrioQueue{
public:
    PrioQueue();
    void push(Ticket& t, int priority);
    void pop();
    
		
private:
    int qpriority;
    vector<Ticket> TicketVector;

};

#endif	/* PRIOQUEUE_H */