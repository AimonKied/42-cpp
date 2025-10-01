/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:42:33 by swied             #+#    #+#             */
/*   Updated: 2025/10/01 15:46:56 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		string arg = argv[i];
		for (int j = 0; j < (int)arg.length(); j++)
		{
			cout << (char)toupper(arg[j]);
		}
		if (i < argc -1)
			cout << " ";
	}
	cout << endl;
	return (0);
}
