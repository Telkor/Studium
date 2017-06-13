#include "GameEngine.h"
#include "Active.h"
#include "Trap.h"

using namespace std;



GameEngine::GameEngine(int height, int width, const vector<string>& data, vector<string>& specialTiles): dm(height,width,data) {
            
    //linker(info);
    link(specialTiles);
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
        bool exit = false;
        Position pos;
        pos = dm.findCharacter(spielfiguren.at(i));
        dm.print(pos);
        
        //Position pos;
        
         
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
                            
                case 'r':  
                            cout << "test";
                            break;            
                
                case 'g':   
                            
                            int eingabe;
                          
                            while(true){
                            cout << "1. Spielerinfos anzeigen" << "\n";
                            cout << "2. Zurueck zum Spiel" << "\n";
                            cout << "3. Spiel beenden" << "\n";
                            
                            cin >> eingabe;
                             
                            if(eingabe == 1){
                              spielfiguren.at(i)->showInfo();  
                            }
                            
                            if(eingabe == 2){
                              break;  
                            }
                            
                            if(eingabe == 3){
                                spielEnde = 0;
                                exit = true;
                                break;
                            }
                            
                            }             
                            
                default:
          
                            break;
        }
        cout << newPos.m_height << " " << newPos.m_width << endl;
        if (exit)
            break;
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

void GameEngine::link(vector<string> &specialTiles){
    Active* activetile;
    Passive* passivetile;
    Position posobj;
    string tmp;
    string obj;
    string controller;
    size_t spos;
    char zeichen;
    size_t tpos;
    
    for (int i = 0; i < specialTiles.size();  i++){
        tmp = static_cast<string> (specialTiles.at(i));
        spos = tmp.find(" ");
        obj = tmp.substr(0, spos);
        tmp = tmp.substr(spos+1, tmp.length());
        tpos = ++spos;
        
        
        if (obj == "Character"){
            zeichen = static_cast<char> (specialTiles.at(i).at(tpos));
            spos = tmp.find(" ");
            tmp = tmp.substr(spos+1, tmp.length());
            tpos += ++spos;
            spos = tmp.find(" ");
            tmp = tmp.substr(spos+1, tmp.length());
            obj = tmp.substr(0,--spos);
            int strength = atoi(obj.c_str());
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            int stamina = atoi(obj.c_str());
            tmp = tmp.substr(spos + 1, tmp.length());                       
            spos = tmp.find(" ");
            controller = tmp.substr(0, spos);         
            tmp = tmp.substr(spos + 1, tmp.length());
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_height = atoi(obj.c_str());
            tmp = tmp.substr(spos + 1, tmp.length());
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_width = atoi(obj.c_str());
            
            
            
            
            if (controller == "ConsoleController"){
                Character* c = new Character(zeichen, strength, stamina, false);
                dm.place(posobj, c);
                spielfiguren.push_back(c);
            }
            if (controller == "StationaryController"){
                Character* c = new Character(zeichen, strength, stamina, true);
                dm.place(posobj, c);
                spielfiguren.push_back(c);
            }
        }
    
        if (obj == "Greatsword"){
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_height = atoi(obj.c_str());
            tmp = tmp.substr(spos+1, tmp.length());
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_width = atoi(obj.c_str());
            
            Greatsword* gs = new Greatsword();
            dm.placeItem(gs, posobj);
        }
        
        if (obj == "Door"){
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_height = atoi(obj.c_str());
            tmp = tmp.substr(spos+1, tmp.length());
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_width = atoi(obj.c_str());
            spos = tmp.find(" ");
            tmp = tmp.substr(spos+1, tmp.length());
            passivetile = dynamic_cast<Passive*> (dm.findTile(posobj));
            spos = tmp.find(" ");
            tmp = tmp.substr(spos+1, tmp.length());
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_height = atoi(obj.c_str());
            tmp = tmp.substr(spos+1, tmp.length());
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_width = atoi(obj.c_str());
            activetile = dynamic_cast<Active*> (dm.findTile(posobj));
        
            activetile->setPassive(passivetile);
        }
        
        if (obj == "Trap"){
            Trap* trap;
            
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_height = atoi(obj.c_str());
            tmp = tmp.substr(spos+1, tmp.length());
            spos = tmp.find(" ");
            obj = tmp.substr(0, spos);
            posobj.m_width = atoi(obj.c_str());
        
            trap = dynamic_cast<Trap*> (dm.findTile(posobj));
        }
    }
}

