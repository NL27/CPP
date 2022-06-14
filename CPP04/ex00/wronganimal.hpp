#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class wronganimal{
	protected:
		std::string _type;
	public:
		wronganimal();
		wronganimal(const wronganimal &copy);
		virtual ~wronganimal();
		wronganimal &operator=(wronganimal const &assign);
		std::string getType()const;
		void makeSound() const;
};

#endif