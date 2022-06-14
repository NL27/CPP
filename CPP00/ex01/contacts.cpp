#include "contacts.hpp"

contacts::contacts(){
}

contacts::~contacts(){
}

void contacts::get(int index){
	std::cout << "|";
	std::cout << std::setw(10) << index << "|";
	if (this->_firstname.length() > 10)
	{
		this->_firstname.resize(10);
		this->_firstname[9] = '.';
	}
	std::cout << std::setw(10) << this->_firstname << "|";
	if (this->_lastname.length() > 10)
	{
		this->_lastname.resize(10);
		this->_lastname[9] = '.';
	}
	std::cout << std::setw(10) << this->_lastname << "|";
	if (this->_nickname.length() > 10)
	{
		this->_nickname.resize(10);
		this->_nickname[9] = '.';
	}
	std::cout << std::setw(10) << this->_nickname << "|";
	std::cout << std::endl;
}

void contacts::get_full(){
	std::cout << std::endl << "Firstname: " << this->_firstname << std::endl;
	std::cout << "Lastname: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phonenbr: " << this->_phonenbr << std::endl;
	std::cout << "Darksecret: " << this->_darksecret << std::endl << std::endl;
}

void contacts::set(std::string _firstname, std::string _lastname, std::string _nickname, std::string _phonenbr, std::string _darksecret){
	this->_firstname = _firstname;
	this->_lastname = _lastname;
	this->_nickname = _nickname;
	this->_phonenbr = _phonenbr;
	this->_darksecret = _darksecret;
}