#include "brain.hpp"

brain::brain(){
	std::cout << "Brain Constructor called" << std::endl;
}

brain::brain(const brain &copy){
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

brain::~brain(){
	std::cout << "Brain Destructor called" << std::endl;
}

brain &brain::operator=(brain const &assign){
	for(int i = 0; i < 100; i++)
		ideas[i] = assign.ideas[i];
	return *this;
}