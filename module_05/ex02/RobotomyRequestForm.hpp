#ifndef ROBOTO_HPP
# define ROBOTO_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
	private:
		const std::string	_target;
		void	executeForm(void) const;

};

#endif
