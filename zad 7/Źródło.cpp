#include <iostream>
#include <string.h>

using namespace std;

string tab[5][7]{ { "HH     H","HH     H","HH     H","HHHHHHHH","HH     H","HH     H","HH     H" }, //H
{"HHHHHHHH","HH      ","HH      ","HHHHHHHH","HH      ","HH      ","HHHHHHHH"},						//E
{"HH      ","HH      ","HH      ","HH      ","HH      ","HH      ","HHHHHHHH"},						//L
{"HH      ","HH      ","HH      ","HH      ","HH      ","HH      ","HHHHHHHH"},						//L
{" HHHHHH ","HH    HH","H      H","H      H","H      H","HH    HH"," HHHHHH "}						//O
};

//};

int main() {

	//poziomo
	cout << "\nPoziomo:\n\n";
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			cout << tab[j][i] << "  ";
		}
		cout << endl;
	}
	cout << "\nPionowo:\n\n";
	//pionowo
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			cout << tab[i][j] << endl;
		}
		cout << endl;
	}

	return 0;
}

/*
HH     H
HH     H
HH     H 
HHHHHHHH
HH     H
HH     H
HH     H

HHHHHHHH
HH      
HH
HHHHHHHH
HH      
HH     
HHHHHHHH

HH
HH
HH
HH
HH
HH
HHHHHHHH

 HHHHHH 
HH    HH
H      H
H      H
H      H 
HH    HH
 HHHHHH 
*/