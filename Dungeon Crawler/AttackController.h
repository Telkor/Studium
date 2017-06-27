#ifndef ATTACKCONTROLLER_H
#define	ATTACKCONTROLLER_H
#include "Controller.h"
#include "DungeonMap.h"
#include "Character.h"
#include <vector>

using namespace std;

class AttackController : public Controller {
public:
    AttackController(DungeonMap* m_dm, Character* ch);
    virtual ~AttackController();
    char move();
private:
    Character* character;
    DungeonMap* dm;
    vector<Position> PathtoPlayer;
};

#endif	/* ATTACKCONTROLLER_H */

