#ifndef ICARACTER_HPP
#define ICARACTER_HPP

#include "Amateria.hpp"

class Amateria;

class Icharacter
{
	public:
		virtual ~Icharacter() {}
		virtual std::string const &getName() const = 0;
		virtual void equip(Amateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, Icharacter& target) = 0;
};

#endif