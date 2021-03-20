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
	LargeUInt a("12345923456789"); // 123456780000000000000045654654524324324399999999999999999999999999999999999999999999999999999999999999999944444444444444444444444444444444444444444444444444444444444444444444444444400000000000000000099999");
	std::cout << "a: " << a.get() << std::endl;
	
	LargeUInt b("999999999923456789");;
	std::cout << "b: " << b.get() << std::endl;

	a += b;
	std::cout << "(a += b): " << a.get() << std::endl;
	std::cout << "(a += b): " << b.get() << std::endl;

	b += a;
	std::cout << "(b += a): " << a.get() << std::endl;
	std::cout << "(b += a): " << b.get() << std::endl;

	return 0;
}

