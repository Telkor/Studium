#ifndef WALL_H
#define	WALL_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
//#include "Character.h"

using namespace std;

class Wall : public Tile{

public: 
    void onEnter(Character* c, Tile* fromTile);
    void print() override;
                
private:
            
    
};


#endif	/* WALL_H */

