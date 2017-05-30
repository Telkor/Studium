#ifndef PASSIVE_H
#define	PASSIVE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"



using namespace std;

class Passive : public Tile{

public: 
       //Passive();
       void setStatus(bool m_status);
       bool getStatus();
       void onEnter(Character* c, Tile* fromTile);
       void onLeave(Tile* toTile) override;
       
private:
      bool status = false;      
  
};


#endif	/* PASSIVE_H */

