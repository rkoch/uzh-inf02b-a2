/*
 *Assignment 2 - Algorithms and data structures
 *
 * University of Zurich
 * Department of Informatics
 * Vizualization and Multimedia Laboratory
 *
 * Author: Genc Mazlami
 *
 * Authored by Remo Koch
 * Public repository at https://github.com/rkoch/uzh-inf02b-a2
 */

#include <iostream>
#include "process_queue.h"
#include "process.h"
#include "QueueExceptions.h"

process_queue::process_queue() {
	_tail_index = 0;
}

/*
 * 1a) this method should return the current queue size
 */
int process_queue::get_size() {
	return _tail_index;
}

/*
 * 1b) this method should return whether the queue is currently empty
 */
bool process_queue::is_empty() {
	return _tail_index <= 0;
}

/*
 * 2) this method should add a new element
 */
void process_queue::add(process *my_process) {
	if (_tail_index >= MAX_SIZE - 1) {
		throw QueueOverflowException();
	}
	_processes[_tail_index++] = my_process;
}

/*
 * 3) this method should remove the front element of the queue
 */
process* process_queue::remove() {
	if (_tail_index <= 0) {
		throw QueueUnderflowException();
	}
	process* ret = _processes[0];

	// move process pointers forward
	for (int i = 0; i < _tail_index; i++) {
		_processes[i] = _processes[i + 1];
	}
	_tail_index--;

	return ret;
}
