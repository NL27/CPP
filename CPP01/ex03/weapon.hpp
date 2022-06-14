#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class weapon{
private:
		std::string _type;
public:
		weapon(std::string type);
		~weapon();
		std::string &getType();
		void setType(const std::string &type);
};

#endif