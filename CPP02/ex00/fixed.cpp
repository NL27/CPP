#include "fixed.hpp"

const int   fixed::_literal8 = 8;

// Constructors
fixed::fixed() : _value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

fixed::fixed(const fixed &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

// Destructor
fixed::~fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Operators
fixed & fixed::operator=(const fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_value = assign.getRawBits();
	return *this;
}

int fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void fixed::setRawBits(const int raw){
	this->_value = raw;
}