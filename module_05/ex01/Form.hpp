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

		class GradeTooHighException : public std::exception {
		};

		class GradeTooLowException : public std::exception {
		};

};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
