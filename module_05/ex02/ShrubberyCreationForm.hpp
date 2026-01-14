#ifndef SHRUBFORM_HPP
# define SHRUBFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const& executor) const;
	private:
		const std::string	_target;
};

#endif
