#ifndef Circle_h
#define Circle_h

#include <cmath>

class Circle{
private:
    double x, y, r;
    
    void init(double x, double y, double r){
        this->x = x;
        this->y = y;
        this->r = r;
        
        area = M_PI * r * r;
        
    }
    
public:
    double area;
   
    //defalut constructor
    Circle(){
        init(0, 0, 1);
    }
    
    //constructor with parameters
    Circle(double a, double b, double rad){
        init(a, b, rad);
    }
    
    //setter methods
    void setX(double a){
        x = a;
    }
    void setY(double b){
        y = b;
    }
    void setR(double rad){
        r = rad;
        area = M_PI * r * r;
    }
    
    //getter methods
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    double getR(){
        return r;
    }
    
    ~Circle(){
        
    }
    
};

#endif
