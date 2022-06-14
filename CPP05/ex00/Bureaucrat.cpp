#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Const Name"), _grade(111){
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

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input){
	output << input.getName() << ", buraucrat grade " << input.getGrade() << std::endl;
	return output;
}
