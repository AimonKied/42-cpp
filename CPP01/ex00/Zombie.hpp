/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:32:56 by swied             #+#    #+#             */
/*   Updated: 2025/12/05 21:24:24 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string name);
        void announce();
        ~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif