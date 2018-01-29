/*
 * Calculator.h
 *
 *  Created on: Nov 1, 2017
 *      Author: navee
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <cstdlib>
#include <string>

using namespace std;
class Calculator {

public:
	double expression();
	double term() throw(string);
	double factor() throw(string);
};

#endif /* CALCULATOR_H_ */
