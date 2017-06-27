#include "AttackController.h"
#include "DungeonMap.h"

AttackController::AttackController(DungeonMap* m_dm, Character* ch) : Controller() {
    dm = m_dm;
    character = ch;
}

AttackController::~AttackController() {
}

char AttackController::move(){
//    PathtoPlayer = dm->getPathTo(dm->findCharacter(character), );
}