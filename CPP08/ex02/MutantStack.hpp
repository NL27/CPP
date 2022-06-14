#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		MutantStack(){};
		MutantStack(const MutantStack &copy){ *this = copy; };
		MutantStack &operator=(const MutantStack &assign){ *this = assign; return *this;};
		~MutantStack(){};


		iterator begin(){ return (MutantStack::c.begin()); };
		iterator end(){ return (MutantStack::c.end()); };
};

#endif