#ifndef TILE_H
#define	TILE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <vector>
#include "Character.h"

#endif	/* TILE_H */

class Tile{

public:
    enum TileTyp{Floor, Wall};
    Character(TileTyp typart, Character* heldfigur);
    TileTyp getTile();
    Character* getCharacter();
    bool hasCharacter();
    void setCharacter();
    void onLeave(Tile* toTile);
    void onEnter(Character* c, Tile* fromTile);
    
    
private:
    TileTyp typ;
    Character* held = nullptr;
    
};