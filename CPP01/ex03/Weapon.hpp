/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:28:53 by swied             #+#    #+#             */
/*   Updated: 2025/12/07 15:46:53 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Weapon{
    private:
        std::string type;
    public:
        Weapon(const std::string &type);
        const std::string &getType() const;
        void setType(const std::string &newType);
};

#endif