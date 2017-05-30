#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Item.h"

using namespace std;

class Tile{

public:
    Tile();
    virtual ~Tile();
    Tile(Character* character);
    //enum TileTyp{Floor, Wall};
    //Tile(TileTyp typart);
    //TileTyp getTile() const;
    Character* getCharacter() const;
    bool hasCharacter() const;
    void setCharacter(Character* heldfigur);
    virtual void onLeave(Tile* toTile);
    virtual void onEnter(Character* c, Tile* fromTile);
    //Character* held = nullptr; // Eigentlich Private (wichtig!!!))
    virtual void print();
    void setItem(Item* i);
    Item* getItem();
    
    
private:
    //TileTyp typ;
    Character* held = nullptr; // Eigentlich Private (wichtig!!!))
    Item* item;
};