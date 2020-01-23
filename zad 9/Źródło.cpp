#include <iostream>
#include "pass.h"

int main() {

	//pass S1;
	//pass S2(-1);
	//pass S3(2);
	//////////////////////////////////////////	

	pass S4;

	char* new_pass = new char[size_pass];

	checkedOP opt = S4.options();
	
	new_pass = S4.generate(S4.dynamic_ar(opt.op[0],opt.op[1],opt.op[2],opt.op[3]));	
	S4.view();

	new_pass = S4.Cesare();
	S4.view(new_pass);
}