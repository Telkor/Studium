#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Trap.h"

using namespace std;

Trap::Trap(){
    triggered = false;
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
        c->damage(20);
        setTriggered(true);
        cout << "Du bist auf eine Falle getreten und hast 20 HP verloren!" << "\n";
    }
    
    else{
        fromTile->setCharacter(nullptr);
        setCharacter(c);
    }
    
    
    
}

void Trap::onLeave(Tile* toTile){
    
    toTile->onEnter(getCharacter(), this); 
} 