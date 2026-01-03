/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 06:11:52 by swied             #+#    #+#             */
/*   Updated: 2026/01/03 06:29:56 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default Constructor
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor (ruft Copy Assignment Operator auf)
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy Assignment Operator
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

// Int Constructor
// Formel: fixedPointValue = n * 2^8 = n << 8
// Beispiel: n=5 -> 5 << 8 = 5 * 256 = 1280
Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = n << _fractionalBits;
}

// Float Constructor
// Formel: fixedPointValue = roundf(f * 2^8)
// Beispiel: f=1.5 -> roundf(1.5 * 256) = roundf(384.0) = 384
// roundf() rundet zur naechsten Ganzzahl
Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const {
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

// Konvertiert Fixed-Point zurueck zu Float
// Formel: float = fixedPointValue / 2^8
// Beispiel: 384 / 256 = 1.5
float Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (float)(1 << _fractionalBits);
}

// Konvertiert Fixed-Point zu Int (einfach ohne Nachkommastelle)
// Formel: int = fixedPointValue >> 8
// Beispiel: 384 >> 8 = 1 (die 0.5 geht verloren)
int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

// Gibt den Float-Wert aus
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
