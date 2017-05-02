#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "DungeonMap.h"

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
    
    Tile*** Spielwelt = new Tile**[height];
    
    for(int i = 0; i < height; i++) {
        Spielwelt[height] = new Tile*[width];
    }
    
    //int counter = 0;
    
    for (int i = 0; i < hoehe; i++){
        for (int j = 0; j < breite; j++){
           if (data.at(i).at(j) == '.') {
				Spielwelt[i][j] = new Tile(Tile::Floor, nullptr);
			} else {
				Spielwelt[i][j] = new Tile(Tile::Wall, nullptr);
			}
            
            /*if (data[counter] == ".")
                Spielwelt[i][j] = new Tile(Tile::Floor, nullptr);
            if (data[counter] == "#")
                Spielwelt[i][j] = new Tile(Tile::Wall, nullptr);
            counter++; */
        }
    }
    
    
    
    
    
    
    
    
    
    
    /*  for (int z = 0; z < data.size(); z++){
        int y = data[z].length();
                 
        for (int a = 0; a < y ; a++){
            string x = data[a].substr(y);
                        
                    while (y > 0) {
                        if (x == ".")
                        Spielwelt[i][j] = new Tile(Tile::Floor, nullptr);
                    if (x == "#"){
                        Spielwelt[i][j] = new Tile(Tile::Wall, nullptr);
                    }
                                
                    }      
                }
            }
            
        
    */       
    
}

DungeonMap::~DungeonMap(){
    delete[] Spielwelt;
}


Position DungeonMap::findCharacter(Character* c) const{ //ermittelt Position von der Figur und gibt diese zurück
    
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

void DungeonMap::print() const{ //Ausgabe der Spielwelt
    
    for (int i = 0; i < hoehe; i++){
        cout << endl;
        for(int j = 0; j < breite; j++){
            if (Spielwelt[i][j]->getTile() == Tile::Floor)
                cout << ".";
            if (Spielwelt[i][j]->getTile() == Tile::Wall)
                cout << "#";
        }
    }
}