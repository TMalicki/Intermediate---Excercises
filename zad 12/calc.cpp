#include <iostream>
#include "calc.h"
#include <string>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using std::cout;
using std::string;
using std::endl;

// constructor of parser class
parser::parser(string & text) {

	this->Text = text;														// assign equation sent to constructor to attribute of that class 

	BUFFOR = new char[Text.length() + 1];									// buffor vector (size of equation length plus '\0' sign)
	EXIT = new char* [Text.length() + 1];									// exit vector (size of equation length plus '\0' sign)
	VALUE = new double[Text.length()];										// value vector (size of equation length plus '\0' sign)
	flag = 0;																// counter
	cntr_ext = 0;															// counter of exit vector
	cntr_buff = 0;															// counter of buffor vector
	actual_priority = 0;													// priority of operator that need assignment 
	buff_priority = 0;														// priority of lastly assigned operator

	signes[0].sign = '(';													// operators signs and priority are set
	signes[0].prioritY = 0;
	signes[1].sign = '+';
	signes[1].prioritY = 1;
	signes[2].sign = '-';
	signes[2].prioritY = 1;
	signes[3].sign = ')';
	signes[3].prioritY = 1;
	signes[4].sign = '*';
	signes[4].prioritY = 2;
	signes[5].sign = '/';
	signes[5].prioritY = 2;
	signes[6].sign = '%';
	signes[6].prioritY = 2;
	signes[7].sign = '^';
	signes[7].prioritY = 3;
}

parser::~parser()
{

}

// method for parsing equation 
void parser::parse() {

	// set zeros for EXIT and BUFFOR vectors
	for (int i = 0; i < Text.length(); i++) {
		EXIT[i] = 0;
		BUFFOR[i] = 0;
	}
	int size2 = 0;															// set zero for size2 - size of each value 
																			// (f.e. : 2.6436 -> is 6 digits)

	for (int i = 0; i < Text.length(); i++)									// main loop of parsing alghoritm	
	{
		if (isdigit(Text[i]) || Text[i] == '.')								// check if char is digit or is it coma
		{
			while (isdigit(Text[i]) || Text[i] == '.') {					// if it is coma or digit than do while loop 
				i++;														// as long as many digits has certain value
				size2++;													// so this loop is for evaluate size2 value
			}
			EXIT[cntr_ext] = new char[size2 + 1];							// make vector inside EXIT vector that can
			for (int j = 0; j < size2; j++) {								// store value of size -> size2
				EXIT[cntr_ext][j] = Text[i - size2 + j];
			}
			EXIT[cntr_ext][size2] = '\0';									// add sign '\0' for end of value
			cntr_ext++;														// go to next element of vector for next element of Text
			size2 = 0;														// reset value size2
			i--;															// correct an i value because of last increment in while loop 
		}																	// that increment size2 value also. (line 59)
		else																// if element of Text is not digit, than
		{
			if (Text[i] == ')')												// check if it is ")" sign and than take everything to 
			{																// "(" sign from BUFFOR to EXIT. "(" sign should be delete 
				cntr_buff--;												// from BUFFOR vector (it will be overwritten in next loop
				while (BUFFOR[cntr_buff] != '(')							// because of cntr_buff decrement in line 83)
				{
					EXIT[cntr_ext] = new char[2];
					EXIT[cntr_ext][0] = BUFFOR[cntr_buff];
					EXIT[cntr_ext][1] = '\0';
					cntr_ext++;
					cntr_buff--;
				}
			}
			else if(Text[i] == '(')											// check if it is "(" than add to buffor
			{
				BUFFOR[cntr_buff] = Text[i];
				cntr_buff++;
			}
			else															// if it is not anything from above, than it has to be
			{																// math operator like "+", or "*", etc.
				if (BUFFOR[0] != 0)											// check if BUFFOR vector is not empty
				{															
					while (Text[i] != signes[flag].sign)					// find char that is equal actual sign
					{
						flag++;												// counter for finding correct sign
					}
					actual_priority = signes[flag].prioritY;				// assignment of priority of actual sign
					flag = 0;
					// spróbować zrobić pamięć priority poprzedniego (by na nowo nie szukać jakie jest priority znaku umieszczonego w bufforze)
					while (BUFFOR[cntr_buff - 1] != signes[flag].sign)		// search for char that is equal to actual sign
					{
						flag++;
					}
					buff_priority = signes[flag].prioritY;					// assignment of priority of actual sign
					flag = 0;

					if (actual_priority > buff_priority)					// check if actual priority is bigger than priority
					{														// of previous char in BUFFOR vector
						BUFFOR[cntr_buff] = Text[i];						// if it is than assign that sign to BUFFOR vector
						cntr_buff++;
					}
					else
					{
						while ((buff_priority >= actual_priority) && ((cntr_buff-1)>=0))	// and if buff priority is bigger or equal 
						{																	// and also if buffor is not empty, than...
							EXIT[cntr_ext] = new char[2];									// make new column of vector EXIT
							EXIT[cntr_ext][0] = BUFFOR[cntr_buff - 1];						// assignment element of BUFFOR to EXIT
							EXIT[cntr_ext][1] = '\0';										// add ending sign to EXIT vector
							cntr_ext++;
							cntr_buff--;
							while (BUFFOR[cntr_buff - 1] != signes[flag].sign)				// search for new buff priority
							{
								flag++;
							}
							buff_priority = signes[flag].prioritY;							// assign new buff priority
							flag = 0;
						}
						BUFFOR[cntr_buff] = Text[i];										// add to BUFFOR actual operator
						cntr_buff++;
					}
				}
				else if (BUFFOR[0] == 0)													// if BUFFOR is empty
				{
					BUFFOR[cntr_buff] = Text[i];
					cntr_buff++;
				}
			}
		}
		
	}
	cntr_buff--;
	while (cntr_buff >= 0) {																// add everything from BUFFOR to EXIT
		EXIT[cntr_ext] = new char[2];
		EXIT[cntr_ext][0] = BUFFOR[cntr_buff];
		EXIT[cntr_ext][1] = '\0';
		cntr_buff--;
		cntr_ext++;
	}
	BUFFOR = nullptr;
	delete[] BUFFOR;

	for (int i = 0; i < cntr_ext; i++) {
		cout << EXIT[i];
	}
}

