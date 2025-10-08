/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:42:54 by swied             #+#    #+#             */
/*   Updated: 2025/10/08 12:43:13 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    
    std::cout << "Adding new contact..." << std::endl;
    newContact.getInfo();
    
    if (!newContact.isEmpty()) {
        if (contactCount < 8) {
            contacts[contactCount] = newContact;
            contactCount++;
        } else {
            contacts[oldestIndex] = newContact;
            oldestIndex = (oldestIndex + 1) % 8;
        }
        std::cout << "Contact added successfully!" << std::endl;
    }
}

void PhoneBook::displayContacts() const {
    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    
    std::cout << "|" << std::setw(10) << "Index";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname";
    std::cout << "|" << std::endl;
    
    for (int i = 0; i < contactCount && i < 8; i++) {
        if (!contacts[i].isEmpty()) {
            contacts[i].displayShort(i);
        }
    }
}

void PhoneBook::searchContact() const {
    displayContacts();
    
    if (contactCount == 0) {
        return;
    }
    
    std::cout << "Enter contact index: ";
    std::string input;
    std::getline(std::cin, input);
    
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
        int index = input[0] - '0';
        if (index < contactCount && !contacts[index].isEmpty()) {
            contacts[index].displayFull();
        } else {
            std::cout << "Invalid index!" << std::endl;
        }
    } else {
        std::cout << "Invalid input!" << std::endl;
    }
}
