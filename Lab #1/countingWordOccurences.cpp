#include<fstream>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string convert(string word) {
    
    long len = word.size();
    
    for (int i = 0; i < word.length(); i++) {
        if (ispunct(word[i]))
        {
            word.erase(i--, 1);
            len = word.size();
        }
        else {
            word[i] = tolower(word[i]);
        }
    }
    return word;
};

int main()
{
    ifstream inFile;
    string comparisonWord;
    
    cin >> comparisonWord;
    
    for (int i = 0; i < comparisonWord.length(); i++) {
        comparisonWord[i] = tolower(comparisonWord[i]);
    }
    
    string word;
    long count = 0;
    
    inFile.open("words.txt");
    
    while (!inFile.eof())
    {
        if (inFile >> word){
            if (comparisonWord == convert(word)) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}


