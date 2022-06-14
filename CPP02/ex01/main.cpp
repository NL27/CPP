#include <iostream>
#include "fixed.hpp"
// using namespace std;

int main() {
	fixed a;
	fixed const b (10);
	fixed const c (42.42f);
	fixed const d (b);

	a = fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// std::cout << "===== OWN TEST =====" << std::endl;
    // fixed   y( -3 );
    // fixed   z( -123.456f );

    // std::cout << "y is " << y << std::endl;
    // std::cout << "z is " << z << std::endl;

    // y = z;
    // std::cout << "y is " << y << std::endl;
    // std::cout << "z is " << z << std::endl;
	return 0;
}
