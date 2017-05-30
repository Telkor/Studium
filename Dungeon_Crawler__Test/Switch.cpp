#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Switch.h"

using namespace std;

void Switch::setPassive(Passive* m_pPointer){
  
}


void Switch::print(){
    if(Active::getStatus() == true){
        cout << "!";
    }
    else if(Active::hasCharacter() == true)
        cout << Active::getCharacter()->getZeichen();
    
    else{
        cout << "?";
    }
}

void Switch::onEnter(Character* c, Tile* fromTile){
    Active::setStatus(true);
    fromTile->setCharacter(nullptr);
    setCharacter(c);
    //getPassive()->setStatus(true);
    
    
}


void Switch::onLeave(Tile* toTile){
    
    toTile->onEnter(getCharacter(), this); 
} 