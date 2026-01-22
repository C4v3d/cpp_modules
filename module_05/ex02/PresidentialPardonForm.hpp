#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
	private:
		const std::string	_target;
		void	executeForm(void) const;
};

#endif
