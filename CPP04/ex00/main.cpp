#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"

#include "wronganimal.hpp"
#include "wrongcat.hpp"

int main()
{
	std::cout << "Constructors:" << std::endl;
	const animal* meta = new animal();
	const animal* j = new dog();
	const animal* i = new cat();
	const wronganimal* m = new wronganimal();
	const wronganimal* n = new wrongcat();
	const wrongcat* l = new wrongcat();

	std::cout << std::endl << "Type:" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << m->getType() << " " << std::endl;
	std::cout << n->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;

	std::cout << std::endl << "Sound:" << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	m->makeSound();
	n->makeSound(); //will not output the wrongcat sound!
	l->makeSound(); //will output the wrongcat sound!

	std::cout << std::endl << "Destrucotrs:" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete m;
	delete n;
	delete l;

	return 0;
}