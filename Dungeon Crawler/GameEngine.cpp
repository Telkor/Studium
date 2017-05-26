#include "GameEngine.h"
#include "Active.h"

using namespace std;

GameEngine::GameEngine(int height, int width, const vector<string>& data, vector<string> info): dm(height,width,data) {
            
    
    Character* c = new Character('8');
    spielfiguren.push_back(c);
    Position pos;
    pos.m_height = 7;
    pos.m_width = 7;
    dm.place(pos, c);
    linker(info);
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
        cout << newPos.m_height << " " << newPos.m_width << endl;
    } 
    spielEnde--;
    
}

void GameEngine::linker(vector<string>& info){
    Active* activetile;
    Passive* passivetile;
    Position posobj;
    
    for (int i = 0; i < info.size(); i++){
        posobj.m_height = static_cast<int> (info.at(i).at(0)) - 48;
        posobj.m_width = static_cast<int> (info.at(i).at(2)) - 48;
        //cout << posobj.m_height /* << posobj.m_width */ << endl;
        passivetile = dynamic_cast<Passive*> (dm.findTile(posobj));
        
        posobj.m_height = static_cast<int> (info.at(i).at(6)) - 48;
        posobj.m_width = static_cast<int> (info.at(i).at(8)) - 48;
        activetile = dynamic_cast<Active*> (dm.findTile(posobj));
        
        activetile->setPassive(passivetile);
    }    
}