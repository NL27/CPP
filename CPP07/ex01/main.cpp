#include "iter.hpp"

int main() {
	char array1[] = { 'a', 'b', 'c', 'd', 'e' };
	// int array2[] = { 1, 2, 3, 4, 5 };

	iter(array1, 5, print);
	std::cout << std::endl;
	// iter(array2, 5, decrease);
	// std::cout << std::endl;
	// iter(array2, 5, increase);

	return (0);
}