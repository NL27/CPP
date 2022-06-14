#ifndef HUMANB_H
# define HUMANB_H

#include "weapon.hpp"

class humanb{
private:
		std::string _humanname;
		weapon 		*_weapontype;
public:
		humanb(std::string name);
		~humanb();
		void attack();
		void setWeapon(weapon &type);
};

#endif