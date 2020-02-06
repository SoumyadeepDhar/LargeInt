/*
 * main.cpp
 *
 *  Created on: 03-Apr-2019
 *      Author: soumyadeep
 */

#include "largeint.h"
int main()
{
	LargeInt a(999999999);

	a *= 999999999;
	a *= 333999999;
	a *= 999999999;
	a *= 999999999;
	a *= 999999999;
	a *= 999999999;
	a *= 999999999;
	a *= 999999999;
	a *= 999999999;
	a *= 999999999;
	a *= 123456789;
	printf("I'm here :: %s\n", a.get().c_str());

	return 0;
}

