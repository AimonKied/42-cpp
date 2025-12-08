/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:41:51 by swied             #+#    #+#             */
/*   Updated: 2025/12/07 15:47:29 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type){
    this->type = type;
}

const std::string &Weapon::getType() const{
    return (this->type);
}

void Weapon::setType(const std::string &newType){
    this->type = newType;
}