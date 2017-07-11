#include "GameEngine.h"
#include "AttackController.h"
#include "StationaryController.h"
#include "ConsoleController.h"


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
    if (spielfiguren.size() == 0){
        cout << "Game Over!" << "\n";
        spielEnde = 0;
        return;
    }
    
    for (int i = 0; i < spielfiguren.size(); i++){
        Position pos;
        int count = 0;
        
        
        
        for (int j = 0; j < spielfiguren.size(); j++){
            if (spielfiguren.at(j)->getZeichen() == '@')
                count++;
        }
        
        if (count == 0){
            cout << "Game Over!" << "\n";
            spielEnde = 0;
            return;
        }
        
        count = 0;
        
       
       
     
        
        
                    
        pos = dm.findCharacter(spielfiguren.at(i));
        dm.print(pos);
        
 
        Tile* oldTile = dm.findTile(pos);
        
        Position newPos = pos;
       
        Tile* newTile;
        
        switch(spielfiguren.at(i)->move()){
            case 'w':   
                        newPos.m_height--;
                        newTile = dm.findTile(newPos);
                        oldTile->onLeave(newTile);
                        break;
                
            case 'q': 
                    newPos.m_height--;
                    newPos.m_width--;
                    newTile = dm.findTile(newPos);
                    oldTile->onLeave(newTile);
                    break;
             
            case 'e':
                    newPos.m_height--;
                    newPos.m_width++;
                    newTile = dm.findTile(newPos);
                    oldTile->onLeave(newTile);
                    break;
                    
            case 'y':
                newPos.m_height++;
                    newPos.m_width--;
                    newTile = dm.findTile(newPos);
                    oldTile->onLeave(newTile);
                    break;
                    
            case 'c':
                newPos.m_height++;
                    newPos.m_width++;
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
        
                case 'x':   
                            newPos.m_height++;
                            newTile = dm.findTile(newPos);
                            oldTile->onLeave(newTile);
                            break;                    
                            
                case 's':  
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
                                return;
                                break;
                            }
                            
                            }             
                            
                default:
          
                            break;
        }
        if (spielfiguren.at(i)->getHP() <= 0){
            pos = dm.findCharacter(spielfiguren.at(i));
            dm.findTile(pos)->setCharacter(nullptr);
            delete spielfiguren.at(i);
            spielfiguren.erase(spielfiguren.begin()+i);
            return;          
        }
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
            spos = tmp.find(" ");
            obj = tmp.substr(0,spos);
            tmp = tmp.substr(spos+1, tmp.length());
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
                Controller* controller = new ConsoleController();
                Character* c = new Character(zeichen, strength, stamina, controller);
                dm.place(posobj, c);
                spielfiguren.push_back(c);
            }
            if (controller == "StationaryController"){
                Controller*  controller = new StationaryController;
                Character* c = new Character(zeichen, strength, stamina, controller);
                dm.place(posobj, c);
                spielfiguren.push_back(c);
            }
            
            if (controller == "AttackController"){
                Controller* controller = new AttackController;
                Character* c = new Character(zeichen, strength, stamina, controller);
                dm.place(posobj, c);
                c->setController(&dm, spielfiguren.at(0));
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

