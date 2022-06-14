#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "Amateria.hpp"

class Imateriasource
{
	public:
		virtual ~Imateriasource() {}
		virtual void learnMateria(Amateria*) = 0;
		virtual Amateria* createMateria(std::string const &type) = 0;
};

#endif