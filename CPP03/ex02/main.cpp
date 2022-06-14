#include "Claptrap.hpp"
#include "Scavtrap.hpp"
#include "Fragtrap.hpp"

int main(){

	Scavtrap fluffy("Fluffy");
	Scavtrap puffy;
	Fragtrap luffy("Luffy");
	Fragtrap muffy;

	std::cout << std::endl << "Attack:" << std::endl;
	// for(int i = 0; i < 12; i++)
		fluffy.attack("Puffy");
	puffy.attack("Fluffy");
	luffy.attack("Muffy");
	muffy.attack("Luffy");

	std::cout << std::endl << "Damage:" << std::endl;
	fluffy.damage(55);
	puffy.damage(55);
	luffy.damage(55);
	muffy.damage(55);

	std::cout << std::endl << "Heal:" << std::endl;
	fluffy.heal(55);
	puffy.heal(55);
	luffy.heal(55);
	muffy.heal(55);

	std::cout << std::endl << "Guard:" << std::endl;
	fluffy.guardGate();
	puffy.guardGate();

	std::cout << std::endl << "High5:" << std::endl;
	luffy.highFiveGuys();
	muffy.highFiveGuys();
	std::cout << std::endl;

	return 0;
}