#ifndef Data_h
#define Data_h

#include <vector>
#include <algorithm>

class Data{
    
private:
    
    std::vector<int> arr;
    
public:
    
    void add(int x){
        arr.push_back(x);
    }
    
    void print(){
        for (auto i = arr.begin(); i != arr.end(); ++i){
            std::cout << *i << " ";
        }
        std::cout << "" << std::endl;
    }
    
    void sort(){
        std::sort(arr.begin(), arr.end());
    }
    
};

#endif
