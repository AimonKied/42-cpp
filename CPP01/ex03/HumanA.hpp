/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:38:13 by swied             #+#    #+#             */
/*   Updated: 2025/12/07 15:58:47 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CPP
#define HUMANA_CPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon &weapon;
    public:
        HumanA(const std::string &name, Weapon &weapon);
        void attack() const;
};

#endif