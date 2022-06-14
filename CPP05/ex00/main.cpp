#include "Bureaucrat.hpp"

int main(){
	Bureaucrat one("Bert", 1);
	std::cout << one.getName() << std::endl;
	std::cout << one.getGrade() << std::endl;
	std::cout << one;
	try{
		one.incrememtGrade();
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	Bureaucrat two("Bob", 150);
	std::cout << two.getName() << std::endl;
	std::cout << two.getGrade() << std::endl;
	std::cout << two;
	try{
		two.decrememtGrade();
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat three("Bill", 0);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat four("Bin", 151);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}