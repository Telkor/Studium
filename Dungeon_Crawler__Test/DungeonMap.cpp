#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "DungeonMap.h"
#include "Trap.h"
#include "Lever.h"

using namespace std;

DungeonMap::DungeonMap(){
    hoehe = 1;
    breite = 1;
    
    Spielwelt = new Tile**[1];
    
    for(int i = 0; i < 1; i++) {
        Spielwelt[i] = new Tile*[1];
    }
    
    for (int i = 0; i < 1; i++){
       
        for (int j = 0; j < 1; j++){
            
            Spielwelt[i][j] = nullptr;
        }
            
    }
}


DungeonMap::DungeonMap(int height, int width){ //zweidimensionales Array anlegen und alle Tile* mit nullptr initalisieren
    hoehe = height;
    breite = width;
    
    Spielwelt = new Tile**[height];
    
    for(int i = 0; i < height; i++) {
        Spielwelt[i] = new Tile*[width];
    }
    
    for (int i = 0; i < height; i++){
       
        for (int j = 0; j < width; j++){
            
            Spielwelt[i][j] = nullptr;
        }
            
    }
       
}

DungeonMap::DungeonMap(int height, int width, const vector<string>& data){ //initalisiert alle Tile* entsprechend des Parameters data 
    hoehe = height;
    breite = width;
    
    Spielwelt = new Tile**[height];
    
    for(int i = 0; i < height; i++) {
        Spielwelt[i] = new Tile*[width];
    }
    
   
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
           
            if (data.at(i).at(j) == '.') {
        		Spielwelt[i][j] = new Floor;
	    } 
            if (data.at(i).at(j) == '#')   {
                        Spielwelt[i][j] = new Wall;
                    }
            if (data.at(i).at(j) == 'D')
                Spielwelt[i][j] = new Door();
            
            if (data.at(i).at(j) == 'S')
                Spielwelt[i][j] = new Switch();
            
            if (data.at(i).at(j) == 'T')
                Spielwelt[i][j] = new Trap();
            
            if (data.at(i).at(j) == 'L')
                Spielwelt[i][j] = new Lever();
        }
    }              
}

DungeonMap::~DungeonMap(){
    for (int z = 0; z < hoehe; z++){        
        for (int j = 0; j < breite; j++){
            delete Spielwelt[z][j];
            
        }
        delete Spielwelt[z];
    }
    
    
    delete Spielwelt;
    
    
    Spielwelt = nullptr;
    hoehe = 0;
    breite = 0;
}


Position DungeonMap::findCharacter(Character* c){ //ermittelt Position von der Figur und gibt diese zurück
    
   for (int i = 0; i < hoehe; i++){
       
        for (int j = 0; j < breite; j++){
            
            if ( Spielwelt[i][j]->getCharacter() == c ){
                Position pos(i,j);
                return pos;
            }
        }

   }
}

void DungeonMap::place(Position pos, Character* c){ //Spielfigur c auf der Kachel an Position pos setzen
    Spielwelt[pos.m_height][pos.m_width]->setCharacter(c);
}

Tile* DungeonMap::findTile(Position pos) const{ //liefert Zeiger auf die Kachel an der angegebenen Position pos
    cout << pos.m_height << " " << pos.m_width << endl;
    Tile* t = Spielwelt[pos.m_height][pos.m_width];
    return t;
}

Position DungeonMap::findTile(Tile* t) const{  //ermittelt die Position von Kachel t und gibt diese zurück
    for(int i = 0; i < hoehe; i++) {
        for(int j = 0; j < breite; j++){
            
            if(Spielwelt[i][j] == t){
                Position pos(i,j);
                return pos;
        
            }
    
        }
    }
    
}

void DungeonMap::print(){ //Ausgabe der Spielwelt
    Character* c = new Character(); //?
  
    
    for (int i = 0; i < hoehe; i++){
        cout << endl;
        for(int j = 0; j < breite; j++){
            Spielwelt[i][j]->print();
            
            
            
      /*      if (Spielwelt[i][j]->hasCharacter()){
                cout << c->getZeichen();
            }
            if (Spielwelt[i][j]->getTile() == Tile::Floor)
                cout << ".";
            if (Spielwelt[i][j]->getTile() == Tile::Wall)
                cout << "#";
            if (Spielwelt[i][j]->getTile() == ) */
        }
    }
    cout << endl;
}

void DungeonMap::placeItem(Item* i, Position pos){
    Spielwelt[pos.m_height][pos.m_width]->setItem(i);
}

bool DungeonMap::hasLineOfSight(Position from, Position to){
    
}