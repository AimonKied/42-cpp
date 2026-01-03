/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 06:53:25 by swied             #+#    #+#             */
/*   Updated: 2026/01/03 07:14:08 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	ClapTrap a("A");
	ClapTrap b("B");


    std::cout << std::endl;
	a.attack("B");
	b.takeDamage(3);

    std::cout << std::endl;
	b.attack("A");
	a.takeDamage(5);

    std::cout << std::endl;
	a.beRepaired(3);

    std::cout << std::endl;
	a.attack("B");
	b.takeDamage(10);

    std::cout << std::endl;
	b.attack("A");
	b.beRepaired(5);
    std::cout << std::endl;

	return 0;
}
