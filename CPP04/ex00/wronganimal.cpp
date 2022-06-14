#include "wronganimal.hpp"

wronganimal::wronganimal(): _type("Wronganimal"){
	std::cout << _type << " Constructor called" << std::endl;
}

wronganimal::wronganimal(const wronganimal &copy){
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

wronganimal::~wronganimal(){
	std::cout << _type << " Destructor called" << std::endl;
}

wronganimal &wronganimal::operator=(wronganimal const &assign){
	_type = assign._type;
	return *this;
}

std::string wronganimal::getType() const{
	return _type;
}

void wronganimal::makeSound() const{
	std::cout << "Lamina Lamina Lamina" << std::endl;
}