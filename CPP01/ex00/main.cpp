/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:18:32 by swied             #+#    #+#             */
/*   Updated: 2025/12/05 21:21:05 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie* heapZombie = newZombie("Foo_heap");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Foo_stack");
    return(0);
}