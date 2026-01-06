#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
	public:
		Bureaucrat(const std::string& name, short grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string	getName() const;
		short			getGrade() const;

		void			incrGrade();
		void			decrGrade();

	private:
		std::string const	_name;
		short			_grade;
};

#endif
