// =====C-TYPE CONVERSION====

int main(){
	int a = 42; 			// reference value

	double b = a; 			// implicit conversion const
	double c = (double) a; 	// explicit conversion const

	double d = a; 			// implicit promotion -> ok
	int e = d;				// implicit demotion -> Harzardous
	int f = (int) d; 		// explicit demotion -> ok you're in charge

	return 0;
}

// =====C-TYPE REINTERPRETATION=====

#include <stdio.h>

int main(){
	float a = 42.042f; 		// reference value

	void * b = &a; 			// implicit reinterpretation const
	void * c = (void *) &a; // explicit reinterpretation const
	
	void * d = &a; 			// implicit promotion -> ok
	// int * e = d;			// implicit demotion -> Harzardous
	int * f = (int *) d; 	// explicit demotion -> ok you're in charge

	printf("%p, %f\n", &a, a);
	
	printf("%p\n", b);
	printf("%p\n", c);

	printf("%p\n", d);
	printf("%p, %d\n", f, *f);

	return 0;
}

// =====C-TYPE QUALIFIER REINTERPRETATION=====

int main(){
	int a = 42; 						// reference value

	int const * b = &a; 				// implicit reinterpretation const
	int const * c = (int const *) &a;	// explicit reinterpretation const
	
	int const * d = &a; 				// implicit promotion -> ok
	// int * e = d;						// implicit demotion -> Harzardous
	int * f = (int *) d; 				// explicit demotion -> ok you're in charge

	return 0;
}

// =====UPCAST & DOWNCAST=====

#include <iostream>

class Parent{};
class Child1: public Parent {};
class Child2: public Parent {};

int main(){
	Child1 a;	 					// reference value

	Parent * b = &a; 				// implicit reinterpretation const
	Parent * c = (Parent *) &a;		// explicit reinterpretation const
	
	Parent * d = &a; 				// implicit upcast -> ok
	// Child1 * e = d;				// implicit downcast -> Harzardous
	Child2 * f = (Child2 *) d; 		// explicit downcast -> ok you're in charge

	return 0;
}

// =====STATIC CAST=====

#include <iostream>

class Parent{};
class Child1: public Parent {};
class Child2: public Parent {};

class Unrelated{};

int main(){
	Child1 a;	 									// reference value

	Parent * b = &a; 								// implicit upcast -> ok
	Child1 * c = b; 								// implicit downcast -> Hell NO!
	Child2 * d = <static_cast><Child2 *>(b);		// explicit downcast -> Harzardous
	
	Unrelated * e = <static_cast><Unrelated *>(&a); // explicit conversion -> Hell NO!

	return 0;
}

// =====DYNAMIC CAST=====

#include <iostream>
#include <typeinfo>
#include <exception>

class Parent{public: virtual ~Parent(void){} };
class Child1: public Parent {};
class Child2: public Parent {};

class Unrelated{};

int main(){
	Child1 a;	 		// reference value
	Parent * b = &a; 	// implicit upcast -> ok
	
	// explicit downcast -> suspens
	Child1 * c = dynamic_cast<Child1 *>(b);
	if (c == NULL)
		std::cout << "Conversion is NOT ok" << std::endl;
	else
		std::cout << "Conversion is ok" << std::endl;
	

	// explicit downcast -> suspens
	try{
		Child2 & d = dynamic_cast><Child2 &>(*b);
		std::cout << "Conversion is ok" << std::endl;
	}
	catch(std::bad_cast &bc){
		std::cout << "Conversion is NOT ok" << bc.what() << std::endl;
		return 0;
	}

	return 0;
}

// =====REINTERPRET CAST=====

int main(){
	float a = 42.042f;					 //reference value

	void *b = &a;						 // implicit promotion -> ok
	int *c = reinterpret_cast<int *>(b); // explicit demotion -> ok
	int &d = reinterpret_cast<int &>(b); // explicit demotion -> ok
}

// =====CONST CAST=====

int main(){
	int a = 42;						//reference value

	int const *b = &a;				// implicit promotion -> ok
	int *c = b; 					// implicit demotion -> HELL NO!
	int *d = const_cast<int *>(b); 	// explicit demotion -> ok
}

// ======CAST OPERATORS=====

#include <iostream>

class Foo{
	private:
	float _v;

	public:
	Foo (float const v) : _v(v){}
	float getV() { return this->_v;}
	operator float() {return this->_v;}
	operator int() {return static_const<int>(this->_v);}
};

int main(){
	Foo a(42.042f);
	float b = a;
	int c = a;

	std:cout << a.getV() << std::endl;
	std:cout << b << std::endl;
	std:cout << c << std::endl;

	return 0;
}

// ===== EXPLICIT KEYWORD=====

#include <iostream>

class A{};
class B{};
class C{
	public:
			 (A const & _) {return;}
	explicit (B const & _) {return;}
};

void f( C const & _ ){
	return;
}

int main(){
	f(A()); // implicit conversion ok
	f(B()); // implicit conversion NOT OK, constructor is explicit
	return 0;
}

// =====CONCLUSION=====

// -------------------------------------------------------------------------------------------
// | CAST 				| CONVERSION | REINTERPRETATION | UPCAST | DOWNCAST | TYPE QUALIFIER |
// -------------------------------------------------------------------------------------------
// | Implicit 			|    YES	 |    				|   YES	 | 		    | 				 |
// | static_cast 		|    YES	 |    				|   YES	 | 	  YES	| 				 |
// | dynamic_cast 		|     		 |    				|   YES	 | 	  YES	| 				 |
// | const_cast 		|     		 |    				|   	 | 	     	| 		YES 	 |
// | reinterpret_cast 	|     		 |       YES		|   YES	 | 	  YES	| 				 |
// -------------------------------------------------------------------------------------------
// | Legacy C cast		|    YES	 |		 YES		|   YES  |    YES	| 		YES		 |
// -------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------
// | CAST 				| SEMANTIC CHECK | RELIABLE AT RUN | TESTED AT RUN | 
// -------------------------------------------------------------------------
// | Implicit 			|    YES		 |    	YES	 	   | 			   |
// | static_cast 		|    YES		 |    		 	   | 	  		   |
// | dynamic_cast 		|    YES 		 |    	YES	 	   | 	  		   |
// | const_cast 		|     			 |    		 	   | 	  YES 	   |
// | reinterpret_cast 	|     			 |      	 	   | 	  		   |
// -------------------------------------------------------------------------
// | Legacy C cast		|				 |				   |			   |
// -------------------------------------------------------------------------


