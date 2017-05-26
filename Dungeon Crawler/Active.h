#ifndef ACTIVE_H
#define	ACTIVE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
#include "Passive.h"

using namespace std;

class Active : public Tile{

public: 
              
    virtual void setPassive(Passive* m_pPointer);
    void setStatus(bool m_status);
    virtual bool getStatus();
    //virtual void onLeave(Tile* toTile);
    virtual void onEnter(Character* c, Tile* fromTile) = 0;
    virtual void onLeave(Tile* toTile) = 0;
    
private:
    Passive* pPointer = new Passive; 
    bool status;
    Character* held;
  
};
#endif	/* ACTIVE_H */

