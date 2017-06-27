#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Switch.h"

using namespace std;

void Switch::print(){
    if(Active::getStatus() == true && Active::hasCharacter() == false){
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
    
}


void Switch::onLeave(Tile* toTile){
    
    toTile->onEnter(getCharacter(), this); 
} 