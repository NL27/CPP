#include "harl.hpp"

harl::harl(){
}

harl::~harl(){
}

void harl::complain(std::string level){
	harl harl;
	int i = 0;
	int lvl = whichlevel(level);
	typedef void (harl::*functptr)();
	functptr functs[] = {&harl::debug, &harl::info, &harl::warning, &harl::error};
	
	while (i < 4){
		if (i == lvl)
			break;
		i++;
	}
	switch (i){
		case 0:
			(harl.*functs[0])();
		case 1:
			(harl.*functs[1])();
		case 2:
			(harl.*functs[2])();
		case 3:
			(harl.*functs[3])();
			break;
		default:
			harl.noise();
			break;
	}
}

int harl::whichlevel(std::string level){
	if (level == "debug")
		return 0;
	if (level == "info")
		return 1;
	if (level == "warning")
		return 2;
	if (level == "error")
		return 3;
	return 4;
}

void harl::noise(){
	std::cout << "This is only noise, nothing to bother about." << std::endl;
}

void harl::debug(){
		std::cout << "[debug]" << std::endl;
		std::cout << "I can hear something getting roasted in your system. Maybe you should have a look." << std::endl;
}

void harl::info(){
		std::cout << "[info]" << std::endl;
		std::cout << "I can smell bacon. It seems like you have a bug in your system." << std::endl;
}

void harl::warning(){
		std::cout << "[warning]" << std::endl;
		std::cout << "I can see the bug in your system. Turn off your system imediately!" << std::endl;
}

void harl::error(){
		std::cout << "[error]" << std::endl;
		std::cout << "I warned you! The bug broke your system & everything is lost forever!" << std::endl;
}

