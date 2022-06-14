#include "Diamondtrap.hpp"

Diamondtrap::Diamondtrap(){
	Fragtrap Fragtrap;
	Scavtrap Scavtrap;
	
	_name = "Unknown";
	_health = Fragtrap.getHealth();
	_energy = Scavtrap.getEnergy();
	_attack = Fragtrap.getAttack();
	std::cout << "Diamondtrap " << _name << " constructor called" << std::endl;
}

Diamondtrap::Diamondtrap(std::string name){
	Claptrap::_name = name + "_clap_name";
	_name = name;
	_health = 100;
	_energy = 50;
	_attack = 30;
	std::cout << "Diamondtrap " << _name << " constructor called" << std::endl;
}

Diamondtrap::Diamondtrap(const Diamondtrap &copy){
	std::cout << "Diamondtrap copy constructor called" << std::endl;
	*this = copy;
}

Diamondtrap::~Diamondtrap(){
	std::cout << "Diamondtrap " << _name << " deconstructor called" << std::endl;
}

Diamondtrap &Diamondtrap::operator=(const Diamondtrap &assign){
	_name = assign._name;
	_health = assign._health;
	_energy = assign._energy;
	_attack = assign._attack;
	std::cout << "Diamondtrap " << _name << " assigned" << std::endl;
	return *this;
}

void Diamondtrap::attack(const std::string &target){
	Scavtrap::attack(target);
}

void Diamondtrap::whoAmI(){
	std::cout << "I am " << _name << " & my name is " << Claptrap::_name << std::endl;
}