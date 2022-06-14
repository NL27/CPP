#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class fixed
{
	public:
		// Default constructor that initializes fixed-point nbr to 0
		fixed();
		fixed(const int i_value);
		fixed(const float f_value);
		//Copy contsructor
		fixed(const fixed &copy);
		// Destructor
		~fixed();
		
		// Operators
		fixed & operator=(const fixed &assign);

		// member function which returns the raw value of the fixed-point value
		int getRawBits() const;
		// member function which sets the raw value of the fixed-point nbr
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

	private:
		// Integer to store the fixed-point nbr value
		int _value;
		// store the nbr of fractional bits (value will always be integer literal 8)
		static const int _literal8;
		
};

std::ostream &operator<<(std::ostream, fixed const &fixed);

#endif