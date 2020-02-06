/*
 * largeint.h
 *
 *  Created on: 03-Apr-2019
 *  Author: soumyadeep dhar
 */

#ifndef LARGEINT_H_
#define LARGEINT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>


#define N_LIMIT_VALUEE 1000000000L

class LargeInt
{
private:

	/// Split up data for
	std :: vector <int> nodeList;

public:
	LargeInt() {
		int  _x = 0;
		nodeList.push_back(_x);
	}

	LargeInt(int _x) {
		if(_x < N_LIMIT_VALUEE) {
			nodeList.push_back(_x);
		} else {
			nodeList.push_back(_x / N_LIMIT_VALUEE);
			nodeList.push_back(_x - (nodeList.back() * N_LIMIT_VALUEE));
		}
	}

	LargeInt(LargeInt& _x) {
		nodeList = _x.nodeList;
	}

	~LargeInt() {
		nodeList.clear();
	}

	/// Get integer as string
	std :: string get();

	/// Multiply by 10 for given number of times
	LargeInt& multiply10(int _x);

    /// This is the operator overloading function for assignment operator(+).
	LargeInt& operator = (int _x);

    /// This is the operator overloading function for assignment operator(+).
	LargeInt& operator += (int _x);

	/// This is the operator overloading function for assignment operator(+).
	LargeInt& operator += (LargeInt& _x);

	/// This is the operator overloading function for assignment operator(*).
	LargeInt& operator *= (int _x);
};



#endif /* LARGEINT_H_ */
