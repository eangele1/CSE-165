#ifndef GenerateCircleData_h
#define GenerateCircleData_h

#include "Vec.h"

void generateCircleData(std::vector<Vec*>& points, const Vec& center, float radius, int resolution){
    // Clear the points vector to make sure it's empty before you start
    points.clear();
    
    float theta = (2*M_PI) / resolution;
    float sinb = sin(theta), cosb = cos(theta);
    float sina = 0, cosa = 1;
    
    for (int i = 0; i != resolution; i++){
        
        float x = radius * cosa + center.getX();
        float y = radius * sina + center.getY();
        
        Vec* u = new Vec(x, y);
        
        points.push_back(u);
        
        float tmp = sina * cosb + cosa * sinb;
        cosa = cosa * cosb - sina * sinb;
        sina = tmp;
        
    }
    
}

#endif
