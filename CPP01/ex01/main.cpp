#include "zombie.hpp"

int main(){
	zombie *horde = zombiehorde(4, "Legion");
	for (int i = 0; i < 4; i++)
		horde[i].announce();
	delete [] horde;
	// system("leaks smombiehorde");
	return 0;
}