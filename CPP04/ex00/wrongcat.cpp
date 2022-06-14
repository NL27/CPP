#include "wrongcat.hpp"

wrongcat::wrongcat(){
	_type = "Wrongcat";
	std::cout << _type << " Constructor called" << std::endl;
}

wrongcat::wrongcat(const wrongcat &copy){
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

wrongcat::~wrongcat(){
	std::cout << _type << " Destructor called" << std::endl;
}

wrongcat &wrongcat::operator=(wrongcat const &assign){
	_type = assign._type;
	return *this;
}

void wrongcat::makeSound()const{
	std::cout << "Ring-ding-ding-ding-dingeringeding!" << std::endl;
}