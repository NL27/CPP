#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "brain.hpp"

class dog : public animal{
	private:
		brain *brian;
	public:
		dog();
		dog(const dog &copy);
		~dog();
		dog &operator=(dog const &assign);
		void makeSound() const;
		brain *getBrain();
};

#endif