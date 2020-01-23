#include <iostream>
#include "head.h"

using namespace std;

int main() {

	int ile;
	cout << "Witaj, ile losowo wybranych elementow chcesz umiescic w tablicy?: ";
	cin >> ile;
	int* tab = new int[ile];

	write(tab,ile);
	bubble_sort(tab, ile);

	return 0;
}