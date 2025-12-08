/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:30:27 by swied             #+#    #+#             */
/*   Updated: 2025/12/06 23:31:08 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++){
        horde[i].name = name;
        horde[i].announce();
    }
    return(&horde[0]);
}
