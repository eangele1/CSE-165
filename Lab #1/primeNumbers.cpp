#include<iostream>

using namespace std;

int main() {

	int num;
	int i;
	int count;
	int n;

	cin >> n;

	for (num = 1; num < n; num++) {
		count = 0;
		for (i = 2; i <= num / 2; i++) {
			if (num % i == 0) {
				count++;
				break;
			}
		}
		if (count == 0 && num != 1) {
			cout << num << endl;
		}
	}
	return 0;
}