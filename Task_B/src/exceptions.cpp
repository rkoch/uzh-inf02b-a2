//
//  exceptions.cpp
//  stack_arraybased
//
//  Created by Loc Nguyen on 23.02.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//

#include <iostream>
#include "exceptions.h"

void OverFlow::overflowoutput() {
	std::cout << "Overflow, stack is full\n";
}

void UnderFlow::underflowoutput() {
	std::cout << "Underflow, stack is empty\n";
}
