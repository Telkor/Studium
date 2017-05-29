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

bool Trap::getTriggered(){
    return triggered;
}

void Trap::print(){
    
    if(triggered == true){
        cout << "T";
    }
    else{
        cout << ".";
    }
    
    
}

void Trap::onEnter(Character* c, Tile* fromTile){
    
    if(getTriggered() == false){
        fromTile->setCharacter(nullptr);
        setCharacter(c);
        c->getMaxHP() - 20;
        setTriggered(true);
    }
    
    else{
        fromTile->setCharacter(nullptr);
        setCharacter(c);
        setTriggered(true);
    }
    
    
    
}


void Trap::onLeave(Tile* toTile){
    
    toTile->onEnter(getCharacter(), this); 
} 