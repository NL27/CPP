#include "Data.hpp"

Data::Data() : _data(0){
}

Data::Data(int input) : _data(input){
}

Data::Data(const Data &copy){
	*this = copy;
}

Data &Data::operator=(const Data &assign){
	_data = assign._data;
	return *this;
}

Data::~Data(){
}

int Data::getData() const{
	return _data;
}

void Data::setData(int const input){
	_data = input;
}

Data* deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

uintptr_t serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}
