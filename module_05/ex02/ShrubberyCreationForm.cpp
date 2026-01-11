#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): 
	AForm("shrub", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other.getName(), getSignGrade(), getExecGrade()), _target(other._target) {
		*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	(void)other;
	std::cout << "Forms are constant thus they cannot be changed after creation" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	drawTree(std::ofstream&	writeFile) {	
	writeFile << "                                               |"		<< std::endl;
	writeFile << "                                              -x-"	<< std::endl;
	writeFile << "                                               |"		<< std::endl;
	writeFile << "              v .   ._, |_  .,"				<< std::endl;
	writeFile << "           `-._\\/  .  \\ /    |/_"			<< std::endl;
	writeFile << "               \\  _.\\, y | \\//"			<< std::endl;
	writeFile << "         _\\_.___\\, \\/ -.\\||"				<< std::endl;
	writeFile << "           `7-,--.`._||  / / ,"				<< std::endl;
	writeFile << "           /'     `-. `./ / |/_.'"			<< std::endl;
	writeFile << "                     |    |//"				<< std::endl;
	writeFile << "                     |_    /"				<< std::endl;
	writeFile << "                     |-   |"				<< std::endl;
	writeFile << "                     |   =|"				<< std::endl;
	writeFile << "                     |    |"				<< std::endl;
	writeFile << "--------------------/ ,  . \\--------._"			<< std::endl;
}

void	plantASeed(std::string target) {
	target.append("_shrubbery");
	std::ofstream	writeFile(target.c_str(), std::ios_base::out);

	if (writeFile.is_open()) {
		drawTree(writeFile);
		writeFile.close();
	}
	else
		std::cout << "File couldn't been created" << std::endl;

}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
	try {
		AForm::execute(executor);
		plantASeed(_target);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
