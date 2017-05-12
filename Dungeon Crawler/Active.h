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
    Passive* ppointer;           
    void setPassive(Passive* ppointer_);
private:
            
  
};
#endif	/* ACTIVE_H */

