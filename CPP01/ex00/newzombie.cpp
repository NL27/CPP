#include "zombie.hpp"

zombie* newzombie(std::string name){
	zombie *newzombie = NULL;
	newzombie = new zombie(name);
	if (newzombie == NULL)
		return NULL;
	return newzombie;
}