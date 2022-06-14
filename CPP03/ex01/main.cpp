#include "Claptrap.hpp"
#include "Scavtrap.hpp"

int main(){

	Scavtrap fluffy("Fluffy");
	Scavtrap puffy;

	std::cout << std::endl << "Attack:" << std::endl;
	// for(int i = 0; i < 12; i++)
		fluffy.attack("Puffy");
	puffy.attack("Fluffy");

	std::cout << std::endl << "Damage:" << std::endl;
	fluffy.damage(55);
	puffy.damage(55);

	std::cout << std::endl << "Heal:" << std::endl;
	fluffy.heal(55);
	puffy.heal(55);

	std::cout << std::endl << "Guard:" << std::endl;
	fluffy.guardGate();
	puffy.guardGate();
	std::cout << std::endl;

	return 0;
}