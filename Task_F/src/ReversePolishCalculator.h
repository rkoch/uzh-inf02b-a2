//
//  ReversePolishCalculator.h
//  Stacks
//
//  Created by Rafael Ballester on 15/01/13.
//  Copyright 2013 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a2
//

#ifndef ReversePolishCalculator_h
#define ReversePolishCalculator_h

#include <stack>

class ReversePolishCalculator {

public:
	void introduceNumber(int input);
	void operate(std::string operatorString);
	void printResult();

private:
	std::stack<int> internalStack;

};

#endif
