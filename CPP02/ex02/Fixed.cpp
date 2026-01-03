/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 06:33:48 by swied             #+#    #+#             */
/*   Updated: 2026/01/03 06:43:37 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int n) {
	_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
	_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const {
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

// Vergleichsoperatoren
bool Fixed::operator>(const Fixed& other) const {
	return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
	return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
	return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _fixedPointValue != other._fixedPointValue;
}

// Arithmetische Operatoren
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Prefix ++a: erhoeht um kleinste Einheit (1/256 = 0.00390625)
Fixed& Fixed::operator++() {
	_fixedPointValue++;
	return *this;
}

// Postfix a++: gibt alten Wert zurueck, dann erhoehen
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_fixedPointValue++;
	return temp;
}

// Prefix --a
Fixed& Fixed::operator--() {
	_fixedPointValue--;
	return *this;
}

// Postfix a--
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_fixedPointValue--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
