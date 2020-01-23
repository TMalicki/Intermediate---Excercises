#include "head.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

void write(int* tab, int ile){

srand(time(NULL));

cout << "Wypelnianie tablicy...\n";

for (int i = 0; i < ile; i++) {
	tab[i] = rand() % 99 + 1;
}
cout << "Tablice wypelniono. Oto ona: \n";

for (int i = 0; i < ile; i++) {
	cout << tab[i] << endl;
}
}

void bubble_sort(int* wsk, int ile) {
	for(int j = 0;j<ile;j++){
		for (int i = 1; i < ile; i++) {
			if (wsk[i - 1] > wsk[i]) {
				int temp = wsk[i - 1];
				wsk[i - 1] = wsk[i];
				wsk[i] = temp;
			}
		}
	}
	cout << "Posortowana tablica: \n";
	for (int i = 0; i < ile; i++) {
		cout << wsk[i] << endl;
	}
}