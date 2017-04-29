#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Tile.h"

#ifndef DUNGEONMAP_H
#define	DUNGEONMAP_H

struct Position{
    int height;
    int width;
};

class DungeonMap{
    
public:
    DungeonMap(int height, int width);
    DungeonMap(int height, int width, const vector<string>& data);
    int hoehe;
    int breite;
    Tile*** Spielwelt;
    
private:
    DungeonMap();
    ~DungeonMap();
    
};


#endif	/* DUNGEONMAP_H */

