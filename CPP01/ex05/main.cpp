#include "harl.hpp"

int main(int argc, char **argv){
	harl harl;

	if (argc != 2){
		std::cout << "Usage: ./harl [parameter]" << std::endl;
		std::cout << "[debug]" << std::endl;
		harl.complain("debug");
		std::cout << "[info]" << std::endl;
		harl.complain("info");
		std::cout << "[warning]" << std::endl;
		harl.complain("warning");
		std::cout << "[error]" << std::endl;
		harl.complain("error");
	} 
	else
		harl.complain(argv[1]);
	return 0;
}