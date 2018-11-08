#ifndef Circle_h
#define Circle_h

#include <vector>
#include <iostream>
#include "Sortable.h"

using namespace std;

class Circle : public Sortable{

private:
    int radius;
    
public:
    
    Circle(){
        radius = 0;
    }
    
    Circle (int r) {
        radius = r;
    }
    
    virtual bool compare(const Sortable* s){
        return this->compareCircles((Circle*)(s));
    }
    
    bool compareCircles(const Circle* s){
        if(this->radius < s->radius){
            return true;
        }
        return false;
    }
    
    virtual void print() {
        cout << "Circle with radius:" << radius << endl;
    }
    
    ~Circle(){
        
    }
    
};

#endif
