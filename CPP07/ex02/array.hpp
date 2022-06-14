#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cmath>

template<typename T>
class Array{
private:
	T *array;
	int _length;
	
public:
	Array() : _length(0) {array = new T[0];};
	Array(unsigned int n) : _length(n) {array = new T[n];};
	Array(const Array &copy) {
		array = new T(copy._length);
		for (int i = 0; i < _length; i++)
			array[i] = copy.array[i];
		_length = copy._length;
	};
	Array &operator=(const Array &assign){
		delete [] array;
		array = new T(assign._length);
		for (int i = 0; i < _length; i++)
			array[i] = assign.array[i];
		_length = assign._length;
		return *this;
	};
	T &operator[](int i){
		if(i < 0 || i >= static_cast<int>(_length))
			throw Array::OutOfBounds();
		return(array[i]);
	};
	~Array() {delete [] array;};

	int size() {return _length;};

	class OutOfBounds : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Index is out of bounds!");
			}
	};
};

#endif