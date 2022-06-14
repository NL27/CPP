#include "dog.hpp"

dog::dog(){
	_type = "Dog";
	std::cout << _type << " Constructor called" << std::endl;
}

dog::dog(const dog &copy){
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

dog::~dog(){
	std::cout << _type << " Destructor called" << std::endl;
}

dog &dog::operator=(dog const &assign){
	_type = assign._type;
	return *this;
}

void dog::makeSound() const{
	std::cout << "Wuff" << std::endl;
}