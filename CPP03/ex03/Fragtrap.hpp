#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "Claptrap.hpp"

class Fragtrap : virtual public Claptrap{
	public:
		Fragtrap();
		Fragtrap(std::string name);
		Fragtrap(const Fragtrap &copy);
		~Fragtrap();
		Fragtrap &operator=(const Fragtrap &assign);
		void attack(const std::string &target);
		void highFiveGuys();
		int	getHealth();
		int	getAttack();
};

#endif