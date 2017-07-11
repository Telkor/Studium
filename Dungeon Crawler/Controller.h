#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class DungeonMap;

class Character;

class Controller{

public:
    Controller(); 
    virtual char move() = 0;    
    Controller(Character* m_character);    
    void virtual setEnemy(Character* enemy);
    void virtual setDm(DungeonMap* m_dm);

protected:
    Character* character;
    DungeonMap* dm;
    
    
    
};


#endif	/* CONTROLLER_H */

