/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:54:31 by swied             #+#    #+#             */
/*   Updated: 2025/12/07 15:58:59 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
: name(name), weapon(NULL) {
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() const {
    if (this->weapon != NULL) {
        std::cout <<this->name << " attacks with their " << this->weapon->getType() << std::endl;
    }
    else {
        std::cout <<this->name << " has no weapon" << std::endl;
    }
}