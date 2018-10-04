#include <iostream>
#include "FillUp.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Read in the size from the user
    int size;
    cin >> size;
    
    // Allocate space on the heap for [size] ints
    // This space is pointed to by pointer arr
    int* arr = new int[size];
    
    // Call the fillUp function
    fillUp(arr, size);
    
    // Call the printPos function on last position
    printPos(arr, size-1);
    
    // Free the memory that was allocated on the heap
    delete[] arr;
    
    return 0;
}
