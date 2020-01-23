#include "pass.h"
#include <cstdlib>
#include <time.h>

using std::cin;
using std::cout;

pass::pass(int amount_l) {
	if (amount_l <= 0) cout << "Nie mozna utworzyc hasla.\n";		// zabezpieczenie - haslo musi miec wiecej niz 0 znakow
	if (amount_l < 4 && amount_l > 0) cout << "Zbyt slabe haslo, uzyj wiecej liter (minimum: 4).\n";	// zabezpieczenie, haslo musi miec wiecej niz 3 znaki
	amount_letters = amount_l;
}

void pass::view() {
	// wyswietlanie hasla
	cout << "\n\nGenerated password: ";
	for (int i = 0; i < amount_letters; i++) {
		cout << password[i];
	}
	cout << endl;
}

DATA pass::dynamic_ar(bool s, bool b, bool d, bool sp) {

	int size = 0;
	char** TAB = new char* [4]; // wskaznik na wskaznik (do utworzenia dynamicznej tablicy tablic)
	DATA data;

	// sprawdzanie po kolei warunkow (idziemy od prawej do lewej) sprawdzanie ktore opcje zostaly wlaczone, a ktore wylaczone
	// dynamiczne budowanie tablicy tablic 

	if (s == 1) {
		TAB[0] = new char[24]; //small;
		TAB[0] = small;
		data.S_AR[0] = 24;
		size++;
		if (b == 1) {
			TAB[1] = new char[24];//big;
			TAB[1] = big;
			data.S_AR[1] = 24;
			size++;
			if (d == 1) {
				TAB[2] = new char[10]; // digit;
				TAB[2] = digit;
				data.S_AR[2] = 10;
				size++;
				if (sp == 1) {
					TAB[3] = new char[5]; // special;
					TAB[3] = special;
					data.S_AR[3] = 5;
					size++;
				}
			}
			else if (sp == 1) {
				TAB[2] = new char[5]; // special;
				TAB[2] = special;
				data.S_AR[2] = 5;
				size++;
			}
		}
		else if (d == 1) {
			TAB[1] = new char[10]; // digit;
			TAB[1] = digit;
			data.S_AR[1] = 10;
			size++;
			if (sp == 1) {
				TAB[2] = new char[5]; // special;
				TAB[2] = special;
				data.S_AR[2] = 5;
				size++;
			}
		}
		else if (sp == 1) {
			TAB[1] = new char[5]; // special;
			TAB[1] = special;
			data.S_AR[1] = 5;
			size++;
		}
	}

	else if (b == 1) {
		TAB[0] = new char[24]; // big;
		TAB[0] = big;
		data.S_AR[0] = 24;
		size++;
		if (d == 1) {
			TAB[1] = new char[10]; // digit;
			TAB[1] = digit;
			data.S_AR[1] = 10;
			size++;
			if (sp == 1) {
				TAB[2] = new char[5]; // special;
				TAB[2] = special;
				data.S_AR[2] = 5;
				size++;
			}
		}
		else if (sp == 1) {
			TAB[1] = new char[5]; // special;
			TAB[1] = special;
			data.S_AR[1] = 5;
			size++;
		}
	}
	else if (d == 1) {
		TAB[0] = new char[10]; // digit;
		TAB[0] = digit;
		data.S_AR[0] = 10;
		size++;
		if (sp == 1) {
			TAB[1] = new char[5]; // special;
			TAB[1] = special;
			data.S_AR[1] = 5;
			size++;
		}
	}
	else if (sp == 1) {
		TAB[0] = new char[5]; //special;
		TAB[0] = special;
		data.S_AR[0] = 5;
		size++;
	}
	
	// aktualizacja danych, ktora wyslana zostanie w paczce struktury typu DATA
	data.T = TAB;
	data.s = size;

	//cout << data.T[0][3] << endl << data.T[1][2] << endl << data.T[2][1] << endl << data.T[3][4] << endl << data.s << endl;
	//cout << size;
	return data;
}
char* pass::generate(DATA data) {	// do generowania hasla, funkcja wykorzystuje strukture ustawien zwroconej w funkcji dynamic_ar()

	//////////////////////////////////////////////////////////
	// GENEROWANIE LOSOWEGO HASŁA W OPARCIU O WYBRANE OPCJE //
	//////////////////////////////////////////////////////////

	srand(time(NULL));	// wlaczenie losowosci 
	int choose;		
	char temp{};
	char* wsk = new char[amount_letters];

	for (int i = 0; i < amount_letters; i++) {
	
		choose = rand() % data.s + 1;	// losowo zostanie wybrana tablica znakow (small, big, digit, special)
										// choose jest w oparciu o wielkosc tablicy utworzonej w funkcji dynamic_ar()
										// tak by losowanie bylo tylko w oparciu o dane ktore maja byc w hasle (small, big, digit, special)
		switch (choose) {
		case 1:{
			temp = data.T[0][rand() % data.S_AR[0]];	// losowo zostanie wybrany znak z danej tablicy (small, big, digit, lub special)
		}
			break;
		case 2: {
			temp = data.T[1][rand() % data.S_AR[1]];
		}
			break;
		case 3: {
			temp = data.T[2][rand() % data.S_AR[2]];
		}
			break;
		case 4: {
			temp = data.T[3][rand() % data.S_AR[3]];
		}
			break;
		}

		wsk[i] = temp;		 // kolejne znaki hasla 
	}

	password = new char[amount_letters];		// utworzenie miejsca dla zmiennej password
	password = wsk;								// przypisanie hasla do zmiennej prywatnej

	/////////////////////////////////////////////////////////////////////////
	//  SPRAWDZENIE CZY WSZYSTKIE WYBRANE OPCJE ZAWARŁY SIĘ W WYGENEROWANYM HAŚLE
	/////////////////////////////////////////////////////////////////////////

	int* check = new int[data.s]{};	// stworzenie zmiennej, która zliczać będzie ilość wystąpień znaków z danej opcji (small, big, etc)

	for (int j = 0; j < data.s; j++) {
		for (int i = 0; i < amount_letters; i++) {
			for (int k = 0; k < data.S_AR[j]; k++) {
				if (password[i] == data.T[j][k]) check[j]++;	// czyli wychodzi np. ze zliczono 4 wystąpienia znakow z tablicy znakow small, 3 z big, oraz
																// 5 z tablicy special
			}
		}
	}
	/*
	// wyświetlenie starego hasła
	cout << "OLD password: " << endl;
	for (int i = 0; i < amount_letters; i++) {
		cout << password[i];
	}
	cout << endl;
	// wyświetlenie ilości zliczeń (zmienna check) wystąpień znaków z poszczególnych tablic (small, big, etc)
	cout << "Amount of characters for each chosen option: " << endl;
	for (int j = 0; j < data.s; j++) {
		cout << check[j] << "   ";
	}
	cout << endl;
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// znalezienie indeksu znaku z hasła, który jest w tablicy (small, big, special, digit), która była wykorzystywana najczęściej do generowania hasła
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int max = check[0];	// najwieksza ilosc wystąpień (maks ze zmiennej chec)
	int max_id = 0;		// numer tablicy ktora najczesciej byla wykorzystywana
	//char letter_of_max{};  


	for (int i = 1; i < data.s; i++) {
		if (check[i] >= max) {
			max = check[i];	// okreslenie ilosci najczesciej powtorzonego zbioru
			max_id = i;		// okreslenie ktory zbior jest najczesciej uzywany
		}
	}

	////////////////////////////////////////////////////////////////////////
	// znalezienie indeksu pierwszego znaku z hasla ze zbioru najczesciej uzywanego
	//////////////////////////////////////////////////////

	int letter_of_max_id{};	// przechowuje indeks pierwszej napotkanej litery w hasle z najczesciej uzywanego zbioru (small, big, etc)

	for (int i = 0; i < amount_letters; i++) 
	{
		for (int j = 0; j < data.S_AR[max_id]; j++) 
		{
			if (password[i] == data.T[max_id][j])
			{
				//letter_of_max = password[i];
				letter_of_max_id = i;
				break;							// znajdz pierwszy znak w hasle ze zbioru ktory byl najczesciej uzywany i zapisz jej indeks
			}
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////
	// znalezienie czy jest jakis nieuzywany (wybrany) zbior, a nastepnie wylosowanie z tego brakujacego zbioru losowej liczby
	// i zastapienie jej z pierwsza litera hasla ktora nalezy do najczesciej uzywanego zbioru (letter_of_max_id)
	////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < data.s; i++) {
		if (check[i] == 0) {
			password[letter_of_max_id] = data.T[i][rand() % data.S_AR[i]];		//losowe wylosowanie znaku z nieuzywanego zbioru
		}
	}

	////////////////////////////////////////
	// wyswietlenie nowego, poprawnego hasla
	////////////////////////////////////
	/*
	cout << "NEW password: " << endl;
	for (int i = 0; i < amount_letters; i++) {
		cout << password[i];
	}
	cout << endl;
	*/
	////////////////////////////////////////////////////////////////////////
	return password;
}

//small:
//a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s,t,u,v,w,x,y,z
//duze:
//A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,R,S,T,U,V,W,X,Y,Z
//liczby:
//0,1,2,3,4,5,6,7,8,9
//znaki specjalne:
//@,#,$,%,&

