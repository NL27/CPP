#ifndef CARACTER_HPP
#define CARACTER_HPP

#include "Icharacter.hpp"
#include "Character.hpp"
#include "Amateria.hpp"

class Character : public Icharacter
{
	private:
		std::string name;
		Amateria *inventory[4];
	
	public:
		Character();
		Character(std::string name);
		Character(const Character &copy);
		Character &operator=(const Character &assign);
		~Character();

		std::string const &getName() const;
		void equip(Amateria* m);
		void unequip(int idx);
		void use(int idx, Icharacter& target);
};

#endif