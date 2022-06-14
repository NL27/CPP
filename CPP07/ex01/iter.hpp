#include <iostream>

template <typename T>
void print(T array){
	std::cout << array << std::endl;
}

// template <typename T>
// void increase(T array){
// 	std::cout << array + 1 << std::endl;
// }

// template <typename T>
// void decrease(T array){
// 	std::cout << array - 1 << std::endl;
// }

template <typename T>
void iter(T *array, int length, void(*func)(T const &input)){
	for (int i = 0; i < length; i++)
		func(array[i]);
}
