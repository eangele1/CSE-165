#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    ifstream inFile;
    string word;
    long count = 0;
    
    inFile.open("words.txt");
    
    while (inFile.good())
    {
        if (inFile >> word){
            count = count + 1;
        }
    }
    
    cout << count << endl;
    
    return 0;
}

