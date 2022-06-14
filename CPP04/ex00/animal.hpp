#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class animal{
	protected:
		std::string _type;
	public:
		animal();
		animal(const animal &copy);
		virtual ~animal();
		animal &operator=(animal const &assign);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif