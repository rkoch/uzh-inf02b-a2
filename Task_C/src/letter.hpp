//
//  letter.hpp
//  Mail
//
//  Created by Fabian Hofstetter on 09.02.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//

#ifndef Mail_letter_hpp
#define Mail_letter_hpp

#include <string>
#include <iostream>

class letter {

public:
	letter(int priority_, std::string tray_, std::string sender_);
	int getPriority();
	std::string getTray();
	std::string getSender();

private:
	int priority;			// 0 =  highest priority
	std::string tray;          // this is the tray where the letter should be stored
	std::string sender;

};

#endif
