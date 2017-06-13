#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Floor.h"

using namespace std;

Floor::Floor() : Tile(){
   
}

void Floor::onLeave(Tile* toTile){
    toTile->onEnter(getCharacter(), this);      
    
}

void Floor::onEnter(Character* c, Tile* fromTile){
    if (hasCharacter() == false){
    setCharacter(c);
    fromTile->setCharacter(nullptr);
    if (getItem() != nullptr)
        c->addItem(getItem());
    setItem(nullptr);
    }
    else 
        fromTile->setCharacter(c);
    
    
}

void Floor::print(){
    if (hasCharacter() == true)
        cout << getCharacter()->getZeichen();
    
    else if (getItem() != nullptr){
        cout << "*";
    }
    
    else{
        cout << ".";  
    }
        
}

bool Floor::isTransparent(){
    return true;
}