#include "Position.h"

Position::Position(){
    m_height = 1;
    m_width = 1;
}

Position::Position(int height, int width) {
    m_height = height;
    m_width = width;
}

Position::~Position() {
}

    ostream& operator<<(ostream& os, const Position& pos){
    os << pos.m_height << pos.m_width;
    return os;    
    }
    
    bool operator<<(const Position& right, const Position& left){
        if (left.m_height < right.m_height)
            return true;
        if(left.m_width < right.m_width && left.m_height == right.m_height)
            return true;
        else
            return false;
    }
