#ifndef Dog_h
#define Dog_h
#include "Animal.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dog : public Animal{
public:
    
    Dog(string name, int age){
        setName(name);
        setAge(age);
        cout << "Creating Dog" << endl;
    }
    
    void feed() {
        cout<< "A bone, please!" <<endl;
    }
    
    ~Dog(){
        cout << "Deleting Dog" << endl;
    }
};

#endif
