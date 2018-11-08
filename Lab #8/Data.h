#ifndef DATA_h
#define DATA_h

#include<vector>
#include<iostream>
#include "Sortable.h"
using namespace std;

class Data {
private:
    vector<Sortable*> data;
public:
    Data(){
    }
    void add(Sortable *s){
        data.push_back(s);
    }
    void sort(){
        int j;
        Sortable * val;
        for(int i = 1; i < data.size(); i++){
            val = data[i];
            j = i - 1;
            
            while(j >= 0 && val->compare(data[j])){
                data[j + 1] = data[j];
                j = j - 1;
            }
            data[j + 1] = val;
        }
    }
    void print(){
        for(int i = 0; i < data.size(); i++){
            data[i]->print();
        }
    }
    
};
#endif
