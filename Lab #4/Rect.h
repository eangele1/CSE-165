#ifndef Vec_h
#define Vec_h
#include <iostream>

using namespace std;

class Vec {
public:
    float xx;
    float yy;
    
    Vec() {
        xx = yy = 0;
    }
    Vec(float x, float y) {
        xx = x;
        yy = y;
    }
};

class Rect{
    
    float x, y, width, height;
    
public:
    Rect(){
        x = y = width = height = 0;
    }
    //constructor
    Rect(float x, float y, float width, float height){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    
    //this function will return tre if a vertex is inside else false
    //as the initial point is left upper point
    bool contains(Vec v){
        if(x <= v.xx && (x + width) >= v.xx && y >= v.yy && (y - height) <= v.yy)
            return true;
        else
            return false;
    }
};

#endif /* Vec_h */
