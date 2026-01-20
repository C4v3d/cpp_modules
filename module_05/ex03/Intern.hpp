#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <map>

class AForm;
class ShrubberyCreationForm;
class LobotomyRequestForm;
class PresidentialPardonForm;

class Intern {
	public:
		Intern();
		Intern(Intern const & other);
		Intern&	operator=(Intern const & other);
		~Intern();

		AForm*	makeForm(std::string const & formName, std::string const & target) const;
	private:
		std::map<std::string, AForm*(Intern::*)(std::string const &)const> _funcMap;
		AForm*	getShrubberyForm(std::string const & target) const;
		AForm*	getRobotomyForm(std::string const & target) const;
		AForm*	getPardonForm(std::string const & target) const;

	class WrongFormException : public std::exception {
		public:
			WrongFormException();
			~WrongFormException() throw();

			const char*	what() const throw();
		private:
			std::string	_message;
	};

};

#endif
