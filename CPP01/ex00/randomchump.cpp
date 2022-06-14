#include "zombie.hpp"

void randomchump(std::string name){
	zombie newzombie = zombie(name); 
	newzombie.announce();
}