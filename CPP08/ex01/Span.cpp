#include "Span.hpp"

Span::Span() : _N(1000000){
}

Span::Span(unsigned int N) : _N(N){
}

Span::Span(const Span &copy){
	_N = copy._N;
	_container = copy._container;
}

Span &Span::operator=(const Span &assign){
	_N = assign._N;
	_container = assign._container;
	return *this;
}

Span::~Span(){
}

void Span::addNumber(int i){
	try{
		if (_container.size() >= _N)
			throw FullSpanException();
		else
			_container.push_back(i);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last){
	try{
		if (first > last)
			throw std::invalid_argument("First must be smaller than last");
		else if ((_container.size() + distance(first, last)) > _N)
			throw FullSpanException();
		else{
			_container.insert(_container.end(), first, last);
			// _container.reserve(_container.size() + distance(first, last));
			// while (first != last){
			// 	_container.push_back(*first);
			// 	first++;
			// }
		}
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

int Span::shortestSpan(){
	try{
		if (_container.size() == 1 || _container.empty())
			throw NoSpanException();
		else{
			int smallestrange = std::numeric_limits<int>::max();
			sort(_container.begin(), _container.end());
			for(unsigned int i = 0; i < _N - 1; i++){
				if (_container[i + 1] - _container[i] < smallestrange)
					smallestrange = _container[i + 1] - _container[i];
			}
			return smallestrange;
		}
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}

int Span::longestSpan(){
	try{
		if (_container.size() == 1 || _container.empty())
			throw NoSpanException();
		else
			return (*max_element(_container.begin(), _container.end()) - *min_element(_container.begin(), _container.end()));
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}