#include "zombie.hpp"

zombie::zombie(std::string name){
	_name = name;
}

zombie::~zombie(){
	std::cout << "zombie: " << this->_name << " was deconstructed..." << std::endl;
}

void zombie::announce(){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
