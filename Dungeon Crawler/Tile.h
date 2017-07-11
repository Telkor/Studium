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
    Character* getCharacter() const;
    bool hasCharacter() const;
    void setCharacter(Character* heldfigur);
    virtual void onLeave(Tile* toTile);
    virtual void onEnter(Character* c, Tile* fromTile);
    virtual void print();
    void setItem(Item* i);
    Item* getItem();
    virtual bool isTransparent();
    
    
private:
    //TileTyp typ;
    Character* held = nullptr; // Eigentlich Private (wichtig!!!))
    Item* item;
};