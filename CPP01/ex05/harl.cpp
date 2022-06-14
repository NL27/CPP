#include "harl.hpp"

harl::harl(){
}

harl::~harl(){
}

int harl::whichlevel(std::string level){
	if (level == "debug")
		return 0;
	else if (level == "info")
		return 1;
	else if (level == "warning")
		return 2;
	else if (level == "error")
		return 3;
	return 4;
}

void harl::complain(std::string level){
	
	harl harl;
	int lvl = harl::whichlevel(level);
	typedef void(harl::*funcptr)();
	funcptr functs[] = {&harl::debug, &harl::info, &harl::warning, &harl::error};

	for (int i = 0; i < 4; i++){
		if (i == lvl)
			(harl.*functs[lvl])();
	}
}

void harl::debug(){
		std::cout << "I can hear something getting roasted in your system. Maybe you should have a look." << std::endl;
}

void harl::info(){
		std::cout << "I can smell bacon. It seems like you have a bug in your system." << std::endl;
}

void harl::warning(){
		std::cout << "I can see the bug in your system. Turn off your system imediately!" << std::endl;
}

void harl::error(){
		std::cout << "I warned you! The bug broke your system & everything is lost forever!" << std::endl;
}
