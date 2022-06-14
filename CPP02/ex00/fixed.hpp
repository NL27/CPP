#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class fixed
{
	public:
		// Default constructor that initializes fixed-point nbr to 0
		fixed();
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

	private:
		// Integer to store the fixed-point nbr value
		int _value;
		// store the nbr of fractional bits (value will always be integer literal 8)
		static const int _literal8;
		
};

#endif