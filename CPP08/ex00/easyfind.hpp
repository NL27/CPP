#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <list>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T container, int search){
	typename T::iterator result;
	result = find(container.begin(), container.end(), search);
	if (result != container.end())
		return result;
	throw std::invalid_argument("invalid input");
}


#endif