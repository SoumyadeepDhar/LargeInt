/*
 * largeint.cpp
 *
 *  Created on: 03-Apr-2019
 *      Author: soumyadeep
 */

#include "largeint.h"
#include <sstream>

std :: string LargeInt :: get() {
	std :: ostringstream str;

	int index = 0;
	str << " [" << index << "] "<< *nodeList.begin();

	for (auto i = nodeList.begin() + 1; i != nodeList.end(); ++i) {
		index ++;
		str << " [" << index << "] ";
		std :: string value(std :: to_string(*i));

		/// append starting zero's
		for (unsigned int x = 9; x > value.length(); x--) {
			str << "0";
		}

		/// append the values
		str << *i;
	}

	return str.str();
}

/// Multiply by 10 for given number of times
LargeInt& LargeInt :: multiply10(int _x) {

	/// For given number of times
	for (int m = 0; m < _x; m++) {

		// Get the starting address
		int carry = 0;
		long long int r = (long long int)nodeList.back() * 10;
		if(r < N_LIMIT_VALUEE) {
			nodeList.back() = r;
			carry = 0;
		} else {
			carry = r / N_LIMIT_VALUEE;
			nodeList.back() = r % N_LIMIT_VALUEE;
		}

		for (auto i = nodeList.rbegin() + 1; i != nodeList.rend(); ++i) {
			r = ((long long int)*i * 10) + (long long int)carry;
			if(r < N_LIMIT_VALUEE) {
				*i = r;
				carry = 0;
			} else {
				carry = r / N_LIMIT_VALUEE;
				*i = r % N_LIMIT_VALUEE;
			}
		}

		if(carry > 0) {
			nodeList.insert(nodeList.begin(), carry);
		}
	}
	return *this;
}

/// This is the operator overloading function for assignment operator(+).
LargeInt& LargeInt :: operator = (int _x)
{
	nodeList.clear();
	if(_x < N_LIMIT_VALUEE) {
		nodeList.push_back(_x);
	} else {
		nodeList.push_back(_x / N_LIMIT_VALUEE);
		nodeList.push_back(_x - (nodeList.back() * N_LIMIT_VALUEE));
	}
	return *this;
}

// This is the operator overloading function for assignment operator(+).
LargeInt& LargeInt :: operator += (int _x)
{
	if(_x > 0) {
		// Get the starting address
		int carry = 0;
		long long int r = (long long int)nodeList.back() + (long long int)_x;
		if(r < N_LIMIT_VALUEE) {
			nodeList.back() = r;
			carry = 0;
		} else {
			carry = r / N_LIMIT_VALUEE;
			nodeList.back() = r % N_LIMIT_VALUEE;
		}

		for (auto i = nodeList.rbegin() + 1; i != nodeList.rend(); ++i) {
			r = (long long int)*i + (long long int)carry;
			if(r < N_LIMIT_VALUEE) {
				*i = r;
				carry = 0;
				break;
			} else {
				carry = r / N_LIMIT_VALUEE;
				*i = r % N_LIMIT_VALUEE;
			}
		}

		if(carry > 0) {
			nodeList.insert(nodeList.begin(), carry);
		}
	}
	return *this;
}

