#include "Claptrap.hpp"

Claptrap::Claptrap(std::string name) : _name(name), _health(10), _energy(10), _attack(0){
	std::cout << "Claptrap " << _name << " constructor called" << std::endl; 
}

Claptrap::Claptrap() : _name("Unknown"), _health(10), _energy(10), _attack(0){
	std::cout << "Claptrap " << _name << " constructor called" << std::endl; 
}

Claptrap::Claptrap(const Claptrap &copy){
	*this = copy;
	std::cout << "Claptrap " << _name << " copy constructor called" << std::endl;
}

Claptrap::~Claptrap(){
	std::cout << "Claptrap " << _name << " deconstructor called" << std::endl;
}

Claptrap &Claptrap::operator=(const Claptrap &assign){
	_name = assign._name;
	_health = assign._health;
	_energy = assign._energy;
	_attack = assign._attack;
	std::cout << "Claptrap " << _name << " has been assigned" << std::endl;
	return *this;
}

void Claptrap::attack(const std::string &target){
	if (_energy > 0 && _health > 0){
		_energy -= 1;
		std::cout << "Claptrap " << _name << " attacks " << target << " which get's damaged by" << _attack << std::endl;
	}else
		std::cout << "Claptrap " << _name << " done! Out of energy or hit (health) points!" << std::endl;
}

void Claptrap::damage(unsigned int amount){
	if (_energy > 0 && _health > 0){
		_health -= amount;
		std::cout << "Claptrap " << _name << " hit (health) points were decreased by " << amount << std::endl;
	}
	else
		std::cout << "Claptrap " << _name << " done! Out of energy or hit (health) points!" << std::endl;
}

void Claptrap::heal(unsigned int amount){
	if (_energy > 0 && _health > 0){
		_health += amount;
		_energy -= 1;
		std::cout << "Claptrap " << _name << " hit (health) points were increased by " << amount << std::endl;
	}else
		std::cout << "Claptrap " << _name << " done! Out of energy or hit (health) points!" << std::endl;
}
