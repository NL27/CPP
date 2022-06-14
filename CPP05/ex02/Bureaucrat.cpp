#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Const Bureaucrat Name"), _grade(111){
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy){
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign){
	_grade = assign._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){
}

std::string const Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrememtGrade(){
	_grade -= 1;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrememtGrade(){
	_grade += 1;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form form){
	if (form.getsigned() == true)
		std::cout << _name << " signed " << form.getName() << std::endl;
	else if (form.getsigned() == false){
		if (form.getEgrade() < _grade && form.getSgrade() < _grade)
			std::cout << _name << " couldn't sign form " << form.getName() << " because... Execution & Sign Grade too low!" << std::endl;
		else if (form.getEgrade() < _grade)
			std::cout << _name << " couldn't sign form " << form.getName() << " because... Execution Grade too low!" << std::endl;
		else if (form.getSgrade() < _grade)
			std::cout << _name << " couldn't sign form " << form.getName() << " because... Sign Grade too low!" << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form){
	if(form.getsigned() == true && _grade <= form.getEgrade())
		std::cout << _name << " executed " << form.getName() << std::endl;
	else if (form.getsigned() == false){
		if (_grade < form.getEgrade() && _grade < form.getSgrade())
			std::cout << _name << " couldn't execute form " << form.getName() << " because... Execution & Sign Grade too low!" << std::endl;
		else if (_grade < form.getEgrade())
			std::cout << _name << " couldn't execute form " << form.getName() << " because... Execution Grade too low!" << std::endl;
		else if (_grade < form.getSgrade())
			std::cout << _name << " couldn't execute form " << form.getName() << " because... Sign Grade too low!" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input){
	output << input.getName() << ", buraucrat grade " << input.getGrade() << std::endl;
	return output;
}
