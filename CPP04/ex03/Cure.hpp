#ifndef CURE_HPP
#define CURE_HPP

#include "Amateria.hpp"

class Cure : public Amateria
{
	private:
	
	public:
		Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &assign);
		virtual ~Cure();

		Amateria* clone() const;
		void use(Icharacter& target);
};

#endif