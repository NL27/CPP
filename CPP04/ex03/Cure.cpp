#include "Cure.hpp"

Cure::Cure() : Amateria("cure"){
}

Cure::Cure(const Cure &copy) : Amateria(copy){
	(void) copy;
}

Cure &Cure::operator=(const Cure &assign){
	(void) assign;
	return *this;
}

Cure::~Cure(){
}

Amateria* Cure::clone() const{
	return (new Cure());
}

void Cure::use(Icharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}