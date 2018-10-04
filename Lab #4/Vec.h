#ifndef Vec_h
#define Vec_h
#include <iostream>

using namespace std;

class Vec {
private:
    float x;
    float y;
public:
    Vec() {
        x = 0;
        y = 0;
    }
    Vec(float x, float y) {
        this->x = x;
        this->y = y;
    }
    float getX() const {
        return x;
    }
    float getY() const {
        return y;
    }
    void add(Vec &v) {
        x += v.x;
        y += v.y;
    }
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

#endif /* Vec_h */
