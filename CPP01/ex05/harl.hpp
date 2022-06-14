#ifndef HARL_H
#define HARL_H

# include <iostream>

class harl{
private:
	void debug();
	void info();
	void warning();
	void error();

public:
	harl();
	~harl();
	void complain(std::string level);
	int whichlevel(std::string level);
};

#endif