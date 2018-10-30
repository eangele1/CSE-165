#include "Rectangle.h"
#include "GlutApp.h"

//function to check if mouse is inside rectangle
bool Rect::contains(float x, float y){
    
    //uses getters to use rectangle values in this function
    float rect_x = getX();
    float rect_y = getY();
    float rect_width = getW();
    float rect_height = getH();
    
    //if mouse is within rectangle bounds, return true; else return false
    if((x < rect_x || x > (rect_x + rect_width)) || (y > rect_y || y < (rect_y - rect_height)))
        return false;
    return true;
}

//Getter functions
float Rect::getX(){
    return x;
}
float Rect::getY(){
    return y;
}
float Rect::getW(){
    return width;
}
float Rect::getH(){
    return height;
}

// Setter functions
void Rect::setX(float x){
    this->x = x;
}
void Rect::setY(float y){
    this->y = y;
}
void Rect::setW(float width){
    this->width = width;
}
void Rect::setH(float height){
    this->height = height;
}

//Default constructor
Rect::Rect(){
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

//Constructor with parameters
Rect::Rect(float x, float y, float width, float height){
    //sets values with setters
    setX(x);
    setY(y);
    setW(width);
    setH(height);
}

//function to draw rectangles
void Rect::makeRect(float mx, float my){
    
    //on initial state does not modify color of rectangle, but will not do anything if mouse is exactly at (0, 0)
    if(mx == 0 && my == 0){
        glColor3f(0.0, 0.0, 0.0);
    }
    else{
        //if mouse is in rectangle, change color
        if(contains(mx, my)){
            glColor3f(0.0, 0.0, 0.0);
        }
        else{
            glColor3f(0.0, 0.0, 0.0);
        }
    }
    
    //start of one rectangle
    glBegin(GL_POLYGON);
    
    // Top of rectangle
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    
    //Left of rectangle
    glVertex2f(x + width, y);
    glVertex2f(x + width, y - height);
    
    //Right of rectangle
    glVertex2f(x + width, y - height);
    glVertex2f(x, y - height);
    
    // Bottom of rectangle
    glVertex2f(x, y - height);
    glVertex2f(x, y);
    
    //end of rectangle
    glEnd();
}

//Destructor
Rect::~Rect(){}
