#ifndef Object_h
#define Object_h

class Object {
public:
    static int count;
    
    Object(){
        count++;
    }
    
    Object(const Object& obj) {
        if(this != &obj)
            count++;
    }
    
    
    
};

#endif /* Object_h */
