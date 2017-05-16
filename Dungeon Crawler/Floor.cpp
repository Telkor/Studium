#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Floor.h"

using namespace std;

Floor::Floor() : Tile(){
   
}

void Floor::onLeave(Tile* toTile){
    
}

void Floor::onEnter(Character* c, Tile* fromTile){
    
}

void Floor::print(){
    cout << ".";
}