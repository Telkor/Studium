#include <cstdlib>
#include <iostream>
#include "PrioQueue.h"
#include "Ticket.h"
#include <string>

using namespace std;

int main() {
    PrioQueue q;
    Ticket t1("a","a");
    Ticket t2("b","b");
    Ticket t3("c","c");
    
    
    q.push(t1, 0);
    q.push(t2, 3);
    q.push(t3, 1);
    
    q.pop();
    q.pop();
    q.pop();
        
    
    
    
  
    
    
    return 0;
}

