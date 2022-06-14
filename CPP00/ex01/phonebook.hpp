#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
// # include <ctype.h>
// # include <stdio.h>
# include "contacts.hpp"

class phonebook{

private:
		int counter;

public:
		phonebook();
		~phonebook();
		contacts contacts[8];
		void add(int i);
		void search();
};
#endif