#pragma once
//#ifndef PASS_H
#include <iostream>
#include <string>

using namespace std;

extern int size_pass;

struct DATA {		//struct of data for storing information for purpose of dynamic_ar() function
	char** T;
	int s;
	int S_AR[4];  // dynamicly created sizes of arrays (like small, big, digit, special) f.e. size = 10, for digit array
};

struct checkedOP {
	bool op[4]{};
};

class pass {
private:
	int amount_letters; // how many characters are in password 
	char small[25]{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','w','x','y','z' }; // 24
	char big[25]{ 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y','Z' }; // 24
	char digit[10]{ '0','1','2','3','4','5','6','7','8','9' };//10
	char special[5] { '@','#','$','%','&' };//5
	char* password{};
public:
	pass(int amount_l);	// constructor of class "pass", automaticly create password of 10 characters
	pass();						// interactive mode
	char* generate(DATA data);	// automaticly generate password with setup stored in data struct
	void view();			
	void view(char* wsk);
	checkedOP options();
	DATA dynamic_ar(bool s = 1, bool b = 1, bool d = 1, bool sp = 1);  // dynamicly create array (sklada sie z wektorw, tych opcji, ktore zostaly wlaczone
	//np jesli jest ustawienie 1,1,1,1 w argumentach tzn, ze w hasle maja byc znaki z wektora small, big, digit, special, jesli np. 
	// 1,0,0,1, to maja byc znaki z wektorow small oraz special
	char* Cesare(); // szyfruj haslo szyfrem cezara
};

//#endif