#include <iostream>

using namespace std;

int main() {

	//x%2 == 0 && x > 0 (dodanie, parzyste)
	
	int ile;
	cout << "Podaj ile liczb chcesz podac: ";
	cin >> ile;
	int* x = new int [ile]{};

	cout << "Podawaj kolejne liczby dodatnie, ktore sa parzyste. Wcisnij \"q\" by przerwac." << endl;
	for (int i = 0; i < ile; i++) {
		cout << "Liczba nr: " << i << " -> ";
		cin >> x[i];
		if (x[i] % 2 != 0 || x[i] <= 0) {
			cout << "Blad, podano liczbe niespelniajaca wymogow.\n";
			i--;
		}
	}

	for (int i = 0; i < ile; i++) {
		cout << "Liczba nr: " << i << " -> ";
		cout << x[i] << endl;
	}
	
	delete[] x;
	return 0;
}