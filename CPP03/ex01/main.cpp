/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 23:25:56 by swied             #+#    #+#             */
/*   Updated: 2026/01/05 23:32:55 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");

	std::cout << std::endl;
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << std::endl;
	scav.attack("Target2");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << std::endl;
	return 0;
}
