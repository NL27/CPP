#include "Diamondtrap.hpp"

int main(){

	Diamondtrap fluffy("Fluffy");
	Diamondtrap puffy("Puffy");

	std::cout << std::endl << "Attack:" << std::endl;
	// for(int i = 0; i < 12; i++)
	fluffy.attack("Puffy");
	puffy.attack("Fluffy");

	std::cout << std::endl << "Damage:" << std::endl;
	fluffy.damage(50);
	puffy.damage(50);

	std::cout << std::endl << "Heal:" << std::endl;
	fluffy.heal(50);
	puffy.heal(50);

	std::cout << std::endl << "Guard:" << std::endl;
	fluffy.guardGate();

	std::cout << std::endl << "High5:" << std::endl;
	puffy.highFiveGuys();

	std::cout << std::endl << "WhoAmI:" << std::endl;
	fluffy.whoAmI();
	puffy.whoAmI();

	std::cout << std::endl;

	return 0;
}