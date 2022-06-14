#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "wronganimal.hpp"

class wrongcat : public wronganimal{
	private:
	
	public:
		wrongcat();
		wrongcat(const wrongcat &copy);
		~wrongcat();
		wrongcat &operator=(wrongcat const &assign);
		void makeSound()const;
};

#endif