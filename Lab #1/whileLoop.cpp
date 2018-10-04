#include <iostream>

using namespace std;

int main() {

    while(true){

    int x;

    cin >> x;
    
    if (x % 2 == 0 && x > 0){
        cout << "EVEN" << endl;
    }
    if (x % 2 != 0 && x > 0) {
        cout << "ODD" << endl;
    }
    if (x < 0){
        break;
    }
    }
    
    return 0;

}
