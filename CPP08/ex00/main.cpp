#include "easyfind.hpp"

int main(){
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	std::list<int>::iterator itl = easyfind(lst, 4);
	std::cout << *itl << std::endl;
	
	try{
		std::list<int>::iterator itl = easyfind(lst, 0);
		std::cout << *itl << std::endl;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::vector<int>::iterator itv = easyfind(vec, 2);
	std::cout << *itv << std::endl;

	try{
		std::vector<int>::iterator itv = easyfind(vec, 10);
		std::cout << *itv << std::endl;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	return (0);
}