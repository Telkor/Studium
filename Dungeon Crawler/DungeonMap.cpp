#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
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

void DungeonMap::print(Position rs){ //Ausgabe der Spielwelt
    Character* c = new Character(); //?
  
    
    for (int i = 0; i < hoehe; i++){
        cout << endl;
        for(int j = 0; j < breite; j++){
            Position pos;
            pos.m_height = i;
            pos.m_width = j;
            if(hasLineOfSight(rs, pos) == true)
             Spielwelt[i][j]->print();   
            
           else
               cout << "#";

             
        }
    }
    cout << endl;
}

void DungeonMap::placeItem(Item* i, Position pos){
    Spielwelt[pos.m_height][pos.m_width]->setItem(i);
}

bool DungeonMap::hasLineOfSight(Position from, Position to){  //Bresenham-Algorithmus
    
    
   /* double dx = to.m_width - from.m_width;
    double dy = to.m_height - from.m_height;
    
    double xstep = 1;
    double ystep = 1;
    
    if(dx < 0){
        dx = -dx;
        xstep = -1;   
    }
    
    if(dy < 0){
        dy = -dy;
        ystep = -1;
        
    }
    
    double a = 2*dx;
    double b = 2*dy;
    
    
    double m = dy / dx;
    
    double y = dy; 
    */
    
    
    double x = to.m_width - from.m_width;
    double y = to.m_height - from.m_height;
    double length = sqrt((x * x) + (y * y));


    double stepx = x / length;
    double stepy = y / length;

    x = from.m_width;
    y = from.m_height;
    for (double i = 0; i < length; i += 1) {
        if (Spielwelt[static_cast<int> (y)][static_cast<int> (x)]->isTransparent() == false)
            return false;

        x += stepx;
        y += stepy;
    }
    return true;
    
    

}

vector<Position> DungeonMap::getPathTo(Position from, Position to){
    vector<Position> weg;
    
    if (hasLineOfSight(from, to) == true){
    
    while (from.m_height != to.m_height && from.m_width != to.m_width){
        
        if (from.m_height > to.m_height && from.m_width > to.m_width){
            from.m_height--;
            from.m_width--;
            weg.push_back(from);
            //continue;
        }
        
        if (from.m_height < to.m_width && from.m_width < to.m_width){
            from.m_height++;
            from.m_width++;
            weg.push_back(from);
        }
        
        if (from.m_height < to.m_width && from.m_width > to.m_width){
            from.m_height++;
            from.m_width--;
            weg.push_back(from);
        }
        
        if (from.m_height > to.m_width && from.m_width < to.m_width){
            from.m_height--;
            from.m_width++;
            weg.push_back(from);
        }
        
        if (from.m_height > to.m_height && from.m_width == to.m_width){
            from.m_height--;
            weg.push_back(from);
        }
        
        if (from.m_height < to.m_height && from.m_width == to.m_width){
            from.m_height++;
            weg.push_back(from);
        }
        
        if (from.m_height == to.m_height && from.m_width < to.m_width){
            from.m_width++;
            weg.push_back(from);
        }
        
        if (from.m_height == to.m_height && from.m_width > to.m_width){
            from.m_width--;
            weg.push_back(from);
        }
        
    }
    }
    else
        return weg;
}