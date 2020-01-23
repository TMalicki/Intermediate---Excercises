#include "calc.h";

void menu() {
	using std::cout;
	using std::cin;
	
	cout << "\t\tCALCULATOR\n\n";
	cout << "\tChoose: (type \"q\" to quit)\n";
	cout << "\t1. Dodawanie\n";
	cout << "\t2. Odejmowanie\n";
	cout << "\t3. Mnozenie\n";
	cout << "\t4. Dzielenie\n";
	cout << "\t5. Potegowanie\n";
	cout << "\t6. Pierwiastkowanie\n";
}

void values(double& x, double& y) {
	using std::cout;
	using std::cin;

	cout << "\tPodaj pierwsza liczbe: ";
	while (!(cin >> x)) {
		cin.clear();
		cin.ignore();
		cout << "\tBlad! Prosze wpisac liczbe:\n";
	}
	cout << "\tPodaj druga liczbe: ";
	while (!(cin >> y)) {
		cin.clear();
		cin.ignore();
		cout << "\tBlad! Prosze wpisac liczbe.\n";
	}
	cout << "\tWynik: ";
}

void values(double& x) {
	using std::cout;
	using std::cin;

	cout << "\tPodaj liczbe: ";
	while (!(cin >> x)) {
		cin.clear();
		cin.ignore();
		cout << "\tBlad! Prosze wpisac liczbe:\n";
	}
}

