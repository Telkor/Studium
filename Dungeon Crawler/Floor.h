#ifndef FLOOR_H
#define	FLOOR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
#include "Item.h"
#include "Character.h"

using namespace std;

class Floor : public Tile{

public:
    Floor();
    Floor(Item* m_item);
    void onLeave(Tile* toTile);
    void onEnter(Character* c, Tile* fromTile);
    virtual void print() override;
    bool isTransparent() override;
    

private:
    //Character* held = new Character;
    
};

#endif	/* FLOOR_H */

