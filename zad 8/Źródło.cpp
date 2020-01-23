#include <iostream>
#include "pass.h"

int main() {

	//pass S1;
	//pass S2(-1);
	//pass S3(2);
	int x;
	std::cout << "Podaj ile liter: ";
	std::cin >> x;

	char* new_pass = new char[x];

	pass S4(x);

	char answer[4]{};
	bool ANSWER[4]{};

	cout << "\n\nWybierz (y = yes, n = no): \n";
	cout << "Czy w hasle maja znajdowac sie male litery?: ";
	cin >> answer[0];
	cout << "Czy w hasle maja znajdowac sie duze litery?: ";
	cin >> answer[1];
	cout << "Czy w hasle maja znajdowac sie liczby?: ";
	cin >> answer[2];
	cout << "Czy w hasle maja znajdowac sie znaki specjalne?: ";
	cin >> answer[3];

	for (int i = 0; i < 4; i++) {
		if (answer[i] == 'y') {
			ANSWER[i] = 1;
		}
	}
	new_pass = S4.generate(S4.dynamic_ar(ANSWER[0],ANSWER[1],ANSWER[2],ANSWER[3]));	
	S4.view();
}


// brakuje sprawdzania czy kazda wybrana opcja zostala uzyta (musi byc bo jest losowanie, wiec jakas wybrana opcja moze
// byc nie wybrana!