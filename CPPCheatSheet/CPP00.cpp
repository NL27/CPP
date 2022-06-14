// CPP 00

// ===== NAMESPACES =====
#include <stdio.h>
int	var = 42;
// Namespaces can declare a variable multiple times without having a error when compiling
namespace One{
	int		var = 40;
}
namespace Two{
	int		var = 2;
}
// Namespaces can be put into other namespaces
namespace Three = Two;
// printing
int	main(){
	printf("var: %d\n", var);
	printf("::var: %d\n", ::var); // same as above^^
	printf("One::var: %d\n", One::var);
	printf("Two::var: %d\n", Two::var);
	printf("Three::var: %d\n", Three::var);
}

// ===== INPUT & OUTPUT =====
#include <iostream>
int	main(){
	char	buff[512];
	std::cout << "Output redirected to standard output... DONE!" << std::endl;
	std::cout << "Input a word to output it: ";
	std::cin >> buff;
	std::cout << "Here is your input as output: " << buff << " " << std::endl;
	return (0);
}

// ===== CLASSES & INSTANCES =====

// create a class in a file
#ifndef NEW_CLASS_H
# define NEW_CLASS_H
class New { // Class Name must be the same as Constructor and Destructor
public:
	New(); // Constructor no return type Create
	~New(); // Destructor no return type Destroy
};
#endif
// in a other file New.class.hpp "New" for the Name "hpp" for the header
#include <iostream>
#include "New.hpp"
New::New(){
	std::cout << "Constructor called" << std::endl;
}
New::~New(){
	std::cout << "Destructor called" << std::endl;
}
// create a instance in a third file
#include "New.hpp"
int	main(){
	New	instance;
	return (0);
}

// ===== MEMBER ATTRIBUTES & FUNCTIONS =====

// create a class in a file
//  #pragma once -> can be used to avoid double inclusions (no need to write ifdef define & endif)
#ifndef NEW_CLASS_H
#define NEW_CLASS_H
class New {
public:
	int	one;
	New();
	~New();
	void	two(); // two is a method almost a function
};
#endif
// in a other file
#include <iostream>
#include "New.hpp"
New::New(){
	std::cout << "Constructor called" << std::endl;
}
New::~New(){
	std::cout << "Destructor called" << std::endl;
}
void New::two(){
	one = 42;
	std::cout << "Member function two called" << std::endl;
}
// create a instance in a third file
#include <iostream>
#include "New.class.hpp"
int	main(){
	New	instance;
	instance.one = 42;
	std::cout << "instance.one: " << std::endl;
	instance.two();
	return (0);
}

//	===== THIS =====

#ifndef NEW_CLASS_H
#define NEW_CLASS_H
class New {
public:
	int	one;
	New(); // constructor is a method
	~New(); // destructor is a method
	void	two(); // two is a method almost a function
};
#endif
New::New(){
	std::cout << "Constructor called" << std::endl;
	this->one = 42; // this only use in methods and only for variables NOT use in functions DO NOT use in main
	this->two();	// this can also be used for methods
}

class obj{
	public:
	obj* get_this(){
		return this;
	}
};
int	main(void)
{
	obj	x;
	obj y;
	std::cout << &x << std::endl;
	std::cout << x.get_this() << std::endl;
	std::cout << &y << std::endl;
	std::cout << y.get_this() << std::endl;
	return (0);
}

class obj{  //class can also be struct
			// public are normally always methods
			// private are normally always variables
}

// ===== INITIALIZING LISTS =====
class obj{
public:
	char a1;
	int	 b1;
	float c1;
	obj(char p1, int p2, float p3);
	~obj();
};
// obj::obj(char p1, int p2, float p3){ // same as below
// 	this->a1 = p1;
// 	this->b1 = p2;
// 	this->c1 = p3;
// 	std::cout << p1 << std::endl;
// 	std::cout << p2 << std::endl;
// 	std::cout << p3 << std::endl;
// }
obj::obj(char p1, int p2, float p3) : a1(p1), b1(p2), c1(p3) {
	std::cout << this->a1 << std::endl;
	std::cout << this->b1 << std::endl;
	std::cout << this->c1 << std::endl;
}
obj::~obj(){
}
int main()
{
	obj pr('a', 42, 127.0f);
	return 0;
}

// ===== CONST =====

class obj{
public:
	const float	x;
	int		 	n;
	obj(const float f);
	~obj();
	void bar() const; // if there is const at the end nothing can be changed in there
};
obj::obj(const float f) : x(f), n(42) {
}
obj::~obj(){	
}
void obj::bar() const{  // in here nothing can be assigned
	std::cout << this->x << std::endl;
	std::cout << this->n << std::endl;
}
int main()
{
	obj pr(127.0f);
	pr.bar();
	return 0;
}

// ===== PRIVATE & PUBLIC =====

public:  // public are normally always methods everything the user should be able to access
private: // private are normally always variables everything the user should NOT be able to access