//// This is the operator overloading function for assignment operator(+).
//LargeInt& LargeInt :: operator += (LargeInt& _x) {
//	auto i =    nodeList.rbegin();
//	auto j = _x.nodeList.rbegin();
//
//	printf("\n A Here %s ......... %s\n", get().c_str(), _x.get().c_str()); fflush(stdout);
//
//	/// Add positional nodes
//	while(i != nodeList.rend() || j != _x.nodeList.rend()) {
//
//		printf("\n Ax Here %d # %d %s ......... %s\n", *i, *j, get().c_str(), _x.get().c_str()); fflush(stdout);
//		/// If both are positive
//		if(*j > 0) {
//
//			int carry = 0;
//			long long int r = (long long int)*i + (long long int)*j;
//			if(r < N_LIMIT_VALUEE) {
//				carry = 0;
//				*i = r;
//			} else {
//				carry = r / N_LIMIT_VALUEE;
//				*i = r % N_LIMIT_VALUEE;
//			}
//
//			for (auto k = std :: next(i); k != nodeList.rend(); ++k) {
//				r = (long long int)*k + (long long int)carry;
//				if(r < N_LIMIT_VALUEE) {
//					*k = r;
//					carry = 0;
//					break;
//				} else {
//					carry = r / N_LIMIT_VALUEE;
//					*k = r % N_LIMIT_VALUEE;
//				}
//			}
//
//			if(carry > 0) {
//				nodeList.insert(nodeList.begin(), carry);
//			}
//		}
//		i++;
//		j++;
//	}
//
//	while(j != _x.nodeList.rend()) {
//		printf("Here B %d ......... %s\n", *j, get().c_str());
//		fflush(stdout);
//
//		nodeList.insert(nodeList.begin(), *j);
//
//		printf("Here C %s ......... %s\n", get().c_str(), _x.get().c_str()); fflush(stdout);
//		j++;
//	}
//
//	return *this;
//}


// This is the operator overloading function for assignment operator(+).
LargeInt& LargeInt :: operator += (LargeInt& _x) {

	int carry = 0;
	unsigned int position = 0;
	auto j = _x.nodeList.rbegin();
	while(j != _x.nodeList.rend()) {

		long long int r = 0;
		if(nodeList.size() > position) {
			r = (long long int)*(nodeList.rbegin() + position) + (long long int)*j + carry;
			if(r < N_LIMIT_VALUEE) {
				carry = 0;
				*(nodeList.rbegin() + position) = r;
			} else {
				carry = r / N_LIMIT_VALUEE;
				*(nodeList.rbegin() + position) = r % N_LIMIT_VALUEE;
			}
		} else {
			r = (long long int)*j + carry;
			if(r < N_LIMIT_VALUEE) {
				carry = 0;
				nodeList.insert(nodeList.begin(), r);
			} else {
				carry = r / N_LIMIT_VALUEE;
				nodeList.insert(nodeList.begin(), r % N_LIMIT_VALUEE);
			}
		}

		/// Move to next element
		j++;
		position ++;
	}

	while(carry > 0) {

		long long int r = 0;

		if(nodeList.size() > position) {
			r = (long long int)*(nodeList.rbegin() + position) + carry;
			if(r < N_LIMIT_VALUEE) {
				carry = 0;
				*(nodeList.rbegin() + position) = r;
			} else {
				carry = r / N_LIMIT_VALUEE;
				*(nodeList.rbegin() + position) = r % N_LIMIT_VALUEE;
			}
		} else {
			r = (long long int) carry;
			if(r < N_LIMIT_VALUEE) {
				carry = 0;
				nodeList.insert(nodeList.begin(), r);
			} else {
				carry = r / N_LIMIT_VALUEE;
				nodeList.insert(nodeList.begin(), r % N_LIMIT_VALUEE);
			}
		}
		position ++;
	}

	return *this;
}

// This is the operator overloading function for assignment operator(*).
LargeInt& LargeInt :: operator *= (int _x) {

	/// Get length of the given multiplier
	int length = std :: to_string(_x).size();

	/// Get original copy of the value
	LargeInt n(*this);

	/// reset value
	*this = 0;

	/// for all the digits
	for (int i = 0; i < length; i++) {

		/// Ignore unit positional place
		if(i > 0) {
			/// Update values
			n.multiply10(1);
		}

		/// if valid positional value present
		if(_x % 10 != 0) {

			LargeInt m(n);
			for (int p = 1; p < _x % 10; p++) {
				m += n;
			}

			/// Update for the current decimal place
			*this += m;
		}

		printf("[%d] %s\n", i, get().c_str());
		/// update multiplier
		_x = _x / 10;
	}

	return *this;
}



