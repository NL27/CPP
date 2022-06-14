#include "phonebook.hpp"

phonebook::phonebook(): counter(0){
}

phonebook::~phonebook(){
}

void phonebook::add(int i){
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenbr;
	std::string _darksecret;
	if (this->counter != 8)
		this->counter += 1;
	std::cout << "Firstname: ";
	std::getline(std::cin, _firstname);
	while (_firstname.empty())
	{
		std::cout << "No input. You need to type something!" << std::endl;
		std::cout << "Firstname: ";
		std::getline(std::cin, _firstname);
	}
	std::cout << "Lastname: ";
	std::getline(std::cin, _lastname);
	while (_lastname.empty())
	{
		std::cout << "No input. You need to type something!" << std::endl;
		std::cout << "Lastname: ";
		std::getline(std::cin, _lastname);
	}
	std::cout << "Nickname: ";
	std::getline(std::cin, _nickname);
	while (_nickname.empty())
	{
		std::cout << "No input. You need to type something!" << std::endl;
		std::cout << "Nickname: ";
		std::getline(std::cin, _nickname);
	}
	std::cout << "Phonenbr: ";
	std::getline(std::cin, _phonenbr);
	while (_phonenbr.empty())
	{
		std::cout << "No input. You need to type something!" << std::endl;
		std::cout << "Phonenbr: ";
		std::getline(std::cin, _phonenbr);
	}
	std::cout << "Darksecret: ";
	std::getline(std::cin, _darksecret);
	while (_darksecret.empty())
	{
		std::cout << "No input. You need to type something!" << std::endl;
		std::cout << "Darksecret: ";
		std::getline(std::cin, _darksecret);
	}
	std::cout << "You now have a new contact in your phone book. You have " << 8 - this->counter << " left to add." << std::endl;
	std::cout << "Once you have 0 left we will override the ones that you added in the beginning." << std::endl;
	this->contacts[i].set(_firstname, _lastname, _nickname, _phonenbr, _darksecret);

}

void phonebook::search(){
	int index = 0;
	
	if (this->counter == 0)
	{
		std::cout << "There are no contacts in your phonebook so far." << std::endl;
		std::cout << "First add some contacts into your phonebook." << std::endl;
	}
	else
	{
		std::cout << "|     Index| Firstname|  Lastname|  Nickname|" << std::endl;
		while (index < this->counter)
		{
			this->contacts[index].get(index);
			index++;
		}
		std::cout << "Enter the index of the contact you want to see all info of: ";
		while (!(std::cin >> index) || (index < 0 || index >= this->counter))
		{
			std::cout << "Please enter a valid index: ";
			std::cin.clear();
			std::cin.ignore(512, '\n');
		}
		this->contacts[index].get_full();
	}
}
