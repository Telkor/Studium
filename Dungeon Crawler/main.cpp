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
    
    
//   if(saveGame.good()){
//        while(getline(saveGame,line)){
//            cout << line << "\n";
//        }
    
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
//}
//    else{
//        cerr << "Fehler";
//    }
    
    
 /*   if (!saveGame.good()){
        cerr << "Fehler";
        return;
    
    }
    while(i < 2){
    //for (int i = 0; i < 21; i++){
        //getline(saveGame, line);
        
        if (i == 0)
            height = 20;
        if (i == 1)
           width = 20;
        else if (i > 1) { 
            //getline(saveGame, line);
            cout << line << "\n";
            map.push_back(line);
        }
        i++;
    }
    
      /*  for (int i = 0; i < height; i++){
            getline (saveGame, line);
            map.push_back(line);
        }
        
        while(saveGame.good()){
            getline(saveGame, line);
            st.push_back(line);
        }
        
        
        
        saveGame.close();  
        //cout << 1;
        for (int i = 0; i < map.size(); i++)
           cout << map[0][0];
       */


    




int main() {
    int height;
    int width;
    /*vector<string> specialTiles{"Character @ 5 5 ConsoleController 6 6",
            "Character % 5 5 StationaryController 3 4",
            "Door 6 2 Switch 2 4",
            "Greatsword 1 4",
            "Trap 4 2"}; */
    vector<string> st;
    //vector<string> info{"6 2 D 2 4 S"};
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
