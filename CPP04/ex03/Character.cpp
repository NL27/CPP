#include "Character.hpp"

Character::Character(){
}

Character::Character(std::string name) : name(name){
}

Character::Character(const Character &copy){
	*this = copy;
}

Character &Character::operator=(const Character &assign){
	for (int i = 0; i < 4; i++)
		inventory[i] = assign.inventory[i];
	name = assign.name;
	return *this;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		delete inventory[i];
}

std::string const &Character::getName() const{
	return name;
}

void Character::equip(Amateria* m){
	for (int i = 0; i < 4; i++){
		if (!inventory[i]){
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx){
	if (inventory[idx])
		inventory[idx] = 0;
}

void Character::use(int idx, Icharacter& target){
	if (inventory[idx])
		inventory[idx]->use(target);
}
