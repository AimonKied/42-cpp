/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 05:34:51 by swied             #+#    #+#             */
/*   Updated: 2026/01/03 06:08:04 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
	// Der eigentliche Wert - gespeichert als Integer
	int _fixedPointValue;
	// Anzahl der Bits fuer den Nachkomma-Teil (immer 8)
	static const int _fractionalBits = 8;
public:
	// 1. DEFAULT CONSTRUCTOR
	Fixed();
	// 2. COPY CONSTRUCTOR
	Fixed(const Fixed& other);
	// 3. COPY ASSIGNMENT OPERATOR
	Fixed& operator=(const Fixed& other);
	// 4. DESTRUCTOR
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
