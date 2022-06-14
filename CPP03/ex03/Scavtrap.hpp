#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "Claptrap.hpp"

class Scavtrap : virtual public Claptrap{
	public:
		Scavtrap();
		Scavtrap(std::string name);
		Scavtrap(const Scavtrap &copy);
		~Scavtrap();
		Scavtrap &operator=(const Scavtrap &assign);
		void attack(const std::string &target);
		void guardGate();
		int getEnergy();
};

#endif