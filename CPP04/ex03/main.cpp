#include "Imateriasource.hpp"
#include "Materiasource.hpp"
#include "Icharacter.hpp"
#include "Character.hpp"
#include "Amateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	Imateriasource *src = new Materiasource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	Icharacter* me = new Character("me");
	
	Amateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	Icharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}