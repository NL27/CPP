#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data{
	private:
	int _data;

	public:
	Data();
	Data(int input);
	Data(const Data &copy);
	Data &operator=(const Data &assign);
	~Data();
	int getData() const;
	void setData(int const input);
};

Data* deserialize(uintptr_t raw);
uintptr_t serialize(Data* ptr);

#endif