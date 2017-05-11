#include "GameEngine.h"

using namespace std;

GameEngine::GameEngine(int height, int width, const vector<string>& data): dm(height,width,data) {
    Character* c = new Character('!');
    spielfiguren.push_back(c);
    Position pos;
    pos.m_height = 5;
    pos.m_width = 5;
    dm.place(pos, c);
}

GameEngine::~GameEngine(){
   
}


bool GameEngine::finished() const{
    if (spielEnde <= 0)
        return true;
    else return false;
}

void GameEngine::run(){
    while (!finished())
        turn();
}

void GameEngine::turn(){
    for (int i = 0; i < spielfiguren.size(); i++){
        dm.print();
        
        Position pos;
                
        pos = dm.findCharacter(spielfiguren.at(i)); 
        //cout << pos.m_height;
 
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
                
                default:
                            break;
        }
    } 
    spielEnde--;

}