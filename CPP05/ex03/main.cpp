#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){

	Intern one;
	one.makeForm("shrubbery creation", "ABM");
	one.makeForm("presidential pardon", "ABM");
	one.makeForm("robotomy request", "ABM");
	try{
		one.makeForm("smth else request", "ABM");
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}