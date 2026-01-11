#ifndef SHRUBFORM_HPP
# define SHRUBFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string& name);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const& executor);
};

#endif
