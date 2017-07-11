#ifndef ATTACKCONTROLLER_H
#define	ATTACKCONTROLLER_H
#include "Controller.h"
//#include "DungeonMap.h"
//#include "Character.h"
//#include "DungeonMap.h"
#include <vector>
#include "Position.h"
#include "DungeonMap.h"

class Character;

using namespace std;

class AttackController : public Controller {
public:
    AttackController();
    AttackController(Character* m_self);
    virtual ~AttackController();
    char move();
    void setDm(DungeonMap* m_dm) override;
    void setEnemy(Character* m_enemy) override;
   
    
private:
    Character* self;
    Character* enemy;
    DungeonMap* dm = new DungeonMap();
    vector<Position> PathtoPlayer;
};

#endif	/* ATTACKCONTROLLER_H */

