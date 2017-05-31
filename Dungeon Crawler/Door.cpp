#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Door.h"

using namespace std;


Door::Door() : Passive(){
    
}

void Door::print(){
    if(getStatus() == false){
        cout << "X";
    }
    else{
        cout << "/";
    }
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