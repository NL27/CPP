#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include "Claptrap.hpp"
#include "Scavtrap.hpp"
#include "Fragtrap.hpp"

class Diamondtrap : virtual public Scavtrap, virtual public Fragtrap{
	private:
		std::string _name;
	public:
		Diamondtrap();
		Diamondtrap(std::string name);
		Diamondtrap(const Diamondtrap &copy);
		~Diamondtrap();
		Diamondtrap &operator=(const Diamondtrap &assign);
		void attack(const std::string &target);
		void whoAmI();
};

#endif