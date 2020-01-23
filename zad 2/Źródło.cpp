#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main() {

	srand(time(NULL));
	
	int ile;
	cout << "Podaj ile liczb chcesz podac: ";
	cin >> ile;
	int* x = new int [ile] {};

	for (int i = 0; i < ile; i++) {
		x[i] = rand() % 190 + 10;
	}

	cout << "Wszystkie: \n";
	for (int i = 0; i < ile; i++) {
		cout << "Indeks nr: " << i+1 << " -> " << x[i] << endl;
	}
	cout << "\n\nNieparzyste indeksy: \n";
	for (int i = 0; i < ile; i = i + 2) {
		cout << "Indeks nr: " << i+1 << " -> " << x[i] << endl;
	}

	return 0;
}