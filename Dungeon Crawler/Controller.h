#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"

class Controller{

public:
    
virtual char move() = 0;    
Controller(Character* m_character);    

private:
    Character* character;
    
};


#endif	/* CONTROLLER_H */

