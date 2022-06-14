#include "Ice.hpp"

Ice::Ice() : Amateria("ice"){
}

Ice::Ice(const Ice &copy) : Amateria(copy){
	(void) copy;
}

Ice &Ice::operator=(const Ice &assign){
	(void) assign;
	return *this;
}

Ice::~Ice(){
}

Amateria* Ice::clone() const{
	return (new Ice());
}

void Ice::use(Icharacter& target){
	std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}