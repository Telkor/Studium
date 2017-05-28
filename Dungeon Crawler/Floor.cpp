#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Floor.h"

using namespace std;

Floor::Floor() : Tile(){
   
}

Floor::Floor(Item* m_item) : Tile(){
    item = m_item;
}

void Floor::onLeave(Tile* toTile){
    toTile->onEnter(getCharacter(), this);      
    
}

void Floor::onEnter(Character* c, Tile* fromTile){
    setCharacter(c);
    fromTile->setCharacter(nullptr);
}

void Floor::print(){
    if (hasCharacter() == true)
        cout << getCharacter()->getZeichen();
    
    else if (item != nullptr ){
        cout << "*";
    }
    
    else{
        cout << ".";  
    }
        
}