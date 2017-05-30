#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Trap.h"

using namespace std;

Trap::Trap(){
    
}

bool Trap::setTriggered(bool m_triggered){
    triggered = m_triggered;
}

void Trap::print(){
    
    if(triggered == true){
        cout << "T";
    }
    else{
        cout << ".";
    }
}