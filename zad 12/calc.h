#pragma once
#include <iostream>
#include <string>

using std::string;
// struct storing priority operators
struct sign_prior {
	char sign;								// math operators
	int prioritY;							// and their priority
};

// class for math operation with reverse polish notation
class parser {			
private:
	string Text;							// place to store your equation
	char** EXIT{};							// exit vector of parsed data
	char* BUFFOR{};							// vector for storing operators of equation
	double* VALUE{};						// vector of onp() datas. Store final value of equation
	int cntr_ext;							// counter of exit vector
	int cntr_buff;							// counter of buffer vector
	int actual_priority;					// stored priority of operator that needs an assignment
	int buff_priority;						// stored priority of operator stored on last place of buffor (lastly assigned)
	sign_prior signes[8];					// defined operators are here
	int flag = 0;							// counter 
	double _SUM(double, double);			// method for performing sum operation
	double _SUB(double, double);			// method for performing substrack operation
	double _MULT(double, double);			// method for performing multiply operation
	double _DIV(double, double);			// method for performing divide operation
	double _POW(double, double);			// method for performing power operation
public:
	parser(string & text);					// constructor of class
	~parser();								// destructor of class
	void parse();							// method for performing parsing with 
	void onp();								// method to perform reverse polish notation
};

//////////////////////////////////////////// OLD VERSION WITH MENU - WITHOUT INTELIGENCY //////////

// class for menu of calculator
class window {
private:
	char tab[7][34]{ {"-----     CALCULATOR     -----\n"},
					 {"----   Wybierz operacje   ----\n"},
					 {"------------------------------\n"},			 // vectors for storing
					 {"->     1. Dodawanie         \n"},			 // menu
					 {"       2. Odejmowanie         \n"},
					 {"       3. Mnozenie         \n"},
					 {"       4. Dzielenie         \n"} };; 
	static const int ARROW_KEY = 224;		// first value after push arrow key button
	static const int KEY_UP = 72;			// second value after push arrow key button (up)
	static const int KEY_DOWN = 80;			// second value after push arrow key button (down)
	static const int ENTER = 13;			// first and only value after push enter button
public:
	void menu();							// method for show menu in console
	int navigate();							// method for responding on keys of keyboard like "up", "down", and "enter"
};

// abstract class of calculator
class calc {
private:

public:
	calc();									// constructor of class
	virtual void show() = 0;				// (method clear virtual) for show results
};

// child of parent class (calc) for sum
class sum : public calc {
private:

public:
	sum();									// method that performing sum operation
	virtual void show();					// method to show result of sum operation (virtual method)
};