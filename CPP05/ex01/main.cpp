#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Bureaucrat one("Bert", 1);
	try{
		Form form = Form("ABM", 0, 50);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	Bureaucrat two("Bob", 150);
	try{
		Form plan = Form("ABM2", 1, 300);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	Form contract = Form("ABM2", 1, 1);
	std::cout << contract;
	try {
		contract.beSigned(one);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << contract;

	try{
		contract.beSigned(two);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	Form assign = Form("ABM2", 1, 150);
	// Form assign = Form("ABM2", 150, 1);
	// Form assign = Form("ABM2", 1, 1);
	try{
		two.signForm(assign);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}