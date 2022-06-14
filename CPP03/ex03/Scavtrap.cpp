#include "Scavtrap.hpp"

Scavtrap::Scavtrap(){
	_name = "Unknown";
	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "Scavtrap " << _name << " constructor called" << std::endl;
}

Scavtrap::Scavtrap(std::string name){
	_name = name;
	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "Scavtrap " << _name << " constructor called" << std::endl;
}

Scavtrap::Scavtrap(const Scavtrap &copy){
	std::cout << "Scavtrap copy constructor called" << std::endl;
	*this = copy;
}

Scavtrap::~Scavtrap(){
	std::cout << "Scavtrap " << _name << " deconstructor called" << std::endl;
}

Scavtrap &Scavtrap::operator=(const Scavtrap &assign){
	_name = assign._name;
	_health = assign._health;
	_energy = assign._energy;
	_attack = assign._attack;
	std::cout << "Scavtrap " << _name << " assigned" << std::endl;
	return *this;
}

void Scavtrap::attack(const std::string &target){
	if (_energy > 0 && _health > 0){
		_energy -= 1;
		std::cout << "Scavtrap " << _name << " attacks " << target << " which get's damaged by " << _attack << std::endl;
	}else
		std::cout << "Scavtrap " << _name << " done! Out of energy or hit (health) points!" << std::endl;
}

void Scavtrap::guardGate(){
	std::cout << "Scavtrap " << _name << " is now in Gate keeper mode" << std::endl;
}

int Scavtrap::getEnergy(){
	return _energy;
}