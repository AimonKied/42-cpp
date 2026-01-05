/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 23:36:26 by swied             #+#    #+#             */
/*   Updated: 2026/01/05 23:36:27 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FragTrap frag("Fraggy");

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
	frag.attack("Target3");
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << std::endl;
	return 0;
}
