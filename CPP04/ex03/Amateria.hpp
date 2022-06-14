#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Icharacter.hpp"

class Icharacter;

class Amateria
{
	protected:
		std::string _type;

	public:
		Amateria(std::string const &type);
		Amateria();
		Amateria(const Amateria &copy);
		Amateria &operator=(const Amateria &assign);
		virtual ~Amateria();
		
		std::string const &getType() const; //Returns the materia type
		virtual Amateria* clone() const = 0;
		virtual void use(Icharacter& target);
};

#endif