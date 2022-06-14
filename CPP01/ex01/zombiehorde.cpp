#include "zombie.hpp"

zombie *zombiehorde(int N, std::string name){
	zombie *horde = new zombie[N];
	if (horde == NULL)
		return NULL;
	for (int i = 0; i < N; i++)
		horde[i].setname(name);
	return &horde[0];
}
