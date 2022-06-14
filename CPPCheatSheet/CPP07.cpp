// ===== TEMPLATES =====

#include <iostream>

template < typename T >
T const & max( T const & x, T const & y){
	return ((x>y) ? x : y);
}

int foo(int x){
	std::cout << "Long computing time" << std::endl;
	return x;
}

int main(){
	int a = 42;
	int b = 21;

	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max<int>(a, b) << std::endl;
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max(a, b) << std::endl;

	float c = -1.7f;
	float d = 4.2f;

	std::cout << "Max of " << c << " and " << d << " is ";
	std::cout << max<float>(c, d) << std::endl;
	std::cout << "Max of " << c << " and " << d << " is ";
	std::cout << max(c, d) << std::endl;

	char e = 'a';
	char f = 'z';

	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << max<char>(e, f) << std::endl;
	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << max(e, f) << std::endl;

	int ret = max<int>(foo(a), foo(b));
	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << ret << std::endl;

	return 0;
}

// No need to do this as there is std

template< typename T>
class List{
	
	public:
	List<T>(T const &content){}
	List<T>(List<T> const &list){}
	~List<T>(){}
	
	private:
	T *	_content;
	List<T> * _next;
}

int main(){
	List<int> a(42);
	List<float> b(3.14f);
	List<List<int>> c(a);

	return 0;
}

// ===== DEFAULT TYPE =====

#include <iostream>
#include <iomanip>

template<typename T = float>
class Vertex{
	
	public:
	Vertex(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z){}
	~Vertex(){}

	T const &getx() const {return this->_x;} 
	T const &gety() const {return this->_y;} 
	T const &getz() const {return this->_z;} 

	private:
	T const _x;
	T const _y;
	T const _z;

	Vertex();
};

template<typename T>
std::ostream &operator<<(std::ostream &o, Vertex<T> const &v){
	std::cout.precision(1);
	o << setiosflags(std::ios::fixed);
	o << "Vertex( ";
	o << v.getx() << ", ";
	o << v.gety() << ", ";
	o << v.getz();
	o << " )";
	return o;
}

int main(){
	Vertex<int> v1(12, 23, 34);
	Vertex<> v2(12, 23, 34);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	return 0;
}

// ===== SPECIALIZATION =====

#include <iostream>
#include <iomanip>

template<typename T, typename U>
class Pair{
	
	public:
	Pair<T, U>(T const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs){
		std::cout << "Generic template" << std::endl;
		return;
	}
	~Pair<T, U>(){}

	T const &fst() const {return this->_lhs;} 
	U const &snd() const {return this->_rhs;} 

	private:
	T const _lhs;
	U const _rhs;

	Pair<T, U>();
};

template<typename U>
class Pair<int, U>{
	
	public:
	Pair<int, U>(int const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs){
		std::cout << "Int partial specialization" << std::endl;
		return;
	}
	~Pair<int, U>(){}

	int &fst() const {return this->_lhs;} 
	U const &snd() const {return this->_rhs;} 

	private:
	int _lhs;
	U const _rhs;

	Pair<int, U>();
};

template<>
class Pair<bool, bool>{
	
	public:
	Pair<bool, bool>(bool lhs, bool rhs){
		std::cout << "Bool/Bool specialization" << std::endl;
		this->_n = 0;
		this->_n != static_cast<int>(lhs) << 0;
		this->_n != static_cast<int>(rhs) << 1;
		return;
	}
	~Pair<bool, bool>(){}

	bool fst() const {return (this->_n & 0x01);} 
	bool snd() const {return (this->_n & 0x02);} 

	private:
	int _n;

	Pair<bool, bool>();
};

template<typename T, typename U>
std::ostream &operator<<(std::ostream & o, Pair<T, U> const &p){
	o << "Pair( " << p.fst() << ", " << p.snd() << " )";
	return o;
}

std::ostream &operator<<(std::ostream & o, Pair<bool, bool> const &p){
	o << std::boolalpha << "Pair( " << p.fst() << ", " << p.snd() << " )";
	return o;
}

int main(){
	Pair<int, int> p1(4, 2);
	Pair<std::string, float> p2(std::string("Pi"), 3.14f);
	Pair<float, bool> p3(4.2f, true);
	Pair<bool, bool> p4(true, false);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;

	return 0;
}