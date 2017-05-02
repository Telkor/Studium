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


DungeonMap::DungeonMap(int height, int width){
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

DungeonMap::DungeonMap(int height, int width, const vector<string>& data){
    hoehe = height;
    breite = width;
    
    Tile*** Spielwelt = new Tile**[height];
    
    for(int i = 0; i < height; i++) {
        Spielwelt[height] = new Tile*[width];
    }
    
    int counter = 0;
    
    for (int i = 0; i < hoehe; i++){
        for (int j = 0; j < breite; j++){
            
            if (data[counter] == ".")
                Spielwelt[i][j] = new Tile(Tile::Floor, nullptr);
            if (data[counter] == "#")
                Spielwelt[i][j] = new Tile(Tile::Wall, nullptr);
            counter++;
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


Position DungeonMap::findCharacter(Character* c){
    
   for (int i = 0; i < hoehe; i++){
       
        for (int j = 0; j < breite; j++){
            
            if ( Spielwelt[i][j]->getCharacter() == c ){
                Position pos(i,j);
                return pos;
            }
        }

   }
}

void DungeonMap::place(Position pos, Character* c){
    Spielwelt[pos.m_height][pos.m_width]->setCharacter(c);
}

Tile* DungeonMap::findTile(Position pos){ 
    Tile* t = Spielwelt[pos.m_height][pos.m_width];
    return t;
}

Position DungeonMap::findTile(Tile* t){
    for(int i = 0; i < hoehe; i++) {
        for(int j = 0; j < breite; j++){
            
            if(Spielwelt[i][j] == t){
                Position pos(i,j);
                return pos;
        
            }
    
        }
    }
    
}

void DungeonMap::print(){
    
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