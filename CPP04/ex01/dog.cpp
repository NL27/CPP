#include "dog.hpp"
#include "brain.hpp"

dog::dog(){
	_type = "Dog";
	std::cout << _type << " Constructor called" << std::endl;
	brian = new brain();
}

dog::dog(const dog &copy){
	std::cout << "Dog Copy Constructor called" << std::endl;
	brian = new brain();
	*this = copy;
}

dog::~dog(){
	std::cout << _type << " Destructor called" << std::endl;
	delete brian;
}

dog &dog::operator=(dog const &assign){
	_type = assign._type;
	return *this;
}

void dog::makeSound() const{
	std::cout << "Wuff" << std::endl;
}

brain *dog::getBrain(){
	return brian;
}