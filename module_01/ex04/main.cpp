#include <iostream>
#include <fstream>
#include <string>

void	process_line(std::string& line, const std::string toFind, const std::string s) {
	int		pos;
	size_t		len = toFind.size();
	std::string	newString;
	std::string	tmp;

	do {
		pos = line.find(toFind);
		if (pos >= 0) {
			newString = line.substr(0, pos);
			newString.append(s);
			tmp = line.substr(pos + len, line.size());
			newString.append(tmp);
			line.swap(newString);
		}
	} while (pos >= 0);
}

void	sedding(std::string fileName, std::string toReplace, std::string s) {
	std::ifstream	readFile(fileName.c_str(), std::ios_base::in);
	std::string	line;

	if (!readFile.is_open()) {
		std::cout << "File does not exist or can't be opened" << std::endl;
		return ;
	}
	if (toReplace == s) {
		std::cout << "Strings must be different." << std::endl;
		readFile.close();
		return ;
	}
	fileName.append(".replace");
	std::ofstream	writeFile(fileName.c_str(), std::ios_base::out);
	 while (getline(readFile, line)) {
		 process_line(line, toReplace, s);
		 writeFile << line << std::endl;
	}
	readFile.close();
	writeFile.close();
}

int	main(int ac, char **av) {

	try {
		if (ac == 4)
			sedding(av[1], av[2], av[3]);
		else
			throw (ac);
	}
	catch (int numArg) {
		std::cout << "Wow really... You can't even count ?\nIt says 3 arguments and you used: " << numArg - 1 << std::endl;
	}
	return (0);
}
