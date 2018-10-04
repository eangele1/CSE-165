#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int x;

    string input = "";
    
    getline(cin, input);

    cin >> x;

    for(int i = 0; i < x; i++){
        cout << input << endl;
    }
    
    return 0;

}
