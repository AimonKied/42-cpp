/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:23:04 by swied             #+#    #+#             */
/*   Updated: 2026/01/09 12:23:04 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	// This should not compile - AAnimal is abstract:
	// const AAnimal* meta = new AAnimal();

	std::cout << "Creating Dog and Cat through AAnimal pointers:" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " says: ";
	j->makeSound();
	std::cout << i->getType() << " says: ";
	i->makeSound();

	std::cout << std::endl;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "Array of animals:" << std::endl;
	const int arraySize = 4;
	AAnimal* animals[arraySize];

	for (int k = 0; k < arraySize / 2; k++) {
		animals[k] = new Dog();
	}
	for (int k = arraySize / 2; k < arraySize; k++) {
		animals[k] = new Cat();
	}

	std::cout << std::endl;
	for (int k = 0; k < arraySize; k++) {
		std::cout << "Animal " << k << " (" << animals[k]->getType() << ") says: ";
		animals[k]->makeSound();
	}

	std::cout << std::endl;
	for (int k = 0; k < arraySize; k++) {
		delete animals[k];
	}

	std::cout << std::endl;
	std::cout << "Deep copy test:" << std::endl;
	Dog original;
	original.getBrain()->setIdea(0, "I want to play fetch!");
	original.getBrain()->setIdea(1, "I love my owner!");

	std::cout << std::endl;
	Dog copy(original);

	std::cout << std::endl;
	std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	copy.getBrain()->setIdea(0, "I want to sleep!");
	std::cout << "After modifying copy:" << std::endl;
	std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	return 0;
}
