#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Lever.h"

using namespace std;

void Lever::setPassive(Passive* m_pPointer){
  
}

void Lever::print(){
    if(Active::getStatus() == true){
        cout << "!";
    }
    else{
        cout << "?";
    }
}

void Lever::onEnter(Character* c, Tile* fromTile){
    if (Active::getStatus() == true)
        Active::setStatus(false);
    else 
        Active::setStatus(true);
    fromTile->setCharacter(nullptr);
    setCharacter(c);
}
                                                    //Lever Funktionalität fehlt noch

void Lever::onLeave(Tile* toTile){
    
    toTile->onEnter(getCharacter(), this);
    
} 
