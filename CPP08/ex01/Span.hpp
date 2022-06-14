#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

class Span{
	private:
		unsigned int _N;
		std::vector<int> _container;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &assign);
		~Span();
		void addNumber(int i);
		void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
		int shortestSpan();
		int longestSpan();
	
	class FullSpanException : public std::exception{
	public:
		virtual const char* what() const throw(){
			return ("Span is full!");
		}
	};
	class NoSpanException : public std::exception{
	public:
		virtual const char* what() const throw(){
			return ("No Span found!");
		}
	};
};

#endif