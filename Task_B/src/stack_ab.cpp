//
//  stack_ab.cpp
//  stack_arraybased
//
//  Created by Loc Nguyen on 16.02.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a2
//

#include <iostream>
#include "stack_ab.h"

Stack_ab::Stack_ab() {
	index = 0;
}

Stack_ab::~Stack_ab() {
	// Nothing to delete as data is only held on the stack and gets destroyed upon exiting current scope.
	// See:
	// http://stackoverflow.com/questions/2722879/calling-constructors-in-c-without-new
}

int Stack_ab::size() {
	return index;
}

void Stack_ab::push(std::string newelement) {
	if (index >= StackMax) {
		throw OverFlow();
	}
	data[index++] = newelement;
}

std::string Stack_ab::pop() {
	if (index <= 0) {
		throw UnderFlow();
	}
	return data[--index];
}

std::string Stack_ab::top() {
	if (index <= 0) {
		throw UnderFlow();
	}
	return data[index - 1];
}

bool Stack_ab::empty() {
	return index <= 0;
}

