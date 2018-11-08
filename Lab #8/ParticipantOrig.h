#ifndef Participant_h
#define Participant_h

#include <iostream>
#include "Sortable.h"

using namespace std;

class Participant : public Sortable {
    
private:
    int age;
    string name;
    double score;
    
public:
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
        return this->compareParticipants((Participant*)(s));
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
