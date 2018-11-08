#ifndef Participant_h
#define Participant_h

#include <iostream>
#include "Sortable.h"

using namespace std;

class Participant : public Sortable {
    
public:
    
    static bool (*comp_cb)(const Participant*, const Participant*);
    int age;
    string name;
    double score;
    
    Participant(){
        name = "";
        age = 0;
        score = 0;
    }
    
    Participant(string newName, int newAge, double newScore){
        name = newName;
        age = newAge;
        score = newScore;
    }
    
    bool compare(const Sortable* s){
        Participant* p = (Participant*) s;
        return !comp_cb(this, (Participant*) p);
    }
    
    bool compareParticipants(Participant* p){
        if(this->score > p->score){
            return true;
        }
        if(this->age < p->age && this->score == p->score){
            return true;
        }
        if(this->name < p->name && this->score == p->score && this->age == p->age){
            return true;
        }
        return false;
    }
    
    virtual void print(){
        cout << this->name << "\t" << this->age << "\t" << this->score << endl;
    }
    
};

#endif
