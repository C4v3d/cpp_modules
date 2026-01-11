#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class AForm; class Bureaucrat {
	public:
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string&	getName() const;
		const int&		getGrade() const;

		void			incrGrade();
		void			decrGrade();

		void			signForm(AForm& form) const;
		void			executeForm(AForm const & form);

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
				~GradeTooLowException() throw();

				const char*	what() const throw();
			private:
				std::string	_message;
		};

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException();
				~GradeTooHighException() throw();

				const char*	what() const throw();
			private:
				std::string	_message;
		};

	private:
		std::string const	_name;
		int			_grade;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat&);

#endif
