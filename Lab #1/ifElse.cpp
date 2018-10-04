// include this to get I/O functionality
#include <iostream>

using namespace std;

int main() {

    // Declare a variable
    int x;
    
    // Read in a vlaue
    cin >> x;
    
    if (x % 2 == 0){
        cout << "EVEN" << endl;
    }
    else {
        cout << "ODD" << endl;
    }
    
    
    return 0;

}
