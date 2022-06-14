#include "humana.hpp"

humana::humana(std::string name, weapon& type) : _humanname(name), _weapontype(type){
}

humana::~humana(){
}

void humana::attack()const{
	std::cout << humana::_humanname << " attacks with their " << humana::_weapontype.getType() << std::endl;
}