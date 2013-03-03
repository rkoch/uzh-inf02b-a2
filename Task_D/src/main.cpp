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

#include <iostream>
#include "process.h"
#include "process_queue.h"

int main(int argc, const char * argv[]) {

	process scheduler_process = process(0, "Scheduler Process");
	process swapper = process(1, "Memory Management Process");
	process web_browser = process(13542, "Google Chrome Webbrowser");
	process text_processor = process(12545, "MS Office Word");
	process ide = process(11342, "XCode IDE");
	process game = process(18765, "3D Game");

	process_queue process_manager = process_queue();

	if (process_manager.is_empty()) {
		std::cout << "The queue is empty. Your is_empty() seems to work correctly!" << std::endl;
	} else {
		std::cout << "The queue actually should be empty, but your is_empty() function seems to have errors!" << std::endl;
	}

	process_manager.add(&scheduler_process);
	process_manager.add(&swapper);
	process_manager.add(&web_browser);
	process_manager.add(&text_processor);
	process_manager.add(&ide);
	process_manager.add(&game);

	if (process_manager.get_size() == 6) {
		std::cout << "The queue size is 6. Your get_size() and add(...) methods seem to be working!" << std::endl;
	} else {
		std::cout << "The queue size actually should be 6. Your get_size() and add(...) methods may have errors. Check again!" << std::endl;
	}

	process_manager.remove();
	process_manager.remove();
	process_manager.remove();
	process_manager.remove();
	process_manager.remove();
	process_manager.remove();

	if (process_manager.is_empty()) {
		std::cout << "The queue size is empty. Your remove() method seems to be working!" << std::endl;
	} else {
		std::cout << "The queue actually should be empty. Your remove() method may have errors. Check again!" << std::endl;
	}

	return 0;
}

