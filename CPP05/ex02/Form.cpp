#include "Form.hpp"

Form::Form() : _name("Const Form Name"), _signed(false), _sgrade(27), _egrade(100){
}

Form::Form(std::string name, const int sgrade, const int egrade) : _name(name), _signed(false), _sgrade(sgrade), _egrade(egrade){
}

Form::Form(const Form &copy) : _name(copy._name), _sgrade(copy._sgrade), _egrade(copy._egrade){
	if (_sgrade < 1 || _egrade < 1)
		throw Form::GradeTooHighException();
	else if (_sgrade > 150 || _egrade > 150)
		throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &assign){
	_signed = assign._signed;
	return *this;
}

Form::~Form(){
}

std::string const Form::getName() const{
	return _name;
}

int Form::getSgrade() const{
	return _sgrade;
}

int Form::getEgrade() const{
	return _egrade;
}

bool Form::getsigned() const{
	return _signed;
}

void Form::setTarget(std::string const target){
	_target = target;
}

std::string Form::getTarget() const{
	return _target;
}

void Form::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= _sgrade){
		_signed = true;
		std::cout << _name << " has been signed!" << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output, Form const &input){
	output << "Form " << input.getName() <<	" Sign Grade " << input.getSgrade() << " Execution Grade " << input.getEgrade()<< std::endl;
	return output;
}