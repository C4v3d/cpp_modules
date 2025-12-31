#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed	();
		Fixed	(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		Fixed	(const int value);
		Fixed	(const float value);
		~Fixed	();

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;

		friend	std::ostream&	operator<<(std::ostream& output, const Fixed& fixed);

		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const; 
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const; 

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);


	private:
		int			_fixedPoint;
		static const int	_fractionalBits = 8;
};

#endif
