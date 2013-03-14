//
//  main.cpp
//  Mail
//
//  Created by Fabian Hofstetter on 09.02.12.
//  Updated by Rafael Ballester on 15.01.13.
//  Copyright 2013 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a2
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#include "letter.hpp"

using std::string;
using std::cout;
using std::endl;
using std::stack;
using std::vector;

void init();
void printTrays();
void cleanUp();
std::stack<letter*> orderByPriority(std::stack<letter*> tray);
/**
 * 3) declaration of letter comparator
 */
bool letterComparator(letter* pLetter1, letter* pLetter2);

std::stack<letter*> tray_work;
std::stack<letter*> tray_family;
std::stack<letter*> tray_hobby;

int main(int argc, const char * argv[]) {

	init();

	printTrays();

	cleanUp();

	printTrays();

	tray_work = orderByPriority(tray_work);
	tray_family = orderByPriority(tray_family);
	tray_hobby = orderByPriority(tray_hobby);

	printTrays();

	return 0;
}

void init() {

	letter* letter1 = new letter(5, "work", "John");
	letter* letter2 = new letter(3, "family", "Jack");
	letter* letter3 = new letter(1, "work", "Hugo");
	letter* letter4 = new letter(9, "hobby", "Lisa");
	letter* letter5 = new letter(4, "family", "Lena");
	letter* letter6 = new letter(0, "work", "Madden");
	letter* letter7 = new letter(8, "hobby", "Jules");
	letter* letter8 = new letter(4, "hobby", "Rachel");
	letter* letter9 = new letter(0, "family", "Sam");
	letter* letter10 = new letter(7, "work", "Lio");

	tray_work.push(letter1);
	tray_work.push(letter2);
	tray_work.push(letter3);

	tray_family.push(letter4);
	tray_family.push(letter5);
	tray_family.push(letter6);

	tray_hobby.push(letter7);
	tray_hobby.push(letter8);
	tray_hobby.push(letter9);
	tray_hobby.push(letter10);

}

/*
 * 1) this method should print out the three trays with the letters in it
 */
void printTrays() {
	string names[3] = { "Work", "Family", "Hobby" };
	stack<letter*>* trays[3] = { &tray_work, &tray_family, &tray_hobby };

	for (int i = 0; i < 3; i++) {
		cout << "Tray " << names[i] << " contains " << trays[i]->size() << " Letters:" << endl;
		stack<letter*> copy(*trays[i]);
		int j = 1;
		while (!copy.empty()) {
			letter* l = copy.top();
			copy.pop();
			cout << "    [" << j++ << "]  Sender: " << l->getSender() << "; Destined tray: " << l->getTray() << "; Priority: " << l->getPriority() << endl;
		}
	}
	cout << endl;
}

/*
 * 2) this method should clean up the trays. This means every letter should be in the correct tray in which it belongs to.
 */
void cleanUp() {
	stack<letter*> inbox;
	stack<letter*>* trays[3] = { &tray_work, &tray_family, &tray_hobby };

	// move all letters back to inbox before resorting them
	for (int i = 0; i < 3; i++) {
		while (!trays[i]->empty()) {
			inbox.push(trays[i]->top());
			trays[i]->pop();
		}
	}

	// Distribute inbox
	while (!inbox.empty()) {
		letter* l = inbox.top();
		inbox.pop();

		if (l->getTray() == "work") {
			tray_work.push(l);
		} else if (l->getTray() == "family") {
			tray_family.push(l);
		} else if (l->getTray() == "hobby") {
			tray_hobby.push(l);
		} else {
			std::cerr << "Error: The letter from " << l->getSender() << " with destined tray " << l->getTray() << " is invalid. This letter is discarded." << endl;
		}
	}
}

/*
 * 3) this method should order the letters after their priority. The letter with the highest priority (=0) should be on top of the stack.
 */
std::stack<letter*> orderByPriority(std::stack<letter*> tray_) {
	// fill stack to vector in order to sort it
	vector<letter*> v;
	while (!tray_.empty()) {
		v.push_back(tray_.top());
		tray_.pop();
	}

	// Sort vector
	std::sort(v.begin(), v.end(), letterComparator);

	// Create stack
	stack<letter*> ret;
	for (vector<letter*>::reverse_iterator itr = v.rbegin(); itr != v.rend(); ++itr) {
		ret.push(*itr);
	}

	return ret;
}

bool letterComparator(letter* pLetter1, letter* pLetter2) {
	return pLetter1->getPriority() < pLetter2->getPriority();
}

