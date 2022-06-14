#include "animal.hpp"

animal::animal() : _type("Animal"){
	std::cout << _type << " Constructor called" << std::endl;
}

animal::animal(const animal &copy){
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

animal::~animal(){
	std::cout << _type << " Destructor called" << std::endl;
}

animal &animal::operator=(animal const &assign){
	_type = assign._type;
	return *this;
}

std::string animal::getType() const{
	return _type;
}

void animal::makeSound() const{
	std::cout << "Animal Animal Animal" << std::endl;
}