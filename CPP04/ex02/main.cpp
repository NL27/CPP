#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "brain.hpp"

int main()
{
	std::cout << "Constructors:" << std::endl;
	// const animal* meta = new animal();
	const animal* j = new dog();
	const animal* i = new cat();


	std::cout << std::endl << "Type:" << std::endl;
	// std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;


	std::cout << std::endl << "Sound:" << std::endl;
	// meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!

	std::cout << std::endl << "Destrucotrs:" << std::endl;
	delete j;
	delete i;

	return 0;
}