#ifndef ICE_HPP
#define ICE_HPP

#include "Amateria.hpp"

class Ice : public Amateria
{
	private:

	public:
		Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice &assign);
		virtual ~Ice();

		Amateria* clone() const;
		void use(Icharacter& target);
};

#endif