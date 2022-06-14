#include "harl.hpp"

int main(int argc, char **argv){
	harl harl;
	
	if (argc != 2){
		std::cout << "Usage: ./harlfilter [parameter]" << std::endl;
		harl.complain("debug");
	} 
	else
		harl.complain(argv[1]);
	return 0;
}