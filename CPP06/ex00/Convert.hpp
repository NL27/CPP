#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <cstring>
#include <float.h>
#include <typeinfo>

class Convert{
	private:
	std::string argv_str;

	public:
	Convert();
	Convert(const Convert &copy);
	Convert &operator=(const Convert &assign);
	~Convert();
	
	void checkInput(const char *argv);

	bool checkChar(const char *argv);
	bool checkInt(const char *argv);
	bool checkFloat(const char *argv);
	bool checkDouble(const char *argv);
	bool checkStr(const char *argv);

	void minus();
	void plus();
	void non();

	class NOT : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("char: impossible\nint: impossible\nfloat: nanf\ndouble: nan");
			}
	};
};

#endif