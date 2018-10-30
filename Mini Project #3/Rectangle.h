#ifndef Rectangle_hpp
#define Rectangle_hpp

class Rect{
private:
    //Maintain rectangle values here
    float x, y, width, height;
    
public:
    
    //constructor
    Rect();
    
    //constructor with parameters
    Rect(float x, float y, float width, float height);
    
    //destructor
    ~Rect();
    
    //function to check if mouse coordinates are inside rectangle
    bool contains(float x, float y);
    
    //Getters
    float getX();
    float getY();
    float getW();
    float getH();
    
    //Setters
    void setX(float x);
    void setY(float y);
    void setW(float width);
    void setH(float height);
    
    //function that makes the rectangle; takes mouse coordinates as input
    void makeRect(float mx, float my);
};

#endif
