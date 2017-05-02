#include "GameEngine.h"

using namespace std;

GameEngine::GameEngine(int height, int width, const vector<string>& data){
    DungeonMap dm(int height, int width, const vector<string>& data);
    auto c = new Character();
    
}


bool GameEngine::finished(){
    
}

void GameEngine::run(){
    while (!finished())
        turn();
}

void GameEngine::turn(){
    
    Character c;
    char move = c.move();
    
    
}