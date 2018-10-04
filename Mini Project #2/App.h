#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"

class App: public GlutApp {
public:
    // Maintain app state here
    float mx;
    float my;

    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
};

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
