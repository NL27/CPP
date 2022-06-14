#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &assign);
		~Bureaucrat();

		std::string const getName() const;
		int getGrade() const ;

		void incrememtGrade();
		void decrememtGrade();

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Grade to high! Highest possible Grade is 1!");
			}
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Grade to low! Lowest possible Grade is 150!");
			}
	};
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input);

#endif