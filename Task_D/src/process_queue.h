/*
 * Assignment 2 - Algorithms and data structures
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

#ifndef process_queue_process_queue_h
#define process_queue_process_queue_h

#define MAX_SIZE 10

#include "process.h"

class process_queue {

private:

	int _tail_index;

	process* _processes[MAX_SIZE];

public:

	process_queue();

	int get_size();

	bool is_empty();

	void add(process* my_process);

	process* remove();

};

#endif
