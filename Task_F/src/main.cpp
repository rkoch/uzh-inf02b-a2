//
//  main.cpp
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

int main(int argc, const char * argv[]) {
	ReversePolishCalculator RPC;
	RPC.introduceNumber(2);
	RPC.introduceNumber(3);
	RPC.operate("+");
	RPC.introduceNumber(4);
	RPC.introduceNumber(5);
	RPC.operate("+");
	RPC.operate("*");
	RPC.printResult();          // should print 45
}
