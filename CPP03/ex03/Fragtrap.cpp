#include "Fragtrap.hpp"

Fragtrap::Fragtrap(){
	_name = "Unknown";
	_health = 100;
	_energy = 100;
	_attack = 30;
	std::cout << "Fragtrap " << _name << " constructor called" << std::endl;
}

Fragtrap::Fragtrap(std::string name){
	_name = name;
	_health = 100;
	_energy = 100;
	_attack = 30;
	std::cout << "Fragtrap " << _name << " constructor called" << std::endl;
}

Fragtrap::Fragtrap(const Fragtrap &copy){
	std::cout << "Fragtrap copy constructor called" << std::endl;
	*this = copy;
}

Fragtrap::~Fragtrap(){
	std::cout << "Fragtrap " << _name << " deconstructor called" << std::endl;
}

Fragtrap &Fragtrap::operator=(const Fragtrap &assign){
	_name = assign._name;
	_health = assign._health;
	_energy = assign._energy;
	_attack = assign._attack;
	std::cout << "Fragtrap " << _name << " assigned" << std::endl;
	return *this;
}

void Fragtrap::attack(const std::string &target){
	if (_energy > 0 && _health > 0){
		_energy -= 1;
		std::cout << "Fragtrap " << _name << " attacks " << target << " which get's damaged by " << _attack << std::endl;
	}else
		std::cout << "Fragtrap " << _name << " done! Out of energy or hit (health) points!" << std::endl;
}

void Fragtrap::highFiveGuys(){
	std::cout << "Fragtrap " << _name << " Highfived itself!" << std::endl;
}

int Fragtrap::getHealth(){
	return _health;
}

int Fragtrap::getAttack(){
	return _attack;
}