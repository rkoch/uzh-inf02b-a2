/*
 *  QueueExceptions.h
 *
 *  Created on: 03.03.2013
 *
 *  Authored by Remo Koch
 *  Public repository at https://github.com/rkoch/uzh-inf02b-a2
 */

#ifndef QUEUE_EXCEPTIONS_H_
#define QUEUE_EXCEPTIONS_H_

#include <iostream>
#include <exception>

using std::exception;

class QueueOverflowException: public exception {
	virtual const char* what() const throw ();
};

class QueueUnderflowException: public exception {
	virtual const char* what() const throw ();
};

#endif /* QUEUE_EXCEPTIONS_H_ */
