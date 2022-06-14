#include "humanb.hpp"

humanb::humanb(std::string name) : _humanname(name), _weapontype(NULL){
}

humanb::~humanb(){
}

void humanb::attack(){
	if (_weapontype == NULL)
		std::cout << humanb::_humanname << " has no wepon!" << std::endl;
	else
		std::cout << humanb::_humanname << " attacks with their " << humanb::_weapontype->getType() << std::endl;
}

void humanb::setWeapon(weapon &type){
	_weapontype = &type;
}