#ifndef ROBOTO_HPP
# define ROBOTO_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public :
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const& executor) const;
	private:
		const std::string&	_target;

};

#endif
