#include "AttackController.h"

AttackController::AttackController() {

}


AttackController::AttackController(Character* m_self) : Controller() {
    self = m_self;
    
}

AttackController::~AttackController() {
}

char AttackController::move(){
    Position pos;
    pos = dm->findCharacter(self);
    cout << pos.m_height << " " << pos.m_width << "\n";
    PathtoPlayer = dm->getPathTo(dm->findCharacter(enemy), dm->findCharacter(self));
    
}

void AttackController::setDm(DungeonMap* m_dm){
    dm = m_dm;
}

void AttackController::setEnemy(Character* m_enemy){
    enemy = m_enemy;
}