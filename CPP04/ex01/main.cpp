#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "brain.hpp"

int main()
{
	std::cout << "Animals creation:" << std::endl;
	animal *animals[4];
	for(int i = 0; i < 2; i++){
		animals[i] = new dog();
		std::cout << std::endl;
	}
	for(int i = 2; i < 4; i++){
		animals[i] = new cat();
		std::cout << std::endl;
	}
	const animal* a = new dog();
	std::cout << std::endl;
	const animal* b = new cat();
	std::cout << std::endl;	
	dog one;
	std::cout << std::endl;
	dog deepcopy = one;
	
	std::cout << std::endl << "Deepcopy:" << std::endl;
	std::cout << one.getBrain() << std::endl;
	std::cout << deepcopy.getBrain() << std::endl;

	std::cout << std::endl << "Animals deletion:" << std::endl;
	for (int i = 0; i < 4; i++){
		delete animals[i];
		std::cout << std::endl;
	}
	delete a;//should not create a leak
	std::cout << std::endl;
	delete b;

	std::cout << std::endl << "System Leaks:" << std::endl;
	system("leaks brain");
	return 0;
}