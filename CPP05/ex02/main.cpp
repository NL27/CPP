#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){

	Bureaucrat one("Bert", 1);
	PresidentialPardonForm contract("Bert");
	try{
		contract.beSigned(one);
		one.executeForm(contract);
		contract.execute(one);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	RobotomyRequestForm robo("Bert");
	try{
		robo.beSigned(one);
		one.executeForm(robo);
		robo.execute(one);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	ShrubberyCreationForm create("ABM");
	try{
		create.beSigned(one);
		one.executeForm(create);
		create.execute(one);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}