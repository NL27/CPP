#include "Intern.hpp"

Intern::Intern(){
}

Intern::Intern(const Intern &copy){
	(void)copy;
	*this = copy;
}

Intern &Intern::operator=(const Intern &assign){
	(void)assign;
	return *this;
}

Intern::~Intern(){
}

Form* Intern::makeForm(std::string formname, std::string targetname){
	std::string array[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = 0;
	Form *newForm = nullptr;
	for (int i = 0; i < 3; i++){
		if (formname == array[i]){
			std::cout << "Intern creates " << formname << std::endl;
			break ;
		}
	}
	switch(i){
		case 0:
			newForm = new PresidentialPardonForm(targetname);
			break ;
		case 1:
			newForm = new RobotomyRequestForm(targetname);
			break ;
		case 2:
			newForm = new ShrubberyCreationForm(targetname);
			break ;
		default:
			throw Intern::FormDoesNotExistException();
	}
}
