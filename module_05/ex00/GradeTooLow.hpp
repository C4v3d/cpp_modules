#ifndef GRADETOOLOW_HPP
# define GRADETOOLOW_HPP

#include <string>
#include <exception>

class GradeTooLow : public std::exception {
	public:
		GradeTooLow(const std::string& message);
		virtual ~GradeTooLow() throw();

		const char*	what() const throw();
	private:
		std::string	_message;
};

#endif
