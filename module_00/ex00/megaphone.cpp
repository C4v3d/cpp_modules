/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c4v3d <c4v3d@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:07:13 by c4v3d             #+#    #+#             */
/*   Updated: 2025/12/08 23:28:51 by c4v3d            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	megaphone(std::string str)
{
	std::locale loc;
	
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i], loc);
	std::cout << str;
}

int	main(int ac, char **av)
{	
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	if (ac == 2)
       		megaphone(av[1]);
	else
	{
		for (int i = 1; i < ac; i++)
		{
			megaphone(av[i]);
			if (i < ac - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
