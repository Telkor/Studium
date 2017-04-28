#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"

Tile::Character(TileTyp typart, Character* heldfigur){
    typ = typart;
    held = heldfigur;
}

Tile::TileTyp Tile::getTile(){
    return typ;
}

Character* Tile::getCharacter(){
    return held;
}

bool Tile::hasCharacter(){
    if(held != nullptr){
        return true;
    }
    return false;
}

void Tile::setCharacter(Character* heldfigur){
    held = heldfigur;
}

void Tile::onLeave(Tile* toTile){
    if(toTile->hasCharacter() == false){
        held = nullptr;
        toTile->onEnter(held, /*?*/ );      
    }
}

void Tile::onEnter(Character* c, Tile* fromTile){
    held = c;
}