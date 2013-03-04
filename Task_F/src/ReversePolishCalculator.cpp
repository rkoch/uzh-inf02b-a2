//
//  ReversePolishCalculator.cpp
//  Stacks
//
//  Created by Rafael Ballester on 15/01/13.
//  Copyright 2013 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a2
//

#include <iostream>
#include "ReversePolishCalculator.h"

using std::cerr;
using std::endl;

/*
 * 1) this method should introduce a new number in the RPC
 */
void ReversePolishCalculator::introduceNumber(int input) {
	internalStack.push(input);
}

/*
 * 2) this method should transform the topmost two elements
 *    into a single one by means of the given operation
 */
void ReversePolishCalculator::operate(std::string operatorString) {
	int right = internalStack.top();
	internalStack.pop();
	int left = internalStack.top();
	internalStack.pop();
	int res;

	if (operatorString == "+") {
		res = left + right;
	} else if (operatorString == "-") {
		res = left - right;
	} else if (operatorString == "*") {
		res = left * right;
	} else if (operatorString == "/") {
		res = left / right;
	} else {
		// In case of a non supported operation push the old values back to stack
		// and throw an error
		internalStack.push(left);
		internalStack.push(right);
		cerr << "ERR: This is not a supported operation (" << operatorString << "). The old (uncomputed) values remain on the stack." << endl;
		return;
	}

	internalStack.push(res);
}

/*
 * 3) this method should print the only remaining element
 *    in the queue, and remove it
 */
void ReversePolishCalculator::printResult() {
	if (internalStack.size() == 1) {
		std::cout << "result = " << internalStack.top() << endl;
		internalStack.pop();
	} else {
		cerr << "ERR: Cannot print result as there are " << internalStack.size() << " items left on the stack. To call this method you need to have only one item left." << endl;
	}
}
