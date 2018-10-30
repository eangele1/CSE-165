#include <iostream>
#include <vector>
#include "Dog.h"
#include "display.h"

using namespace std;

int main(int argc, const char * argv[]){
    
    int n;
    cin >> n;
    string type, name;
    int age;
    
    vector<Animal*> list;
    
    for(int i = 0; i < n; i++){
        cin >> type >> name >> age;
        
        if(type == "A"){
            
            Animal* animal = new Animal();
            
            animal->setName(name);
            
            list.push_back(animal);
        }
        else{
            list.push_back(new Dog(name, age));
        }
    }
    
    display(list);

    return 0;
}

