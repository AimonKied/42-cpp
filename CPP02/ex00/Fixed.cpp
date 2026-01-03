/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 05:34:56 by swied             #+#    #+#             */
/*   Updated: 2026/01/03 06:30:49 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Default Constructor
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
// Copy Cunstructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = other.getRawBits();
}
// Copy Assignment Constructor
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return *this;
}
// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}
