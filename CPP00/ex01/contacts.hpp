#ifndef CONTACTS_H
# define CONTACTS_H

# include <iostream>
# include <iomanip>

class contacts{

private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenbr;
		std::string _darksecret;

public:
		contacts();
		~contacts();
		void get(int index);
		void get_full();
		void set(std::string _firstname, std::string _lastname, std::string _nickname, std::string _phonenbr, std::string _darksecret);
};

#endif