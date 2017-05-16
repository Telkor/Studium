#ifndef DOOR_H
#define	DOOR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Passive.h"

using namespace std;

class Door : public Passive{

public:
    
    void print() override;
   
private:
            
};

#endif	/* DOOR_H */

