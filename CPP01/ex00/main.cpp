#include "zombie.hpp"

int main(){
	zombie stack = zombie("Stack");
	zombie* heap = new zombie("Heap");
	if (heap == NULL)
		return -1;
	randomchump("Stack2.0");
	zombie *heap2 = newzombie("Heap2.0");
	delete heap;
	delete heap2;
	return 0;
}

// int main (){
// 	std::string input;
// 	zombie zombie("Smombie");
// 	std::cout << "Enter your smombie name here: ";
// 	std::getline(std::cin, input);
// 	std::cout << input << ":";
// 	zombie.announce();
// }