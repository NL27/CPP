#include "point.hpp"

float triangle(point const one, point const two, point const three){
	// Triangle Area Formula = [(x1*(y2-y3) +x2*(y3-y1)+ x3*(y1-y2)]/2.0
	float area = ((one.getXfloat() * (two.getYfloat() - three.getYfloat())
				  + two.getXfloat() * (three.getYfloat() - one.getYfloat())
				  + three.getXfloat() * (one.getYfloat() - two.getYfloat()))
				  / 2.0);

	if (area >= 0)
		return area;
	else
		return (area * -1);
}

bool bsp(point const a, point const b, point const c, point const point){
	bool ret_val = false;
	float abc = triangle(a, b, c);
	float pab = triangle(point, a, b);
	float pbc = triangle(point, b, c);
	float pac = triangle(point, a, c);

	if (pab == 0 || pbc == 0 || pac == 0)
		ret_val = false;
	else if (pab + pbc + pac == abc)
		ret_val = true;
	return ret_val;
}

