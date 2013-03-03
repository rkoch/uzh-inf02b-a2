//
//  Car.cpp
//  Queues
//
//  Created by Michael Kündig on 2/16/12.
//  Copyright 2012 University of Zurich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a2

#include <iostream>
#include "Car.h"

void Car::waitAtRedLight(int lane) {
	std::cout << "Car number " << carNumber << " is waiting at the red light (lane " << lane << ")\n" << std::endl;
}

void Car::passCrossroads() {
	std::cout << "Car number " << carNumber << " is passing the crossroads\n" << std::endl;
}
