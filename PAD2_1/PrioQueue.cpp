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
    
    if (TicketVector.size() == 0){
            TicketVector.push_back(t);
            return;
        }
   
    if (TicketVector.size() > 0){
           for (int i = 0; i < TicketVector.size(); i++){
               if (y == 1)
                   break;
               if (TicketVector[i].getPriority() < priority && i == TicketVector.size() - 1){
                   TicketVector.push_back(t);    
                   y++;
                   continue;
               }
               else if (TicketVector[i].getPriority() > priority){
                   for (int j = TicketVector.size() - 1; j > i; j--){
                       if (j == TicketVector.size() - 1)
                           TicketVector.push_back(TicketVector[j]);
                       else     
                           TicketVector[j - 1] = TicketVector[j];  
                    }  
                   TicketVector[i] = t;
               }
              
           }
   
    }
}

void PrioQueue::pop(){
    TicketVector[0].print();
    
    for (int i = 1; i < TicketVector.size(); i++) {
        TicketVector[i - 1] = TicketVector[i];
    }
        
    
}
