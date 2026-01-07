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
};

#endif
