/*
 * main.cpp
 *
 *  Created on: 03-Apr-2019
 *  Modified on: 09-Mar-2021
 *  Author: Soumyadeep Dhar
 */

#include <bits/stdc++.h>
#include "largeuint.h"
int main()
{
	LargeUInt a("12345923456789");
	std::cout << "a: " << a.get() << std::endl;

	LargeUInt b("999999999923456789");
	std::cout << "b: " << b.get() << std::endl;

	a += b;
	std::cout << "(a += b):a = " << a.get() << std::endl;

	b += a;
	std::cout << "(b += a):b = " << b.get() << std::endl;

	return 0;
}
