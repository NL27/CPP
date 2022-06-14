#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "List: " << std::endl;
	std::list<int> nstack;
	nstack.push_front(5);
	nstack.push_front(17);
	std::cout << nstack.front() << std::endl;
	nstack.pop_front();
	std::cout << nstack.size() << std::endl;
	nstack.push_back(3);
	nstack.push_back(5);
	nstack.push_back(737);
	//[...]
	nstack.push_back(0);
	std::list<int>::iterator itl = nstack.begin();
	std::list<int>::iterator itel = nstack.end();
	++itl;
	--itl;
	while (itl != itel){
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> l(nstack);

	std::cout << std::endl << "MutantStack: " << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
