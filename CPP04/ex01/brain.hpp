#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "animal.hpp"

class brain{
	private:
		std::string ideas[100];
	public:
		brain();
		brain(const brain &copy);
		~brain();
		brain &operator=(brain const &assign);
};

#endif