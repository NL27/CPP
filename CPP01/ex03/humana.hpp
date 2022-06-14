#ifndef HUMANA_H
# define HUMANA_H

#include "weapon.hpp"

class humana{
private:
		std::string _humanname;
		weapon	 	&_weapontype;
public:
		humana(std::string name, weapon &type);
		~humana();
		void attack() const;
};

#endif