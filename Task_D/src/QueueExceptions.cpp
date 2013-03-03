/*
 *  QueueExceptions.cpp
 *
 *  Created on: 03.03.2013
 *
 *  Authored by Remo Koch
 *  Public repository at https://github.com/rkoch/uzh-inf02b-a2
 */

#include "QueueExceptions.h"

const char* QueueOverflowException::what() const throw () {
	return "Queue is already full";
}

const char* QueueUnderflowException::what() const throw () {
	return "Queue is already empty";
}
