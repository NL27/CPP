#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class zombie{
private:
		std::string _name;
public:
		zombie(std::string name);
		~zombie();
		void announce();
};
zombie* newzombie(std::string name);
void randomchump(std::string name);

#endif