// ===== CLASS VS STRUCT =====

// in classes scopes are private by default
// in struct scopes are public by default

// ===== ACCESSORS C++ || GET & SET =====

class obj{
public:
	obj();
	~obj();
	int getfoo() const;
	int compare(obj * other) const;
private:
	int _foo;
};
int obj::getfoo() const{
	return this->_foo;
}
void obj::setfoo(int v){
	if (v >= 0) // can be only changed if it is a positive number
		return this->_foo;
	return;
}

// ===== COMPARISON C++ =====

class obj{
public:
	obj();
	~obj();
	int setfoo() const;
	void getfoo(int v);
private:
	int _foo;
};
int obj::getfoo() const{
	return this->_foo;
}
void obj::compare(obj * other) const{
	if (this->_foo < other->getfoo())
		return -1;
	else if (this->_foo > other->getfoo())
		return 1;
	return 0;
}

int main(){
	obj instance1(42);
	obj instance2(42);

	if (&instance1 == &instance1)
		std::cout << "instance1 & 1 are physically the same" << std::endl;
	else
		std::cout << "instance1 & 1 are physically not the same" << std::endl;
	if (&instance1 == &instance2)
		std::cout << "instance1 & 2 are physically the same" << std::endl;
	else
		std::cout << "instance1 & 2 are physically not the same" << std::endl;

	if (instance1.compare(&instance1) == 0)
		std::cout << "instance1 & 1 are structurally the same" << std::endl;
	else
		std::cout << "instance1 & 1 are structurally not the same" << std::endl;
	if (instance1.compare(&instance2) == 0)
		std::cout << "instance1 & 2 are structurally the same" << std::endl;
	else
		std::cout << "instance1 & 2 are structurally not the same" << std::endl;
}

// ===== NON MEMBER ATTRIBUTES & FUNCTIONS =====

class obj{
public:
	obj();
	~obj();
	static int getNbInst();
private:
	static int _nbInst;
};
int obj::getNbInst(){
	return obj::_nbInst;
}
int obj::_nbInst = 0; // the only way to initialize a static non member attribute

// ===== POINTERS TO MEMBERS =====

class obj{
public:
	int foo;
	obj();
	~obj();
	void bar() const;
};
obj::obj() : foo(0){
	return;
}
obj::~obj(){
	return;
}
void obj:bar()const{
	return;
}
int main(){
	obj instance;
	obj * instancep = &instance;
	int	obj::*p = NULL;
	void (obj::*f)() const;
	p = &obj::foo;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	f = &obj::bar;
	(instance.*f)();
	(instancep->.*f)();
	return 0;
}

// ===== Phonebook ====
int mygetline(std::istream &is, std::string &s);
int mygetline(std::istream &is, std::string *s);
int mygetline(std::istream &is, const std::string &s) // alias - different name for the same object

class Contact
{
private:
	std::string _name;
	char *memory;
public:
	contact()
	{
		memory = new char[5];
	}
	contact(std::string name) : _name(name)
	{

	}
	~contact()
	{
		delete memory;
	}
	std::string getName() { return (_name); }
};

std::ostream &operator<<(std::ostream &os, Contact a)
{
	os << a.getName();
	return (os);
}

class Phonebook
{
private:
	std::string _name;
	Contact contacts[8];
	unsigned int current_position;
public:
	Phonebook() : current_position(0)
	{
	}

	std::string getName()
	{
		return (_name);
	}

	void setName(std::string name)
	{
		_name = name;
	}

	void pushName(std::string name)
	{
		contacts[current_position] = name;
		current_position++;
		if (current_position == 8)
			current_position = 0;
	}

	void printNames()
	{
		for (unsigned int i = 0; i < 8; ++i)
			std::cout << contacts[i] << std::endl;
	}
};

int main(int argc, char **argv)
{
	Contact a;
	std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
	std::cout << "ADD to save a contact" << std::endl;
	std::cout << "SEARCH to display a specific contact" << std::endl;
	std::cout << "EXIT to quit program & delete all contacts" << std::endl;
	// while (1)
	// {
	// 	if ()
	// }

	Phonebook p1;
	std::string names[10] = {
		"1", "2", "3", "1", "2", "3", "1", "2", "3", "4"
	};
	for (unsigned int i = 0; i < 10; ++i)
		p1.pushName(names[i]);

	p1.printNames();
	std::string b("hello");
	mygetline(std::cin, b);
	std::cout << b << std::endl; // yo
	mygetline(std::cin, &b);
}

int mygetline(std::istream &is, std::string &s) // alias - different name for the same object
{
	s = "yo";
}

int mygetline(std::istream &is, const std::string &s) // alias - different name for the same object
{
	// s = "yo"; // not legal cause s is const reference
	std::cout << s << std::endl;
}

int mygetline(std::istream &is, std::string *s) // pointer
{
	*s = "yo";
}

int mygetline(std::istream &is, std::string s) // takes s in by copy
{
	s = "yo";
}