// method that sum two values
double parser::_SUM(double a, double b) {
	return a + b;
}
// method that substract two values
double parser::_SUB(double a, double b) {
	return a - b;
}
// method that multiply two values
double parser::_MULT(double a, double b) {
	return a * b;
}
// method that divide two values
double parser::_DIV(double a, double b) {
	if (b == 0) {
		cout << "Error, failed during dividing by zero.\n";
		return 0;
	}
	else return a / b;	
}
// method that power two values
double parser::_POW(double a, double b) {
	return pow(a,b);
}

// method that evaluate reverse polish notation
void parser::onp() {
	for (int i = 0; i < cntr_ext; i++) {
		if (isdigit(EXIT[i][0])) {
			VALUE[flag] = atof(EXIT[i]);
			flag++;
		}
		else {
			flag--;
			switch (EXIT[i][0]) {
			case '+': VALUE[flag - 1] = _SUM(VALUE[flag - 1], VALUE[flag]);
				break;
			case '-': VALUE[flag - 1] = _SUB(VALUE[flag - 1], VALUE[flag]);
				break;
			case '*': VALUE[flag - 1] = _MULT(VALUE[flag - 1], VALUE[flag]);
				break;
			case '/': VALUE[flag - 1] = _DIV(VALUE[flag - 1], VALUE[flag]);
				break;
			case '^': VALUE[flag - 1] = _POW(VALUE[flag - 1], VALUE[flag]);
				break;
			}
		}
	}

	EXIT = nullptr;
	delete[] EXIT;
	std::cout << std::endl << std::endl;
	std::cout << "Wynik: ";
	std::cout << VALUE[0] << std::endl;
}



////////////////////////////////////////////////// OLD //////

void window::menu() {

	cout << tab[0];
	cout << tab[1];
	cout << tab[2];
	cout << tab[3];
	cout << tab[4];
	cout << tab[5];
	cout << tab[6];
}

int window::navigate() {

	while (_getch() != ENTER)
	{
		switch (_getch())
		{
		case KEY_UP:
		{
			cout << "GORA\n";
		}
		break;
		case KEY_DOWN:
		{
			cout << "DOL\n";
		}
		break;
		}
	}
	cout << "ZATWIERDZONO\n\n";
	//*tab[5] = "->";
	return 0;
}

calc::calc() {

}

sum::sum() : calc() {

}


void sum::show() {

}
