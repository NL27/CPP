#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
	setTarget("Standard");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45){
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form("RobotomyRequestForm", 72, 45){
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign){
	setTarget(assign.getTarget());
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	
	srand(time(NULL));

	if (executor.getGrade() <= getEgrade())
	{
		if (getsigned() == true){
			std::cout << "Makes some drilling noise... ";
			if (rand() % 100 / 50)
				std::cout << getTarget() << " has been robotomized sucessfully." << std::endl;
			else
				std::cout << "Robotonomy failed..." << std::endl;;
		}
		else
			throw Form::FormNotSignedException();
	}
	else
		throw Form::GradeTooLowException();
}