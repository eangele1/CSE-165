#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	vector <string> list;

	while (true) {

		string input = "";

		getline(cin, input);

		if (input == "quit") {
			return(0);
		}

		else if (input.length() > 1) {
			list.push_back(input);
		}

		else if (input.length() == 1) {
			char c[1];
			for (int i = 0; i < 1; i++) {
				c[i] = input[i];
			}
			for (int i = 0; i < list.size(); i++) {
				if (list[i][0] == c[0]) {
					cout << list.at(i) << endl;
				}
			}
		}
	}
	return 0;
}