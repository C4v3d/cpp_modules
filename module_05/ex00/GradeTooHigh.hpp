#ifndef GRADETOOHIGH_HPP
# define GRADETOOHIGH_HPP

#include <string>
#include <exception>

class GradeTooHigh : public std::exception {
	public:
		GradeTooHigh(const std::string& message);
		virtual ~GradeTooHigh() throw();

		const char*	what() const throw();

	private:
		std::string	_message;
};

#endif
