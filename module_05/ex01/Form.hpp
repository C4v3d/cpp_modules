#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
	public:
		Form(const std::string& name, const int& signGrade, const int& signExec);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		const bool&		getSignStatus() const;
		const int&		getSignGrade() const;
		const int&		getExecGrade() const;

		void			beSigned(const Bureaucrat& bureaucrat);

	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_signGrade;
		const int		_execGrade;

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

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
