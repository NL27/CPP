#include "cat.hpp"

cat::cat(){
	_type = "Cat";
	std::cout << _type << " Constructor called" << std::endl;
	brian = new brain();
}

cat::cat(const cat &copy){
	std::cout << _type << "Copy Constructor called" << std::endl;
	brian = new brain();
	*this = copy;
}

cat::~cat(){
	std::cout << _type << " Destructor called" << std::endl;
	delete brian;
}

cat &cat::operator=(cat const &assign){
	_type = assign._type;
	return *this;
}

void cat::makeSound() const{
	std::cout << "Rawr" << std::endl;
}