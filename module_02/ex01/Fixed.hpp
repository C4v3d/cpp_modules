#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed	();
		Fixed	(const Fixed& other);
		Fixed&	operator=(const Fixed& other);

		Fixed	(const int value);
		Fixed	(const float value);
		int operator<<(const int shiftValue);
		~Fixed	();

		int	getRawBits(void);
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;

	private:
		int			_fixedPoint;
		static const int	_fractionalBits = 8;
};

#endif
