#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class fixed
{
	private:
		int _value;
		static const int _literal8;
	public:
		fixed();
		fixed(const int i_value);
		fixed(const float f_value);
		//Copy contsructor
		fixed(const fixed &copy);
		// Destructor
		~fixed();
		
		// Comparison Operators
		fixed &operator=(const fixed &assign);

		bool operator==(const fixed &assign) const;
		bool operator!=(const fixed &assign) const;
		bool operator>=(const fixed &assign) const;
		bool operator<=(const fixed &assign) const;
		bool operator>(const fixed &assign) const;
		bool operator<(const fixed &assign) const;
		// Arithmetic Operators
		fixed operator+(const fixed &assign) const;
		fixed operator-(const fixed &assign) const;
		fixed operator*(const fixed &assign) const;
		fixed operator/(const fixed &assign) const;

		fixed operator++(int);
		fixed operator++();
		fixed operator--(int);
		fixed operator--();

		static fixed &min(fixed &one, fixed &two);
		static const fixed &min(fixed const &one, fixed const &two);
		static fixed &max(fixed &one, fixed &two);
		static const fixed &max(fixed const &one, fixed const &two);

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;	
};

std::ostream &operator<<(std::ostream &o, fixed const &fixed);

#endif