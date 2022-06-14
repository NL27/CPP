#include "Amateria.hpp"

Amateria::Amateria(){
}

Amateria::Amateria(std::string const &type) : _type(type){
}

Amateria::Amateria(const Amateria &copy){
	*this = copy;
}

Amateria &Amateria::operator=(const Amateria &assign){
	_type = assign._type;
	return *this;
}

Amateria::~Amateria(){
}

std::string const &Amateria::getType() const{
	return _type;
}

// Amateria* Amateria::clone() const{
// }

void Amateria::use(Icharacter& target){
	(void) target;
}
