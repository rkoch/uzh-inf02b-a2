//
//  main.cpp
//  Queues
//
//  Created by Michael Kündig on 2/16/12.
//  Copyright 2012 University of Zurich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a2
//

#include <iostream>
#include <queue>
#include "Car.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::queue;

void placeCar(Car* pCar, bool pRedLight);
void handleLane(queue<Car*>* pLane, bool pRedLight);

int count;
bool redLight;
queue<Car*> lane1;
queue<Car*> lane2;

/*
 * 1) do a simulation of cars arriving to a traffic light from two lanes
 */
int main(int argc, const char * argv[]) {
	count = 0;
	redLight = true;

	cout << "Welcome to Traffic-My-Crossroad v1.0.0" << endl;
	cout << endl;

	string input;
	while (true) {
		cout << "A new car is arriving. There currently are " << (int) (lane1.size() + lane2.size()) << " cars waiting. ";
		cout << "The light is " << (redLight ? "red" : "green") << "." << endl;
		cout << "Do you want to toggle the light? [y/stop/any other key]: " << std::flush;
		cin >> input;

		if (input == "stop") {
			break;
		} else if (input == "y") {
			redLight = !redLight;
		}

		// New car arriving
		Car* car = new Car(count++);

		// Add new car to lane
		placeCar(car, redLight);

		// Processing lane
		handleLane(&lane1, redLight);
		handleLane(&lane2, redLight);
	}

	cout << endl;
	cout << "Shutting down traffic. Goodbye." << endl;

	return 0;
}

void placeCar(Car* pCar, bool pRedLight) {
	bool toLane1 = lane1.size() <= lane2.size();
	if (toLane1) {
		lane1.push(pCar);
	} else {
		lane2.push(pCar);
	}

	// set new car to wait
	if (pRedLight) {
		pCar->waitAtRedLight(toLane1 ? 1 : 2);
	}
}

void handleLane(queue<Car*>* pLane, bool pRedLight) {
	if (!pRedLight) {					// cars can drive only if light is green
		while (!pLane->empty()) {
			Car* c = pLane->front();
			pLane->pop();
			c->passCrossroads();
			delete c;
		}
	}
}

