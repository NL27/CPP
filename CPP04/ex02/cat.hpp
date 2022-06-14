#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "brain.hpp"

class cat : public animal{
	private:
		brain *brian;
	public:
		cat();
		cat(const cat &copy);
		~cat();
		cat &operator=(cat const &assign);
		void makeSound() const;
};

#endif