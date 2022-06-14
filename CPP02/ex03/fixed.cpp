#include <cmath>
#include "fixed.hpp"

const int   fixed::_literal8 = 8;

// Constructors
fixed::fixed() : _value(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

fixed::fixed(const int i_value)
{
	// std::cout << "Int Constructor called" << std::endl;
	this->_value = i_value << this->_literal8;
}

fixed::fixed(const float f_value)
{
	// std::cout << "Float Constructor called" << std::endl;
	this->_value = roundf(f_value * (1 << this->_literal8));
}

fixed::fixed(const fixed &copy)
{
	// std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

// Destructor
fixed::~fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Operators
fixed & fixed::operator=(const fixed &assign)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_value = assign.getRawBits();
	return *this;
}

int fixed::getRawBits() const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void fixed::setRawBits(const int raw){
	this->_value = raw;
}

float fixed::toFloat() const{
	return ((float)this->_value / (float)(1 << this->_literal8));
}

int fixed::toInt() const{
	return (this->_value >> this->_literal8);
}

std::ostream &operator<<(std::ostream &o, fixed const &fixed){
	o << fixed.toFloat();
	return o;
}