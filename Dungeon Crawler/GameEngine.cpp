#include "GameEngine.h"

using namespace std;

GameEngine::GameEngine(int height, int width, const vector<string>& data) {
    dm = DungeonMap(height,width,data);
    Character* c = new Character();
    spielfiguren.push_back(c);
}

GameEngine::~GameEngine(){
    dm.~DungeonMap();
}


bool GameEngine::finished() const{
    if (spielEnde <= 0)
        return true;
}

void GameEngine::run(){
    while (!finished())
        turn();
}

void GameEngine::turn(){
    for (int i = 0; i < spielfiguren.size(); i++){
        
        Position pos;
        
        dm.findCharacter(spielfiguren.at(i)) = pos; 
     
        Tile* oldTile = dm.findTile(pos);
        Position newPos = pos;
        Tile* newTile;
        
        switch(spielfiguren.at(i)->move()){
                case 'w':   
                            newPos.m_height--;
                            newTile = dm.findTile(newPos);
                            oldTile->onLeave(newTile);
                            break;
                
                case 'a':   
                            newPos.m_width--;
                            newTile = dm.findTile(newPos);
                            oldTile->onLeave(newTile);
                            break;         
                            
                case 'd':   
                            newPos.m_width++;
                            newTile = dm.findTile(newPos);
                            oldTile->onLeave(newTile);
                            break;         
        
                case 's':   
                            newPos.m_height++;
                            newTile = dm.findTile(newPos);
                            oldTile->onLeave(newTile);
                            break;                    
    
        }
    } 
    spielEnde--;

}