#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Wall.h"

using namespace std;


void Wall::onEnter(Character* c, Tile* fromTile){
    fromTile->setCharacter(c);
}

void Wall::print(){
    cout << "#";
}

bool Wall::isTransparent(){
    return false;
}