/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 23:25:47 by swied             #+#    #+#             */
/*   Updated: 2026/01/05 23:32:53 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

// Constructor mit Name
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap " << _name << " copied!" << std::endl;
}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

// Attack: Greift target an, kostet 1 energyPoints
void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// TakeDamage: Nimmt Schaden, verliert hitPoints
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! HP: " << _hitPoints << std::endl;
}

// BeRepaired: Repariert sich, kostet 1 energypoints, gibt amount hitPoints
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot repair!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy to repair!" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " HP! HP: " << _hitPoints << std::endl;
}
