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
       bool Status();
       void setStatus();
       void getStatus();
private:
            
  
};


#endif	/* PASSIVE_H */

