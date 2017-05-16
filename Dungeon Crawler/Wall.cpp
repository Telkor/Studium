#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Wall.h"

using namespace std;

void Wall::onLeave(Tile* toTile){
   /* if(toTile->hasCharacter() == false && toTile->getTile() == Floor){
        toTile->onEnter(held, this);      
        held = nullptr;
    } */ 
}

void Wall::onEnter(Character* c, Tile* fromTile){
    fromTile->hasCharacter();
}

void Wall::print(){
    cout << "#";
}