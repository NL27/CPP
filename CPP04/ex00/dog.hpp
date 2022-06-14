#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class dog : public animal{
	private:
	
	public:
		dog();
		dog(const dog &copy);
		~dog();
		dog &operator=(dog const &assign);
		void makeSound() const;
};

#endif