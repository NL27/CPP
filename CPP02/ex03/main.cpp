#include "point.hpp"

bool	bsp(point const a, point const b, point const c, point const point);

int main() {
	
	// working version
	point	point1( 10, 15 );
	std::cout << "point: " << point1;
	point	a( 0, 0 );
	point	b( 20, 0 );
	point	c( 10, 30 );

	std::cout << "Works: " << bsp( a, b, c, point1 ) << std::endl << std::endl;

	// non-working version (point2 is on edge of triangle)
	point	point2( 10, 0 );
	std::cout << "point: " << point2;
	point	a2( 0, 0 );
	point	b2( 20, 0 );
	point	c2( 10, 30 );

	std::cout << "Doesn't work (edge): " << bsp( a2, b2, c2, point2 ) << std::endl << std::endl;

	// non-working version (point3 is equal to vertex a3)
	point	point3( 10, 30 );
	std::cout << "point: " << point3;
	point	a3( 0, 0 );
	point	b3( 20, 0 );
	point	c3( 10, 30 );

	std::cout << "Doesn't work (point == vertex): " << bsp( a3, b3, c3, point3 ) << std::endl << std::endl;


	// non-working version (point not inside triangle)
	point	point4( 9, 30 );
	std::cout << "point: " << point4;
	point	a4( 0, 0 );
	point	b4( 20, 0 );
	point	c4( 10, 30 );

	std::cout << "Doesn't work (point outside triangle): " << bsp( a4, b4, c4, point4 ) << std::endl;
	return 0;
}
