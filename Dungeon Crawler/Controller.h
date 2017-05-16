#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>



class Character;

class Controller{

public:
    
virtual char move() = 0;    
Controller(Character* m_character);    

private:
    Character* character;
    
};


#endif	/* CONTROLLER_H */

