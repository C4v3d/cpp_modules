#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const & executor) const;
	private:
		const std::string	_target;
};

#endif
