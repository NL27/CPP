#include "point.hpp"

point::point() : _x(0), _y(0){
}

point::point(const float x, const float y) : _x(x), _y(y){
}

point::point(const point &copy) : _x(copy.getX()), _y(copy.getY()){
	*this = copy;
}

point::~point(){
}

point &point::operator=(const point &assign){
	if (this != &assign){
		// this->_x = assign._x;
		// this->_y = assign._y;
	}
	return *this;
}

fixed point::getX() const{
	return this->_x;
}

fixed point::getY() const{
	return this->_y;
}

float point::getXfloat() const{
	return this->_x.toFloat();
}

float point::getYfloat() const{
	return this->_y.toFloat();
}

std::ostream &operator<<(std::ostream &o, point const point){
	o << "_x: " << point.getXfloat() << "_y: " << point.getYfloat() << std::endl;
	return o; 
}