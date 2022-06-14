#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class zombie{
private:
		std::string _name;
public:
		zombie();
		~zombie();
		void announce();
		void setname(std::string name);
};
zombie *zombiehorde(int N, std::string name);

#endif