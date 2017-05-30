#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Door.h"

using namespace std;


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
        fromTile->onEnter(c, this);
    else 
        fromTile->setCharacter(c);
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