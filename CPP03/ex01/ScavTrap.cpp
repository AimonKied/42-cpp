/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 23:26:23 by swied             #+#    #+#             */
/*   Updated: 2026/01/05 23:32:59 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

// Constructor mit Name
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << _name << " copy constructed!" << std::endl;
}

// Copy Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

// ueberschreibt ClapTrap::attack()
void ScavTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
