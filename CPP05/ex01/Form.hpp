#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		bool _signed;
		const int _sgrade;
		const int _egrade;

	public:
		Form();
		Form(std::string name, const int sgrade, const int egrade);
		Form(const Form &copy);
		Form &operator=(const Form &assign);
		~Form();
		std::string const getName() const;
		bool getsigned() const;
		int getSgrade() const;
		int getEgrade() const;
		void beSigned(Bureaucrat bureaucrat);

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Grade to high!");
			}
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Grade to low!");
			}
	};
};

std::ostream &operator<<(std::ostream &output, Form const &input);

#endif