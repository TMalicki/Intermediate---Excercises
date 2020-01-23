#include <iostream>

using namespace std;

int main() {

	char x = 'A';
	char y = 'A';

	for (int i = 0; i < 26; i++) {
		for (int i = 0; i < 26; i++) {
			cout << x;
			x++;
			if (x >= ('A' + 26)) x = 'A';
		}
		cout << endl;
		y++;
		x = y;
	}

	return 0;
}