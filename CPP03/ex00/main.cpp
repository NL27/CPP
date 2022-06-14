#include "Claptrap.hpp"

int main(){

	Claptrap fluffy("Fluffy");
	Claptrap mystery;
	Claptrap puffy(mystery);

	std::cout << "Attack:" << std::endl;
	// for(int i = 0; i < 12; i++)
		fluffy.attack("Puffy");
	puffy.attack("Fluffy");

	std::cout << "Damage:" << std::endl;
	fluffy.damage(5);
	puffy.damage(5);

	std::cout << "Heal:" << std::endl;
	fluffy.heal(5);
	puffy.heal(5);

	return 0;
}