#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
	setTarget("Standard");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5){
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): Form("PresidentialPardonForm", 25, 5){
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign){
	setTarget(assign.getTarget());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (executor.getGrade() <= getEgrade())
	{
		if (getsigned() == true)
			std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
			throw Form::FormNotSignedException();
	}
	else
		throw Form::GradeTooLowException();
}
