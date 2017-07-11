#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Floor.h"
#include "Wall.h"
#include "Door.h"
#include "Switch.h"
#include "Tile.h"
#include "Trap.h"
#include "Lever.h"
#include "Position.h"

using namespace std;

#ifndef DUNGEONMAP_H
#define	DUNGEONMAP_H

class DungeonMap{
    
public:
    DungeonMap();
    DungeonMap(int height, int width);
    DungeonMap(int height, int width, const vector<string>& data);
    ~DungeonMap();
    void place(Position pos, Character* c);
    Position findTile(Tile* t) const;
    Tile* findTile(Position pos) const;
    Position findCharacter(Character* c);
    void print(Position rs);
    void placeItem(Item* i, Position pos);
    bool hasLineOfSight(Position from, Position to);
    vector<Position> getPathTo(Position from, Position to);
    
    
private:
    Tile*** Spielwelt;
    int hoehe;
    int breite;
    
};


#endif	/* DUNGEONMAP_H */

