#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <vector>
#include "Character.h"



class Tile{

public:
    //Tile();
    enum TileTyp{Floor, Wall};
    Tile(TileTyp typart, Character* heldfigur);
    TileTyp getTile();
    Character* getCharacter();
    bool hasCharacter();
    void setCharacter(Character* heldfigur);
    void onLeave(Tile* toTile);
    void onEnter(Character* c, Tile* fromTile);
    
    
private:
    TileTyp typ;
    Character* held = nullptr;
    
};