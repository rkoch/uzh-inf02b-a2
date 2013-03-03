//
//  stack_ab.h
//  stack_arraybased
//
//  Created by Loc Nguyen on 16.02.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
//   Authored by Remo Koch
//

#ifndef stack_arraybased_stack_ab_h
#define stack_arraybased_stack_ab_h
const int StackMax = 10;
#include <string>
#include "exceptions.h"

class Stack_ab {

	std::string data[StackMax];
	int index;

public:
	Stack_ab();
	~Stack_ab();
	int size();
	void push(std::string);
	std::string pop();
	std::string top();
	bool empty();

};

#endif
