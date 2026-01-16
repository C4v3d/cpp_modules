#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain();
		const std::string&	getIdea(size_t const & i) const;
		void				setIdea(std::string const & idea);

	private:
		std::string	_ideas[100];
		size_t		_index;

};

#endif
