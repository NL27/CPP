#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class Claptrap{
	protected:
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _attack;

	public:
	Claptrap();
	Claptrap(std::string name);
	Claptrap(const Claptrap &copy);
	~Claptrap();
	Claptrap &operator=(const Claptrap &assign);
	void attack(const std::string &target);
	void damage(unsigned int amount);
	void heal(unsigned int amount);
};

#endif