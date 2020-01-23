#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// file location:
//source = "D:\\Visual Studio Enterprise 2019\\workspace\\ZADANIA OD PIOTRA\\intermediate\\zad 10\\zapis.txt";
//remove("D:\\Visual Studio Enterprise 2019\\workspace\\ZADANIA OD PIOTRA\\intermediate\\zad 10\\zapis.txt");

void write() {
	ofstream myfile;
	string source;

	cout << "Podaj lokalizacje pliku: ";
	getline(cin, source);

	remove(source.c_str());
	myfile.open(source.c_str(), ios::app);

	cout << "Wpisz tekst do zapisania w pliku: (wpisz \"q\" by przerwac)\n\n";
	string x;
	getline(cin, x);
	while (x != "q") {
		myfile << x;
		myfile << endl;
		getline(cin, x);
	}
	myfile.close();
	cout << "\n\nTekst zapisano.\n\n";
}

void write(string source) {
	ofstream myfile;

	remove(source.c_str());
	myfile.open(source.c_str(), ios::app);

	cout << "Wpisz tekst do zapisania w pliku: (wpisz \"q\" by przerwac)\n\n";
	string x;
	getline(cin, x);
	while (x != "q") {
		myfile << x;
		myfile << endl;
		getline(cin, x);
	}
	myfile.close();
	cout << "\n\nTekst zapisano.\n\n";
}