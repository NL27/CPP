#include "zombie.hpp"

zombie::zombie(){
}

zombie::~zombie(){
	std::cout << "smombie " << zombie::_name << " died for the horde!" << std::endl;
}

void zombie::setname(std::string name){
	_name = name;
}

void zombie::announce(){
	std::cout << zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
