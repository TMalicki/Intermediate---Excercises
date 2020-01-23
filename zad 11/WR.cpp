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

void load() {

	ifstream myfile;
	string source;
	string output;
	char sign;

	cout << "Podaj lokalizacje pliku: ";
	getline(cin, source);

	cout << "Podaj jakim znakiem zastapic spacje: ";
	cin >> sign;

	myfile.open(source.c_str());
	
	if (myfile.is_open())
	{
		while (getline(myfile, output))
		{
			int length = output.length();
			for (int i = 0; i < length; i++) {
				if (isspace(output[i])) output[i] = sign;
			}
			cout << output << '\n';
		}
		myfile.close();
	}

	myfile.close();
}

void load(string source) {
	
	ifstream myfile;
	string output;
	char sign;

	cout << "Podaj jakim znakiem zastapic spacje: ";
	cin >> sign;

	myfile.open(source.c_str());

	if (myfile.is_open())
	{
		while (getline(myfile, output))
		{
			int length = output.length();
			for (int i = 0; i < length; i++) {
				if (isspace(output[i])) output[i] = sign;
			}
			cout << output << '\n';
		}
		myfile.close();
	}

	myfile.close();
}