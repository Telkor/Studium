#ifndef POSITION_H
#define	POSITION_H

#include <iostream>
using namespace std;
class Position {
public:
    Position();
    Position(int height,int width);
    virtual ~Position();
    int m_height;
    int m_width;
    
    friend ostream& operator<<(ostream& os, const Position& pos);
    friend bool operator<(const Position& rechts, const Position& links);
    
private:
    
};

#endif	/* POSITION_H */

