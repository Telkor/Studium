
#ifndef LEVER_H
#define	LEVER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Active.h"        

class Lever : public Active{
    
public:

    void setPassive(Passive* m_pPointer);
    void print() override;
    void onEnter(Character* c, Tile* fromTile);
    void onLeave(Tile* toTile);
    
private:
    
};
        
        
#endif	/* LEVER_H */

