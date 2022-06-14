#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"

class ShrubberyCreationForm : public Form{
	private:

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);
		virtual ~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;
		void makeTree() const;
};

#endif