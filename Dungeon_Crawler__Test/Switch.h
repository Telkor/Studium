#ifndef SWITCH_H
#define	SWITCH_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Active.h"

using namespace std;

class Switch : public Active{
    
public:
    //Switch();
    void setPassive(Passive* m_pPointer);
    void print() override;
    void onEnter(Character* c, Tile* fromTile);
    void onLeave(Tile* toTile);
    
private:
    
};

#endif	/* SWITCH_H */

