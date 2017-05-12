#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <vector>
#include "Character.h"

using namespace std;

class Tile{

public:
    enum TileTyp{Floor, Wall};
    Tile(TileTyp typart);
    TileTyp getTile() const;
    Character* getCharacter() const;
    bool hasCharacter() const;
    void setCharacter(Character* heldfigur);
    void virtual onLeave(Tile* toTile);
    void virtual onEnter(Character* c, Tile* fromTile);
    //Character* held = nullptr; // Eigentlich Private (wichtig!!!))
    
private:
    TileTyp typ;
    Character* held = nullptr; // Eigentlich Private (wichtig!!!))
    
};