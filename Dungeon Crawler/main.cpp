#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Tile.h"
#include "GameEngine.h"

using namespace std;

void loadFromFile(string filename, vector<string>& map, vector<string>& st,
                int& height, int& width){
    
    ifstream saveGame;
    string line;   
    saveGame.open("level1.txt");
    int i = 0;
    
    if (saveGame.good()){
        
        saveGame >> height;
        saveGame >> width;
        
        for (int i = 0; i < height; i++){
            saveGame >> line;
            map.push_back(line);
        }
    
        while(!saveGame.eof()){
            getline(saveGame, line);
            st.push_back(line);
        }
    }
    
    
    saveGame.close();
}

int main() {
    int height;
    int width;
  
    vector<string> st;
    vector<string> map;
    /*vector<string> data{ 
        "####################", 
        "####...............#", 
        "###.S..............#", 
        "##.........####....#", 
        "#T............#....#", 
        "#..........####....#", 
        "#.D................#", 
        "#..................#", 
        "#..................#", 
        "####################",}; */
       
       loadFromFile("level1.txt", map, st, height, width);
        
       
       //GameEngine ge(10,20,data, specialTiles);
       //ge.run();
       
       GameEngine g(20,20,map,st);
       g.run();
    
    
    return 0;
}
