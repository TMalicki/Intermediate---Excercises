#include <iostream>

using namespace std;

void fib(long x) {
	double * tab = new double[x];

	tab[0] = 1;
	tab[1] = 1;

	for (int i = 2; i < x; i++) {
		tab[i] = tab[i - 2] + tab[i - 1];
	}

	for (int i = 0; i < x; i++) {
		cout << "Wyraz nr " << i + 1 << " ciagu Fibbonaciego wynosi: " << tab[i] << endl;
	}
}

int main() {

	long x;
	cout << "Podaj ile liczb ciagu Fibonaciego mam wyswietlic: ";
	cin >> x;
	fib(x);

	return 0;
}