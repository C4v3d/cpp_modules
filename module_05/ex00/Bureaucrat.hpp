#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
	public:
		Bureaucrat(const std::string& name, short grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		std::string	getName() const;
		short		getGrade() const;

		void		incrGrade();
		void		decrGrade();

		/* Can't use friend key word */
		friend std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

	private:
		std::string const	_name;
		short			_grade;

		void			grader();
};

#endif
