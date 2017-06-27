#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Door.h"

using namespace std;


Door::Door() : Passive(){
    
}

void Door::print(){
    if(getStatus() == false && Passive::hasCharacter() == false)
        cout << "X";
     
    else if (Passive::hasCharacter() == true)
        cout << Passive::getCharacter()->getZeichen();
    
    else
        cout << "/";
    
}

void Door::onEnter(Character* c, Tile* fromTile){
    if (Passive::getStatus() == false)
        fromTile->setCharacter(c);
    else {
        setCharacter(c);
        fromTile->setCharacter(nullptr);
    }
} 

void Door::onLeave(Tile* toTile){
    toTile->onEnter(getCharacter(), this);
}

bool Door::isTransparent(){
    if (Passive::getStatus() == false)
        return false;
    else  
        return true;
    
}