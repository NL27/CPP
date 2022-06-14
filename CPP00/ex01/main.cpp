#include "contacts.hpp"
#include "phonebook.hpp"

int main()
{
	int 		i = 0;
	std::string input;
	phonebook	phonebook;

	std::cout << "Enter ADD, SEARCH or EXIT to use the program" << std::endl;
	std::cout << "ADD to save a contact" << std::endl;
	std::cout << "SEARCH to display a specific contact" << std::endl;
	std::cout << "EXIT to quit program & delete all contacts" << std::endl;
	while (1)
	{
		if (std::getline(std::cin, input) == nullptr)
			return -1;
		if (input == "ADD")
		{
			if (i == 8)
				i = 0;
			phonebook.add(i);
			i++;
		}
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			return -1;
		else
		{
			std::cout << "Enter ADD, SEARCH or EXIT to use the program" << std::endl;
			std::cout << "ADD to save a contact" << std::endl;
			std::cout << "SEARCH to display a specific contact" << std::endl;
			std::cout << "EXIT to quit program & delete all contacts" << std::endl;
		}
	}
	return 0;
}
