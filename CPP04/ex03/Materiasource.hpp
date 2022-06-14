#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Amateria.hpp"
#include "Imateriasource.hpp"

class Materiasource : public Imateriasource
{
	private:
		Amateria *materias[4];

	public:
		Materiasource();
		Materiasource(const Materiasource &copy);
		~Materiasource();
		Materiasource &operator=(const Materiasource &assign);

		void learnMateria(Amateria* materia);
		Amateria* createMateria(std::string const &type);
};

#endif