/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:42:33 by swied             #+#    #+#             */
/*   Updated: 2025/10/06 15:54:18 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		for (int j = 0; j < (int)arg.length(); j++)
		{
			std::cout << (char)toupper(arg[j]);
		}
		if (i < argc -1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
