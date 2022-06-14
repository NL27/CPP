#include "Data.hpp"

int main(){
	Data data(42);
	Data *data_ptr = &data;

	std::cout << "Data Address:                          " << data_ptr << std::endl;
	std::cout << "Data Address deserialized(serialized): " << deserialize(serialize(data_ptr)) << std::endl << std::endl;

	std::cout << "Data before Serialization " << data_ptr->getData() << std::endl << std::endl;
	
	uintptr_t encrypted = serialize(data_ptr);
	std::cout << "Encrypted: " << encrypted << std::endl;

	Data *decrypted = &data;deserialize(encrypted);
	std::cout << "Decrypted: " << decrypted << std::endl << std::endl;

	std::cout << "Data After: " << decrypted->getData() << std::endl;

	return 0;
}