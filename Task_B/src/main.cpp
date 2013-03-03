//
//  main.cpp
//  stack_arraybased
//
//  Created by Loc Nguyen on 08.02.12.
//  Updated by Rafael Ballester on 16.01.13
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//

#include <iostream>
#include "stack_ab.h"

int main(int argc, const char * argv[]) {

	Stack_ab mystack;
	std::string temp;
	std::cout << "initial size of stack: " << mystack.size() << std::endl;
	try {
		mystack.push("Villa");
		mystack.push("Messi");
		mystack.push("Alexis");
		mystack.push("Iniesta");
		mystack.push("Xavi");
		mystack.push("Mascherano");
		mystack.push("Dani Alves");
		mystack.push("Abidal");
		mystack.push("Pique");
		mystack.push("Puyol");
		mystack.push("Valdes");

	} catch (OverFlow& e) {
		e.overflowoutput();
	}

	std::cout << "current size of stack: " << mystack.size() << std::endl;

	std::cout << "current top element is: " << mystack.top() << std::endl;

	try {
		while (!mystack.empty()) {
			std::cout << mystack.pop() << " wurde gepopt" << std::endl;
			std::cout << mystack.top() << " is now on top" << std::endl;
		}
	} catch (UnderFlow& e) {
		e.underflowoutput();
	}

	return 0;
}

