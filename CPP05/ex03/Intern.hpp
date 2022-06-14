#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
	private:

	public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &assign);
	~Intern();

	Form* makeForm(std::string formname, std::string targetname);
	class FormDoesNotExistException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Form does Not exist!");
			}
	};
};

#endif