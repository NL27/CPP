// CPP02

// ===== ADHOC POLYMORPHISM =====

#ifndef CPP_H
# define CPP_H
# include <iostream>

class Sample{
public:
	Sample();
	~Sample();
	void bar(char const c)const;
	void bar(int const n)const;
	void bar(float const f)const;
	void bar(Sample const &i)const;
};

#endif

Sample::Sample(){
}

Sample::~Sample(){
}

void Sample::bar(char const c)const {
	std::cout << "Called with char" << c << std::endl;
}

void Sample::bar(int const n)const {
	std::cout << "Called with int" << n << std::endl;
}

void Sample::bar(float const f)const {
	std::cout << "Called with float" << f << std::endl;
}

void Sample::bar(Sample const &i)const {
	(void) i;
	std::cout << "Called with Sample"<< std::endl;
}

// ===== OPERATOR OVERLOAD =====

#ifndef CPP_H
# define CPP_H
# include <iostream>

class Integer{
private:
	int _n;
public:
	Integer();
	~Integer();
	int getValue()const;
	Integer &opetrator=(Integer const &rhs);
	Integer opetrator+(Integer const &rhs)const;
};

std::ostream &operator<<(std::ostream &o, Integer const &rhs);

#endif

Integer::Integer(){
}

Integer::~Integer(){
}

int Integer::getValue()const{
	return this->_n;
}

Integer &Integer::operator=(Integer const &rhs){
	std::cout << "Assign operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;
	this->_n = rhs.getValue();
	return *this; 
}

Integer Integer::operator+(Integer const &rhs)const{
	std::cout << "Assign operator called from " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;
	return Integer(this->_n + rhs.getValue()); 
}

std::ostream &operator<<(std::ostream &o, Integer const &rhs){
	o << rhs.getValue();
	return o;
}

int main(){
	Integer x(30);
	Integer y(10);
	Integer z(0);

	std::cout << "Value x: " << x << std::endl;
	std::cout << "Value y: " << y << std::endl;
	y = Integer(12);
	std::cout << "Value y: " << y << std::endl;
	std::cout << "Value z: " << z << std::endl;
	z = x + y;
	std::cout << "Value z: " << z << std::endl;
	return 0;
}

// ===== CANONICAL FORM =====

#ifndef CPP_H
# define CPP_H
# include <iostream>

class Sample{
private:
	int _foo;
public:
	Sample();
	~Sample();
	Sample(int const n);
	Sample(Sample const &src);
	Sample &operator=(Sample const &rhs);
	int getFoo()const;
};

std::ostream &operator<<(std::ostream &o, Sample const &i);

#endif

int main(){
	Sample inst1;
	Sample inst2(42);
	Sample inst3(inst1);

	std::cout << inst1 << std::endl;
	std::cout << inst2 << std::endl;
	std::cout << inst3 << std::endl;

	inst3 = inst2;
	std::cout << inst3 << std::endl;
	return 0;
}
