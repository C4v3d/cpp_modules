#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name): 
	AForm(name, 145, 137) {
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
		plantASeed(getName());
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
