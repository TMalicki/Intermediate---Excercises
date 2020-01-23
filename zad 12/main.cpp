// kalkulator

#include <iostream>
#include "calc.h"

int main() {

	using std::cout;
	using std::cin;

	window menu;
	menu.menu();
	menu.navigate();

	string text{};
	cin >> text;
	//text = "12+2*(3*4+10/5)";

	cout << "Rownanie: " << text << std::endl << std::endl;
	parser obj1(text);
	obj1.parse();
	obj1.onp();
	
	calc* c1 = new sum;
	
}

// multiply
// sum
// divide
// percent
// minus