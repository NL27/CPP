#include "weapon.hpp"

weapon::weapon(std::string type) : _type(type){
}

weapon::~weapon(){
}

void weapon::setType(const std::string &type){
	_type = type;
}

std::string &weapon::getType(){
	return _type;
}