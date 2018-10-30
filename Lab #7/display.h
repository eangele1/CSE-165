#ifndef LA4_display_h
#define LA4_display_h

#include <iostream>
#include <vector>
void display (const std::vector<Animal*> &list){
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i]->getName() << std::endl;
    }
}

#endif
