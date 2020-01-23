#include <iostream>
#include "calc.h"
#include <Windows.h>

using namespace std;

int main() {

	int choose;
	menu();
	double x = 0, y = 0;
	while (cin >> choose) {

			switch (choose) {
			case 1: {
				values(x, y);
				cout << x + y;
			}
			break;
			case 2: {
				values(x, y);
				cout << x - y;
			}
			break;
		case 3: {
			values(x, y);
			cout << x * y;
		}
			break;
		case 4: {
			values(x, y);
			if (y == 0) {
				cout << "\tBlad!";
			}
			else cout << x / y;
		}
			break;
		case 5: {
			values(x);
			cout << x * x;
		}
			break;
		case 6: {
			values(x);
			cout << sqrt(x);
		}
			break;
		}

		cout << "\n\n\tAgain?\n";
		cout << "\t1. Yes\n";
		cout << "\t2. No\n";
		cin >> choose;
		if (choose == 2) break;

		system("CLS");
		menu();
	}
	cout << "\tKoniec.\n\n";
}