#ifndef POINT_H
#define POINT_H

#include "fixed.hpp"

class point{
	private:
		fixed const _x;
		fixed const _y;

	public:
		point();
		point(const float x, const float y);
		point(const point &copy);
		point &operator=(const point &assign);
		~point();

		fixed getX() const;
		fixed getY() const;
		float getXfloat() const;
		float getYfloat() const;
};

std::ostream &operator<<(std::ostream &o, point const point);

#endif