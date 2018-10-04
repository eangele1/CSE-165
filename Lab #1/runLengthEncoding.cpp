#include <iostream>

using namespace std;

int main()
{
	int number;
	char letter;

	while (true) {
		cin >> letter;
		cin >> number;

		if (number == -2) {
			return(0);
		}
		else if (number == -1) {
			cout << endl;
		}
		else {
			for (int i = number; i > 0; i--) {
				cout << letter;
			}
		}

	}
    return 0;
}